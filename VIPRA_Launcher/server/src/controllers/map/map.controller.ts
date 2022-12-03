import express from 'express';
import path from 'path';
import { OMap } from '../../types/maps/map.types';
import { Status } from '../../types/status';
import { Nullable, OperationResult } from '../../types/typeDefs';
import { RepoType, UploadRequest, UploadType } from '../../types/uploading.types';
import { forAllFilesThatMatchDo, readJsonFile } from '../../util/fileOperations';
import { uploadMap } from '../../util/filestore';
import { BaseController } from '../base.controller';
import { RequestType } from '../events/eventTypes';
import { Logger } from '../logging/logger';


/**
 * @description Controller For Obstacle Maps
 */
export class MapController extends BaseController<OMap> {
  /**
   * @description Starts the main function of the controller
   * @note Should only be called after all controllers have been constructed
   */
  public start(): void {
    this.findMaps();
  }

  /**
   * @description Sets the event handlers for maps
   */
  protected setupEventHandlers(): void {
    
  }

  /**
   * @description Sets the request handlers for maps
   */
  protected setupRequestHandlers(): void {
    this.evSys.setRequestHandler(RequestType.DATA, 'OMap', (select : Partial<OMap>) : Promise<Nullable<OMap[]>> => {
      return this.service.get(select);
    });

    this.evSys.setRequestHandler(RequestType.DATA_W_PATH, 'OMap', (select: Partial<OMap>) : Promise<Nullable<RepoType<OMap>[]>> => {
      return this.service.getRepo(select);
    });
  }

  /**
   * @description Converts a request into a usable format
   * @param {express.Request} req - client request object
   */
  protected async createUpload(req: express.Request): Promise<OperationResult<Partial<UploadType<OMap>>>> {
    const upload = await uploadMap(req);
    if (upload ===  Status.SUCCESS) {
      const request = req as UploadRequest;
      return { status: Status.SUCCESS, object: {
        object: undefined,
        files: {
          map: (request.files?.map ? request.files?.map : undefined),
        },
      } };
    }
    return { status: upload, object: null };
  }

  /**
   * @description Finds all installed maps and adds them to the repo
   */
  private findMaps() : void {
    forAllFilesThatMatchDo(/.*\.omm/, this.config.map.mapsDir, (filePath : string)=>{     
      const map : Nullable<OMap> = readJsonFile<OMap>(filePath);
      if (map) {
        Logger.info(`Found Map: ${map.name} : ${map.id} AT: ${filePath}`);
        void this.service.found(map, path.dirname(filePath));
      }
    });
  }
}