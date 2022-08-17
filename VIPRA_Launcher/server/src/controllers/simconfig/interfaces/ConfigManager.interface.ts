/**
 * @module ConfigManager.Interface
 */

import { Nullable } from "../../../types/typeDefs";
import { ParamSet } from "../../../types/simparam";


export interface IConfigManager{
    getParams(configID : string) : Nullable<{type : string; params : ParamSet}[]>;
}