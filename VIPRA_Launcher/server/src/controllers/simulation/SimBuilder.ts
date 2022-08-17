/**
 * @module SimBuilder
 */

import child_process from 'child_process';

import { Nullable, FuncResult, SimState } from "../../types/typeDefs";
import { Status } from "../../types/Status";
import { Module, ModulesFile, ModuleType } from "../../types/module";
import { config } from '../../configuration/config';
import { Logger } from '../../logging/Logging';
import { FLAGS } from '../../types/flags';
import { container, injectable, singleton } from 'tsyringe';
import { FilesController } from '../files/FilesController';
import { ISimBuilder } from './interfaces/SimBuilder.interface';


// TODO add module history to see which modules caused the simulation to not compile -RG

// TODO check whether atleast one of each required module is installed -RG

// TODO add check that compilation was successful before overwriting simulation executable -RG




/**
 * @description Handles building/comiplation of modules and the simulation
 */
@singleton()
export class SimBuilder implements ISimBuilder {

    private debugMode : boolean;
    private rebuild : boolean;
    private lastBuild : {ready : boolean; reason : Nullable<string>};

    private requiredMet : Map<string, boolean>;


    constructor(){
        this.setup();
    }

    /**
     * @description Sets the flags for SimBuilder
     *
     * FLAGS:
     * - DEBUG_BUILD: whether debug mode should be enabled when building objects
     *
     * @param  {Map<string, string>} argv - command line flags
     * @returns void
     */
    public setFlags(argv : Map<string, string>) : void {
        this.rebuild = argv.get(FLAGS.REBUILD)==='false' || argv.get(FLAGS.REBUILD)==='False' || argv.get(FLAGS.REBUILD)==='FALSE';
        this.debugMode = argv.has(FLAGS.DEBUG_BUILD);
    }


    /**
     * @description Returns whether the simulation is compiled and ready to run and the reason, if it is not
     *
     * @readonly
     */
    public isSimReady() : SimState {
        const missing = this.getMissing();
        if(missing !== null){
            return {ready: false, reason: `Missing a ${missing} Module`};
        }
        return this.lastBuild;
    }


    /**
     * @description Attempts to compile the simulation with all currently installed modules
     *
     * @async
     */
    public async compileSimulation() : Promise<FuncResult> {
        const compiled = await compileSim(this.debugMode);

        if(compiled === Status.SUCCESS){
            this.lastBuild.ready = true;
            this.lastBuild.reason = null;
        }else{
            this.lastBuild.ready = false;
            this.lastBuild.reason = 'Unable to Compile Simulation';
        }
        return {status: compiled, message: compiled === Status.SUCCESS ? null : 'Unable to Compile Simulation'};
    }


    /**
     * @description Attempts to compile the module provided
     *
     * @async
     * @param  {Module} module - the module to compile
     */
    public async addModule(module : Module) : Promise<FuncResult> {
        const built = await buildModule(module, this.debugMode);
        return {status:built, message: built === Status.SUCCESS ? null : 'Unable to Compile Module'};
    }


    /**
     * @description Attempts to compile each module in modules
     * IF compiled
     * module.compiled is set to true
     *
     * @async
     * @param  {ModulesFile} modules - Object with all modules to be compiled
     */
    private async compileAllModules (modules : ModulesFile) : Promise<void>{
        for(const key of Object.keys(modules)){
            for(const value of Object.values(modules.getModulesofType(key as ModuleType))){
                await this.addModule(value)
                .then((compiled)=>{
                    if(compiled.status === Status.SUCCESS){
                        value.compiled = true;
                        this.requiredMet.set(value.type, true);
                    }
                })
                .catch(()=>{
                    value.compiled = false;
                });
            }
        }
    }

    /**
     * @description Compiles generate_main, creates main.cpp, then builds main.o
     *
     * @async
     */
    private async generateMain() : Promise<FuncResult> {
        const completed : FuncResult = await compileGenMain(this.debugMode)
        .then((genmain)=>{
            if(genmain === Status.SUCCESS){
                return compileMain(this.debugMode)
                .then((main)=>{
                    return {status: main, message: main === Status.SUCCESS ? null : 'Compile Main'};
                });
            }else{
                return {status: Status.INTERNAL_ERROR, message: 'Compile Generate Main'};
            }
        })
        .catch(()=>{
            return {status: Status.INTERNAL_ERROR, message: 'Unknown'};
        });

        return {status: completed.status, message: completed.status === Status.SUCCESS ? null : completed.message};
    }

    /**
     * @description Attempts to compile all installed modules, then compile a running simulation
     *
     * @async
     * @param  {ModulesFile} modules - all installed modules
     */
    public async startup(modules : ModulesFile) : Promise<FuncResult> {
        if(!this.rebuild){
            const completed : FuncResult = await compileGenMain(this.debugMode)
            .then((genmain)=>{

                if(genmain === Status.SUCCESS){
                    return compileHumanBehavior(this.debugMode)
                    .then((humanBehavior)=>{

                        if(humanBehavior === Status.SUCCESS){
                            return this.compileAllModules(modules)
                            .then(()=>{
                                const missing = this.getMissing();
                                if(missing === null){
                                    return this.generateMain()
                                    .then((main)=>{

                                        if(main.status === Status.SUCCESS){
                                            return this.compileSimulation();
                                        }else{
                                            this.setLastBuild(false, `Simulation Main Failed to Compile`);
                                            return {status: Status.INTERNAL_ERROR, message: 'Error in Generate Main'};
                                        }
                                    });
                                }else{
                                    const message = `Missing a ${missing} Module`;
                                    this.setLastBuild(false, message);
                                    return {status: Status.INTERNAL_ERROR, message};
                                }
                            });
                        }else{
                            this.setLastBuild(false, 'Human Behavior Failed to Compile');
                            return {status: Status.INTERNAL_ERROR, message: 'Error in Human Behavior'};
                        }
                    });
                }else{
                    this.setLastBuild(false, 'Generate Main Failed to Compile');
                    return {status: Status.INTERNAL_ERROR, message: 'Error in Compile Generate Main'};
                }
            })
            .catch((error : string)=>{
                Logger.error(`Error in SimBuilder startup: ${error}`);
                this.setLastBuild(false, 'Unknown');
                return {status: Status.INTERNAL_ERROR, message: 'Unknown'};
            });

            return {status: completed.status, message: completed.status === Status.SUCCESS ? null : completed.message};
        }else{

            // TODO check if required are already compiled if rebuild is set to false -RG

            return{status: Status.SUCCESS, message: null};
        }
    }

    /**
     * @description Sets up starting object values
     */
    private setup() : void {
        this.lastBuild = {ready: false, reason: 'Builder Not Started'};
        this.requiredMet = new Map();
        Object.values(ModuleType).forEach((type)=>{
            this.requiredMet.set(type, false);
        });
    }
    /**
     * @description Sets the state of the last build run
     * @param  {boolean} ready - whether the simulation has been successfully compiled and ready to run
     * @param  {string} reason - reason for simulation not being read
     */
    private setLastBuild(ready : boolean, reason : string) : void {
        this.lastBuild.ready = ready;
        this.lastBuild.reason = reason;
    }
    /**
     * @description Returns the first missing required module
     */
    private getMissing() : Nullable<string> {
        let missing : Nullable<string> = null;
        this.requiredMet.forEach((value : boolean, key : string)=>{
            if(!value){
                missing = key;
            }
        });
        return missing;
    }
}



const fc = container.resolve(FilesController);

/**
 * @description Builds the object file for the provided module
 *
 *
 * @async
 * @private
 * @param  {Module} module - the module to be compiled
 * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
 */
const buildModule = async (module : Module, debug : boolean) : Promise<Status> => {
    return new Promise((resolve, reject)=>{
        if(!fc.fileExists(`${module.includePath}`)){
            Logger.error(`Attempt to build module that doesn't exist: ${module.name}:${module.id}`);
            reject(Status.NOT_FOUND);
        }
        fc.makeDir(`${config.vipra.vipraDir}/build`);
        cleanModuleObject(module.id);
        const command : string = `make module -C ${config.vipra.simsDir} MODULEPATH=${module.dirPath}/${module.name} MODULEID=${module.id} ${debug ? "DEBUG_OUTPUT=1" : ""}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
            if(error){
                Logger.error(`buildModule: ${error.message}`);
                resolve(Status.INTERNAL_ERROR);
            }
        });
        if(ps && ps.stderr && ps.stdout){
            ps.stderr.on('data', (data : string) => {
                Logger.info(`buildModule: ${data}`);
            });
            ps.stdout.on('data', (data : string) => {
                Logger.info(`buildModule: ${data}`);
            });
            ps.on('close', (code : number) => {
                if(code !== 0){
                    resolve(Status.INTERNAL_ERROR);
                }else{
                    Logger.info(`Module Build Successful: ${module.name}:${module.id}`);
                    resolve(Status.SUCCESS);
                }
            });
        }else{
            reject(`Build Module Process is null`);
        }
    });
};

/**
 * @description Deletes the object file for module with id
 *
 *
 * @private
 * @param  {string} id - id of module to delete
 */
const cleanModuleObject = (id : string) => {
    const objectFile = `${config.vipra.vipraDir}/build/${id}.o`;
    if(fc.fileExists(objectFile)){
        fc.deleteFile(objectFile);
    }
};

/**
 * @description Compiles the entirety of the Human Behavior Model
 *
 *
 * @async
 * @private
 * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
 */
const compileHumanBehavior = async (debug : boolean) : Promise<Status> => {
    return new Promise((resolve, reject) => {
        const command : string = `make compile -C ${config.vipra.behaviorDir} ${debug ? "DEBUG_OUTPUT=1" : ""}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
            if(error){
                Logger.error(`compileHumanBehavior: ${error.message}`);
                reject(error);
            }
        });
        if(ps && ps.stderr && ps.stdout){
            ps.stderr.on('data', (data : string) => {
                Logger.info(`compileHumanBehavior: ${data}`);
            });
            ps.stdout.on('data', (data : string) => {
                Logger.info(`compileHumanBehavior: ${data}`);
            });
            ps.on('close', (code : number, signal : NodeJS.Signals) => {
                if(code !== 0){
                    reject(signal);
                }else{
                    Logger.info(`Human Behavior Compiled Successfully`);
                    resolve(Status.SUCCESS);
                }
            });
        }else{
            reject('Compile Human Behavior Process is null');
        }
    });
};

/**
 * @description Compiles generate_main
 *
 *
 * @async
 * @private
 * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
 */
const compileGenMain = async (debug : boolean) : Promise<Status> => {
    return new Promise((resolve, reject) =>{
        const command : string = `make generate_main -C ${config.vipra.simsDir} ${debug ? "DEBUG_OUTPUT=1" : ""}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
            if(error){
                Logger.error(`compileGenMain: ${error.message}`);
                reject(error);
            }
        });
        if(ps && ps.stderr && ps.stdout){
            ps.stderr.on('data', (data : string) => {
                Logger.info(`compileGenMain: ${data}`);
            });
            ps.stdout.on('data', (data : string) => {
                Logger.info(`compileGenMain: ${data}`);
            });
            ps.on('close', (code : number, signal : NodeJS.Signals) => {
                if(code !== 0){
                    reject(signal);
                }else{
                    Logger.info(`Generate Main Compiled Successfully`);
                    resolve(Status.SUCCESS);
                }
            });
        }else{
            reject('Compile Gen Main Process is null');
        }
    });
};

/**
 * @description Calls generate_main then compiles the resulting main.cpp
 *
 *
 * @async
 * @private
 * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
 */
const compileMain = async (debug : boolean) : Promise<Status> => {
    return new Promise((resolve, reject) =>{
        const command : string = `make compileMain -C ${config.vipra.simsDir} MODULEFILE=${config.module.modulesFile} ${debug ? "DEBUG_OUTPUT=1" : ""}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
            if(error){
                Logger.error(`compileMain: ${error.message}`);
                reject(error);
            }
        });
        if(ps && ps.stderr && ps.stdout){
            ps.stderr.on('data', (data : string) => {
                Logger.info(`compileMain: ${data}`);
            });
            ps.stdout.on('data', (data : string) => {
                Logger.info(`compileMain: ${data}`);
            });
            ps.on('close', (code : number, signal : NodeJS.Signals) => {
                if(code !== 0){
                    reject(signal);
                }else{
                    Logger.info(`Main Compiled Successfully`);
                    resolve(Status.SUCCESS);
                }
            });
        }else{
            reject('Compile Main Process is null');
        }
    });
};

/**
 * @description Compiles the simulation, resulting in the executable VIPRA
 *
 *
 * @private
 * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
 */
const compileSim = (debug : boolean) : Promise<Status> => {
    return new Promise((resolve, reject) =>{
        const command : string = `make simulation -C ${config.vipra.simsDir} ${debug ? "DEBUG_OUTPUT=1" : ""}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
            if(error){
                Logger.error(`compileSim: ${error.message}`);
                reject(error);
            }
        });
        if(ps && ps.stderr && ps.stdout){
            ps.stderr.on('data', (data : string) => {
                Logger.info(`compileSim: ${data}`);
            });
            ps.stdout.on('data', (data : string) => {
                Logger.info(`compileSim: ${data}`);
            });
            ps.on('close', (code : number, signal : NodeJS.Signals) => {
                if(code !== 0){
                    reject(signal);
                }else{
                    Logger.info(`Simulation Generated Successfully`);
                    resolve(Status.SUCCESS);
                }
            });
        }else{
            reject('Compile Simulation Process is null');
        }
    });
};