import express                          from "express";

import { Status }                       from "../../data_models/Status";
import { IModuleRepo }                  from "../../repos/module/ModuleRepo.interface";
import { storeFiles, Files }            from "../../util/FileStore";
import { config }                       from "../../configuration/config";
import { deleteFile, deleteDir, tarDirectory, makeDir }     from "../../util/FileHandling/FileOperations";
import { Module, ModuleMeta, ModuleType, typeFromString }   from "../../data_models/Module";


// TODO!!!!! ?? decide if models without a source and header should be available for download -RG
//                  the idea behind allowing them to create the model is so they can reserve the name etc.

export class ModulesController{

    private moduleRepo      : IModuleRepo;
    private tempDirPath     : string;

    constructor(moduleRepo : IModuleRepo, tempDir : string){
        this.moduleRepo = moduleRepo;
        this.tempDirPath = tempDir;
        makeDir(tempDir);
    }

    // TODO add caching of options -RG
    public async getOptions(type : ModuleType) : Promise<{status: Status, options: ModuleMeta[]}>{
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

    public async getModuleInfo(type : ModuleType, name : string) : Promise<{status : Status, moduleMeta: ModuleMeta}>{
        const module = await this.moduleRepo.getModuleInfo(type, name);
        return module;
    }

    // TODO cache tars until model is updated -RG
    public async getModule(type : ModuleType, name : string) : Promise<{status: Status, path: string}>{
        const staged = await this.moduleRepo.stageModule(type, name);
        if(staged.status === Status.SUCCESS){
            const tarred = await tarDirectory(this.tempDirPath, name, this.tempDirPath);
            return tarred;
        }else{
            return {status: staged.status, path: null};
        }
    }

    public async handleDownloadCleanup(moduleName : string) : Promise<void>{
        await deleteDir(`${config.Module.TempDir}/${moduleName}`, true);
        await deleteFile(`${config.Module.TempDir}/${moduleName}.tar`);
    }

    public async createModule(req : express.Request) : Promise<Status>{
        const stored = await storeFiles(req);
        if(stored !== Status.SUCCESS){
            return stored;
        }

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

        if(!this.checkUpdateRequest(req)){
            return Status.BAD_REQUEST;
        }

        const files : Files = req.files as Files;

        // TODO refactor this to one call -RG
        if(files.source){
            const sourceUpdated = await this.moduleRepo.updateModuleSource(req.body.moduleName, files.source[0].buffer.toString());
            if(sourceUpdated !== Status.SUCCESS){
                return sourceUpdated;
            }
        }
        if(files.header){
            const headerUpdated = await this.moduleRepo.updateModuleSource(req.body.moduleName, files.header[0].buffer.toString());
            if(headerUpdated !== Status.SUCCESS){
                return headerUpdated;
            }
        }

        return Status.SUCCESS;
    }

    public async deleteModule(type : ModuleType, name : string) : Promise<Status>{
        const deleted = await this.moduleRepo.deleteModule(type, name);
        return deleted;
    }

    private async checkCreateRequest(req : express.Request) : Promise<Status> {
        const required : boolean = (req.body.modulename && req.body.description && req.body.publish);
        if(!required){
            return Status.BAD_REQUEST;
        }

        const type : ModuleType = typeFromString(req.body.type);
        if(!type){
            return Status.BAD_REQUEST;
        }

        const exists = (await this.moduleRepo.getModuleInfo(type, req.body.modulename)).status !== Status.NOT_FOUND;
        if(exists){
            return Status.CONFLICT;
        }
        return Status.SUCCESS;
    }

    private checkUpdateRequest(req : express.Request) : Status {
        const required : boolean = req.body.moduleName;
        if(!required){
            return Status.BAD_REQUEST;
        }
    }
}