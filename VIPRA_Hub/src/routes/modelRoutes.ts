import express      from "express";


import { ModelsController }     from "../controllers/model/ModelsController";
import { config }               from "../configuration/config";
import { Status }               from "../data_models/Status";

import { RespondError, RespondUnknownError, RespondSuccess, RespondFile, RespondData }       from "../util/Responses";


const ModelRoutes : express.Router = express.Router();

const modelRepo = config.Model.ModelRepo();
modelRepo.connect(config.Model.DB_URI);

const ModelController : ModelsController = new ModelsController(modelRepo, config.Model.Zip_Path);

ModelRoutes.get('/', (req, res)=>{
    // TODO
    ModelController.getOptions()
    .then((result)=>{
        switch(result.status){
            case Status.SUCCESS:
                RespondData(res, result.options);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                console.log(`[ERROR] Unhandled Status in GET /model : ${result.status}`);
                RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        console.log(`[ERROR] Error in GET /model : ${error}`);
        RespondUnknownError(res);
    });
});

ModelRoutes.get('/info/:name', (req, res)=>{
    ModelController.getModelInfo(req.params.name)
    .then((info)=>{
        switch(info.status){
            case Status.SUCCESS:
                RespondData(res, info.modelMeta);
                break;
            case Status.NOT_FOUND:
                RespondError(Status.NOT_FOUND, "Not Found", "No Model with the given name was found.", res);
                break;
            default:
                console.log(`[ERROR] Error Unhandled Status in /model/info: ${info.status}`);
                RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        console.log(`[ERROR] Error in GET /model/info: ${error}`);
        RespondUnknownError(res);
    });
});

ModelRoutes.get('/:name', (req, res)=>{
    // TODO
    ModelController.getModel(req.params.name)
    .then((result)=>{
        switch(result.status){
            case Status.SUCCESS:
                RespondFile(res, result.path);
                break;
            case Status.NOT_FOUND:
                RespondError(Status.NOT_FOUND, "Not Found", "No Model with the provided name was found", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                console.log(`[ERROR] Unhandled Status in GET /model: ${result.status}`);
                RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        console.log(`[ERROR] Error in GET /model: ${error}`);
        RespondUnknownError(res);
    });
});


// TODO client needs to have modelname as the first element in the form data, want to find a way to fix this -RG
ModelRoutes.post('/', (req, res)=>{
    ModelController.createModel(req)
    .then((created)=>{
        switch(created){
            case Status.SUCCESS:
                RespondSuccess(res);
                break;
            case Status.CONFLICT:
                RespondError(Status.CONFLICT, "Duplicate", "Models are not allowed duplicate names. Use a PUT request to update models.", res);
                break;
            case Status.BAD_REQUEST:
                RespondError(Status.BAD_REQUEST, "Invalid Request", "Models must be uploaded as two files: a .cpp and .hpp", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                console.log(`[ERROR] Unhandled Status in POST /model: ${created}`);
                RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        console.log(`[ERROR] Error in POST /model: ${error}`);
        RespondUnknownError(res);
    });
});

ModelRoutes.delete('/:name', (req, res)=>{
    ModelController.deleteModel(req.params.name)
    .then((deleted)=>{
        switch(deleted){
            case Status.SUCCESS:
                RespondSuccess(res);
                break;
            case Status.NOT_FOUND:
                RespondError(Status.NOT_FOUND, "Not Found", "No Model with the provided name was found", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                console.log(`[ERROR] Unhandled Status in DELETE /model: ${deleted}`);
                RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        console.log(`[ERROR] Error in DELETE /model: ${error}`);
        RespondUnknownError(res);
    });
});

export {ModelRoutes};
