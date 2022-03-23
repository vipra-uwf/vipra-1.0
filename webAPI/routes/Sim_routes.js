const express               = require('express');
const bodyParser            = require('body-parser');

const { checkConfig }       = require('../middleware/checkConfig');
const { checkConfigID }     = require('../middleware/checkConfigID');
const { authenticate }      = require('../middleware/authenticate');

const { Status }            = require('../configurations/Status')

const config                = require('../configurations/config');

const router                = express.Router();

const ConfigRepo        = new config.repos.ConfigRepo();
const ConfigManager     = new config.simulation.ConfigManager(ConfigRepo);

const BehaviorRepo      = new config.repos.BehaviorRepo(config.database.BehaviorDB_Con);
const BehaviorManager   = new config.behavior.BehaviorManager(BehaviorRepo);

const SimManager        = new config.simulation.SimManager(ConfigManager, BehaviorManager);
const UpdateManager     = new config.simulation.UpdateManager(SimManager);

router.use(bodyParser.json());
router.use(bodyParser.urlencoded({extended: true}));

router.use(authenticate);

router.get("/sim", (req, res) =>{
	SimManager.SendSimOptions(res);
});

router.post("/sim", checkConfig, (req, res) =>{
    SimManager.HandleSimRequest(req.body, req.Auth, res);
});

router.get("/sim/updates/:simID", checkConfigID, (req, res) =>{
    const simID = req.params.simID;
    UpdateManager.ProvideUpdates(simID, res, req.Auth)
    .catch((err)=>{
        console.log("[ERROR] Error in sim updates: " + err);
        res.status(500).json({message: "Unable to provide simulation Updates"})
    });
});


router.get("/sim/behaviors", (req, res)=>{
    // TODO return only published or auth made behaviors -RG
    BehaviorManager.GetBehaviorOptions()
    .then((options)=>{
        if(options){
            res.status(200).json({'data': options});
        }else{
            res.status(500).json({message: "Unable to load behaviors"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Load Behavior Options: " + err);
        res.status(500).json({message: "Unable to load behaviors"});
    });
});

router.post("/sim/behaviors", (req, res)=>{
    BehaviorManager.CreateBehavior(req.body.behavior, req.Auth)
    .then((created)=>{
        switch(created){
            case Status.SUCCESS:
                res.status(200).json({message: "Behavior Created"});
                break;
            case Status.BAD_REQUEST:
                res.status(400).json({error: "Invalid Request", detail: "Invalid Behavior Parameters or Behavior already exists, to update use PUT request"});
                break;
            case Status.UNAUTHORIZED:
                res.status(401).json({error: "Unauthorized", detail: "Not authorized to access this resource"});
                break;
            default:
                console.log(`[ERROR] Unhandled status in Create Behavior`);
                res.status(500).json({message: "Unable to Create Behavior", detail: "An Unknown error occured on the server"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Create Behavior: " + err);
        res.status(500).json({error: "Unable to Create Behavior", detail: "An Unknown error occured on the server"});
    });
});

router.put("/sim/behaviors", (req, res)=>{
    BehaviorManager.UpdateBehavior(req.body.behavior, req.Auth)
    .then((updated)=>{
        switch(updated){
            case Status.SUCCESS:
                res.status(200).json({message: "Behavior Updated"});
                break;
            case Status.BAD_REQUEST:
                res.status(400).json({error: "Bad Request", detail: "Missing Behavior Parameters"});
                break;
            case Status.NOT_FOUND:
                res.status(404).json({error: "Not Found", detail: "No Behavior with provided name"});
                break;
            case Status.UNAUTHORIZED:
                res.status(401).json({error: "Unauthorized", detail: "Not authorized to access this resource"});
                break;
            case Status.INTERNAL_ERROR:
                res.status(500).json({message: "Unable to Create Behavior", detail: "An Unknown error occured on the server"});
                break;
            default:
                console.log(`[ERROR] Unhandled status in Update Behavior`);
                res.status(500).json({message: "Unable to Update Behavior", detail: "An Unknown error occured on the server"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Create Behavior: " + err);
        res.status(500).json({error: "Unable to create behavior", detail: "An Unknown error occured on the server"});
    });
});

router.delete("/sim/behaviors/:name", (req, res)=>{
    BehaviorManager.DeleteBehavior(req.params.name)
    .then((deleted)=>{
        switch(deleted){
            case Status.SUCCESS:
                res.status(200).json({message: `Behavior Deleted`});
                break;
            case Status.BAD_REQUEST:
                res.status(400).json({error: "Bad Request", detail: "No Behavior with provided name"}); 
                break;
            case Status.NOT_FOUND:
                res.status(404).json({error: "Not Found", detail: "No Behavior with provided name"}); 
                break;
            case Status.UNAUTHORIZED:
                res.status(401).json({error: "Unauthorized", detail: "Not authorized to access this resource"});
                break;
            default:
                console.log(`[ERROR] Unhandled status in Delete Behavior`);
                res.status(500).json({message: "Unable to Delete Behavior", detail: "An Unknown error occured on the server"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Delete Behavior: " + err);
        res.status(500).json({error: "Unable to delete behavior", detail: "An Unknown error occured on the server"});
    });
});

module.exports = router