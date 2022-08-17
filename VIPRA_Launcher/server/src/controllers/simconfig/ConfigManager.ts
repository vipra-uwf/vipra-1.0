/**
 * @module ConfigManager
 */

import { ParamSet } from "../../types/simparam";
import { Nullable } from "../../types/typeDefs";
import { injectable } from "tsyringe";

import { IConfigManager } from "./interfaces/ConfigManager.interface";



// TODO when creating a new sim config, create new service for ChainBuilder -RG

/**
 * @description Handles creation and tracking of simulation configurations
 */
@injectable()
export class ConfigManager implements IConfigManager{

    /**
     * @description temp
     * @param  {string} configID - aewrg
     * @returns ParamSet
     */
    public getParams(configID : string) : Nullable<{type : string; params : ParamSet}[]>{
        return null;
    }
}