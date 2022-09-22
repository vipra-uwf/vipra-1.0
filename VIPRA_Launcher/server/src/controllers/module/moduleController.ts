/**
 * @module Controllers
 */

import path                                                                                               from 'path';

import { FileBuffers }                                                                                    from '../../util/FileStore';
import { FuncResult, Nullable }                                                                           from '../../types/typeDefs';
import { Status }                                                                                         from '../../types/Status';
import { config }                                                                                         from '../../configuration/config';
import { getModule, makeModule, Module, ModuleInfo, ModulesFile, ModuleType, removeModule, toModuleInfo } from '../../types/module';

import { inject, singleton }                                                                              from 'tsyringe';
import { IFilesController }                                                                               from '../files/interfaces/FilesController.interface';
import { ISimBuilder }                                                                                    from '../simulation/interfaces/SimBuilder.interface';
import { IModuleController }                                                                              from './interfaces/ModuleController.interface';
import { Logger }                                                                                         from '../../logging/Logging';

/**
 * @description Handles keeping track of modules for the simulation
 */
@singleton()
export class ModuleController implements IModuleController {

  private fc                  : IFilesController;

  private modules             : ModulesFile;

  private simBuilder          : ISimBuilder;

  constructor(@inject('SimBuilder') simBuilder : ISimBuilder, @inject('FilesController') fileController : IFilesController) {
    this.simBuilder = simBuilder;
    this.fc = fileController;
    this.loadModules();
    this.writeModulesFile();
  }


  /**
   * @description Checks the module is installed and ready to use
   * @param  {string} id - id of module to check
   */
  public checkModule(id: string): FuncResult {
    const module = getModule(id, this.modules);
    if (module) {
      if (module.compiled) {
        return { status: Status.SUCCESS, message: null };
      } else {
        return { status: Status.INTERNAL_ERROR, message: 'Not Compiled' };
      }
    } else {
      return { status: Status.NOT_FOUND, message: null };
    }
  }

  /**
   * @description Returns the module with the given ID, null if it doesn't exist
   * @param  {string} id - id of module to find
   */
  public getModule(id: string): Nullable<Module> {
    return getModule(id, this.modules);
  }

  /**
   * @description Returns all of the currently installed modules
   */
  public getModules() : ModulesFile {
    return this.modules;
  }

  /**
   * @description Returns all installed modules without their respective paths
   */
  public allModulesInfo() :{ [type: string] : ModuleInfo[] } {
    const moduleInfo : { [type: string] : ModuleInfo[] } = { 'pedestrian_dynamics_model':[], 'goals':[], 'output_data_writer':[], 'input_data_loader':[], 'simulation_output_handler':[], 'pedestrian_set':[], 'obstacle_set':[], 'entity_set_factory':[], 'human_behavior_model':[], 'configuration_reader':[], 'clock':[], 'data':[], 'simulation': [] };
    Object.keys(this.modules).forEach((type)=>{
      Object.values(this.modules[type as ModuleType]).forEach((module)=>{
        moduleInfo[type].push(toModuleInfo(module));
      });
    });
    return moduleInfo;
  }

  /**
   * @description Returns all of the installed modules of a given type
   *
   * @param  {ModuleType} type - required type of modules
   */
  public getModulesofType(type : ModuleType) : Module[] {
    const test = this.modules[type];
    return test;
  }

  /**
   * @description Installs a module that has been uploaded through {@link FileStore.storeModule}
   *
   * @param  {ModuleInfo} moduleInfo - information about module to be installed
   * @param  {FileBuffers} fileBuffers - file buffers of the module source files
   */
  public async installModule(moduleInfo : ModuleInfo, fileBuffers : FileBuffers) : Promise<FuncResult> {

    if (this.checkDuplicate(moduleInfo)) {
      return { status: Status.CONFLICT, message: `Duplicate Module ID: ${moduleInfo.id}` };
    }

    const moduleDir = `${config.vipra.vipraDir}/${moduleInfo.id}`;
    this.fc.makeDir(moduleDir);
    fileBuffers.forEach((file)=>{this.fc.writeFileFromBuffer(`${moduleDir}/${file.name}`, file.buffer);});

    const module : Module = makeModule(moduleDir, moduleInfo);
    this.addModule(module);

    return this.simBuilder.addedModule(module);
  }

  /**
   * @description Removes the module with id id
   *
   * @note turned off require-await as this will require await later -RG
   *
   * @param  {string} id - ID of module to remove
   */
  public removeModule(id : string) : FuncResult {
    const module = removeModule(id, this.modules);
    if (module) {
      this.writeModulesFile();
      this.fc.deleteDir(module.dirPath, false);
      this.fc.deleteFile(`${config.vipra.vipraDir}/build/${module.id}.o`);
      return this.simBuilder.removedModule(module);
    } else {
      return { status: Status.NOT_FOUND, message: 'Unable to find module' };
    }
  }

  /**
   * @description Checks if a module has a duplicate already installed
   *
   * @param  {ModuleInfo} module - module to check for duplicate of
   */
  private checkDuplicate(module : ModuleInfo) : boolean {
    const modules = this.modules[module.type];
    if (modules) {
      return modules.find((mod)=>{return mod.id === module.id;}) !== undefined;
    }
    return false;
  }

  /**
   * @description Adds module to options, and updates the modules file
   *
   * @param  {Module} module - the module to be added
   */
  private addModule(module : Module) : void {
    this.modules[module.type].push(module);
    this.writeModulesFile();
  }

  /**
   * @description Writes the currently installed modules to the modulesFile path in config.module
   *
   * @note The modules file needs to be written out for VIPRA as generate_main consumes it -RG
   */
  public writeModulesFile() : void {
    this.fc.writeFile(config.module.modulesFile, JSON.stringify(this.modules));
  }

  /**
   * @description Loads All modules in config.vipra.vipraDir & this.secondaryModuleDir
   */
  private loadModules() : void {
    /**
     * @description Loads a module from a module file
     * @param {string} filePath - path of module file
     */
    const loadFunc = (filePath: string) : void => {
      const moduleinfo : Nullable<ModuleInfo> = this.fc.readJsonFile<ModuleInfo>(filePath, { error: true });
      if (moduleinfo) {
        const module = makeModule(path.dirname(filePath), moduleinfo);
        Logger.info(`Found Module: ${module.name}:${module.id} ${module.type}`);
        this.modules[module.type].push(module);
      }
    };

    this.modules = {
      input_data_loader: [],
      human_behavior_model: [],
      output_data_writer: [],
      simulation_output_handler: [],
      pedestrian_set: [],
      obstacle_set: [],
      goals: [],
      pedestrian_dynamics_model: [],
      configuration_reader: [],
      clock: [],
      simulation: [],
    };
    this.fc.forAllFilesThatMatchDo(/.*\.mm/, config.module.modulesDir, loadFunc);
    this.fc.forAllFilesThatMatchDo(/.*\.mm/, config.vipra.vipraDir, loadFunc);
  }
}