
import express from 'express';
import { OMap } from '../../types/maps/map.types';
import { Status } from '../../types/status';
import { Nullable, OperationResult } from '../../types/typeDefs';
import { UploadRequest, UploadType } from '../../types/uploading.types';
import { uploadMap } from '../../util/filestore';
import { BaseController } from '../base.controller';
import { RequestType } from '../events/eventTypes';


/**
 * @description Controller for Maps
 */
export class MapController extends BaseController<OMap> {
  /**
   * @description Sets up handlers for events involving Maps
   */
  protected setupEventHandlers(): void {}

  /**
   * @description Sets up handlers for requests of maps
   */
  protected setupRequestHandlers(): void {
    this.evSys.setRequestHandler(RequestType.DATA, 'Map', (select : Partial<OMap>) : Promise<Nullable<OMap[]>> => {
      return this.service.get(select);
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
          meta: (request.files?.meta ? request.files?.meta : undefined),
        },
      } };
    }
    return { status: upload, object: null };
  }
}