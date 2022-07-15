import crypto from 'crypto';

import { config } from '../../configuration/config';
import { addModule, configIsSame, hasAllTypes, SimConfig, SimConfigIDs } from "../../data_models/simconfig";
import { Status } from "../../data_models/Status.e";
import { Logger } from '../../logging/Logging';
import { makeDir, writeFile } from '../../util/FileOperations';
import { Module, ModulesFile } from '../../data_models/module';
import { readModules } from '../module/moduleLoading';

export class ConfigManager{

    private         configs         : Map<string, SimConfig>;

    constructor(){
        this.configs = new Map();
    }

    public getConfigs() : SimConfig[]{
        return Array.from<SimConfig>(this.configs.values());
    }

    // eslint-disable-next-line @typescript-eslint/require-await
    public async createConfig(name : string, description : string, simConfigIds : SimConfigIDs) : Promise<{status: Status; config : SimConfig}>{
        if(!hasAllTypes(simConfigIds)){
            return {
                status: Status.BAD_REQUEST,
                config: null
            };
        }

        const duplicate : SimConfig = this.getDuplicate(simConfigIds);
        if(duplicate){
            return {
                status: Status.CONFLICT,
                config: duplicate
            };
        }

        let configID : string = crypto.randomUUID();
        while(this.configs.has(configID)){
            configID = crypto.randomUUID();
        }

        const simConfig = this.makeSimConfig(configID, name, description, simConfigIds);
        if(!simConfig){
            return {
                status: Status.INTERNAL_ERROR,
                config: null
            };
        }

        simConfig.id = configID;
        this.configs.set(configID, simConfig);

        this.setupConfig(simConfig);

        return {
            status: Status.CREATED,
            config: simConfig
        };
    }

    public removeConfig(id : string) : Status{
        if(!this.configs.has(id)){
            return Status.NOT_FOUND;
        }
        this.configs.delete(id);
        return Status.SUCCESS;
    }

    public getDuplicate(simconfig : SimConfigIDs) : SimConfig{
        let ret : SimConfig;
        this.configs.forEach((conf)=>{
            if(configIsSame(simconfig, conf)){
                ret = conf;
                return;
            }
        });
        return ret;
    }

    private makeSimConfig(id : string, name : string, description : string, simConfigIds : SimConfigIDs) : SimConfig {
        const simConfig : SimConfig = {
            id,
            name,
            description
        };

        const available : ModulesFile = readModules();
        if(!available){
            return null;
        }

        Object.values(simConfigIds).forEach((i : {id: string})=>{
            const module = available.getModule(i.id);
            if(!module){
                return null;
            }
            addModule(simConfig, module);
        });

        return simConfig;
    }

    private setupConfig(simconfig : SimConfig) : void {
        const configDir : string = `${config.vipra.simsDir}/${simconfig.id}`;
        makeDir(configDir);
        let configFile = "{";
        configFile += Object.entries(simconfig).map((value : [string, Module]) => {
            let ret = `"${value[0]}":`;
            if(value[0] !== "name" && value[0] !== "id" && value[0] !== "description"){
                ret += `{"id":"${value[1].id}"}`;
            }else{
                ret += `"${simconfig[value[0]]}"`;
            }
            return ret;
        });
        configFile += '}';
        writeFile(`${configDir}/sim.config`, configFile);
    }
}