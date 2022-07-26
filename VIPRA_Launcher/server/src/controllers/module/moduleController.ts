import express from 'express';
import crypto from 'crypto';

import { storeModule }      from '../../util/FileStore';
import { Status }           from "../../data_models/Status.e";
import { config }           from '../../configuration/config';
import { Logger }           from '../../logging/Logging';
import { buildModule, compileSim }      from '../../util/Processes';
import { Module, ModulesFile, ModuleType } from "../../data_models/module";
import { deleteDir, deleteFile, extractTar, makeDir, matchFile, moveFile, readJsonFile, writeFile, writeFileFromBuffer }      from '../../util/FileOperations';
import { readModules, saveInstalledModules } from './moduleLoading';
import { generateSimulation } from '../simulation/simulationBuild';


// TODO split out-> module loading, File operations etc -RG

// TODO at startup, load all modules from the vipra folder, not a file -RG
// TODO if installation/compilation fails, remove from options and remove module code -RG
// TODO provide more in-depth error messages for client -RG
// TODO on start-up, make sure that all installed modules are compiled, compile them if not -RG

// TODO remove modulesDir -RG

export class ModuleController {

    modules         : ModulesFile;
    moduleFilePath  : string;
    modulesDir      : string;

    constructor(){
        this.modulesDir = './';
        this.moduleFilePath = `${config.module.modulesFile}`;
        this.setupDirectories();
        this.modules = readModules();
    }

    public getModulesofType(type : ModuleType) : Module[] {
        return this.modules[type];
    }

    // TODO change the extraction etc to in-memory -RG
    public async installModule(req : express.Request) : Promise<Status> {
        const stored = await storeModule(req);
        if(stored !== Status.SUCCESS){
            return stored;
        }

        if(!(req.file)){
            return Status.BAD_REQUEST;
        }

        const moduleFile : Express.Multer.File = req.file;
        const transId : string = crypto.randomUUID();

        const unpacked = await this.unPackModule(moduleFile, transId)
        .finally(()=>{
              this.cleanup(transId);
        });

        if(unpacked.status !== Status.SUCCESS){
            return unpacked.status;
        }

        // TODO break out simulation generation -RG

        const build : Status = await buildModule(unpacked.module);
        if(build !== Status.SUCCESS){
            return build;
        }

        // TODO setting all modules to compiled even if failed -RG
        unpacked.module.compiled = true;
        this.addModuleOption(unpacked.module);

        const compiled : Status = await generateSimulation();
        if(compiled !== Status.SUCCESS){
            return compiled;
        }

        return Status.SUCCESS;
    }

    // NOTE: turned off require-await as this will require await later -RG
    // eslint-disable-next-line @typescript-eslint/require-await
    public async removeModule(id : string) : Promise<Status> {
        let modulePath : string;
        for(const key of Object.keys(this.modules)){
            const index = this.modules[key as ModuleType].findIndex((mod : Module) =>{
                if(mod.id === id){
                    return true;
                }
            });
            if(index !== -1){
                modulePath = this.modules[key as ModuleType][index].dirPath;
                this.modules[key as ModuleType].splice(index, 1);
            }
        }
        deleteDir(modulePath, true);
        saveInstalledModules(this.modules);
        return Status.SUCCESS;
    }

    private setupDirectories() : void{
        makeDir(this.modulesDir);
        return;
    }

    private checkModule(module : Module) : boolean{
        return (module.name && module.type && (module.params !== undefined));
    }

    private async unPackModule(file : Express.Multer.File, transId : string) : Promise<{status:Status; module:Module}>{

        const written = writeFileFromBuffer(this.modulesDir, `${transId}.tar`, file.buffer);
        if(written !== Status.SUCCESS){
            return {
                status: written,
                module: null
            };
        }

        const extracted = await extractTar(this.modulesDir, `${transId}.tar`, `${this.modulesDir}/${transId}`);
        if(extracted.status !== Status.SUCCESS){
            return {
                status: extracted.status,
                module: null
            };
        }

        const metaFilePath : string = matchFile(/.*\.mm/, extracted.path, true);
        if(!metaFilePath){
            return {
                status: Status.INTERNAL_ERROR,
                module: null
            };
        }

        const module : Module = readJsonFile<Module>(metaFilePath);
        if(this.checkDuplicate(module)){
            return {
                status: Status.CONFLICT,
                module
            };
        }

        const correct = this.checkModule(module);
        if(!correct){
            return {
                status: Status.BAD_REQUEST,
                module: null
            };
        }

        // TODO this should be added after compilation -RG

        this.moveModule(module, extracted.path);
        Logger.info(`Installed Module: ${module.name}:${module.id}`);
        return {
            status: Status.SUCCESS,
            module
        };
    }

    private moveModule(module : Module, fromDir : string) : void {
        makeDir(`${config.vipra.vipraDir}/${module.name}/`);
        moveFile(`${fromDir}/${module.name}/${module.name}.hpp`, `${config.vipra.vipraDir}/${module.name}/${module.name}.hpp`);
        moveFile(`${fromDir}/${module.name}/${module.name}.cpp`, `${config.vipra.vipraDir}/${module.name}/${module.name}.cpp`);
        module.dirPath = `${config.vipra.vipraDir}/${module.name}/`;
        module.includePath = `${config.vipra.vipraDir}/${module.name}/${module.name}.hpp`;
    }

    private cleanup(id : string){
        deleteDir(`${this.modulesDir}/${id}`, true);
        deleteFile(`${this.modulesDir}/${id}.tar`);
        return;
    }

    private checkDuplicate(module : Module) : Module {
        const modules = this.modules[module.type];
        if(modules){
            const duplicate = modules.find((mod) => {
                if(mod.id === module.id){
                    return true;
                }
            });
            return duplicate;
        }
        return null;
    }

    private addModuleOption(module : Module) : void {
        this.modules[module.type].push(module);
        saveInstalledModules(this.modules);
    }
}