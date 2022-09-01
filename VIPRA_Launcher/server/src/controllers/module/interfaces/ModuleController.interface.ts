/**
 * @module Controller.Interfaces
 */

import { FuncResult } from '../../../types/typeDefs';
import { Module, ModuleInfo, ModulesFile, ModuleType } from '../../../types/module';
import { FileBuffers } from '../../../util/FileStore';


export interface IModuleController {
  getModules() : ModulesFile;
  allModulesInfo() : { [type: string] : ModuleInfo[] };
  getModulesofType(type : ModuleType) : Module[];
  installModule(moduleInfo : ModuleInfo, fileBuffers : FileBuffers) : Promise<FuncResult>;
  removeModule(id : string) : FuncResult;
  checkModule(id : string) : FuncResult;
  writeModulesFile() : void;
}