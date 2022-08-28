/**
 * @module Controller.Interfaces
 */

import { FuncResult, Protect } from '../../../types/typeDefs';
import { Module, ModuleInfo, ModulesFile, ModuleType } from '../../../types/module';
import { FileBuffers } from '../../../util/FileStore';


export interface IModuleController {
  getModules() : Protect<ModulesFile>;
  allModulesInfo() : { [type: string] : ModuleInfo[] };
  getModulesofType(type : ModuleType) : Module[];
  installModule(moduleInfo : ModuleInfo, fileBuffers : FileBuffers) : Promise<FuncResult>;
  removeModule(id : string) : FuncResult;
  checkModule(id : string) : FuncResult;
}