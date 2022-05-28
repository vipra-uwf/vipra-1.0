import { Behavior } from "../../../data_models/Behavior";
import { Status } from "../../../data_models/Status";
import { IBehaviorRepo } from "../BehaviorRepo.interface";
import { behaviorScema } from "./BehaviorModel";

import mongoose from "mongoose";
import { MongoErrToStatus } from "./ErrorHandling";

export class BehaviorRepo implements IBehaviorRepo{

    private dbConn: mongoose.Connection;
    private bModel: mongoose.Model<Behavior>;

    constructor(){}

    public connect(dbURI: string) : Status{
        console.log("Connecting");
        this.dbConn = mongoose.createConnection(dbURI);
        this.bModel = this.dbConn.model('Behavior', behaviorScema);
        if(!this.isConnected){
            // TODO provide better error messaging -RG
            return Status.INTERNAL_ERROR;
        }
        console.log("Connected");
        return Status.SUCCESS;
    }

    private isConnected(): boolean{
        return this.dbConn.readyState === mongoose.ConnectionStates.connected;
    }

    public async createBehavior(behavior: Behavior): Promise<Status> {
        const created = await this.bModel.create(behavior)
        .catch((error)=>{
            console.log(error);

            return MongoErrToStatus(error.code);
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
        if(!this.isConnected){
            return Status.INTERNAL_ERROR;
        }

    }

    public async deleteBehavior(behaviorName: string): Promise<Status> {
        const deleted = await this.bModel.deleteOne({name: behaviorName})
        .catch((error)=>{
            console.log(`[ERROR] Error in deleteBehavior: ${error}`);
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
                console.log(`[ERROR] Unhandled Result in deleteBehavior: ${deleted.deletedCount}`);
                return Status.INTERNAL_ERROR;
        }
    }

    public async updateContent(behaviorName: string, content: string): Promise<Status> {
        throw new Error("Method not implemented.");
    }

    public async getAll(): Promise<Behavior[]> {
        throw new Error("Method not implemented.");
    }
    public async getBehavior(behaviorName: string): Promise<Behavior> {
        throw new Error("Method not implemented.");
    }
}