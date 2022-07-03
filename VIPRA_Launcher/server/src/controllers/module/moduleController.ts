import express from 'express';
import crypto from 'crypto';

import { storeModule }                           from '../../util/FileStore';
import { Module }                               from "../../data_models/module";
import { Status }                               from "../../data_models/Status.e";
import { deleteDir, deleteFile, extractTar, fileExists, makeDir, matchFile, moveFile, readJsonFile, writeFile, writeFileFromBuffer }      from '../../util/FileOperations';
import { config } from '../../configuration/config';
import { Logger } from '../../logging/Logging';

export class ModuleController {

    modules         : Module[];
    moduleFilePath  : string;
    modulesDir      : string;

    constructor(modulesDirPath : string){
        this.modulesDir = modulesDirPath;
        this.moduleFilePath = `${modulesDirPath}/modules.json`;
        this.setupDirectories();
        this.loadModules();
    }

    public getInstalledModules() : Module[] {
        return this.modules;
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

        const installed = await this.unPackModule(moduleFile, transId)
        .finally(()=>{
            this.cleanup(transId);
        });

        return installed;
    }

    // NOTE: turned off require-await as this may require await later -RG
    // eslint-disable-next-line @typescript-eslint/require-await
    public async removeModule(id : string) : Promise<Status> {
        const moduleIndex : number = this.modules.findIndex((mod)=>{
            return mod.id === id;
        });

        const module : Module = this.modules.at(moduleIndex);
        if(module){
            const deleted = deleteDir(`${module.dirPath}/${module.id}`, true);
            if(deleted !== Status.SUCCESS){
                return deleted;
            }
            Logger.info(`Removed Module: ${module.name}:${module.id}`);
            this.modules = this.modules.slice(moduleIndex, moduleIndex);
            this.writeModules();
            return Status.SUCCESS;
        }else{
            return Status.NOT_FOUND;
        }
    }

    private setupDirectories() : void{
        makeDir(this.modulesDir);
        return;
    }

    private loadModules() : void {
        if(fileExists(this.moduleFilePath)){
            this.modules = readJsonFile<Module[]>(this.moduleFilePath);
        }else{
            this.modules = [];
            writeFile(this.moduleFilePath, "[]");
        }
        return;
    }

    private writeModules() : void {
        writeFile(this.moduleFilePath, JSON.stringify(this.modules));
    }


    private checkModule(module : Module) : boolean{
        return (module.name && module.type && (module.params !== undefined));
    }

    private async unPackModule(file : Express.Multer.File, transId : string) : Promise<Status>{

        const written = writeFileFromBuffer(this.modulesDir, `${transId}.tar`, file.buffer);
        if(written !== Status.SUCCESS){
            return written;
        }

        const extracted = await extractTar(this.modulesDir, `${transId}.tar`, `${this.modulesDir}/${transId}`);
        if(extracted.status !== Status.SUCCESS){
            return extracted.status;
        }

        const metaFilePath : string = matchFile(/.*\.mm/, extracted.path, true);
        if(!metaFilePath){
            return Status.INTERNAL_ERROR;
        }

        const module : Module = readJsonFile<Module>(metaFilePath);
        if(this.checkDuplicate(module)){
            return Status.CONFLICT;
        }

        const correct = this.checkModule(module);
        if(!correct){
            return Status.BAD_REQUEST;
        }

        this.moveModule(module, extracted.path);
        this.addModuleOption(module);
        Logger.info(`Installed Module: ${module.name}:${module.id}`);
        return Status.SUCCESS;
    }

    private moveModule(module : Module, fromDir : string) : void{
        makeDir(`${config.vipra.vipraDir}/${module.type}`);
        makeDir(`${config.vipra.vipraDir}/${module.type}/${module.id}`);
        moveFile(`${fromDir}/${module.name}/${module.name}.hpp`, `${config.vipra.vipraDir}/${module.type}/${module.id}/${module.name}.hpp`);
        moveFile(`${fromDir}/${module.name}/${module.name}.cpp`, `${config.vipra.vipraDir}/${module.type}/${module.id}/${module.name}.cpp`);
        module.dirPath = `${config.vipra.vipraDir}/${module.type}`;
    }

    private cleanup(id : string){
        deleteDir(`${this.modulesDir}/${id}`, true);
        deleteFile(`${this.modulesDir}/${id}.tar`);
        return;
    }

    private checkDuplicate(module : Module) : boolean {
        if(this.modules.length === 0){
            return false;
        }
        const duplicate : boolean = this.modules.every((m)=>{
            return (m.id !== module.id);
        });
        return !duplicate;
    }

    private addModuleOption(module : Module){
        this.modules.push(module);
        this.writeModules();
    }
}