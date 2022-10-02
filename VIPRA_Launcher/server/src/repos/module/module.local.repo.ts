
import { Status } from '../../types/status';
import { Full, Nullable, OperationResult } from '../../types/typeDefs';
import { Module, ModuleUpload } from '../../types/module/module.types';
import { BaseRepo } from '../base.repo';
import { InstalledModules, ModuleModel, toModule } from './module.model';
import { deleteDir, forAllFilesThatMatchDo, readJsonFile, writeFileFromBuffer } from '../../util/fileOperations';
import { Config } from '../../configuration/config';
import { File } from '../../controllers/module/filestore';
import path from 'path';


/**
 * @description Module Repo that holds Modules on the local Filesystem
 */
export class LocalModuleRepo implements BaseRepo<ModuleUpload, Module> {
  
  private installedModules : InstalledModules;

  private moduleDir : string;

  constructor(config : Config) {
    this.setConfiguration(config);
    this.loadInstalledModules();
  }

  
  /**
   * @description returns all modules in the repo
   */
  // eslint-disable-next-line @typescript-eslint/require-await
  async getAll(): Promise<Module[]> {
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
  // eslint-disable-next-line @typescript-eslint/require-await
  public async get(id: string): Promise<Nullable<Module>> {
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
    const module : ModuleModel = { module: upload.module, dirPath: '' };
    module.dirPath = `${this.moduleDir}/${module.module.name}`;
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
      return { status: await deleteDir(module.dirPath, true), object: toModule(module) };
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
      return { status: Status.SUCCESS, object: toModule(oldModule) };
    } else {
      return { status: Status.NOT_FOUND, object: null };
    }
  }

  /**
   * @note This is here for possible extention in the future, and has no use atm
   * @description - Stages a module and returns the directory it resides in
   * @param {string} id - id of module to stage
   */
  // eslint-disable-next-line @typescript-eslint/require-await
  public async stage(id: string): Promise<OperationResult<string>> {
    for (const key in this.installedModules) {
      const value = this.installedModules[key as keyof InstalledModules];
      for (const module of value) {
        if (id == module.module.id) {
          return { status: Status.SUCCESS, object: module.dirPath };
        }
      }
    }
    return { status: Status.NOT_FOUND, object: null };
  }

  /**
   * @description Loads all installed modules
   */
  private loadInstalledModules() : void {
    forAllFilesThatMatchDo(/\*.mm/, this.moduleDir, (filePath : string)=>{
      const module : Nullable<Module> = readJsonFile<Module>(filePath);
      if (module) {
        const mm : ModuleModel = {
          module,
          dirPath : path.dirname(filePath),
        };
        this.installedModules[module.type].push(mm);
      }
    });
  }

  /**
   * @description Saves the module to a file
   * @param {ModuleModel} module - module to save
   * @param {File} header - header file
   * @param {File} source - source file
   * @param {File} meta - module meta data
   */
  private async saveModule(module : ModuleModel, header : File, source : File, meta : File) : Promise<void> {
    const basePath = `${module.dirPath}/${module.module.name}`;
    await Promise.all([writeFileFromBuffer(`${basePath}.hpp`, header.buffer),
      writeFileFromBuffer(`${basePath}.cpp`, source.buffer),
      writeFileFromBuffer(`${basePath}.mm`, meta.buffer)]);
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
   * @description Takes in a config and sets the appropriate properties
   * @param {Config} config - configuration settings
   */
  private setConfiguration(config : Config) : void {
    this.moduleDir = config.modules.modulesURL;
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
}