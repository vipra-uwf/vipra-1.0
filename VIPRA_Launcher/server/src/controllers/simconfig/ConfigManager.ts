import crypto from 'crypto';
import { compileConfig } from '../../util/Processes';

import { SimConfig } from "../../data_models/simconfig";
import { Status } from "../../data_models/Status.e";

export class ConfigManager{

    private static  instance        : ConfigManager;
    private         configs         : Map<string, SimConfig>;

    constructor(){
        this.configs = new Map();
    }

    public getConfigs() : SimConfig[]{
        return Array.from<SimConfig>(this.configs.values());
    }

    // TODO NEXT change this to accept a list of ids for modules
    //      get available modules from modulemanager, compare -RG

    public async createConfig(simconfig : SimConfig) : Promise<{status: Status; config : SimConfig}>{
        const correct : boolean = this.checkConfig(simconfig);
        if(!correct){
            return {
                status: Status.BAD_REQUEST,
                config: null
            };
        }

        const duplicate : SimConfig = this.getDuplicate(simconfig);
        if(duplicate){
            return {
                status: Status.CONFLICT,
                config: duplicate
            };
        }

        let configID : string;
        while(this.configs.has(configID)){
            configID = crypto.randomUUID();
        }

        const compiled = await compileConfig(simconfig);
        if(compiled !== Status.SUCCESS){
            return {
                status: Status.INTERNAL_ERROR,
                config: null
            };
        }
        simconfig.id = configID;
        this.configs.set(configID, simconfig);

        return {
            status: Status.CREATED,
            config: simconfig
        };
    }

    public removeConfig(id : string) : Status{
        if(!this.configs.has(id)){
            return Status.NOT_FOUND;
        }
        this.configs.delete(id);
        return Status.SUCCESS;
    }

    public getDuplicate(config : SimConfig) : SimConfig{
        let ret : SimConfig;
        this.configs.forEach((conf)=>{
            if(this.isSame(config, conf)){
                ret = conf;
                return;
            }
        });
        return ret;
    }

    private checkConfig(config : SimConfig) : boolean{
        const ok : boolean = (
            "description_id" in config &&
            "entity_set_factor_id" in config &&
            "goals_id" in config &&
            "human_behavior_model_id" in config &&
            "input_data_loader_id" in config &&
            "name_id" in config &&
            "obstacle_set_id" in config &&
            "output_data_writer_id" in config &&
            "pedestrian_dynamics_model_id" in config &&
            "pedestrian_set_id" in config &&
            "simulation_output_handler_id" in config
        );

        return ok;
    }

    private isSame(conf1 : SimConfig, conf2 : SimConfig) : boolean{
        return(
            conf1.entity_set_factory_id         === conf2.entity_set_factory_id &&
            conf1.goals_id                      === conf2.goals_id &&
            conf1.output_data_writer_id         === conf2.output_data_writer_id &&
            conf1.simulation_output_handler_id  === conf2.simulation_output_handler_id &&
            conf1.pedestrian_dynamics_model_id  === conf2.pedestrian_dynamics_model_id &&
            conf1.obstacle_set_id               === conf2.obstacle_set_id &&
            conf1.pedestrian_set_id             === conf2.pedestrian_set_id &&
            conf1.human_behavior_model_id       === conf2.human_behavior_model_id &&
            conf1.input_data_loader_id          === conf2.input_data_loader_id
        );
    }
}