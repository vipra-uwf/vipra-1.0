import path from 'path';
import { Logger } from '../../controllers/logging/logger';
import { Module, ModuleType } from '../../types/module/module.types';
import { Status } from '../../types/status';
import { Full, Nullable, OperationResult } from '../../types/typeDefs';
import { RepoType, UploadType } from '../../types/uploading.types';
import { forAllFilesThatMatchDo, makeDir, readJsonFile, writeFile, writeFileFromBuffer } from '../../util/fileOperations';
import { Files } from '../../util/filestore';
import { BaseLocalRepo } from '../base.local.repo';


/**
 * @description Local Repo for module files
 */
export class ModuleRepo extends BaseLocalRepo<Module> {

  /**
   * @description Method called at end of successful create
   */
  postCreate() : void {
    this.writeModulesFile(this.objects);
  }

  /**
   * @description Method Called at end of successful update
   */
  postUpdate() : void {
    this.writeModulesFile(this.objects);
  }

  /**
   * @description Method for loading installed modules on construction
   */
  loadInstalledObjects(): Map<string, RepoType<Module>> {

    const modules : Map<string, RepoType<Module>> = new Map();

    for (const dir of [this.config.modules.modulesDir, this.config.vipra.vipraDir]) {
      forAllFilesThatMatchDo(/.*\.mm/, dir, (filePath : string)=>{     
        const module : Nullable<Module> = readJsonFile<Module>(filePath);
        if (module) {
          Logger.info(`Found Module: ${module.name} : ${module.id} AT: ${filePath}`);
          const mm : RepoType<Module> = {
            object: module,
            dirPath : path.resolve(path.dirname(filePath)),
          };
          mm.object.compiled = false;
          modules.set(mm.object.id, mm);
        }
      });
    }

    this.writeModulesFile(modules);
    return modules;
  }

  /**
   * @description Method for saving files on module installation
   * @param {Full<UploadType<Module>>} data - uploaded object
   */
  async onNew(data: Full<UploadType<Module>>): Promise<OperationResult<RepoType<Module>>> {
    const dirPath = `${this.config.modules.modulesDir}/${data.object.name}`;
    makeDir(dirPath);
    if (data.files.source && data.files.header && data.files.meta) {
      await writeFileFromBuffer(`${dirPath}/${data.object.name}.cpp`, data.files.source[0].buffer as Buffer);
      await writeFileFromBuffer(`${dirPath}/${data.object.name}.hpp`, data.files.header[0].buffer as Buffer);
      await writeFileFromBuffer(`${dirPath}/${data.object.name}.mm`, data.files.meta[0].buffer as Buffer);
    } else {
      return { status: Status.BAD_REQUEST, object: null };  
    }

    return { status: Status.SUCCESS, object: { object: data.object, dirPath } };
  }

  /**
   * @description Method for updating files with new content
   * @param {RepoType<Module>} object - module being updated
   * @param {Partial<Files>} files - files to update with
   */
  async onUpdated(object: RepoType<Module>, files: Partial<Files>): Promise<Status> {
    const basePath = `${object.dirPath}/${object.object.name}/${object.object.name}`;
    if (files.source) {
      await writeFileFromBuffer(`${basePath}.cpp`, files.source[0].buffer);
    }
    if (files.header) {
      await writeFileFromBuffer(`${basePath}.hpp`, files.header[0].buffer);
    }
    if (files.meta) {
      await writeFileFromBuffer(`${basePath}.mm`, files.meta[0].buffer);
    }

    return Status.SUCCESS;
  }

  /**
   * @description Saves the installed modules to the modules file, used by the simulation
   * @param {Map<string, RepoType<Module>>} modules - installed modules
   */
  private writeModulesFile(modules : Map<string, RepoType<Module>>) : void {
    const installedModules : Record<ModuleType, RepoType<Module>[]> = {
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
    for (const key of modules.keys()) {
      const module = modules.get(key);
      if (module) {
        installedModules[module.object.type].push(module);
      }
    }
    writeFile(this.config.modules.modulesFilePath, JSON.stringify(installedModules));
  }
}