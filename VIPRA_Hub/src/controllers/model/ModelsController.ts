import express                      from "express";
import { deleteFile, tarDirectory } from "../../util/FileHandling/FileOperations";
import { ModelMeta }                from "../../data_models/ModelMeta";
import { Status }                   from "../../data_models/Status";
import { IModelRepo }               from "../../repos/models/ModelRepo.interface";
import { storeModel, Files }        from "../../repos/models/ModelStore";
import { IModel }                   from "../../repos/models/Mongo/ModelSchema";

export class ModelsController{

    private modelRepo       : IModelRepo;
    private tempDirPath     : string;

    constructor(modelRepo : IModelRepo, tempDir : string){
        this.modelRepo = modelRepo;
        this.tempDirPath = tempDir;
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
            const tarred = await tarDirectory(this.tempDirPath, name, staged.dirPath);
            return tarred;
        }else{
            return {status: staged.status, path: null};
        }
    }

    public async handleDownloadCleanup(modelName : string) : Promise<void>{
        await deleteFile(this.tempDirPath.concat(modelName, '.tar'));
    }

    public async createModel(req : express.Request) : Promise<Status>{
        const stored = await storeModel(req);
        if(stored !== Status.SUCCESS){
            return stored;
        }

        const requestCheck = this.checkCreateRequest(req);
        if(requestCheck !== Status.SUCCESS){
            return requestCheck;
        }
        const files : Files = req.files as Files;


        // TODO have this take in authentication for creator when that is added -RG
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

    public async deleteModel(name : string) : Promise<Status>{
        const deleted = await this.modelRepo.deleteModel(name);
        return deleted;
    }

    // TODO check that model doesn't alread exist
    private checkCreateRequest(req : express.Request) : Status {
        const required = (req.body.modelname && req.body.description && req.body.publish);
        if(!required){
            return Status.BAD_REQUEST;
        }
        const exists = this.modelRepo.getModelInfo(req.body.modelname);
        if(exists){
            return Status.CONFLICT;
        }
        return Status.SUCCESS;
    }
}