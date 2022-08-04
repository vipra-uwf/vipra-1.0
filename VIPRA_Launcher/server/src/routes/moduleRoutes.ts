import express from 'express';

import { Logger } from '../logging/Logging';
import { respondData, respondError, respondSuccess, respondUnknownError } from '../util/Responses';
import { ModuleController } from '../controllers/module/moduleController';
import { Status } from '../data_models/Status.e';
import { ModulesFile, ModuleType } from '../data_models/module';

const moduleRouter = (moduleController : ModuleController) : express.Router => {

    const moduleRoutes = express.Router();

    moduleRoutes.get('/', (req, res)=>{
        const modules = moduleController.allModulesInfo();
        respondData(modules, res);
    });

    moduleRoutes.get('/:type', (req, res)=>{
        Logger.info('Get /module/:type');
        // TODO check that the type is valid -RG
        const type : ModuleType = req.params.type as ModuleType;
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
    });

    moduleRoutes.post('/', (req, res)=>{
        moduleController.installModule(req)
        .then((installed)=>{
            switch(installed){
                case Status.SUCCESS:
                    respondSuccess(res);
                    break;
                case Status.BAD_REQUEST:
                    respondError(Status.BAD_REQUEST, `No File`, `A Module Tar file is required`, res);
                    break;
                case Status.CONFLICT:
                    respondError(Status.CONFLICT, `Duplicate`, `The provided module is already installed`, res);
                    break;
                case Status.INTERNAL_ERROR:
                    respondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in POST /module: ${installed}`);
                    respondUnknownError(res);
            }
        })
        .catch((error : Error)=>{
            Logger.error(error.message);
            respondUnknownError(res);
        });
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