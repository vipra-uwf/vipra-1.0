import express                          from "express";

import { Status }                       from "../../data_models/Status";
import { IModuleRepo }                  from "../../repos/module/ModuleRepo.interface";
import { storeFiles, Files }            from "../../util/FileStore";
import { config }                       from "../../configuration/config";
import { deleteFile, deleteDir, tarDirectory, makeDir }     from "../../util/FileHandling/FileOperations";
import { Module, ModuleMeta, ModuleType, ModuleUpdate, typeFromString }   from "../../data_models/Module";

export class ModulesController{

    private moduleRepo      : IModuleRepo;
    private tempDirPath     : string;

    constructor(moduleRepo : IModuleRepo, tempDir : string){
        this.moduleRepo = moduleRepo;
        this.tempDirPath = tempDir;
        makeDir(tempDir);
    }

    // TODO add caching of options -RG
    public async getOptions(type : ModuleType) : Promise<{status: Status; options: ModuleMeta[]}>{
        const options = await this.moduleRepo.getOptions(type);
        if(options){
            return {
                status: Status.SUCCESS,
                options
            };
        }else{
            return {
                status: Status.INTERNAL_ERROR,
                options: null
            };
        }
    }

    public async getModuleInfo(type : ModuleType, name : string) : Promise<{status : Status; moduleMeta: ModuleMeta}>{
        const module = await this.moduleRepo.getModuleInfo(type, name);
        return module;
    }

    // TODO cache tars until model is updated -RG
    public async getModule(type : ModuleType, name : string) : Promise<{status: Status; path: string}>{
        const staged = await this.moduleRepo.stageModule(type, name);
        if(staged.status === Status.SUCCESS){
            const tarred = await tarDirectory(this.tempDirPath, name, this.tempDirPath);
            return tarred;
        }else{
            return {status: staged.status, path: null};
        }
    }

    public handleDownloadCleanup(moduleName : string) : void{
        deleteDir(`${config.Module.TempDir}/${moduleName}`, true);
        deleteFile(`${config.Module.TempDir}/${moduleName}.tar`);
    }

    public async createModule(req : express.Request) : Promise<Status>{
        const requestCheck = await this.checkCreateRequest(req);
        if(requestCheck !== Status.SUCCESS){
            return requestCheck;
        }

        const files : Files = req.files as Files;
        const moduleData : Module = {
            name: req.body.modulename,
            description: req.body.description,
            type : typeFromString(req.params.type),
            publish: req.body.publish
        };

        if(files.source){
            moduleData.source = files.source[0].buffer.toString();
        }
        if(files.header){
            moduleData.header = files.header[0].buffer.toString();
        }

        const created = this.moduleRepo.createModule(moduleData);
        return created;
    }

    public async updateModule(req : express.Request) : Promise<Status>{
        const stored = await storeFiles(req);
        if(stored !== Status.SUCCESS){
            return stored;
        }

        const update : ModuleUpdate = {
            name: req.params.name,
            type: typeFromString(req.params.type)
        };

        const files : Files = req.files as Files;
        if(files){
            if(files.source){
                update.source = files.source[0].buffer.toString();
            }
            if(files.header){
                update.header = files.header[0].buffer.toString();
            }
        }else{
            if(!req.body.description && ! req.body.publish){
                return Status.BAD_REQUEST;
            }
        }

        if(req.body.description){
            update.description = req.body.description;
        }
        if(req.body.publish){
            update.publish = req.body.publish;
        }

        const updated = await this.moduleRepo.updateModule(update);
        return updated;
    }

    public async deleteModule(type : ModuleType, name : string) : Promise<Status>{
        const deleted = await this.moduleRepo.deleteModule(type, name);
        return deleted;
    }

    private async checkCreateRequest(req : express.Request) : Promise<Status> {
        // IMPORTANT: stored MUST go first as it parses the request -RG
        const stored = await storeFiles(req);
        if(stored !== Status.SUCCESS){
            return stored;
        }

        if(!config.Module.AllowNoSource){
            const checkFiles = this.checkFiles(req);
            if(checkFiles !== Status.SUCCESS){
                return checkFiles;
            }
        }

        const required : boolean = (req.body.modulename && req.body.description && req.body.publish);
        if(!required){
            return Status.BAD_REQUEST;
        }

        const type : ModuleType = typeFromString(req.params.type);
        if(!type){
            return Status.BAD_REQUEST;
        }

        const exists = (await this.moduleRepo.getModuleInfo(type, req.body.modulename)).status !== Status.NOT_FOUND;
        if(exists){
            return Status.CONFLICT;
        }

        return Status.SUCCESS;
    }

    private checkFiles(req : express.Request) : Status{
        const files = req.files as Files;
        if(!files || !(files.source && files.header)){
            return Status.BAD_REQUEST;
        }

        return Status.SUCCESS;
    }
}