import express from 'express';
import { Status } from '../../types/status';
import { Nullable, OperationResult } from '../../types/typeDefs';
import { UploadRequest, UploadType } from '../../types/uploading.types';
import { uploadModule } from '../../util/filestore';
import { Module } from '../../types/module/module.types';
import { BaseController } from '../base.controller';
import { EventHandler, EventType, RequestType } from '../events/eventTypes';




/**
 * @description Controller for modules
 */
export class ModuleController extends BaseController<Module> {
  /**
   * @description Sets up handlers for events involving Modules
   */
  protected setupEventHandlers(): void {
    this.evSys.subscribe(EventType.FAIL, 'Module', this.moduleFailHandler);
    this.evSys.subscribe(EventType.SUCCESS, 'Module', this.moduleBuiltHandler);
  }

  /**
   * @description Sets up handlers for requests of modules
   */
  protected setupRequestHandlers(): void {
    this.evSys.setRequestHandler(RequestType.MODULE, (select : Partial<Module>) : Promise<Nullable<Module[]>> => {
      return this.service.get(select);
    });
  }

  /**
   * @description Converts an upload request into a usable form for the module service
   * @param {express.Request} req - client request object
   */
  protected async createUpload(req: express.Request): Promise<OperationResult<Partial<UploadType<Module>>>> {

    const upload = await uploadModule(req);

    if (upload === Status.SUCCESS) {
      const request = req as UploadRequest;
      return { status: Status.SUCCESS, object: {
        object: undefined,
        files: {
          source: (request.files?.source ? request.files?.source : undefined),
          header: (request.files?.header ? request.files?.header : undefined),
          meta: (request.files?.meta ? request.files?.meta : undefined),
        },
      } };
    }
    return { status: Status.BAD_REQUEST, object: null };
  }
  
  /**
   * @description Handles Failed Module Compilation
   * @param {Module} module - module that failed compilation
   */
  private moduleFailHandler : EventHandler = (module : Module) : void => {
    void this.service.update(module.id, {
      object: {
        compiled: false,
      },
    });
  };

  /**
   * @description Handles Successful Module Compilation
   * @param {Module} module - module that was compiled
   */
  private moduleBuiltHandler : EventHandler = (module : Module) : void => {
    void this.service.update(module.id, {
      object: {
        compiled: true,
      },
    });
  };
}