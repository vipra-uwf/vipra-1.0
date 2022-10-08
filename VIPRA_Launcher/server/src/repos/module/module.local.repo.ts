
import { Status } from '../../types/status';
import { Full, Nullable, OperationResult } from '../../types/typeDefs';
import { Module, ModuleType, ModuleUpload } from '../../types/module/module.types';
import { BaseRepo } from '../base.repo';
import { InstalledModules, ModuleModel, toModule } from './module.model';
import { deleteDir, forAllFilesThatMatchDo, makeDir, readJsonFile, writeFile, writeFileFromBuffer } from '../../util/fileOperations';
import { Config } from '../../configuration/config';
import { File } from '../../controllers/module/filestore';
import path from 'path';
import { Logger } from '../../controllers/logging/logger';


/**
 * @description Module Repo that holds Modules on the local Filesystem
 */
export class LocalModuleRepo implements BaseRepo<ModuleUpload, Module> {
  
  private installedModules : Record<ModuleType, ModuleModel[]>;

  private config : Config;

  constructor(config? : Config) {
    if (config) {
      this.config = config;
    } else {
      throw new Error('Attempt to Create Local Module Repo without a Config');
    }
    this.loadInstalledModules();
  }

  
  /**
   * @description returns all modules in the repo
   */
  public getAll(): Module[] {
    const retVal : Module[] = [];
    for (const key in this.installedModules) {
      const value = this.installedModules[key as keyof InstalledModules];
      retVal.concat(value.map(module=>{
        return toModule(module);
      }));
    }
    return retVal;
  }

  /**
   * @description Returns the Module with id, null if no module with id
   * @param {string} id - id of module to find
   */
  public get(id: string): Nullable<Module> {
    const module = this.findModuleById(id);
    if (module) {
      return toModule(module);
    } else {
      return null;
    }
  }

  /**
   * @description Saves a new module, returns the id of the new resource
   * @param {ModuleUpload} upload - module to add to repo 
   */
  public async create(upload : Full<ModuleUpload>): Promise<OperationResult<Module>> {
    const duplicate : Nullable<Module> = this.get(upload.module.id);
    if (duplicate) {
      return { status: Status.CONFLICT, object: duplicate };
    }

    const module : ModuleModel = { module: upload.module, dirPath: '' };
    module.dirPath = `${this.config.modules.modulesURL}/${module.module.name}`;
    await this.saveModule(module, upload.files.headerFile as File, upload.files.srcFile as File, upload.files.metaFile as File);
    this.installedModules[module.module.type].push(module);
    return { status: Status.CREATED, object: toModule(module) };
  }

  
  /**
   * @description Deletes the module with id
   * @param  {string} id - id of module to delete
   */
  async delete(id: string): Promise<OperationResult<Module>> {
    const module = this.findModuleById(id);
    if (module) {
      const deleted = await deleteDir(module.dirPath, true);
      this.writeModulesFile();
      return { status: deleted, object: toModule(module) };
    } else {
      return { status: Status.NOT_FOUND, object: null };
    }
  }

  
  /**
   * @description Updates a module with the provided data
   * @param  {string} id - id of module to update
   * @param  {Partial<Module>} module - data to update module with
   */
  public async update(id: string, module: Partial<ModuleUpload>): Promise<OperationResult<Module>> {
    const oldModule = this.findModuleById(id);
    if (oldModule) {
      oldModule.module = { ...oldModule.module, ...module.module };
      await this.updateFiles(oldModule, module);
      this.writeModulesFile();
      return { status: Status.SUCCESS, object: toModule(oldModule) };
    } else {
      return { status: Status.NOT_FOUND, object: null };
    }
  }

  /**
   * @description Loads all installed modules
   */
  private loadInstalledModules() : void {
    this.installedModules = {
      pedestrian_dynamics_model: [],
      goals: [],
      output_data_writer: [],
      input_data_loader: [],
      simulation_output_handler: [],
      pedestrian_set: [],
      obstacle_set: [],
      human_behavior_model: [],
      configuration_reader: [],
      clock: [],
      simulation: [],
    };

    for (const dir of [this.config.modules.modulesURL, this.config.vipra.vipraDir]) {
      forAllFilesThatMatchDo(/.*\.mm/, dir, (filePath : string)=>{     
        const module : Nullable<Module> = readJsonFile<Module>(filePath);
        if (module) {
          Logger.info(`Found Module: ${module.name} : ${module.id} AT: ${filePath}`);
          const mm : ModuleModel = {
            module,
            dirPath : path.resolve(path.dirname(filePath)),
          };
          mm.module.compiled = false;
          this.installedModules[module.type].push(mm);
        }
      });
    }

    this.writeModulesFile();
  }

  /**
   * @description Saves the module to a file
   * @param {ModuleModel} module - module to save
   * @param {File} header - header file
   * @param {File} source - source file
   * @param {File} meta - module meta data
   */
  private async saveModule(module : ModuleModel, header : File, source : File, meta : File) : Promise<void> {
    makeDir(module.dirPath);
    const basePath = `${module.dirPath}/${module.module.name}`;
    await Promise.all([writeFileFromBuffer(`${basePath}.hpp`, header.buffer),
      writeFileFromBuffer(`${basePath}.cpp`, source.buffer),
      writeFileFromBuffer(`${basePath}.mm`, meta.buffer)]);
    this.writeModulesFile();
  }

  /**
   * @description finds a module with id
   * @param {string} id - id of module to find
   */
  private findModuleById(id : string) : Nullable<ModuleModel> {
    for (const key in this.installedModules) {
      const value = this.installedModules[key as keyof InstalledModules];
      for (const module of value) {
        if (id == module.module.id) {
          return module;
        }
      }
    }
    return null;
  }

  /**
   * @description Updates the files for a module if they were provided in an update
   * @param {ModuleModel} oldModule - old module object
   * @param {Partial<ModuleUpload>} newModule - new module object
   */
  private async updateFiles(oldModule : ModuleModel, newModule : Partial<ModuleUpload>) : Promise<void> {
    const dir = oldModule.dirPath;
    if (newModule.files?.headerFile) {
      await writeFileFromBuffer(`${dir}/${oldModule.module.name}/${oldModule.module.name}.hpp`, newModule.files.headerFile.buffer);
    }
    if (newModule.files?.srcFile) {
      await writeFileFromBuffer(`${dir}/${oldModule.module.name}/${oldModule.module.name}.cpp`, newModule.files.srcFile.buffer);
    }
  }

  /**
   * @description Saves the installed modules to the modules file, used by the simulation
   */
  private writeModulesFile() : void {
    writeFile(this.config.modules.modulesFilePath, JSON.stringify(this.installedModules));
  }
}