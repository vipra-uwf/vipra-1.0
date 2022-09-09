/**
 * @module Routes
 */
import express from 'express';
import multer from 'multer';
import { respondData, respondError, respondSuccess, respondUnknownError } from '../util/Responses';

import { IConfigManager } from '../controllers/simconfig/interfaces/ConfigManager.interface';
import { Status } from '../types/Status';
import { SimConfig } from '../types/simconfig';
import { ModuleType } from '../types/module';
import { Logger } from '../logging/Logging';
import { Nullable } from '../types/typeDefs';

const formData = multer();

type ConfigRequestBody = {
  name? : string;
  description? : string;
  moduleIDs? : Record<ModuleType, string>;
};

/**
 * @description Creates the router that handles routes pertaining to the simulation configurations
 *
 * @note router factory functions are used to ensure that the objects are made at the correct time -RG
 *
 * @param  {ConfigManager} configManager - ConfigManager implementation that will be used to handle simconfigs
 */
const simConfigRouter = (configManager : IConfigManager):express.Router=>{//(argv : Map<string, string>, configManager : IConfigManager) : express.Router => {

  const simConfigRoutes   : express.Router    = express.Router();

  
  simConfigRoutes.get('/', (req : express.Request, res : express.Response)=>{
    respondData(configManager.getConfigs(), res);
  });

  simConfigRoutes.get('/:id', (req : express.Request, res : express.Response)=>{
    const config : Nullable<SimConfig> = configManager.getConfig(req.params.id);
    if (config) {
      respondData(config, res);
    } else {
      respondError(Status.NOT_FOUND, 'Config Not Found', `No Config with ID: ${req.params.id}`, res);
    }
  });

  simConfigRoutes.post('/', formData.none(), (req : express.Request, res : express.Response)=>{
    const body = req.body as ConfigRequestBody;
    if (body && body.name && body.description) {
      const added = configManager.addConfig(body as Partial<SimConfig>);
      switch (added.status) {
        case Status.SUCCESS:
          respondSuccess(res);
          break;
        case Status.CONFLICT:
          respondError(Status.CONFLICT, 'Duplicate Configuration', `There is already a Configuration with the provided modules ID: ${added.message || 'null'}`, res);
          break;
        case Status.BAD_REQUEST:
          respondError(Status.BAD_REQUEST, 'Bad Request', (added.message || 'null'), res);
          break;
        case Status.INTERNAL_ERROR:
          respondUnknownError(res);
          break;
        default:
          Logger.error(`Unhandled Status in POST /simconfig/: ${added.status}`);
          respondUnknownError(res);
      }
    } else {
      respondError(Status.BAD_REQUEST, 'Missing Properties', 'Request is Missing Properties', res);
    }
  });

  simConfigRoutes.put('/:id', formData.none(), (req : express.Request, res : express.Response)=>{
    const body = req.body as ConfigRequestBody;
    if (body && body.description || body.moduleIDs) {
      const updated = configManager.updateConfig(req.params.id, body);
      switch (updated.status) {
        case Status.SUCCESS:
          respondSuccess(res);
          break;
        case Status.BAD_REQUEST:
          respondError(Status.BAD_REQUEST, 'Bad Request', (updated.message || 'null'), res);
          break;
        case Status.NOT_FOUND:
          respondError(Status.NOT_FOUND, 'Config Not Found', `No Config with ID: ${req.params.id}`, res);
          break;
        case Status.INTERNAL_ERROR:
          respondUnknownError(res);
          break;
        default:
          Logger.error(`Unhandled Status in PUT /simconfig/:id : ${updated.status}`);
          respondUnknownError(res);  
      }
    } else {
      respondError(Status.BAD_REQUEST, 'Missing Properties', 'Request is Missing Properties', res);
    }
  });

  simConfigRoutes.delete('/:id', (req : express.Request, res : express.Response)=>{
    const deleted = configManager.deleteConfig(req.params.id);
    switch (deleted.status) {
      case Status.SUCCESS:
        respondSuccess(res);
        break;
      case Status.NOT_FOUND:
        respondError(Status.NOT_FOUND, 'Config Not Found', `No SimCOnfig with ID: ${req.params.id}`, res);
        break;
      default:
        Logger.error(`Unhandled Status in DELETE /simconfig/:id : ${deleted.status}`);
        respondUnknownError(res);
    }
  });

  return simConfigRoutes;
};


export {
  simConfigRouter,
};