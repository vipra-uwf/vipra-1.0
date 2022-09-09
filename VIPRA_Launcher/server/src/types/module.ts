/**
 * @module Types
 */

import { CbParameter } from 'typechain';
import { Nullable } from './typeDefs';

export enum ModuleType {
  MODEL                   = 'pedestrian_dynamics_model',
  GOALS                   = 'goals',
  OUTPUT_DATA_WRITER      = 'output_data_writer',
  INPUT_DATA_LOADER       = 'input_data_loader',
  SIM_OUTPUT_HANDLER      = 'simulation_output_handler',
  PEDESTRIAN_SET          = 'pedestrian_set',
  OBSTACLE_SET            = 'obstacle_set',
  ENTITY_SET_FACTORY      = 'entity_set_factory',
  HUMAN_BEHAVIOR_MODEL    = 'human_behavior_model',
  CONFIGURATION_READER    = 'configuration_reader',
  CLOCK                   = 'clock',
  DATA                    = 'data',
  SIMULATION              = 'simulation',
}


export interface ModulesFile {
  input_data_loader : Module[];
  human_behavior_model : Module[];
  output_data_writer : Module[];
  simulation_output_handler : Module[];
  pedestrian_set : Module[];
  obstacle_set : Module[];
  entity_set_factory : Module[];
  goals : Module[];
  pedestrian_dynamics_model : Module[];
  configuration_reader: Module[];
  clock : Module[];
  data : Module[];
  simulation : Module[];
}

/**
 * @description Returns the module with id in modules, null if no module with id
 * @param  {string} id - id of module to search for
 * @param  {ModulesFile} modules - ModulesFile to search in
 */
export const getModule = (id : string, modules : ModulesFile) : Nullable<Module> => {
  for (const key in modules) {
    let ret : Nullable<Module> = null;
    if ({}.hasOwnProperty.call(modules, key)) {
      modules[key as keyof ModulesFile].forEach((module)=>{
        if (module.id === id) {
          ret = module;
        }
      });
    }
    if (ret) {
      return ret;
    }
  }
  return null;
};

/**
 * @description Removes the module with id in modules, returns the removed module, null if no module is found
 * @param  {string} id - id of module to remove
 * @param  {ModulesFile} modules - ModulesFile to remove the module from
 */
export const removeModule = (id : string, modules : ModulesFile) : Nullable<Module> => {
  for (const key in modules) {
    if ({}.hasOwnProperty.call(modules, key)) {
      const index = modules[key as keyof ModulesFile].findIndex((module)=>{
        return module.id === id;
      });
      if (index !== -1) {
        return modules[key as keyof ModulesFile].splice(index, 1)[0];
      }
    }
  }
  return null;
};


export interface Module {
  id          : string;
  name        : string;
  description : string;
  params      : CbParameter[];
  dirPath     : string;
  className   : string;
  type        : ModuleType;
  includePath : string;
  compiled    : boolean;
}

export type ModuleInfo = Omit<Module, 'dirPath' | 'includePath' | 'compiled'>;

/**
 * @description Removes file paths and class information from modules, generally used to send information to clients
 * @note returns a copy of the object, module is not changed
 * @param {Protect<Module>} module - module to get info from
 */
export const toModuleInfo = (module : Module) : ModuleInfo => {
  const info : ModuleInfo = {
    id: module.id,
    name: module.name,
    description: module.description,
    params: module.params,
    className: module.className,
    type: module.type,
  };
  return info;
};

/**
 * @description Takes a ModuleInfo and adds its filepaths
 * @param {string} moduleDir - absolute path to directory holding module files
 * @param {Protect<ModuleInfo>} moduleInfo - ModuleInfo to get a Module from
 */
export const makeModule = (moduleDir : string, moduleInfo : ModuleInfo) : Module =>{
  return {
    id          : moduleInfo.id,
    name        : moduleInfo.name,
    description : moduleInfo.description,
    params      : moduleInfo.params,
    dirPath     : moduleDir,
    className   : moduleInfo.className,
    type        : moduleInfo.type,
    includePath : `${moduleDir}/${moduleInfo.name}.hpp`,
    compiled    : false,
  };
};

/**
 * @description Takes an object and verifies whether it follows the Module interface, Returns the object as Module or null if it isn't a module
 * @param {any} obj - object to check
 */
// eslint-disable-next-line @typescript-eslint/no-explicit-any
export const verifyModule = (obj : any) : Nullable<Module> =>{
  if (obj) {
    if (
      'id' in obj &&
            'name' in obj &&
            'description' in obj &&
            'className' in obj &&
            'type' in obj
    ) {
      // eslint-disable-next-line @typescript-eslint/no-unsafe-argument, @typescript-eslint/no-unsafe-member-access
      if (Object.values(ModuleType).includes(obj.type)) {
        return obj as Module;
      }
    }
  }

  return null;
};