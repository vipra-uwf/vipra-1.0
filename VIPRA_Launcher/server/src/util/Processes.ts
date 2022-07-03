import child_process from 'child_process';

import { Logger } from '../logging/Logging';
import { config } from "../configuration/config";
import { Status } from "../data_models/Status.e";
import { fileExists } from './FileOperations';
import { SimConfig } from '../data_models/simconfig';


const buildModule = async (moduleDir : string) : Promise<child_process.ChildProcess> => {
    return new Promise((resolve, reject)=>{
        if(!fileExists(moduleDir)){
            Logger.error(`Attempt to build module that doesn't exist: ${moduleDir}`);
            reject(Status.BAD_REQUEST);
        }
        const ps = child_process.exec(`sh ${config.vipra.scripts.moduleObj} --module ${moduleDir}`, (error : child_process.ExecException) => {
            if(error){
                Logger.error(`buildModule: ${error.message}`);
                reject(error);
            }
        });
        ps.stderr.on('data', (data : string) => {
            Logger.info(`buildModule: ${data}`);
        });
        ps.stdout.on('data', (data : string) =>{
            Logger.info(`buildModule: ${data}`);
        });
        ps.on('close', (code : number, signal : NodeJS.Signals)=>{
            if(code !== 0){
                reject(signal);
            }else{
                Logger.info(`Module Build Successful: ${moduleDir}`);
                resolve(ps);
            }
        });
    });
};

const compileGenMain = async () : Promise<child_process.ChildProcess> => {
    return new Promise((resolve, reject) =>{
        const ps = child_process.exec(`sh ${config.vipra.scripts.genMain} --vipraDir ${config.vipra.vipraDir}`, (error : child_process.ExecException) => {
            if(error){
                Logger.error(`compileGenMain: ${error.message}`);
                reject(error);
            }
        });
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
                resolve(ps);
            }
        });
    });
};

const compileConfig = async (simconfig : SimConfig) : Promise<Status> => {
    return new Promise((resolve, reject)=>{
        const command : string =
        `sh ${config.vipra.scripts.compConfig}\
        --ID ${simconfig.id}\
        --IDL ${simconfig.input_data_loader_id}\
        --ODP ${simconfig.output_data_writer_id}\
        --SOH ${simconfig.simulation_output_handler_id}\
        --PS ${simconfig.pedestrian_set_id}\
        --OS ${simconfig.obstacle_set_id}\
        --ESF ${simconfig.entity_set_factory_id}\
        --GS ${simconfig.goals_id}\
        --PDM ${simconfig.pedestrian_dynamics_model_id}\
        --HBM ${simconfig.human_behavior_model_id}`;

        const ps = child_process.exec(command, (error : child_process.ExecException) => {
            if(error){
                Logger.error(`compileConfig: ID: ${simconfig.id} : ${error.message}`);
                reject(error);
            }
        });
        ps.stderr.on('data', (data : string) => {
            Logger.error(`compileConfig: ID: ${simconfig.id} : ${data}`);
        });
        ps.stdout.on('data', (data : string) => {
            Logger.info(`compileConfig: ID: ${simconfig.id} : ${data}`);
        });
        ps.on('close', (code : number, signal : NodeJS.Signals) => {
            if(code !== 0){
                reject(signal);
            }
            Logger.info(`Config Compiled Successfully: ${simconfig.id}`);
            resolve(Status.SUCCESS);
        });
    });
};

const runSim = (configID : string, outputDir : string) : child_process.ChildProcess =>{
    if(!fileExists(`${config.vipra.simsDir}/${configID}`)){
        return null;
    }
    const ps = child_process.exec(`sh ${config.vipra.scripts.runSim} --configID ${configID} --outDir ${outputDir}`, (error) =>{
        if(error){
            Logger.error(`runSim: ${error.message}`);
        }
    });
    ps.stderr.on('data', (data : string) => {
        Logger.error(`runSim: ID: ${configID} : ${data}`);
    });
    ps.stdout.on('data', (data : string) => {
        Logger.info(`runSim: ID: ${configID} : ${data}`);
    });
    return ps;
};


export {
    buildModule,
    compileConfig,
    runSim,
    compileGenMain
};