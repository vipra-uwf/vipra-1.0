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

    public connect(dbURI: string, stagingDir : string): void {
        this.dbConn = mongoose.createConnection(dbURI);
        this.mModel = this.dbConn.model('Model', ModelSchema);
        this.stagingDir = stagingDir;
        makeDir(stagingDir);
    }

    public async getOptions(): Promise<ModelMeta[]> {
        const models = await this.mModel.find({publish:true});
        return models.map((model : IModel) =>{
            return {
                name : model.name,
                description: model.description
            };
        });
    }

    public async createModel(model : IModel): Promise<Status> {
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

    public async deleteModel(name: string): Promise<Status> {
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

    public async updateModelSource(name : string, source : string): Promise<Status> {
        const updated = await this.mModel.updateOne({name}, {source});

        if(updated.modifiedCount === 1){
            return Status.SUCCESS;
        }else{
            return Status.NOT_FOUND;
        }
    }

    public async updateModelHeader(name : string, header: string): Promise<Status> {
        const updated = await this.mModel.updateOne({name}, {header});

        if(updated.modifiedCount === 1){
            return Status.SUCCESS;
        }else{
            return Status.NOT_FOUND;
        }
    }

    public async stageModel(name: string): Promise<{ status: Status, dirPath: string}> {
        const model = await this.mModel.findOne({name});
        if(model){

            if(!model.source && !model.header){
                return {
                    status: Status.NO_CONTENT,
                    dirPath: null
                };
            }

            const dirPath : string = this.stagingDir.concat('/', name, '/');
            makeDir(dirPath);

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
                dirPath
            };
        }else{
            return {
                status: Status.NOT_FOUND,
                dirPath: null
            };
        }
    }

    public async getModelInfo(name: string): Promise<{status: Status, modelMeta: ModelMeta}> {
        const model = await this.mModel.findOne({name});
        if(model){
            return {
                status: Status.SUCCESS,
                modelMeta: {
                    name,
                    description: model.description
                }
            };
        }else{
            return {
                status: Status.NOT_FOUND,
                modelMeta: null
            };
        }
    }
}