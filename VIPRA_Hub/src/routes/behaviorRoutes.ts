import express      from "express";
import { Request }  from "express";

import { BehaviorsContoller }   from "../controllers/behavior/BehaviorsController";
import { config }               from "../configuration/config";
import { Status }               from "../data_models/Status";
import { Behavior }             from "../data_models/Behavior";


const BehaviorRoutes : express.Router = express.Router();

const behaviorRepo = config.Behavior.BehaviorRepo();
behaviorRepo.connect(config.Behavior.DB_URI);

const BehaviorController : BehaviorsContoller = new BehaviorsContoller(behaviorRepo);

BehaviorRoutes.get('/', (req, res)=>{
    // TODO
    BehaviorController.getOptions()
    .then((options)=>{
        if(options !== null){
            res.status(Status.SUCCESS).json({
               data: options
            });
        }
        res.status(Status.INTERNAL_ERROR).json({ error: 'Unable to load options' });
    })
    .catch((error)=>{
        res.status(Status.INTERNAL_ERROR).json({ error: 'Unable to load options' });
    });
});

BehaviorRoutes.get('/:name', (req, res)=>{
    // TODO
});

BehaviorRoutes.post('/', (req, res)=>{
    // TODO
    if(!req.body.behavior){
        res.status(Status.BAD_REQUEST).json({ error: "No Behavior", detail: "No Behavior was provided with the request"});
        return;
    }

    BehaviorController.createBehavior(req.body.behavior)
    .then((created) =>{
        res.status(created);
        switch(created){
            case Status.CREATED:
                res.json({});
                break;
            case Status.BAD_REQUEST:
                res.json({ error: "Improper Format", detail: "Behaviors require attributes: name, content, creator, and publish"});
                break;
            case Status.CONFLICT:
                res.json({ error: "Duplicate Name", detail: "Duplicate Behavior Names are not allowed. Use a PUT request to update behaviors"});
                break;
            case Status.INTERNAL_ERROR:
                res.json({ error: "Unknown Error, Behavior not created"});
                break;
            default:
                console.log(`[ERROR] Unhandled Status in POST /behavior : ${created}`);
                res.status(Status.INTERNAL_ERROR).json({ error: "Unkown Error, Behavior not created"});
                break;
        }
    })
    .catch((error)=>{
        console.log(`[ERROR] Error in POST /Behavior ${error}`);
        res.status(Status.INTERNAL_ERROR).json({ error: "Unkown Error, Behavior not created"});
    });
});

BehaviorRoutes.put('/', (req : express.Request<{}, {}, {behavior: Behavior}>, res)=>{

    const behavior : Behavior = req.body.behavior;

    if(!behavior.name || (!behavior.content && !behavior.publish)){
        res.status(Status.BAD_REQUEST).json({error: "Missing Attributes", detail: "Request requires: name, and content or publish"});
    }

    BehaviorController.updateBehavior(req.body.behavior.name, )
    .then((updated)=>{
        res.status(updated);
        switch(updated){
            case Status.SUCCESS:
                res.json({});
                break;
            case Status.BAD_REQUEST:
                res.json({error: ""});
                break;
            case Status.INTERNAL_ERROR:
                break;
            default:
                console.log(`[ERROR] Unhandled Status in PUT /behavior : ${updated}`);
                res.status(Status.INTERNAL_ERROR).json({ error: "Unkown Error, Behavior not Updated"});
                break;
        }
    })
    .catch((error)=>{
        console.log(`[ERROR] Error in PUT /Behavior ${error}`);
        res.status(Status.INTERNAL_ERROR).json({ error: "Unkown Error, Behavior not Updated"});
    });
});

BehaviorRoutes.delete('/', (req : express.Request<{},{},{},{name: string}>, res)=>{
    if(!req.query.name){
        res.status(Status.BAD_REQUEST).json({ error: "No Behavior Name", detail: "No Behavior Name was provided with the request"});
        return;
    }

    BehaviorController.deleteBehavior(req.query.name)
    .then((deleted)=>{
        res.status(deleted);
        switch(deleted){
            case Status.SUCCESS:
                res.json({});
                break;
            case Status.NOT_FOUND:
                res.json({error: "Not Found", detail: "No Behavior with the provided name was found"});
                break;
            case Status.INTERNAL_ERROR:
                res.json({ error: "Unkown Error", detail: "An Unknown error occured. The Behavior may not have been deleted"});
                break;
            default:
                console.log(`[ERROR] Unhandled Status in DELETE /behavior : ${deleted}`);
                res.status(Status.INTERNAL_ERROR).json({ error: "Unkown Error", detail: "An Unknown error occured. The Behavior may not have been deleted"});
                break;
        }
    })
    .catch((error)=>{
        console.log(`[ERROR] Error in deleteBehavior: ${error}`);
        res.status(Status.INTERNAL_ERROR).json({ error: "Unkown Error", detail: "An Unknown error occured. The Behavior may not have been deleted"});
    });
});

export { BehaviorRoutes };