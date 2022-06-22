import express      from "express";

import { ModulesController }     from "../controllers/module/ModulesController";
import { config }               from "../configuration/config";
import { Status }               from "../data_models/Status";
import { ModuleType, typeFromString } from "../data_models/Module";

import { RespondError, RespondUnknownError, RespondSuccess, RespondFile, RespondData, RespondCreated } from "../util/Responses";
import { Logger } from "../logging/Logging";

const ModuleRoutes : express.Router = express.Router();

const moduleRepo = config.Module.ModuleRepo();
moduleRepo.connect(config.Module.DB_URI, config.Module.TempDir);

const ModuleController : ModulesController = new ModulesController(moduleRepo, config.Module.TempDir);


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
ModuleRoutes.get('/', (req, res)=>{
    res.json({
        "data":{
            "Pedestrian Model": "pedestrianmodel",
        }
    });
});

ModuleRoutes.get('/:type', (req, res)=>{
    const type : ModuleType = typeFromString(req.params.type);
    if(type){
        ModuleController.getOptions(type)
        .then((result)=>{
            switch(result.status){
                case Status.SUCCESS:
                    RespondData(res, result.options);
                    break;
                case Status.INTERNAL_ERROR:
                    RespondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in GET /module : ${result.status}`);
                    RespondUnknownError(res);
            }
        })
        .catch((error)=>{
            Logger.error(`Error in GET /module : ${error}`);
            RespondUnknownError(res);
        });
    }else{
        RespondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});


ModuleRoutes.get('/info/:type/:name', (req, res)=>{
    const type : ModuleType = typeFromString(req.params.type);
    if(type){
        ModuleController.getModuleInfo(type, req.params.name)
        .then((info)=>{
            switch(info.status){
                case Status.SUCCESS:
                    RespondData(res, info.moduleMeta);
                    break;
                case Status.NOT_FOUND:
                    RespondError(Status.NOT_FOUND, "Not Found", "No Module with the given name was found.", res);
                    break;
                default:
                    Logger.error(`Error Unhandled Status in /module/info: ${info.status}`);
                    RespondUnknownError(res);
            }
        })
        .catch((error)=>{
            Logger.error(`Error in GET /module/info: ${error}`);
            RespondUnknownError(res);
        });
    }else{
        RespondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});


ModuleRoutes.get('/:type/:name', (req, res) => {
    const moduleName = req.params.name;
    const type = typeFromString(req.params.type);

    if(type){
        ModuleController.getModule(type, moduleName)
        .then((result)=>{
            switch(result.status){
                case Status.SUCCESS:
                    RespondFile(res, result.path, {
                                filename: moduleName,
                                callback: ModuleController.handleDownloadCleanup
                    });
                    break;
                case Status.NOT_FOUND:
                    RespondError(Status.NOT_FOUND, "Not Found", "No Module with the provided name was found", res);
                    break;
                case Status.INTERNAL_ERROR:
                    RespondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in GET /module: ${result.status}`);
                    RespondUnknownError(res);
            }
        })
        .catch((error)=>{
            Logger.error(`Error in GET /module: ${error}`);
            RespondUnknownError(res);
        });
    }else{
        RespondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});


ModuleRoutes.post('/:type',(req, res)=>{
    ModuleController.createModule(req)
    .then((created)=>{
        switch(created){
            case Status.CREATED:
                RespondCreated(res);
                break;
            case Status.CONFLICT:
                RespondError(Status.CONFLICT, "Duplicate", "Modules are not allowed duplicate names. Use a PUT request to update modules.", res);
                break;
            case Status.BAD_REQUEST:
                RespondError(Status.BAD_REQUEST, "Invalid Request", "Make sure the request has all required parameters and they are formatted correctly", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                Logger.error(`Unhandled Status in POST /module/${req.params.type}: ${created}`);
                RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        Logger.error(`Error in POST /module/${req.params.type}: ${error}`);
        RespondUnknownError(res);
    });
});

ModuleRoutes.put('/:type/:name', (req, res) => {
    const type = typeFromString(req.params.type);
    if(type){
        ModuleController.updateModule(req)
        .then((updated)=>{
            switch(updated){
                case Status.SUCCESS:
                    RespondSuccess(res);
                    break;
                case Status.BAD_REQUEST:
                    RespondError(Status.BAD_REQUEST, "Missing Attributes", "Missing or Malformed Attributes", res);
                    break;
                case Status.NOT_FOUND:
                    RespondError(Status.NOT_FOUND, "Not Found", "No Module with the provided name was found", res);
                    break;
                case Status.INTERNAL_ERROR:
                    RespondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in PUT /module/${req.params.type}/${req.params.name}: ${updated}`);
                    RespondUnknownError(res);
            }
        })
        .catch((error)=>{
            Logger.error(`Error in PUT /module/${req.params.type}/${req.params.name}: ${error}`);
            RespondUnknownError(res);
        });
    }else{
        RespondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});

ModuleRoutes.delete('/:type/:name', (req, res)=>{
    const type = typeFromString(req.params.type);
    if(type){
        ModuleController.deleteModule(type, req.params.name)
        .then((deleted)=>{
            switch(deleted){
                case Status.SUCCESS:
                    RespondSuccess(res);
                    break;
                case Status.NOT_FOUND:
                    RespondError(Status.NOT_FOUND, "Not Found", "No Module with the provided name was found", res);
                    break;
                case Status.INTERNAL_ERROR:
                    RespondUnknownError(res);
                    break;
                default:
                    Logger.error(`Unhandled Status in DELETE /module: ${deleted}`);
                    RespondUnknownError(res);
            }
        })
        .catch((error)=>{
            Logger.error(`Error in DELETE /module: ${error}`);
            RespondUnknownError(res);
        });
    }else{
        RespondError(Status.BAD_REQUEST, 'Invalid Module Type', `Module Type ${req.params.type} does not exists`, res);
    }
});

export { ModuleRoutes };
