import express from 'express';
import crypto from 'crypto';

import { storeFiles }                           from '../../util/FileStore';
import { Module }                               from "../../data_models/module";
import { Status }                               from "../../data_models/Status.e";
import { deleteDir, deleteFile, extractTar, fileExists, makeDir, matchFile, moveFile, readJsonFile, writeFile, writeFileFromBuffer }      from '../../util/FileOperations';
import { config } from '../../configuration/config';
import { Logger } from '../../logging/Logging';

export class ModuleController {

    modules         : Module[];
    moduleFilePath  : string;
    tmpDir          : string;

    constructor(tempDir : string, moduleFilePath : string){
        this.moduleFilePath = moduleFilePath;
        this.loadModules();
        this.setupTempDir(tempDir);
    }

    public getInstalledModules() : Module[] {
        return this.modules;
    }

    // TODO change the extraction etc to in-memory -RG
    public async installModule(req : express.Request) : Promise<Status> {
        const stored = await storeFiles(req);
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

    public removeModule(id : string) : Status {
        const moduleIndex : number = this.modules.findIndex((mod)=>{
            return mod.id === id;
        });

        const module = this.modules.at(moduleIndex);
        if(module){
            const deleted = deleteDir(`${module.dirPath}/${module.name}`, true);
            if(deleted !== Status.SUCCESS){
                return deleted;
            }
            this.modules.slice(moduleIndex, moduleIndex);
            writeFile(this.moduleFilePath, JSON.stringify(this.modules));
        }else{
            return Status.NOT_FOUND;
        }
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

    private setupTempDir(tempDir : string){
        this.tmpDir = tempDir;
        makeDir(tempDir);
    }

    private checkModule(module : Module) : boolean{
        return (module.name && module.type && (module.params !== undefined));
    }

    private async unPackModule(file : Express.Multer.File, transId : string) : Promise<Status>{

        const written = writeFileFromBuffer(this.tmpDir, `${transId}.tar`, file.buffer);
        if(written !== Status.SUCCESS){
            return written;
        }

        const extracted = await extractTar(this.tmpDir, `${transId}.tar`, `${this.tmpDir}/${transId}`);
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
        return Status.SUCCESS;
    }

    private moveModule(module : Module, fromDir : string) : void{
        makeDir(`${config.vipra.vipraDir}/${module.type}`);
        makeDir(`${config.vipra.vipraDir}/${module.type}/${module.name}`);
        moveFile(`${fromDir}/${module.name}/${module.name}.hpp`, `${config.vipra.vipraDir}/${module.type}/${module.name}/${module.name}.hpp`);
        moveFile(`${fromDir}/${module.name}/${module.name}.cpp`, `${config.vipra.vipraDir}/${module.type}/${module.name}/${module.name}.cpp`);
        module.dirPath = `${config.vipra.vipraDir}/${module.type}`;
    }

    private cleanup(id : string){
        let deleted = deleteDir(`${this.tmpDir}/${id}`, true);
        deleted = deleteFile(`${this.tmpDir}/${id}.tar`);
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
        writeFile(this.moduleFilePath, JSON.stringify(this.modules));
    }
}