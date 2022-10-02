/**
 * @module Controller.Interfaces
 */

import { FuncResult, Nullable } from '../../../types/typeDefs';
import { SimConfig } from '../../../types/simconfig';

export interface IConfigManager {
  getConfig(id : string) : Nullable<SimConfig>;
  getConfigs() : SimConfig[];
  addConfig(simConfig : Partial<SimConfig>) : FuncResult;
  updateConfig(configID : string, simConfig : Partial<SimConfig>) : FuncResult;
  removeConfig(configID : string) : FuncResult;
}