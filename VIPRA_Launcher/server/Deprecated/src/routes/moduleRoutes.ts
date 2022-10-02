/**
 * @module Routes
 */

import express                                                            from 'express';

import { Logger }                                                         from '../logging/Logging';
import { respondCreated, respondData, respondError, respondUnknownError } from '../util/Responses';
import { Status }                                                         from '../types/Status';
import { Module, ModuleInfo, ModuleType, toModuleInfo }                   from '../types/module';

import { IModuleController }                                              from '../controllers/module/interfaces/ModuleController.interface';
import { storeModule }                                                    from '../util/FileStore';
import { Nullable }                                                       from 'typechain/dist/typedefs';

/**
 * @description Creates the router that handles routes pertaining to modules
 *
 * @note router factory functions are used to ensure that the objects are made at the correct time -RG
 *
 * @param  {Map<string, string>} argv - Map containing the commandline flags and their values
 * @param  {ModuleManager} moduleController - ModuleController implementation that will be used to handle modules
 */
const moduleRouter = (argv : Map<string, string>, moduleController : IModuleController) : express.Router => {

  const moduleRoutes = express.Router();

  moduleRoutes.get('/', (req, res)=>{
    const modules = moduleController.allModulesInfo();
    respondData(modules, res);
  });

  moduleRoutes.get('/:id', (req, res)=>{
    const module : Nullable<Module> = moduleController.getModule(req.params.id);
    if (module) {
      const moduleInfo : ModuleInfo = toModuleInfo(module);
      respondData(moduleInfo, res);
    } else {
      respondError(Status.NOT_FOUND, 'Module Not Found', `No Module with ID: ${req.params.id}`, res);
    }
  });

  moduleRoutes.get('/type/:type', (req, res)=>{
    const type : ModuleType = req.params.type as ModuleType;
    if (!Object.values(ModuleType).includes(type)) {
      respondError(Status.BAD_REQUEST, 'Invalid Type', `${type} is not a valid type`, res);
    } else {
      const modulesInfo : ModuleInfo[] = moduleController.getModulesofType(type).map((module)=>{ return toModuleInfo(module); });
      respondData(modulesInfo, res);
    }
  });

  moduleRoutes.post('/', storeModule, (req, res)=>{
    if (req.module && req.fileBuffers) {
      moduleController.installModule(req.module, req.fileBuffers)
        .then((installed)=>{
          switch (installed.status) {
            case Status.SUCCESS:
              respondCreated(res);
              break;
            case Status.CONFLICT:
              respondError(Status.CONFLICT, 'Duplicate Module', installed.message || '', res);
              break;
            case Status.INTERNAL_ERROR:
              respondError(Status.INTERNAL_ERROR, installed.message || '', '', res);
              break;
            case Status.BAD_REQUEST:
              respondError(Status.BAD_REQUEST, '', '', res);
              break;
            default:
              Logger.error(`Unhandled Status in POST /module/: ${installed.status}`);
              respondUnknownError(res);
          }
        })
        .catch((error : string)=>{
          Logger.error(`POST /module/ : ${error}`);
          respondUnknownError(res);
        });
    }
  });

  moduleRoutes.put('/:id', (req, res)=>{
    respondError(Status.NOT_FOUND, 'No Route', `There is no route at: ${req.originalUrl}`, res);
  });

  moduleRoutes.delete('/:id', (req, res)=>{
    const id : string = req.params.id;
    const removed = moduleController.removeModule(id);
    switch (removed.status) {
      case Status.SUCCESS:
        respondCreated(res);
        break;
      case Status.NOT_FOUND:
        respondError(Status.NOT_FOUND, 'Not Found', 'No Module with the provided id was found', res);
        break;
      case Status.INTERNAL_ERROR:
        respondUnknownError(res);
        break;
      default:
        Logger.error(`Unhandled Status in DELETE /module/:id: ${removed.status}`);
        respondUnknownError(res);
    }
  });

  return moduleRoutes;
};


export {
  moduleRouter,
};