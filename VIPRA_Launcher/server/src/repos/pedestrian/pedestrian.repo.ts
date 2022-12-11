import { PedMap } from '../../types/pedestrian/pedestrian.types';
import { Full, Nullable } from '../../types/typeDefs';
import { RepoType, UploadType } from '../../types/uploading.types';
import { makeDir, writeFile, writeFileFromBuffer } from '../../util/fileOperations';
import { Files } from '../../util/filestore';
import { BaseLocalRepo } from '../base.local.repo';


/**
 * @description Repo for Pedestrian Maps
 */
export class PedestrianRepo extends BaseLocalRepo<PedMap> {
  
  /**
   * @description Called after a pedestrian map is created, currently no functionality
   */
  postCreate(): void {}

  /**
   * @description Called after a pedestrian map is updated, currently no functionality
   */
  postUpdate(): void {}
  
  /**
   * @description Called after a pedestrian map is found, currently no functionality
   */
  postFound(): void {}

  /**
   * @description Called after a pedestrian map is deleted, currently no functionality
   */
  postDelete(): void {}


  /**
   * @description Saves the files from a pedestrian map create request
   * @param {Full<UploadType<PedMap>>} object - uploaded object
   */
  async saveFiles(object: Full<UploadType<PedMap>>): Promise<Nullable<string>> {
    const dirPath = `${this.config.map.mapsDir}/pedestrian_maps/${object.object.id}`;
    makeDir(dirPath);
    if (object.files.pedmap) {
      await writeFileFromBuffer(`${dirPath}/${object.object.name}.pmap`, object.files.pedmap[0].buffer as Buffer);
      writeFile(`${dirPath}/${object.object.name}.pmm`, JSON.stringify(object.object));
    } else {
      return null;
    }

    return dirPath;
  }

  /**
   * @description Updates files when a pedestrian map is updated
   * @param {RepoType<PedMap>} object - Updated pedestrian map
   * @param {Files} files - uploaded files
   */
  async updateFiles(object: RepoType<PedMap>, files: Files): Promise<Nullable<string>> {
    const dirPath = `${this.config.map.mapsDir}/pedestrian_maps/${object.object.id}`;
    if (files) {
      if (files.map) {
        await writeFileFromBuffer(`${dirPath}/${object.object.name}.pmap`, files.map[0].buffer);
      }
      if (files.meta) {
        await writeFileFromBuffer(`${dirPath}/${object.object.name}.pmm`, files.meta[0].buffer);
      }
    }
    return dirPath;
  }
}