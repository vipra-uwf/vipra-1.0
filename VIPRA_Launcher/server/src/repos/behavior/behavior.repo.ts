import { Behavior } from '../../types/behavior/behavior.types';
import { Full, Nullable } from '../../types/typeDefs';
import { RepoType, UploadType } from '../../types/uploading.types';
import { makeDir, writeFile, writeFileFromBuffer } from '../../util/fileOperations';
import { Files } from '../../util/filestore';
import { BaseLocalRepo } from '../base.local.repo';


/**
 * @description Repo for Behaviors
 */
export class BehaviorRepo extends BaseLocalRepo<Behavior> {

  /**
   * @description Run Before Super Load
   */
  preLoad(): void {
  }

  /**
   * @description Called after a behavior is created
   * @param {RepoType<Behavior>} object - created behavior
   */
  postCreate(): void {
    
  }

  /**
   * @description Called after a behavior is updated
   * @param {RepoType<Behavior>} object - updated behavior
   */
  postUpdate(): void {
    
  }

  /**
   * @description Called after a behavior is found
   * @param {RepoType<Behavior>} object - found behavior
   */
  postFound(): void {
    
  }

  /**
   * @description Called after behaviors are deleted
   * @param {Behaivor[]} objects - deleted behaviors
   */
  postDelete(): void {
    
  }

  /**
   * @description Saves the files uploaded with the behavior
   * @param {Full<UploadType<Behavior>>} object - uploaded behavior object
   */
  async saveFiles(object: Full<UploadType<Behavior>>): Promise<Nullable<string>> {
    const dirPath = `${this.config.behavior.behaviorsDir}/${object.object.name}`;
    makeDir(dirPath);
    if (object.files.map) {
      await writeFileFromBuffer(`${dirPath}/${object.object.name}.behavior`, object.files.map[0].buffer as Buffer);
      writeFile(`${dirPath}/${object.object.name}.bmm`, JSON.stringify(object.object));
    } else {
      return null;
    }

    return dirPath;
  }

  /**
   * @description Updates a behaviors files with newly uploaded ones
   * @param {RepoType<Behavior>} object - object that was updated
   * @param {Files} files - updated files
   */
  async updateFiles(object: RepoType<Behavior>, files: Files): Promise<Nullable<string>> {
    const dirPath = `${this.config.modules.modulesDir}/${object.object.id}`;
    if (files) {
      if (files.map) {
        await writeFileFromBuffer(`${dirPath}/${object.object.name}.omap`, files.map[0].buffer);
      }
      if (files.meta) {
        await writeFileFromBuffer(`${dirPath}/${object.object.name}.mm`, files.meta[0].buffer);
      }
    }
    return dirPath;
  }
}