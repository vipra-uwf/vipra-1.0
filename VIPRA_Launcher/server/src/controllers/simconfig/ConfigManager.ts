import crypto from 'crypto';

import { SimConfig } from "../../data_models/simconfig";
import { Status } from "../../data_models/Status.e";


export class ConfigManager{

    private static  instance : ConfigManager;
    private         configs         : Map<string, SimConfig>;

    private constructor(){
        this.configs = new Map();
    }

    public static getInstance() : ConfigManager {
        if(ConfigManager.instance){
            return ConfigManager.instance;
        }else{
            return new ConfigManager();
        }
    }

    public getConfigs() : SimConfig[]{
        return Array.from<SimConfig>(this.configs.values());
    }

    public createConfig(config : SimConfig) : Status{
        const correct : boolean = this.checkConfig(config);
        if(!correct){
            return Status.BAD_REQUEST;
        }

        const duplicate : boolean = this.checkDuplicate(config);

        let configID : string;
        while(this.configs.has(configID)){
            configID = crypto.randomUUID();
        }
        config.id = configID;
        this.configs.set(configID, config);

        return Status.CREATED;
    }

    public removeConfig(id : string) : Status{
        if(!this.configs.has(id)){
            return Status.NOT_FOUND;
        }
        this.configs.delete(id);
        return Status.SUCCESS;
    }

    private checkConfig(config : SimConfig) : boolean{
        const ok : boolean = (
            "description" in config &&
            "entity_set_factor" in config &&
            "goals" in config &&
            "human_behavior_model" in config &&
            "input_data_loader" in config &&
            "name" in config &&
            "obstacle_set" in config &&
            "output_data_writer" in config &&
            "pedestrian_dynamics_model" in config &&
            "pedestrian_set" in config &&
            "simulation_output_handler" in config
        );

        return ok;
    }

    private checkDuplicate(config : SimConfig) : boolean {
        return false;
    }
}