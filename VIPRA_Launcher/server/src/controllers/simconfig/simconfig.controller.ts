

import express from 'express';
import { SimConfig, SimConfigUpload } from '../../types/simconfig/simconfig.types';
import { Nullable, OperationResult } from '../../types/typeDefs';
import { BaseController } from '../base.controller';
import { EventSystem } from '../events/eventSystem';
import { SimConfigService } from '../../services/simconfig/simconfig.service';
import { Status } from '../../types/status';
import { EventType, RequestType } from '../events/eventTypes';
import { getFormData } from '../../util/utilMethods';
import { Module, ModuleParam } from '../../types/module/module.types';


/**
 * @description Contoller for SimConfigs
 */
export class SimConfigController implements BaseController<SimConfig> {

  private eventController : EventSystem;

  private scService : SimConfigService;


  constructor(eventController : EventSystem, scService : SimConfigService) {
    this.eventController = eventController;
    this.scService = scService;
    this.setupHandlers();
  }

  /**
   * @description Returns all SimConfigs
   */
  public async getAll(): Promise<OperationResult<SimConfig[]>> {
    return { status: Status.SUCCESS, object: await this.scService.getAll() };
  }

  /**
   * @description Returns the SimConfig with id
   * @param {express.Request} req - client request object
   */
  public async get(req: express.Request): Promise<OperationResult<SimConfig>> {
    const id = req.params.id;
    if (id) {
      const result = await this.scService.get(id);
      if (result) {
        return { status: Status.SUCCESS, object: result };
      } else {
        return { status: Status.NOT_FOUND, object: null };
      }
    }
    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Creates a SimConfig from a request
   * @param {express.Request} req - client request object
   */
  public async create(req: express.Request): Promise<OperationResult<SimConfig>> {
    const simconfig : SimConfigUpload = await getFormData<SimConfig>(req);
    const result = await this.scService.create(simconfig);

    if (result.status == Status.CREATED) {
      void this.eventController.emit<SimConfig>(EventType.NEW_SIMCONFIG, result.object);
    }
    return result;
  }

  /**
   * @description Updates a SimConfig from a request
   * @param {express.Request} req - client request object
   */
  public async update(req: express.Request): Promise<OperationResult<SimConfig>> {
    const id = req.params.id;
    const simconfig : SimConfigUpload = await getFormData<SimConfig>(req);

    if (id && simconfig) {
      const result = await this.scService.update(id, simconfig);
      if (result.status == Status.SUCCESS) {
        void this.eventController.emit<SimConfig>(EventType.UPDATE_SIMCONFIG, result.object);
      }
      return result;
    }

    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Deletes a SimConfig from a request
   * @param {express.Request} req - client request object
   */
  public async delete(req: express.Request): Promise<OperationResult<SimConfig>> {
    const id = req.params.id;

    if (id) {
      const result = await this.scService.delete(id);
      if (result.status == Status.SUCCESS) {
        void this.eventController.emit<SimConfig>(EventType.DELETE_SIMCONFIG, result.object);
      }
      return result;
    }
    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description sets up handlers for events
   */
  private setupHandlers() : void {   
    this.eventController.setRequestHandler(RequestType.SIM_CONFIG, this.simconfigRequestHandler);
    this.eventController.setRequestHandler(RequestType.SIM_CONFIG_PARAMS, this.getParams);
  }

  /**
   * @description Returns the parameters for a simconfig
   * @param {{ id?: string }} select - select object with id
   * @param {string} select.id - config id
   */
  private getParams = async (select : { id?: string }) : Promise<Nullable<ModuleParam[]>> => {
    if (select.id) {
      const simconfig = await this.scService.get(select.id);
      if (simconfig) {
        const params : ModuleParam[] = [];
        for (const moduleId of Object.values(simconfig.modules)) {
          const module = await this.eventController.request<Module>(RequestType.MODULE, { id: moduleId });
          if (module) {
            params.concat(module.params);
          }
        }
        return params;
      }
    }
    return Promise.resolve(null);
  };

  /**
   * @description finds the requested module and returns it
   * @param {any} select - information for identifying the module
   */
  private simconfigRequestHandler = (select : unknown) : Promise<Nullable<SimConfig>> => {
    const simconfig = select as Partial<SimConfig>;
    if (simconfig.id) {
      return this.scService.get(simconfig.id);
    } else {
      return Promise.resolve(null);
    }
  };
}