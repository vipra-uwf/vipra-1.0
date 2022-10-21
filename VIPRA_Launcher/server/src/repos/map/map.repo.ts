import { Status } from '../../types/status';
import { Full, Nullable, OperationResult } from '../../types/typeDefs';
import { RepoType, UploadType } from '../../types/uploading.types';
import { BaseLocalRepo } from '../base.local.repo';
import { OMap } from '../../types/maps/map.types';
import { forAllFilesThatMatchDo, makeDir, readJsonFile, writeFileFromBuffer } from '../../util/fileOperations';
import { Logger } from '../../controllers/logging/logger';
import path from 'path';
import { Files } from '../../util/filestore';


/**
 * @description Repo for Maps
 */
export class MapRepo extends BaseLocalRepo<OMap> {

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
   * @description Method run on construction to load all installed maps into the repo
   */
  loadInstalledObjects(): Map<string, RepoType<OMap>> {
    const maps : Map<string, RepoType<OMap>> = new Map();
    forAllFilesThatMatchDo(/.*\.vmeta/, this.config.map.mapsDir, (filePath : string)=>{     
      const map : Nullable<OMap> = readJsonFile<OMap>(filePath);
      if (map) {
        Logger.info(`Found map: ${map.name} : ${map.id} AT: ${filePath}`);
        const mm : RepoType<OMap> = {
          object : map,
          dirPath : path.resolve(path.dirname(filePath)),
        };
        maps.set(mm.object.id, mm);
      }
    });
    return maps;
  }

  /**
   * @description Method used to save files to local disk
   * @param {Full<UploadType<OMap>>} data - uploaded data
   */
  async onNew(data: Full<UploadType<OMap>>): Promise<OperationResult<RepoType<OMap>>> {
    const dirPath = `${this.config.map.mapsDir}/${data.object.name}`;
    makeDir(dirPath);
    if (data.files.map && data.files.meta) {
      await writeFileFromBuffer(`${dirPath}/${data.object.name}.vmap`, data.files.map[0].buffer as Buffer);
      await writeFileFromBuffer(`${dirPath}/${data.object.name}.vmeta`, data.files.meta[0].buffer as Buffer);
    } else {
      return { status: Status.BAD_REQUEST, object: null };  
    }

    return { status: Status.SUCCESS, object: { object: data.object, dirPath } };
  }

  /**
   * @description Updates the files on the local filesystem
   * @param {RepoType<OMap>} object - object being updated
   * @param {Parital<Files>} files - files uploaded
   */
  async onUpdated(object: RepoType<OMap>, files: Partial<Files>): Promise<Status> {
    const basePath = `${object.dirPath}/${object.object.name}/${object.object.name}`;
    if (files.map) {
      await writeFileFromBuffer(`${basePath}.vmap`, files.map[0].buffer);
    }
    if (files.meta) {
      await writeFileFromBuffer(`${basePath}.vmeta`, files.meta[0].buffer);
    }

    return Status.SUCCESS;
  }
}