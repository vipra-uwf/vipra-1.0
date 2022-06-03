import express      from "express";
// import multer       from "multer";

import { ModelsController }       from "../controllers/model/ModelsController";
import { config }               from "../configuration/config";
import { Status }               from "../data_models/Status";
import { RespondError, RespondUnknownError, RespondSuccess, RespondBehavior, RespondData }       from "../util/Responses";


const ModelRoutes : express.Router = express.Router();

const modelRepo = config.Model.ModelRepo();
// modelRepo.connect(config.Model.DB_URI);

const ModelController : ModelsController = new ModelsController(modelRepo);

ModelRoutes.get('/', (req, res)=>{
    // TODO
    ModelController.getOptions()
    .then((result)=>{
        switch(result.status){
            case Status.SUCCESS:
                RespondData(res, result.models);
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

ModelRoutes.get('/:name', (req, res)=>{
    // TODO
    ModelController.getModel(req.params.name)
    .then((model)=>{
        
    })
    .catch((error)=>{
        console.log(`[ERROR] Error in GET /model: ${error}`);
        RespondUnknownError(res);
    });
});

ModelRoutes.post('/', (req, res)=>{
    // TODO
    res.send("hello");
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
