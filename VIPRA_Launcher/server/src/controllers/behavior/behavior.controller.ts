import express from 'express';
import { Status } from 'src/types/status';
import { uploadBehavior } from 'src/util/filestore';
import { Behavior } from '../../types/behavior/behavior.types';
import { Nullable, OperationResult } from '../../types/typeDefs';
import { RepoType, UploadRequest, UploadType } from '../../types/uploading.types';
import { BaseController } from '../base.controller';
import { RequestType } from '../events/eventTypes';


/**
 * @description Controller For Behaviors
 */
export class BehaviorController extends BaseController<Behavior> {
  /**
   * @description Sets up event hanlders for Behavior Events
   */
  protected setupEventHandlers(): void {}

  /**
   * @description Sets up request handlers for behaviors
   */
  protected setupRequestHandlers(): void {
    this.evSys.setRequestHandler(RequestType.DATA, 'Behavior', (select : Partial<Behavior>) : Promise<Nullable<Behavior[]>> => {
      return this.service.get(select);
    });
    this.evSys.setRequestHandler(RequestType.DATA_W_PATH, 'Behavior', (select : Partial<Behavior>) : Promise<Nullable<RepoType<Behavior>[]>> => {
      return this.service.getRepo(select);
    });
  }

  /**
   * @description Converts an upload request into a usable form for the module service
   * @param {express.Request} req - client request object
   */
  protected async createUpload(req: express.Request): Promise<OperationResult<Partial<UploadType<Behavior>>>> {
    const upload = await uploadBehavior(req);

    if (upload === Status.SUCCESS) {
      const request = req as UploadRequest;
      return { status: Status.SUCCESS, object: {
        object: undefined,
        files: {
          behavior: (request.files?.behavior ? request.files?.behavior : undefined),
        },
      } };
    }
    return { status: Status.BAD_REQUEST, object: null };
  }
}