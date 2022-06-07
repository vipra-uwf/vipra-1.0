import express from "express";

import { Status } from "../../../data_models/Status";
import { ModelMeta } from "../../../data_models/ModelMeta";
import { IModelRepo } from "../ModelRepo.interface";

import { StoreModel } from "./ModelFileStore";
import { FileExists } from "../../../util/FileHandling/FileOperations";


export class ModelRepo implements IModelRepo{

    private uploadPath : string;

    public connect(dbURI: string): void {
        this.uploadPath = dbURI;
    }

    public async createModel(req : express.Request): Promise<{status: Status, modelMeta: ModelMeta}> {        
        const created = await StoreModel(req);

        return created;
    }
    public async updateModel(req : express.Request): Promise<Status> {
        throw new Error("Method not implemented.");
    }
    public async deleteModel(): Promise<Status> {
        throw new Error("Method not implemented.");
    }

    public async getModel(name: string): Promise<string> {
        throw new Error("Method not implemented.");
    }

    public async getOptions(): Promise<ModelMeta> {
        throw new Error("Method not implemented.");
    }

    public async stageModel(name: string): Promise<{status: Status, files: string[]}> {
        const filePath = this.uploadPath.concat('/', name);
        if(!FileExists(filePath.concat('.hpp'))){
            return {
                status: Status.NOT_FOUND,
                files: null
            };
        }

        return {
            status: Status.SUCCESS,
            files: [
                filePath.concat('.hpp'),
                filePath.concat('.cpp')
            ]
        };
    }

}