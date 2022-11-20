import express from 'express';
import path from 'path';
import { Status } from '../../types/status';
import { Nullable, OperationResult } from '../../types/typeDefs';
import { RepoType, UploadRequest, UploadType } from '../../types/uploading.types';
import { uploadModule } from '../../util/filestore';
import { Module } from '../../types/module/module.types';
import { BaseController } from '../base.controller';
import { EventType, RequestType } from '../events/eventTypes';
import { forAllFilesThatMatchDo, readJsonFile } from '../../util/fileOperations';
import { Logger } from '../logging/logger';




/**
 * @description Controller for modules
 */
export class ModuleController extends BaseController<Module> {

  /**
   * @description Sets up handlers for events involving Modules
   */
  protected setupEventHandlers(): void {
    this.evSys.subscribe(EventType.FAIL, 'Module', (module : Module) : void => {
      void this.service.update(module.id, {
        object: {
          compiled: false,
        },
      });
    });
    
    this.evSys.subscribe(EventType.SUCCESS, 'Module', (module : Module) : void => {
      void this.service.update(module.id, {
        object: {
          compiled: true,
        },
      });
    });
  }

  /**
   * @description Called after base constructor has finised
   */
  protected postConstruct(): void {
    void this.loadInstalledObjects();
  }

  /**
   * @description Sets up handlers for requests of modules
   */
  protected setupRequestHandlers(): void {
    this.evSys.setRequestHandler(RequestType.DATA, 'Module', (select : Partial<Module>) : Promise<Nullable<Module[]>> => {
      return this.service.get(select);
    });

    this.evSys.setRequestHandler(RequestType.DATA_W_PATH, 'Module', (select: Partial<Module>) : Promise<Nullable<RepoType<Module>[]>> => {
      return this.service.getRepo(select);
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
   * @description Method for loading installed modules on construction
   */
  private loadInstalledObjects(): void {
    for (const dir of [this.config.modules.modulesDir, this.config.vipra.vipraDir]) {
      forAllFilesThatMatchDo(/.*\.mm/, dir, (filePath : string)=>{     
        const module : Nullable<Module> = readJsonFile<Module>(filePath);
        if (module) {
          Logger.info(`Found Module: ${module.name} : ${module.id} AT: ${filePath}`);
          void this.service.found(module, path.dirname(filePath));
        }
      });
    }
  }
}