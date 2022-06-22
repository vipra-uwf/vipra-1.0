import { Behavior } from "../../../data_models/Behavior";
import { Status } from "../../../data_models/Status";
import { IBehaviorRepo } from "../BehaviorRepo.interface";
import { BehaviorSchema } from "./BehaviorSchema";

import mongoose from "mongoose";
import { MongoErrToStatus } from "../../../util/ErrorHandling";
import { Logger } from "../../../logging/Logging";
import { loggers } from "winston";

export class BehaviorRepo implements IBehaviorRepo{

    private dbConn: mongoose.Connection;
    private bModel: mongoose.Model<Behavior>;

    public connect(dbURI: string) : Status{
        this.dbConn = mongoose.createConnection(dbURI);
        this.bModel = this.dbConn.model('Behavior', BehaviorSchema);
        if(!this.isConnected){
            return Status.INTERNAL_ERROR;
        }
        return Status.SUCCESS;
    }

    private isConnected(): boolean{
        return this.dbConn.readyState === mongoose.ConnectionStates.connected;
    }

    public async createBehavior(behavior: Behavior): Promise<Status> {
        const created = await this.bModel.create(behavior)
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

    public async updatePublished(behaviorName: string, publish: boolean): Promise<Status> {
        const updated = await this.bModel.updateOne({name:behaviorName}, {publish})
        .catch((error)=>{
            Logger.error(`Error in deleteBehavior: ${error}`);
            return {matchedCount: -1};
        });

        switch(updated.matchedCount){
            case 1:
                return Status.SUCCESS;
            case 0:
                return Status.NOT_FOUND;
            case -1:
                return Status.INTERNAL_ERROR;
            default:
                Logger.error(`Unhandled Result in updatePublished: ${updated}`);
                return Status.INTERNAL_ERROR;
        }
    }

    public async deleteBehavior(behaviorName: string): Promise<Status> {
        const deleted = await this.bModel.deleteOne({name: behaviorName})
        .catch((error)=>{
            Logger.error(`Error in deleteBehavior: ${error}`);
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
                Logger.error(`Unhandled Result in deleteBehavior: ${deleted.deletedCount}`);
                return Status.INTERNAL_ERROR;
        }
    }

    public async updateContent(behaviorName: string, content: string): Promise<Status> {
        const updated = await this.bModel.updateOne({name:behaviorName}, {content})
        .catch((error)=>{
            Logger.error(`Error in deleteBehavior: ${error}`);
            return {matchedCount: -1};
        });

        switch(updated.matchedCount){
            case 1:
                return Status.SUCCESS;
            case 0:
                return Status.NOT_FOUND;
            case -1:
                return Status.INTERNAL_ERROR;
            default:
                Logger.error(`Unhandled Result in updateContent: ${updated}`);
                return Status.INTERNAL_ERROR;
        }
    }

    public async getAll(): Promise<Behavior[]> {
        const result = this.bModel.find();
        return (await result).map((behavior) : Behavior=>{
            const b : Behavior = behavior;
            return b;
        });
    }

    public async getBehavior(behaviorName: string): Promise<{behavior: Behavior, status: Status}> {

        let status : Status = Status.SUCCESS;
        let behavior : Behavior = await this.bModel.findOne({name: behaviorName}).
        catch((error)=>{
            status = MongoErrToStatus(error);
            return null;
        });

        if(!behavior && status === Status.SUCCESS){
            return {behavior: null, status: Status.NOT_FOUND};
        }

        behavior = {
            name: behavior.name,
            content: behavior.content,
            description: behavior.description,
            publish: behavior.publish,
            creator: behavior.creator
        };

        return {
            behavior,
            status
        };
    }
}