import express      from "express";

import { BehaviorsContoller }   from "../controllers/behavior/BehaviorsController";
import { config }               from "../configuration/config";
import { Status }               from "../data_models/Status";
import { respondError, respondUnknownError, respondSuccess, respondBehavior, respondCreated }       from "../util/Responses";
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
            respondUnknownError(res);
        }
    })
    .catch((error)=>{
        Logger.error(`Error in get /behavior: ${error}`);
        respondUnknownError(res);
    });
});


BehaviorRoutes.get('/:name', (req : express.Request<{name: string}>, res)=>{
    BehaviorController.getBehavior(req.params.name)
    .then((behavior)=>{
        switch(behavior.status){
            case Status.SUCCESS:
                respondBehavior(res, behavior.behavior);
                break;
            case Status.NOT_FOUND:
                respondError(Status.NOT_FOUND, "Not Found", "No Behavior with the provided name was found", res);
                break;
            case Status.INTERNAL_ERROR:
                respondUnknownError(res);
                break;
            default:
                Logger.error(` Unhandled Status in GET /:name: ${behavior.status}`);
                respondUnknownError(res);
        }
    })
    .catch((error)=>{
        Logger.error(` Error in GET /:name : ${error}`);
        respondUnknownError(res);
    });
});


// TODO ?? allow for file upload to create behaviors ?? -RG
BehaviorRoutes.post('/', (req, res)=>{
    if(!req.body.behavior){
        respondError(Status.BAD_REQUEST, "No Behavior", "No Behavior was provided with the request", res);
        return;
    }

    BehaviorController.createBehavior(req.body.behavior)
    .then((created) =>{
        res.status(created);
        switch(created){
            case Status.CREATED:
                respondCreated(res);
                break;
            case Status.BAD_REQUEST:
                respondError(created, "Improper Format", "Behaviors require attributes: name, content, creator, and publish", res);
                break;
            case Status.CONFLICT:
                respondError(created, "Duplicate Name", "Duplicate Behavior Names are not allowed. Use a PUT request to update behaviors", res);
                break;
            case Status.INTERNAL_ERROR:
                respondUnknownError(res);
                break;
            default:
                Logger.error(` Unhandled Status in POST /behavior : ${created}`);
                respondUnknownError(res);
                break;
        }
    })
    .catch((error)=>{
        Logger.error(` Error in POST /Behavior ${error}`);
        respondUnknownError(res);
    });
});


// TODO NEXT change this to handle the name in the params rather than the body -RG
BehaviorRoutes.put('/:name', (req : express.Request<{}, {}, {behavior: {name:string; content?:string; publish?:boolean}}, {}>, res)=>{

    if(!req.body.behavior){
        respondError(Status.BAD_REQUEST, "Missing Behavior", "No Behavior was provided with the request", res);
        return;
    }

    const bName = req.body.behavior.name;
    const bContent = req.body.behavior.content;
    const bPublish = req.body.behavior.publish;

    if(!bName || (!bContent && (bPublish === undefined))){
        respondError(Status.BAD_REQUEST, "Missing Attributes", "Request requires: name, and content or publish", res);
        return;
    }

    BehaviorController.updateBehavior(bName, bContent, bPublish)
    .then((updated)=>{
        res.status(updated);
        switch(updated){
            case Status.SUCCESS:
                respondCreated(res);
                break;
            case Status.BAD_REQUEST:
                respondError(Status.BAD_REQUEST, "Invalid Request", "Check The Request Format and Retry", res);
                break;
            case Status.INTERNAL_ERROR:
                respondUnknownError(res);
                break;
            default:
                Logger.error(` Unhandled Status in PUT /behavior : ${updated}`);
                respondUnknownError(res);
                break;
        }
    })
    .catch((error)=>{
        Logger.error(` Error in PUT /Behavior ${error}`);
        respondUnknownError(res);
    });
});

BehaviorRoutes.delete('/:name', (req, res)=>{

    BehaviorController.deleteBehavior(req.params.name)
    .then((deleted)=>{
        res.status(deleted);
        switch(deleted){
            case Status.SUCCESS:
                respondSuccess(res);
                break;
            case Status.NOT_FOUND:
                respondError(deleted, "Not Found", "No Behavior with the provided name was found", res);
                break;
            case Status.INTERNAL_ERROR:
                respondUnknownError(res);
                break;
            default:
                Logger.error(` Unhandled Status in DELETE /behavior : ${deleted}`);
                respondUnknownError(res);
                break;
        }
    })
    .catch((error)=>{
        Logger.error(` Error in deleteBehavior: ${error}`);
        respondUnknownError(res);
    });
});

export { BehaviorRoutes };