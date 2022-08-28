/**
 * @module SimConfig
 */

import { ModuleType } from './module';
import { Nullable } from './typeDefs';

interface SimConfig {
  id          : string;
  name        : string;
  description : string;
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
    if (simConfig.moduleIDs) {
      return (simConfig.moduleIDs[value as ModuleType] !== undefined && simConfig.moduleIDs[value as ModuleType] !== null && simConfig.moduleIDs[value as ModuleType] !== '');
    } else {
      return false;
    }
  });

  if (simConfig.id && simConfig.name && simConfig.description && simConfig.moduleIDs && modulesMet) {

    return Object.assign(simConfig, {
      id,
      name: simConfig.name,
      description: simConfig.description,
      moduleIDs: simConfig.moduleIDs,
    });
  } else {
    return null;
  }
};

export {
  complete,
  SimConfig,
};
