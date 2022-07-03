import { Status } from "../../data_models/Status";
import { Map } from "../../data_models/Map";


export interface IMapRepo{
    connect(dbURI: string): Status;
    isConnected(): boolean;
    getAll(): Promise<Map[]>;
    getMap(mapName: string): Promise<{map: Map; status: Status}>;
    createMap(map: Map): Promise<Status>;
    deleteMap(mapName: string): Promise<Status>;
    updateMap(mapName: string, map: Map): Promise<Status>;
}
