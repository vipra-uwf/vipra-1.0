import express      from "express";

import { ModulesController }     from "../controllers/module/ModulesController";
import { config }               from "../configuration/config";
import { Status }               from "../data_models/Status";
import { ModuleType, typeFromString } from "../data_models/Module";

import { respondError, respondUnknownError, respondSuccess, respondFile, respondData, respondCreated } from "../util/Responses";
import { Logger } from "../logging/Logging";

const moduleRoutes : express.Router = express.Router();

const moduleRepo = config.Module.ModuleRepo();
moduleRepo.connect(config.Module.DB_URI, config.Module.TempDir);

const moduleController : ModulesController = new ModulesController(moduleRepo, config.Module.TempDir);


/* TODO

    /module GET returns module types

    /:type POST creates module of type
    /:type GET gets all of type

    /:type/:name GET downloads the module
    /:type/:name PUT updates the module

    /:type/:name/info GET returns information about the module

    make duplicates based on type and name
*/

// TODO make this not hard coded -RG
moduleRoutes.get('/', (req, res)=>{
    res.json({
        "data":{
            "Pedestrian Model": "pedestrianmodel",
        }
    });
});

moduleRoutes.get('/:type', (req, res)=>{
    const type : ModuleType = typeFromString(req.params.type);
    if(type){
        moduleController.getOptions(type)
        .then((result)=>{
            switch(result.status){
                case Status.SUCCESS:
                    respondData(res, result.options);
                    break;
                case Status.INTERNAL_ERROR:
                    respondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in GET /module : ${result.status}`);
                    respondUnknownError(res);
            }
        })
        .catch((error : string)=>{
            Logger.error(`Error in GET /module : ${error}`);
            respondUnknownError(res);
        });
    }else{
        respondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});


moduleRoutes.get('/info/:type/:name', (req, res)=>{
    const type : ModuleType = typeFromString(req.params.type);
    if(type){
        moduleController.getModuleInfo(type, req.params.name)
        .then((info)=>{
            switch(info.status){
                case Status.SUCCESS:
                    respondData(res, info.moduleMeta);
                    break;
                case Status.NOT_FOUND:
                    respondError(Status.NOT_FOUND, "Not Found", "No Module with the given name was found.", res);
                    break;
                default:
                    Logger.error(`Error Unhandled Status in /module/info: ${info.status}`);
                    respondUnknownError(res);
            }
        })
        .catch((error : string)=>{
            Logger.error(`Error in GET /module/info: ${error}`);
            respondUnknownError(res);
        });
    }else{
        respondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});


moduleRoutes.get('/:type/:name', (req, res) => {
    const moduleName = req.params.name;
    const type = typeFromString(req.params.type);

    if(type){
        moduleController.getModule(type, moduleName)
        .then((result)=>{
            switch(result.status){
                case Status.SUCCESS:
                    respondFile(res, result.path, {
                                filename: moduleName,
                                callback: moduleController.handleDownloadCleanup
                    });
                    break;
                case Status.NOT_FOUND:
                    respondError(Status.NOT_FOUND, "Not Found", "No Module with the provided name was found", res);
                    break;
                case Status.INTERNAL_ERROR:
                    respondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in GET /module: ${result.status}`);
                    respondUnknownError(res);
            }
        })
        .catch((error)=>{
            Logger.error(`Error in GET /module: ${error}`);
            respondUnknownError(res);
        });
    }else{
        respondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});


moduleRoutes.post('/:type',(req, res)=>{
    moduleController.createModule(req)
    .then((created)=>{
        switch(created){
            case Status.CREATED:
                respondCreated(res);
                break;
            case Status.CONFLICT:
                respondError(Status.CONFLICT, "Duplicate", "Modules are not allowed duplicate names. Use a PUT request to update modules.", res);
                break;
            case Status.BAD_REQUEST:
                respondError(Status.BAD_REQUEST, "Invalid Request", "Make sure the request has all required parameters and they are formatted correctly", res);
                break;
            case Status.INTERNAL_ERROR:
                respondUnknownError(res);
                break;
            default:
                Logger.error(`Unhandled Status in POST /module/${req.params.type}: ${created}`);
                respondUnknownError(res);
        }
    })
    .catch((error)=>{
        Logger.error(`Error in POST /module/${req.params.type}: ${error}`);
        respondUnknownError(res);
    });
});

moduleRoutes.put('/:type/:name', (req, res) => {
    const type = typeFromString(req.params.type);
    if(type){
        moduleController.updateModule(req)
        .then((updated)=>{
            switch(updated){
                case Status.SUCCESS:
                    respondSuccess(res);
                    break;
                case Status.BAD_REQUEST:
                    respondError(Status.BAD_REQUEST, "Missing Attributes", "Missing or Malformed Attributes", res);
                    break;
                case Status.NOT_FOUND:
                    respondError(Status.NOT_FOUND, "Not Found", "No Module with the provided name was found", res);
                    break;
                case Status.INTERNAL_ERROR:
                    respondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in PUT /module/${req.params.type}/${req.params.name}: ${updated}`);
                    respondUnknownError(res);
            }
        })
        .catch((error)=>{
            Logger.error(`Error in PUT /module/${req.params.type}/${req.params.name}: ${error}`);
            respondUnknownError(res);
        });
    }else{
        respondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});

moduleRoutes.delete('/:type/:name', (req, res)=>{
    const type = typeFromString(req.params.type);
    if(type){
        moduleController.deleteModule(type, req.params.name)
        .then((deleted)=>{
            switch(deleted){
                case Status.SUCCESS:
                    respondSuccess(res);
                    break;
                case Status.NOT_FOUND:
                    respondError(Status.NOT_FOUND, "Not Found", "No Module with the provided name was found", res);
                    break;
                case Status.INTERNAL_ERROR:
                    respondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in DELETE /module: ${deleted}`);
                    respondUnknownError(res);
            }
        })
        .catch((error)=>{
            Logger.error(`Error in DELETE /module: ${error}`);
            respondUnknownError(res);
        });
    }else{
        respondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});

export { moduleRoutes };
