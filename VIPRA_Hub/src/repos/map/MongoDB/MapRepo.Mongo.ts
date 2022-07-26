import mongoose from "mongoose";

import { Status } from "../../../data_models/Status";
import { Map } from "../../../data_models/Map";
import { IMapRepo } from "../MapRepo.interface";
import { MapSchema } from "./MapSchema";
import { MongoErrToStatus } from "../../../util/ErrorHandling";
import { Logger } from "../../../logging/Logging";


export class MapRepo implements IMapRepo{

    private dbConn: mongoose.Connection;
    private bModel: mongoose.Model<Map>;

    connect(dbURI: string): Status{
        this.dbConn = mongoose.createConnection(dbURI);
        this.bModel = this.dbConn.model('Map', MapSchema);
        if(!this.isConnected){
            Logger.error(`MapRepo Unable To Connect`);
            return Status.INTERNAL_ERROR;
        }
        return Status.SUCCESS;
    }

    isConnected(): boolean {
        return this.dbConn.readyState === mongoose.ConnectionStates.connected;
    }

    // TODO fix if no maps present -RG
    async getAll(): Promise<Map[]>{
        const maps = this.bModel.find();
        return (await maps).map((map)=>{
            const m : Map = map;
            return m;
        });
    }

    async getMap(mapName: string): Promise<{map: Map; status: Status}>{
        let map : Map = await this.bModel.findOne({name: mapName});
        if(!map){
            return {
                map: null,
                status: Status.NOT_FOUND
            };
        }

        map = {
            name: map.name,
            content: map.content,
            description: map.description,
            creator: map.creator,
            publish: map.publish
        };

        return{
            map,
            status: Status.SUCCESS
        };
    }

    async createMap(map: Map): Promise<Status>{
        const created = await this.bModel.create(map)
        .catch((error)=>{
            return MongoErrToStatus(error);
        });

        if(created === Status.CONFLICT){
            return Status.CONFLICT;
        }

        if(created){
            return Status.SUCCESS;
        }else{
            return Status.INTERNAL_ERROR;
        }
    }

    async deleteMap(mapName: string): Promise<Status>{
        const deleted = await this.bModel.deleteOne({name: mapName})
        .catch((error)=>{
            Logger.error(`Error in deleteMap: ${error}`);
            return {deletedCount : -1};
        });

        switch(deleted.deletedCount){
            case 0:
                return Status.NOT_FOUND;
            case 1:
                return Status.SUCCESS;
            case -1:
                return Status.INTERNAL_ERROR;
        }
    }

    async updateMap(mapName: string, map: Map): Promise<Status>{
        const updated = await this.bModel.updateOne({name:mapName}, {
            content: map.content,
            description: map.description,
            publish: map.publish,
        });

        switch(updated.modifiedCount){
            case 0:
                return Status.NOT_FOUND;
            case 1:
                return Status.SUCCESS;
        }
    }
}