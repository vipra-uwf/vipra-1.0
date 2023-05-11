import express from 'express';
import path from 'path';
import { OMap } from '../../types/maps/map.types';
import { PedMap } from '../../types/pedestrian/pedestrian.types';
import { Status } from '../../types/status';
import { Nullable, OperationResult } from '../../types/typeDefs';
import { RepoType, UploadRequest, UploadType } from '../../types/uploading.types';
import { forAllFilesThatMatchDo, readJsonFile } from '../../util/fileOperations';
import { uploadPedMap } from '../../util/filestore';
import { BaseController } from '../base.controller';
import { RequestType } from '../events/eventTypes';
import { Logger } from '../logging/logger';


/**
 * @description Controller for pedestrian maps
 */
export class PedestrianController extends BaseController<PedMap> {
  /**
   * @description Starts the main function of the controller
   */
  public start(): void {
    this.findPedMaps();
  }

  /**
   * @description Registers event handlers for pedmaps
   */
  protected setupEventHandlers(): void {
    
  }

  /**
   * @description Registers request handlers for pedmaps
   */
  protected setupRequestHandlers(): void {
    this.evSys.setRequestHandler(RequestType.DATA, 'PedMap', (select : Partial<PedMap>) : Promise<Nullable<PedMap[]>> => { return this.service.get(select); });
    this.evSys.setRequestHandler(RequestType.DATA_W_PATH, 'PedMap', (select : Partial<PedMap>) : Promise<Nullable<RepoType<PedMap>[]>> => { return this.service.getRepo(select); });
  }

  /**
   * @description Converst a request into a usable format
   * @param {express.Request} req - client request object
   */
  protected async createUpload(req: express.Request): Promise<OperationResult<Partial<UploadType<PedMap>>>> {
    const upload = await uploadPedMap(req);
    if (upload ===  Status.SUCCESS) {
      const request = req as UploadRequest;
      return { status: Status.SUCCESS, object: {
        object: undefined,
        files: {
          pedmap: (request.files?.pedmap ? request.files?.pedmap : undefined),
        },
      } };
    }
    return { status: upload, object: null };
  }


  /**
   * @description Locates all pedestrian maps
   */
  private findPedMaps() : void {
    forAllFilesThatMatchDo(/.*\.pmm/, this.config.map.mapsDir, (filePath : string)=>{     
      const pedmap : Nullable<PedMap> = readJsonFile<PedMap>(filePath);
      if (pedmap) {
        void this.evSys.request<RepoType<OMap>>(RequestType.DATA_W_PATH, 'OMap', { id: pedmap.mapRef })
          .then((map) => {
            if (map && map[0]) {
              Logger.info(`Found Pedestrian Map For ${map[0].object.name}: ${pedmap.name} : ${pedmap.id} AT: ${filePath}`);
              void this.service.found(pedmap, path.dirname(filePath));
            }
          });
      }
    });
  }
}