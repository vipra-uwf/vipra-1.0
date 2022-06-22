import mongoose from "mongoose";


import { MongoErrToStatus }                 from "../../../util/ErrorHandling";
import { Module, ModuleMeta, ModuleType, toString } from "../../../data_models/Module";
import { Status }                           from "../../../data_models/Status";
import { IModuleRepo }                      from "../ModuleRepo.interface";
import { ModuleSchema }                     from "./ModuleSchema";
import { makeDir, writeFile }               from "../../../util/FileHandling/FileOperations";
import { Logger }                           from "../../../logging/Logging";

export class ModuleRepo implements IModuleRepo{

    private dbConn : mongoose.Connection;
    private mModel : mongoose.Model<Module>;
    private stagingDir : string;

    public connect(dbURI: string, stagingDir : string): void {
        this.dbConn = mongoose.createConnection(dbURI);
        this.mModel = this.dbConn.model('Model', ModuleSchema);
        this.stagingDir = stagingDir;
        makeDir(stagingDir);
    }

    // TODO make get options for different types -RG

    public async getOptions(type : ModuleType): Promise<ModuleMeta[]> {
        const modules = await this.mModel.find({type: type.toString(), publish:true});
        return modules.map((module : Module) =>{
            return {
                name : module.name,
                description: module.description,
                type : module.type
            };
        });
    }

    public async createModule(module : Module): Promise<Status> {
        const created = await this.mModel.create(module)
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

    public async deleteModule(type : ModuleType, name: string): Promise<Status> {
        const deleted = await this.mModel.deleteOne({type, name})
        .catch((error)=>{
            Logger.error(`Error in deleteModule: ${error}`);
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
                Logger.error(`Unhandled Result in deleteModule: ${deleted.deletedCount}`);
                return Status.INTERNAL_ERROR;
        }
    }

    public async updateModuleSource(name : string, source : string): Promise<Status> {
        const updated = await this.mModel.updateOne({name}, {source});

        if(updated.modifiedCount === 1){
            return Status.SUCCESS;
        }else{
            return Status.NOT_FOUND;
        }
    }

    public async updateModuleHeader(name : string, header: string): Promise<Status> {
        const updated = await this.mModel.updateOne({name}, {header});

        if(updated.modifiedCount === 1){
            return Status.SUCCESS;
        }else{
            return Status.NOT_FOUND;
        }
    }

    public async stageModule(type : ModuleType, name: string): Promise<{ status: Status, dirPath: string}> {
        const module = await this.mModel.findOne({type, name});
        if(module){

            if(!module.source && !module.header){
                return {
                    status: Status.NO_CONTENT,
                    dirPath: null
                };
            }

            const dirPath : string = this.stagingDir.concat('/', name, '/');
            makeDir(dirPath);

            if(module.source){
                writeFile(dirPath, name.concat('.cpp'), module.source);
            }
            if(module.header){
                writeFile(dirPath, name.concat('.hpp'), module.header);
            }
            const meta : ModuleMeta = module;
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

    public async getModuleInfo(type : ModuleType, name: string): Promise<{status: Status, moduleMeta: ModuleMeta}> {
        const module = await this.mModel.findOne({type, name});
        if(module){
            return {
                status: Status.SUCCESS,
                moduleMeta: {
                    name,
                    description: module.description,
                    type: module.type
                }
            };
        }else{
            return {
                status: Status.NOT_FOUND,
                moduleMeta: null
            };
        }
    }
}