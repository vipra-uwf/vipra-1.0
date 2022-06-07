import express      from "express";

import { TarFiles } from "../../util/FileHandling/FileOperations";
import { ModelMeta }        from "../../data_models/ModelMeta";
import { Status }           from "../../data_models/Status";
import { IModelRepo }       from "../../repos/models/ModelRepo.interface";

// TODO add file that holds metadata on models
//      update that file when a new model is added -RG

export class ModelsController{

    private models      : Map<string, ModelMeta>;
    private modelRepo   : IModelRepo;
    private zipPath     : string;

    constructor(modelRepo : IModelRepo, zipPath : string){
        this.modelRepo = modelRepo;
        this.zipPath = zipPath;
        this.models = new Map();
    }

    public async getOptions() : Promise<{status: Status, options: ModelMeta[]}>{
        throw new Error("Not Implemented");
    }

    public async getModel(name : string) : Promise<{status: Status, path: string}>{

        if(!this.models.get(name)){
            return {
                status: Status.NOT_FOUND,
                path: null
            };
        }

        const staged = await this.modelRepo.stageModel(name);
        if(staged.status === Status.NOT_FOUND){
            this.models.delete(name);
            return {
                status: Status.NOT_FOUND,
                path: null
            };
        }

        const zipped = await TarFiles(this.zipPath, name, staged.files);
        return zipped;
    }

    public async getModelInfo(name : string) : Promise<{status: Status, modelMeta: ModelMeta}>{
        if(!this.models.get(name)){
            return {
                status: Status.NOT_FOUND,
                modelMeta: null
            };
        }
        return {
            status: Status.SUCCESS,
            modelMeta: this.models.get(name)
        };
    }

    public async createModel(req : express.Request) : Promise<Status>{
        const result = await this.modelRepo.createModel(req);
        if(result.status === Status.SUCCESS){
            this.updateOptions(result.modelMeta);
        }
        return result.status;
    }

    public async updateModel(req : express.Request) : Promise<Status>{
        const result = await this.modelRepo.updateModel(req);

        return result;
    }

    public async deleteModel(name : string) : Promise<Status>{
        const deleted = await this.modelRepo.deleteModel(name);
        if(deleted === Status.SUCCESS){
            this.models.delete(name);
        }
        return deleted;
    }

    private updateOptions(model : ModelMeta){
        this.models.set(model.name, model);
    }
}