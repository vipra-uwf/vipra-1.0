
import { Module } from '../../types/module/module.types';
import { ModuleType } from '../../types/module/module.types';

export interface ModuleModel {
  module  : Module;
  dirPath : string;
}

export type InstalledModules = Record<ModuleType, ModuleModel[]>;

/**
 * @description Turns a ModuleModel into a regular Module
 * @param {ModuleModel} module - module to convert
 */
export const toModule = (module : ModuleModel) : Module => {
  return {
    id: module.module.id,
    name : module.module.name,
    description: module.module.description,
    params: module.module.params,
    type: module.module.type,
  };
};