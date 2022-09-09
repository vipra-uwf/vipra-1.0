/**
 * @module SimConfig
 */

import { ModuleType } from './module';
import { Nullable } from './typeDefs';

interface SimConfig {
  id          : string;
  name        : string;
  description : string;
  author      : string;
  email       : string;
  moduleIDs   : Record<ModuleType, string>;
}

/**
 * @description Takes a partial simconfig, makes sure it is correct and returns a full SimConfig. null if incorrect
 * @param  {Partial<SimConfig>} simConfig - partial simconfig to check
 * @param  {string} id - id to give the simconfig
 */
const complete = (id : string, simConfig : Partial<SimConfig>) : Nullable<SimConfig> => {
  simConfig.id = id;
  const modulesMet : boolean = Object.values(ModuleType).every((value)=>{ 
    return (simConfig[value as unknown as keyof SimConfig]);
  });

  if (simConfig.id && simConfig.name && simConfig.description && modulesMet) {
    return simConfig as SimConfig;
  } else {
    return null;
  }
};

export {
  complete,
  SimConfig,
};
