import express from 'express';


import { Module, ModuleRequest, ModuleUpload } from '../../types/module/module.types';
import { Status } from '../../types/status';
import { ModuleService } from '../../services/module/module.service';
import { EventSystem } from '../events/eventSystem';
import { Nullable, OperationResult } from '../../types/typeDefs';
import { uploadModule } from './filestore';
import { EventType, RequestType } from '../events/eventTypes';
import { Logger } from '../logging/logger';
import { BaseController } from '../base.controller';



/**
 * @description Business logic controller for modules
 */
export class ModuleController implements BaseController<Module> {

  private moduleService : ModuleService;

  private eventController : EventSystem;

  private logger : Logger;

  constructor(eventController : EventSystem, logger : Logger, moduleService : ModuleService) {
    this.moduleService = moduleService;
    this.eventController = eventController;
    this.logger = logger;
    this.setupHandlers();
  }

  /**
   * @description Returns all of the modules in the module service
   */
  public async getAll() : Promise<OperationResult<Module[]>> {
    return { status: Status.SUCCESS, object: await this.moduleService.getAll() };
  }

  /**
   * @description Gets the module requested
   * @param {express.Request} req - client request
   */
  public async get(req : express.Request) : Promise<OperationResult<Module>> {
    const id = req.params.id;
    if (id) {
      const module = await this.moduleService.get(id);
      if (module) {
        return { status: Status.SUCCESS, object: module };
      } else {  
        return { status: Status.NOT_FOUND, object: null };
      }
    } else {
      return { status: Status.BAD_REQUEST, object: null };
    }
  }

  /**
   * @description Creates a Module from a request
   * @param {express.Request} req - client request
   */
  public async create(req : express.Request) : Promise<OperationResult<Module>> {

    const upload : Status = await uploadModule(req)
      .catch(()=>{
        return Status.BAD_REQUEST;
      });

    if (upload != Status.SUCCESS) { return { status: upload, object: null }; }

    const request = req as ModuleRequest;
    if (request) {
      const createRequest : Partial<ModuleUpload> = this.createUpload(request);
      if (createRequest) {
        const result = await this.moduleService.create(createRequest);
        if (result.status == Status.CREATED) {
          this.eventController.emit<Module, ModuleController>(EventType.NEW_MODULE, result.object, this);
        }
        return result;
      }
    }
    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Updates a Module from a request
   * @param {express.Request} req - client request
   */
  public async update(req : express.Request) : Promise<OperationResult<Module>> {
    const id = req.params.id;
    const request = req as ModuleRequest;
    if (id && request.body) {
      const uploadRequest : Partial<ModuleUpload> = this.createUpload(request);
      if (uploadRequest) {
        const result = await this.moduleService.update(id, uploadRequest);
        if (result.status == Status.SUCCESS) {
          this.eventController.emit<Module, ModuleController>(EventType.UPDATE_MODULE, result.object, this);
        }
        return result;
      }
    }

    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Deletes a module requested
   * @param {express.Request} req - client request
   */
  public async delete(req : express.Request) : Promise<OperationResult<Module>> {
    const id : Nullable<string> = req.params.id || null;
    if (id) {
      const result = await this.moduleService.delete(id);
      if (result.status == Status.SUCCESS) {
        this.eventController.emit<Module, ModuleController>(EventType.DELETE_MODULE, result.object, this);
      }
      return result;
    }

    return { status: Status.BAD_REQUEST, object: null };
  }


  /**
   * @description sets up handlers for events
   */
  private setupHandlers() : void {
    /**
     * @description finds the requested module and returns it
     * @param {any} select - information for identifying the module
     */
    const moduleRequestHandler = (select : unknown) : Promise<Nullable<Module>> => {
      const module = select as Partial<Module>;
      if (module.id) {
        return this.moduleService.get(module.id);
      } else {
        return Promise.resolve(null);
      }
    };

    this.eventController.setRequestHandler(RequestType.MODULE, moduleRequestHandler);
  }

  /**
   * @description Transforms a request into a ModuleUpload
   * @param {CreateModuleRequest} upload - upload request
   */
  private createUpload(upload : ModuleRequest) : Partial<ModuleUpload> {
    return {
      module: upload.body?.module,
      files: {
        srcFile : upload.files?.source,
        headerFile : upload.files?.header,
        metaFile : upload.files?.meta,
      },
    };
  }
}