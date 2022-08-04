import crypto from 'crypto';
import path from 'path';

import { config } from '../../configuration/config';
import { addModule, configIsSame, hasAllTypes, SimConfig, SimConfigIDs } from "../../data_models/simconfig";
import { Status } from "../../data_models/Status.e";
import { Logger } from '../../logging/Logging';
import { forAllFilesThatMatchDo, makeDir, readJsonFile, writeFile } from '../../util/FileOperations';
import { Module, ModulesFile, ModuleType } from '../../data_models/module';
import { readModules } from '../module/moduleLoading';
import { ParamSet } from '../../data_models/simparam';

export class ConfigManager{

    private configs : Map<string, SimConfig>;

    constructor(){
        this.configs = new Map();
    }

    public getParams(configID : string) : {type : string, params : ParamSet}[] {
        if(this.configs.has(configID)){
            const config = this.configs.get(configID);
            let ret : {type : string, params : ParamSet}[] = [];
            Object.values(ModuleType).forEach((key)=>{
                ret.push({
                    type: key as string,
                    params: config[key].params
                });
            });
            return ret;
        }else{
            return null;
        }
    }

    public getConfigs() : SimConfig[]{
        return Array.from<SimConfig>(this.configs.values());
    }

    // eslint-disable-next-line @typescript-eslint/require-await
    public async createConfig(simConfigIds : SimConfigIDs) : Promise<{status: Status; config : SimConfig}>{
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

        const simConfig = this.makeSimConfig(configID, simConfigIds);
        if(!simConfig){
            return {
                status: Status.BAD_REQUEST,
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

    private makeSimConfig(id : string, simConfigIds : SimConfigIDs) : SimConfig {
        const simConfig : SimConfig = {
            id,
            name: simConfigIds.name,
            description: simConfigIds.description
        };

        const available : ModulesFile = readModules();
        if(!available){
            return null;
        }

        let ok : boolean = true;
        Object.values(simConfigIds).forEach((i : {id: string})=>{
            if(i.id){
                const module = available.getModule(i.id);
                if(!module){
                    ok = false;
                }
                addModule(simConfig, module);
            }
        });
        if(ok){
            return simConfig;
        }else{
            return null;
        }
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

    public loadConfigs() {
        forAllFilesThatMatchDo(/sim\.config/, config.vipra.simsDir, (filePath : string)=>{
            const simconfigIDs = readJsonFile<SimConfigIDs>(filePath , {error:false});
            const id = path.basename(path.dirname(filePath));
            const simconfig = this.makeSimConfig(id, simconfigIDs);
            if(simconfig){
                Logger.info(`Found Simulation Configuration at: ${filePath}`);
                this.configs.set(id, simconfig);
            }
        });
        Logger.info(`Finished Loading Simulation Configurations`);
    }
}