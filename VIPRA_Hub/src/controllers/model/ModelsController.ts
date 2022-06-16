import express                      from "express";
import { deleteFile, deleteDir, tarDirectory, makeDir } from "../../util/FileHandling/FileOperations";
import { ModelMeta }                from "../../data_models/ModelMeta";
import { Status }                   from "../../data_models/Status";
import { IModelRepo }               from "../../repos/models/ModelRepo.interface";
import { storeModel, Files }        from "../../repos/models/ModelStore";
import { IModel }                   from "../../repos/models/Mongo/ModelSchema";
import { config }                   from "../../configuration/config";


// TODO!!!!! ?? decide if models without a source and header should be available for download -RG
//                  the idea behind allowing them to create the model is so they can reserve the name etc.

export class ModelsController{

    private modelRepo       : IModelRepo;
    private tempDirPath     : string;

    constructor(modelRepo : IModelRepo, tempDir : string){
        this.modelRepo = modelRepo;
        this.tempDirPath = tempDir;
        makeDir(tempDir);
    }

    // TODO add caching of options -RG
    public async getOptions() : Promise<{status: Status, options: ModelMeta[]}>{
        const options = await this.modelRepo.getOptions();
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

    public async getModelInfo(name : string) : Promise<{status : Status, modelMeta: ModelMeta}>{
        const model = await this.modelRepo.getModelInfo(name);
        return model;
    }

    // TODO cache tars until model is updated -RG
    public async getModel(name : string) : Promise<{status: Status, path: string}>{
        const staged = await this.modelRepo.stageModel(name);
        if(staged.status === Status.SUCCESS){
            const tarred = await tarDirectory(this.tempDirPath, name, this.tempDirPath);
            return tarred;
        }else{
            return {status: staged.status, path: null};
        }
    }

    public async handleDownloadCleanup(modelName : string) : Promise<void>{
        await deleteDir(`${config.Model.TempDir}/${modelName}`, true);
        await deleteFile(`${config.Model.TempDir}/${modelName}.tar`);
    }

    public async createModel(req : express.Request) : Promise<Status>{
        const stored = await storeModel(req);
        if(stored !== Status.SUCCESS){
            return stored;
        }

        const requestCheck = await this.checkCreateRequest(req);
        if(requestCheck !== Status.SUCCESS){
            return requestCheck;
        }
        const files : Files = req.files as Files;


        // TODO!!! have this take in authentication for creator when that is added -RG
        const modelData : IModel = {
            name: req.body.modelname,
            description: req.body.description,
            creator: 'test@email.com',
            publish: req.body.publish
        };
        if(files.source){
            modelData.source = files.source[0].buffer.toString();
        }
        if(files.header){
            modelData.header = files.header[0].buffer.toString();
        }

        const created = this.modelRepo.createModel(modelData);
        return created;
    }

    public async updateModel(req : express.Request) : Promise<Status>{
        const stored = await storeModel(req);
        if(stored !== Status.SUCCESS){
            return stored;
        }

        if(!this.checkUpdateRequest(req)){
            return Status.BAD_REQUEST;
        }

        const files : Files = req.files as Files;

        // TODO refactor this to one call -RG
        if(files.source){
            const sourceUpdated = await this.modelRepo.updateModelSource(req.body.modelName, files.source[0].buffer.toString());
            if(sourceUpdated !== Status.SUCCESS){
                return sourceUpdated;
            }
        }
        if(files.header){
            const headerUpdated = await this.modelRepo.updateModelSource(req.body.modelName, files.header[0].buffer.toString());
            if(headerUpdated !== Status.SUCCESS){
                return headerUpdated;
            }
        }

        return Status.SUCCESS;
    }

    public async deleteModel(name : string) : Promise<Status>{
        const deleted = await this.modelRepo.deleteModel(name);
        return deleted;
    }

    private async checkCreateRequest(req : express.Request) : Promise<Status> {
        const required : boolean = (req.body.modelname && req.body.description && req.body.publish);
        if(!required){
            return Status.BAD_REQUEST;
        }
        const exists = (await this.modelRepo.getModelInfo(req.body.modelname)).status !== Status.NOT_FOUND;
        if(exists){
            return Status.CONFLICT;
        }
        return Status.SUCCESS;
    }

    private checkUpdateRequest(req : express.Request) : Status {
        const required : boolean = req.body.modelName;
        if(!required){
            return Status.BAD_REQUEST;
        }
    }
}