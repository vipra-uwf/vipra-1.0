import express      from "express";

import { BehaviorsContoller }   from "../controllers/behavior/BehaviorsController";
import { config }               from "../configuration/config";
import { Status }               from "../data_models/Status";
import { RespondError, RespondUnknownError, RespondSuccess, RespondBehavior, RespondCreated }       from "../util/Responses";
import { Logger } from "../logging/Logging";


const BehaviorRoutes : express.Router = express.Router();

const behaviorRepo = config.Behavior.BehaviorRepo();
behaviorRepo.connect(config.Behavior.DB_URI);

const BehaviorController : BehaviorsContoller = new BehaviorsContoller(behaviorRepo);


BehaviorRoutes.get('/', (req, res)=>{
    BehaviorController.getOptions()
    .then((options)=>{
        if(options !== null){
            res.status(Status.SUCCESS).json({
               data: options
            });
        }else{
            RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        Logger.error(`Error in get /behavior: ${error}`);
        RespondUnknownError(res);
    });
});


BehaviorRoutes.get('/:name', (req : express.Request<{name: string}>, res)=>{
    BehaviorController.getBehavior(req.params.name)
    .then((behavior)=>{
        switch(behavior.status){
            case Status.SUCCESS:
                RespondBehavior(res, behavior.behavior);
                break;
            case Status.NOT_FOUND:
                RespondError(Status.NOT_FOUND, "Not Found", "No Behavior with the provided name was found", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                Logger.error(` Unhandled Status in GET /:name: ${behavior.status}`);
                RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        Logger.error(` Error in GET /:name : ${error}`);
        RespondUnknownError(res);
    });
});


// TODO ?? allow for file upload to create behaviors ?? -RG
BehaviorRoutes.post('/', (req, res)=>{
    if(!req.body.behavior){
        RespondError(Status.BAD_REQUEST, "No Behavior", "No Behavior was provided with the request", res);
        return;
    }

    BehaviorController.createBehavior(req.body.behavior)
    .then((created) =>{
        res.status(created);
        switch(created){
            case Status.CREATED:
                RespondCreated(res);
                break;
            case Status.BAD_REQUEST:
                RespondError(created, "Improper Format", "Behaviors require attributes: name, content, creator, and publish", res);
                break;
            case Status.CONFLICT:
                RespondError(created, "Duplicate Name", "Duplicate Behavior Names are not allowed. Use a PUT request to update behaviors", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                Logger.error(` Unhandled Status in POST /behavior : ${created}`);
                RespondUnknownError(res);
                break;
        }
    })
    .catch((error)=>{
        Logger.error(` Error in POST /Behavior ${error}`);
        RespondUnknownError(res);
    });
});


// TODO NEXT change this to handle the name in the params rather than the body -RG
BehaviorRoutes.put('/:name', (req : express.Request<{}, {}, {behavior: {name:string, content?:string, publish?:boolean}}, {}>, res)=>{

    if(!req.body.behavior){
        RespondError(Status.BAD_REQUEST, "Missing Behavior", "No Behavior was provided with the request", res);
        return;
    }

    const bName = req.body.behavior.name;
    const bContent = req.body.behavior.content;
    const bPublish = req.body.behavior.publish;

    if(!bName || (!bContent && (bPublish === undefined))){
        RespondError(Status.BAD_REQUEST, "Missing Attributes", "Request requires: name, and content or publish", res);
        return;
    }

    BehaviorController.updateBehavior(bName, bContent, bPublish)
    .then((updated)=>{
        res.status(updated);
        switch(updated){
            case Status.SUCCESS:
                RespondCreated(res);
                break;
            case Status.BAD_REQUEST:
                RespondError(Status.BAD_REQUEST, "Invalid Request", "Check The Request Format and Retry", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                Logger.error(` Unhandled Status in PUT /behavior : ${updated}`);
                RespondUnknownError(res);
                break;
        }
    })
    .catch((error)=>{
        Logger.error(` Error in PUT /Behavior ${error}`);
        RespondUnknownError(res);
    });
});

BehaviorRoutes.delete('/:name', (req, res)=>{

    BehaviorController.deleteBehavior(req.params.name)
    .then((deleted)=>{
        res.status(deleted);
        switch(deleted){
            case Status.SUCCESS:
                RespondSuccess(res);
                break;
            case Status.NOT_FOUND:
                RespondError(deleted, "Not Found", "No Behavior with the provided name was found", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                Logger.error(` Unhandled Status in DELETE /behavior : ${deleted}`);
                RespondUnknownError(res);
                break;
        }
    })
    .catch((error)=>{
        Logger.error(` Error in deleteBehavior: ${error}`);
        RespondUnknownError(res);
    });
});

export { BehaviorRoutes };