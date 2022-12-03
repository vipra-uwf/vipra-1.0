
import express from 'express';
import path from 'path';
import { Status } from '../../types/status';
import { forAllFilesThatMatchDo, readJsonFile } from '../../util/fileOperations';
import { uploadBehavior } from '../../util/filestore';
import { Behavior } from '../../types/behavior/behavior.types';
import { Nullable, OperationResult } from '../../types/typeDefs';
import { RepoType, UploadRequest, UploadType } from '../../types/uploading.types';
import { BaseController } from '../base.controller';
import { RequestType } from '../events/eventTypes';
import { Logger } from '../logging/logger';


/**
 * @description Controller for Behaviors
 */
export class BehaviorController extends BaseController<Behavior> {
  /**
   * @description Starts the main function of the controller
   * @note Should only be called after all controllers have been constructed
   */
  public start(): void {
    this.findBehaviors();
  }

  /**
   * @description Sets up the event handlers for behaviors
   */
  protected setupEventHandlers(): void {
    
  }

  /**
   * @description Sets up the request handlers for behaviors
   */
  protected setupRequestHandlers(): void {
    this.evSys.setRequestHandler(RequestType.DATA, 'Behavior', (select : Partial<Behavior>) : Promise<Nullable<Behavior[]>> => {
      return this.service.get(select);
    });

    this.evSys.setRequestHandler(RequestType.DATA_W_PATH, 'Behavior', (select: Partial<Behavior>) : Promise<Nullable<RepoType<Behavior>[]>> => {
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

  /**
   * @description Finds all installed behaviors and adds them to the repo
   */
  private findBehaviors() : void {
    forAllFilesThatMatchDo(/.*\.bm/, this.config.behavior.behaviorsDir, (filePath : string)=>{     
      const behavior : Nullable<Behavior> = readJsonFile<Behavior>(filePath);
      if (behavior) {
        Logger.info(`Found Behavior: ${behavior.name} : ${behavior.id} AT: ${filePath}`);
        void this.service.found(behavior, path.dirname(filePath));
      }
    });
  }

}