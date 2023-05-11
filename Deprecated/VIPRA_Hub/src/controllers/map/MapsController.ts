import { IMapRepo } from "../../repos/map/MapRepo.interface";
import { Map } from "../../data_models/Map";
import { Status } from "../../data_models/Status";

export class MapsContoller{

    private mapRepo : IMapRepo;

    constructor(mapRepo : IMapRepo){
        this.CheckParams(mapRepo);
        this.mapRepo = mapRepo;
    }

    public async createMap(map : Map) : Promise<Status>{
        const created = await this.mapRepo.createMap(map);
        return created;
    }

    public async deleteMap(name : string) : Promise<Status>{
        const deleted = await this.mapRepo.deleteMap(name);
        return deleted;
    }

    public async getMap(name : string) : Promise<{map: Map; status: Status}>{
        const map = await this.mapRepo.getMap(name);
        return map;
    }

    public async updateMap(mapName: string, map : Map) : Promise<Status>{
        const updated = await this.mapRepo.updateMap(mapName, map);
        return updated;
    }

    public async getOptions() : Promise<{name: string; description: string}[]>{
        const maps = await this.mapRepo.getAll();
        return maps.map((map)=>{
            const m = {
                name: map.name,
                description: map.description
            };
            return m;
        });
    }

    private CheckParams(mapRepo : IMapRepo){
        if(!mapRepo){
            throw new Error('[ERROR] MapsController: MapRepo is Null / Not Defined');
        }
    }
}