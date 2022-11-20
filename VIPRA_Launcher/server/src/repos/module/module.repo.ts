

import { Config } from '../../configuration/config';
import { Module, ModuleType } from '../../types/module/module.types';
import { Full, Nullable } from '../../types/typeDefs';
import { RepoType, UploadType } from '../../types/uploading.types';
import { makeDir, writeFile, writeFileFromBuffer } from '../../util/fileOperations';
import { Files } from '../../util/filestore';
import { BaseLocalRepo } from '../base.local.repo';


/**
 * @description Local Repo for module files
 */
export class ModuleRepo extends BaseLocalRepo<Module> {
  
  private modulesFile : Record<ModuleType, RepoType<Module>[]>;
  
  constructor(typeName : string, config : Config) {
    super(typeName, config);
    this.modulesFile = {
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
      map_loader: [],
      policy_model: [],
    };
  }
  
  /**
   * @description Called after a new Module is created, updates modules file
   * @param {RepoType<Module>} object - module created
   */
  postCreate(object: RepoType<Module>): void {
    this.modulesFile[object.object.type].push(object);
    this.writeModulesFile();
  }

  /**
   * @description Called after a module is updated, updates modules files
   * @param {RepoType<Module>} object - module updated
   */
  postUpdate(object: RepoType<Module>): void {
    // search for module and update
    const index = this.modulesFile[object.object.type].findIndex((value : RepoType<Module>)=>{
      return value.object.id === object.object.id;
    });
    if (index > -1) {
      this.modulesFile[object.object.type][index] = object;
      this.writeModulesFile();
    }
  }

  /**
   * @description Called after a module is found, updates modules file
   * @param {RepoType<Module>} object - module Found
   */
  postFound(object: RepoType<Module>): void {
    this.postCreate(object);
  }

  /**
   * @description Called after a module is deleted, updates modules file
   * @param {Module[]} objects - modules deleted
   */
  postDelete(objects: Module[]): void {
    objects.forEach((module : Module)=>{
      this.modulesFile[module.type] = this.modulesFile[module.type].filter((value)=>{
        return value.object.id !== module.id;
      });
    });
    this.writeModulesFile();
  }


  /**
   * @description Saves module files
   * @param {Full<UploadType<Module>>} object - new module
   */
  async saveFiles(object: Full<UploadType<Module>>): Promise<Nullable<string>> {
    const dirPath = `${this.config.modules.modulesDir}/${object.object.name}`;
    makeDir(dirPath);
    if (object.files.source && object.files.header && object.files.meta) {
      await writeFileFromBuffer(`${dirPath}/${object.object.name}.cpp`, object.files.source[0].buffer as Buffer);
      await writeFileFromBuffer(`${dirPath}/${object.object.name}.hpp`, object.files.header[0].buffer as Buffer);
      await writeFileFromBuffer(`${dirPath}/${object.object.name}.mm`, object.files.meta[0].buffer as Buffer);
    } else {
      return null;
    }

    return dirPath;
  }
  
  /**
   * @description Updates module files
   * @param {RepoType<Module>} object - updated object
   * @param {Files} files - updated files
   */
  async updateFiles(object: RepoType<Module>, files: Files): Promise<Nullable<string>> {
    const dirPath = `${this.config.modules.modulesDir}/${object.object.name}`;
    if (files) {
      if (files.source) {
        await writeFileFromBuffer(`${dirPath}/${object.object.name}.cpp`, files.source[0].buffer);
      }
      if (files.header) {
        await writeFileFromBuffer(`${dirPath}/${object.object.name}.hpp`, files.header[0].buffer);
      }
      if (files.meta) {
        await writeFileFromBuffer(`${dirPath}/${object.object.name}.mm`, files.meta[0].buffer);
      }
    }
    return dirPath;
  }

  /**
   * @description Writes the file that input into the simulation code generation
   */
  private writeModulesFile() : void {
    writeFile(this.config.modules.modulesFilePath, JSON.stringify(this.modulesFile));
  }
}