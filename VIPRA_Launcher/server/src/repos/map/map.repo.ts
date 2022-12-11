import { OMap } from '../../types/maps/map.types';
import { Full, Nullable } from '../../types/typeDefs';
import { RepoType, UploadType } from '../../types/uploading.types';
import { makeDir, writeFile, writeFileFromBuffer } from '../../util/fileOperations';
import { Files } from '../../util/filestore';
import { BaseLocalRepo } from '../base.local.repo';


/**
 * @description Repo For Obstacle Maps
 */
export class MapRepo extends BaseLocalRepo<OMap> {
  /**
   * @description Called after a map is created, no function
   */
  postCreate(): void {}

  /**
   * @description Called after a map is updated, no function
   */
  postUpdate(): void {}

  /**
   * @description Called after a map is found, no function
   */
  postFound(): void {}

  /**
   * @description Called after a map is deleted, no function
   */
  postDelete(): void {}

  /**
   * @description Saves the files from a map create request
   * @param {Full<UploadType<OMap>>} object - uploaded object
   */
  async saveFiles(object: Full<UploadType<OMap>>): Promise<Nullable<string>> {
    const dirPath = `${this.config.map.mapsDir}/obstacle_maps/${object.object.id}`;
    makeDir(dirPath);
    if (object.files.map) {
      await writeFileFromBuffer(`${dirPath}/${object.object.name}.omap`, object.files.map[0].buffer as Buffer);
      writeFile(`${dirPath}/${object.object.name}.omm`, JSON.stringify(object.object));
    } else {
      return null;
    }

    return dirPath;
  }

  /**
   * @description Updates the files for a map
   * @param {RepoType<OMap>} object - map that was updated
   * @param {Files} files - updated files
   */
  async updateFiles(object: RepoType<OMap>, files: Files): Promise<Nullable<string>> {
    if (files) {
      if (files.pedmap) {
        await writeFileFromBuffer(`${object.dirPath}/${object.object.name}.omap`, files.pedmap[0].buffer);
      }
    }
    writeFile(`${object.dirPath}/${object.object.name}.omm`, JSON.stringify(object.object));
    return object.dirPath;
  }
}