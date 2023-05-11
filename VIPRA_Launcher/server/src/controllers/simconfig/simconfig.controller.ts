import express from 'express';
import path from 'path';
import { forAllFilesThatMatchDo, readJsonFile } from '../../util/fileOperations';
import { Module, ModuleParam, ModuleType } from '../../types/module/module.types';
import { SimConfig } from '../../types/simconfig/simconfig.types';
import { Status } from '../../types/status';
import { DeepPartial, Nullable, OperationResult } from '../../types/typeDefs';
import { UploadRequest, UploadType } from '../../types/uploading.types';
import { getFormData } from '../../util/utilMethods';
import { BaseController } from '../base.controller';
import { EventType, RequestType } from '../events/eventTypes';
import { Logger } from '../logging/logger';


/**
 * @description Controller for Simulation Configurations
 */
export class SimConfigController extends BaseController<SimConfig> {
  

  
  /**
   * @description Starts the main function of the controller
   * @note Should only be called after all controllers have been constructed
   */
  public start(): void {
    this.findConfigs();
  }

  /**
   * @description Sets the hanlders for SimConfig events 
   */
  protected setupEventHandlers(): void {
  }

  /**
   * @description Sets the handlers for SimConfig Requests
   */
  protected setupRequestHandlers(): void {
    this.evSys.setRequestHandler(RequestType.DATA, 'SimConfig', (select : Partial<SimConfig>) : Promise<Nullable<SimConfig[]>> => {
      return this.service.get(select);
    });

    /**
     * @description Request Hanlder for simconfig parameters
     * @note By the event system convention this should return Promise<Nullable<ModuleParam[][]>>, but currently does not
     * @param {Partial<SimConfig>} select - select object for simconfig
     */
    const getParams = async (select : Partial<SimConfig>) : Promise<Nullable<ModuleParam[]>> => {
      const simconfig = await this.service.get(select);
      if (simconfig && simconfig?.length > 0) {
        let params : ModuleParam[] = [];
        for (const id of Object.values(simconfig[0].modules)) {
          const module = await this.evSys.request<Module>(RequestType.DATA, 'Module', { id });
          if (module && module[0]) {
            params = params.concat(module[0].params);
          }
        }
        return params;
      } else {
        return null;
      }
    };

    this.evSys.setRequestHandler(RequestType.DATA, 'SimConfigParams', getParams);
  }

  /**
   * @description Creates an upload object from a request
   * @param {express.Request} req - client request object
   */
  protected async createUpload(req: express.Request): Promise<OperationResult<Partial<UploadType<SimConfig>>>> {
    const upload = await getFormData<SimConfig>(req);

    if (upload) {
      const request = req as UploadRequest;
      const config = await this.makeConfig(request);
      if (config) {
        return { status: Status.SUCCESS, object: { object: config, files: undefined } };
      }
    }
    return { status: Status.BAD_REQUEST, object: null };
  } 

  /**
   * @description Creates a simconfig from a request, returns null if the request is missing properties
   * @param {UploadRequest} request - request object
   */
  private makeConfig = async (request : UploadRequest) : Promise<Nullable<SimConfig>> => {
    if (request.body.id && request.body.name && request.body.description) {
      const config : DeepPartial<SimConfig> = {
        id: request.body.id as string,
        name: request.body.name as string,
        description: request.body.description as string,
        modules: {},
      };

      if (config.modules) {
        for (const key of Object.values(ModuleType)) {
          if (request.body[key]) {
            const modules = await this.evSys.request<Module>(RequestType.DATA, 'Module', { id: request.body[key] as string });
            if (modules) {
              if (modules[0]) {
                if (modules[0].type === key) {
                  config.modules[key] = request.body[key] as string;
                  continue;
                }
              }
            }
          }
          return null;
        }
        return config as SimConfig;
      }
    }
    return null;
  };

  

  /**
   * @description Finds all installed maps and adds them to the repo
   */
  private findConfigs() : void {
    forAllFilesThatMatchDo(/sim.config/, this.config.simconfig.simconfigDir, (filePath : string)=>{     
      const config : Nullable<SimConfig> = readJsonFile<SimConfig>(filePath);
      if (config) {
        Logger.info(`Found SimConfig: ${config.name} : ${config.id} AT: ${filePath}`);
        void this.service.found(config, path.dirname(filePath)).then(() => {
          void this.evSys.emit<SimConfig>(EventType.NEW, 'SimConfig', config);
        });
      }
    });
  }
}