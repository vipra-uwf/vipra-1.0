import express from 'express';


import { Logger } from '../logging/Logging';
import { respondData, respondError, respondSuccess, respondUnknownError } from '../util/Responses';
import { ModuleController } from '../controllers/module/moduleController';
import { Status } from '../data_models/Status.e';
import { config } from '../configuration/config';


const moduleRouter = express.Router();
const moduleController = new ModuleController(config.module.tmpDir, config.module.modulesFile);

// TODO Can eventually have this link directly to the vipra hub -RG

moduleRouter.get('/', (req, res)=>{
    const modules = moduleController.getInstalledModules();
    respondData(modules, res);
});

moduleRouter.post('/', (req, res)=>{
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

moduleRouter.delete('/:id', (req, res)=>{
    const removed = moduleController.removeModule(req.params.id);
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
});


export {
    moduleRouter
};