import path from 'path';
import { makeDir, writeFile } from '../../util/fileOperations';
import { Logger } from '../../controllers/logging/logger';
import { SimConfig } from '../../types/simconfig/simconfig.types';
import { Status } from '../../types/status';
import { Full, Nullable, OperationResult } from '../../types/typeDefs';
import { RepoType, UploadType } from '../../types/uploading.types';
import { forAllFilesThatMatchDo, readJsonFile } from '../../util/fileOperations';
import { BaseLocalRepo } from '../base.local.repo';


/**
 * @description Local Repo for SimConfigs
 */
export class SimConfigRepo extends BaseLocalRepo<SimConfig> {
  /**
   * @description Method called at end of successful create
   */
  postCreate(): void {
  }

  /**
   * @description Method Called at end of successful update
   */
  postUpdate(): void {
  }

  /**
   * @description Loads SimConfigs on construction
   */
  loadInstalledObjects(): Map<string, RepoType<SimConfig>> {
    const configs : Map<string, RepoType<SimConfig>> = new Map();
    forAllFilesThatMatchDo(/sim\.config/, this.config.simconfig.simconfigDir, (filePath : string)=>{     
      const simconfig : Nullable<SimConfig> = readJsonFile<SimConfig>(filePath);
      if (simconfig) {
        Logger.info(`Found SimConfig: ${simconfig.name} : ${simconfig.id} AT: ${filePath}`);
        const mm : RepoType<SimConfig> = {
          object: simconfig,
          dirPath : path.resolve(path.dirname(filePath)),
        };
        configs.set(mm.object.id, mm);
      }
    });

    return configs;
  }

  /**
   * @description Saves the simconfig as a file
   * @param {Full<UploadType<SimConfig>>} data - uploaded data
   */
  onNew(data: Full<UploadType<SimConfig>>): Promise<OperationResult<RepoType<SimConfig>>> {
    const dirPath = `${this.config.simconfig.simconfigDir}/${data.object.id}`;
    makeDir(dirPath);
    writeFile(`${dirPath}/sim.config`, JSON.stringify(data.object));
    return Promise.resolve({ status: Status.SUCCESS, object: { object: data.object, dirPath } });
  }

  /**
   * @description Updates the files with any updated information
   * @param {RepoType<SimConfig>} object - the updated object
   * @param {Partial<Files>} files - any files uploaded
   */
  onUpdated(object: RepoType<SimConfig>): Promise<Status> {
    const dirPath = `${this.config.simconfig.simconfigDir}/${object.object.id}`;
    makeDir(dirPath);
    writeFile(`${dirPath}/sim.config`, JSON.stringify(object.object));
    return Promise.resolve(Status.SUCCESS);
  }
}