/**
 * @module ModuleRoutes
 */

import express from 'express';

import { Logger } from '../logging/Logging';
import { respondCreated, respondData, respondError, respondSuccess, respondUnknownError } from '../util/Responses';
import { ModuleController } from '../controllers/module/moduleController';
import { Status } from '../types/Status';
import { ModuleType } from '../types/module';

import { storeModule } from '../util/FileStore';

/**
 * @description Creates the router that handles routes pertaining to modules
 *
 * @note router factory functions are used to ensure that the objects are made at the correct time -RG
 *
 * @param  {Map<string, string>} argv - Map containing the commandline flags and their values
 * @param  {ModuleManager} moduleController - ModuleController implementation that will be used to handle modules
 */
const moduleRouter = (argv : Map<string, string>, moduleController : ModuleController) : express.Router => {

    const moduleRoutes = express.Router();

    moduleRoutes.get('/', (req, res)=>{
        const modules = moduleController.allModulesInfo();
        respondData(modules, res);
    });

    moduleRoutes.get('/:id', (req, res)=>{
        // TODO
        respondUnknownError(res);
    });

    moduleRoutes.get('/type/:type', (req, res)=>{
        Logger.info('Get /module/:type');
        const type : ModuleType = req.params.type as ModuleType;
        if(!Object.values(ModuleType).includes(type)){
            respondError(Status.BAD_REQUEST, `Invalid Type`, `${type} is not a valid type`, res);
        }else{
            const modules = moduleController.getModulesofType(type);
            respondData(modules.map((module)=>{
                return {
                    name: module.name,
                    description: module.description,
                    type: module.type,
                    params: module.params,
                    id: module.id
                };
            }), res);
        }
    });

    moduleRoutes.post('/', storeModule, (req, res)=>{
        // TODO NEXT
        if(req.module && req.fileBuffers){
        moduleController.installModule(req.module, req.fileBuffers)
        .then((installed)=>{
            switch(installed.status){
                case Status.SUCCESS:
                    respondCreated(res);
                    break;
                case Status.CONFLICT:
                    respondError(Status.CONFLICT, 'Duplicate Module', installed.message || "", res);
                    break;
                case Status.INTERNAL_ERROR:
                    respondError(Status.INTERNAL_ERROR, installed.message || "", ``, res);
                    break;
                case Status.BAD_REQUEST:
                    respondError(Status.BAD_REQUEST, ``, ``, res);
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
        // TODO
        respondUnknownError(res);
    });

    moduleRoutes.delete('/:id', (req, res)=>{
        moduleController.removeModule(req.params.id)
        .then((removed)=>{
            switch(removed){
                case Status.SUCCESS:
                    respondSuccess(res);
                    break;
                case Status.NOT_FOUND:
                    respondError(Status.NOT_FOUND, 'Not Found', 'No Module with the provided id was found', res);
                    break;
                case Status.INTERNAL_ERROR:
                    respondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in DELETE /module/:id: ${removed}`);
                    respondUnknownError(res);
            }
        })
        .catch((error : string)=>{
            Logger.error(`DELETE /module/${req.params.id} : ${error}`);
            respondUnknownError(res);
        });
    });

    return moduleRoutes;
};


export {
    moduleRouter
};