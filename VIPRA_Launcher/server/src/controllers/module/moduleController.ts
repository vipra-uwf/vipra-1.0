import express from 'express';
import crypto from 'crypto';

import { storeModule }      from '../../util/FileStore';
import { Status }           from "../../data_models/Status.e";
import { config }           from '../../configuration/config';
import { Logger }           from '../../logging/Logging';
import { buildModule }      from '../../util/Processes';
import { Module, ModuleInfo, ModulesFile, ModuleType } from "../../data_models/module";
import { deleteDir, deleteFile, extractTar, makeDir, matchFile, moveFile, readJsonFile, writeFile, writeFileFromBuffer }      from '../../util/FileOperations';
import { readModules, saveInstalledModules } from './moduleLoading';
import { generateSimulation } from '../simulation/simulationBuild';
import { SimManager } from '../simulation/SimManager';

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

    public allModulesInfo() : {[type: string] : ModuleInfo[]}{
        const moduleInfo : {[type: string] : ModuleInfo[]} = {'pedestrian_dynamics_model':[],'goals':[],'output_data_writer':[],'input_data_loader':[],'simulation_output_handler':[],'pedestrian_set':[],'obstacle_set':[],'entity_set_factory':[],'human_behavior_model':[],'configuration_reader':[],'clock':[],'data':[],'simulation': []};
        Object.keys(this.modules).forEach((type)=>{
            Object.values(this.modules[type as ModuleType]).forEach((module)=>{
                moduleInfo[type].push({
                    id: module.id,
                    name: module.name,
                    description: module.description,
                    params: module.params,
                    type: module.type
                });
            });
        });
        return moduleInfo;
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

        const build : Status = await buildModule(unpacked.module, false);
        if(build !== Status.SUCCESS){
            return build;
        }

        // TODO setting all modules to compiled even if failed -RG
        unpacked.module.compiled = true;
        this.addModuleOption(unpacked.module);

        const compiled : Status = await generateSimulation(false);
        if(compiled !== Status.SUCCESS){
            return compiled;
        }

        return Status.SUCCESS;
    }

    // NOTE: turned off require-await as this will require await later -RG
    // eslint-disable-next-line @typescript-eslint/require-await
    public async removeModule(id : string) : Promise<Status> {
        const module = this.modules.getModule(id);
        deleteDir(module.dirPath, true);
        this.modules.removeModule(module.id);
        saveInstalledModules(this.modules);
        return Status.SUCCESS;
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

        const module : Module = readJsonFile<Module>(metaFilePath, {error: true});
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

    private setupDirectories() : void{
        makeDir(this.modulesDir);
        return;
    }

    private checkModule(module : Module) : boolean{
        return (module.name && module.type && (module.params !== undefined));
    }
}