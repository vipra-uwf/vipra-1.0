import mongoose from "mongoose";


import { MongoErrToStatus }         from "../../../util/ErrorHandling";
import { ModelMeta, toString }      from "../../../data_models/ModelMeta";
import { Status }                   from "../../../data_models/Status";
import { IModelRepo }               from "../ModelRepo.interface";
import { IModel, ModelSchema }      from "./ModelSchema";
import { makeDir, writeFile }       from "../../../util/FileHandling/FileOperations";

export class ModelRepo implements IModelRepo{

    private dbConn : mongoose.Connection;
    private mModel : mongoose.Model<IModel>;
    private stagingDir : string;

    connect(dbURI: string, stagingDir : string): void {
        this.dbConn = mongoose.createConnection(dbURI);
        this.mModel = this.dbConn.model('Model', ModelSchema);
        this.stagingDir = stagingDir;
        makeDir(stagingDir);
    }

    getOptions(): Promise<ModelMeta[]> {
        throw new Error("Method not implemented.");
    }

    async createModel(model : IModel): Promise<Status> {
        const created = await this.mModel.create(model)
        .catch((error)=>{
            return MongoErrToStatus(error);
        });
        if(created === Status.CONFLICT){
            return created;
        }
        if(created){
            return Status.CREATED;
        }else{
            return Status.INTERNAL_ERROR;
        }
    }

    async deleteModel(name: string): Promise<Status> {
        const deleted = await this.mModel.deleteOne({name})
        .catch((error)=>{
            console.log(`[ERROR] Error in deleteModel: ${error}`);
            return {deletedCount: -1};
        });

        switch(deleted.deletedCount){
            case 0:
                return Status.NOT_FOUND;
            case 1:
                return Status.SUCCESS;
            case -1:
                return Status.INTERNAL_ERROR;
            default:
                console.log(`[ERROR] Unhandled Result in deleteModel: ${deleted.deletedCount}`);
                return Status.INTERNAL_ERROR;
        }
    }

    async updateModelSource(name : string, source : string): Promise<Status> {
        throw new Error("Method not implemented.");
    }

    async updateModelHeader(name : string, header: string): Promise<Status> {
        throw new Error("Method not implemented.");
    }

    async stageModel(name: string): Promise<{ status: Status, dirPath: string}> {
        const model = await this.mModel.findOne({name});
        if(model){

            if(!model.source && !model.header){
                return {
                    status: Status.NO_CONTENT,
                    dirPath: null
                }
            }

            const dirPath : string = this.stagingDir.concat('/', name, '/');

            if(model.source){
                writeFile(dirPath, name.concat('.cpp'), model.source);
            }
            if(model.header){
                writeFile(dirPath, name.concat('.hpp'), model.header);
            }

            const meta : ModelMeta = model;
            writeFile(dirPath, name.concat('.mm'), toString(meta));

            return {
                status: Status.SUCCESS,
                dirPath: dirPath
            }
        }else{
            return {
                status: Status.NOT_FOUND,
                dirPath: null
            };
        }
    }

    getModelInfo(name: string): Promise<{status: Status, modelMeta: ModelMeta}> {
        throw new Error("Method not implemented.");
    }
}