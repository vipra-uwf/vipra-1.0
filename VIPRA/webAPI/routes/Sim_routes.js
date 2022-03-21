const express                    = require('express');
const bodyParser                 = require('body-parser');

const { checkConfig }            = require('../middleware/checkConfig');
const { checkConfigID }          = require('../middleware/checkConfigID');
const { authenticate }           = require('../middleware/authenticate');

const { Status }                 = require('../configurations/Status')

const config                     = require('../configurations/config');

const router        = express.Router();

const SimManager    = new config.simulation.SimManager();
const UpdateManager = new config.simulation.UpdateManager(SimManager);

const ConfigRepo    = new config.repos.ConfigRepo();
const ConfigManager = new config.simulation.ConfigManager(ConfigRepo);

const BehaviorRepo      = new config.repos.BehaviorRepo(config.database.BehaviorDB_Con);
const BehaviorManager   = new config.behavior.BehaviorManager(BehaviorRepo);

router.use(bodyParser.json());
router.use(bodyParser.urlencoded({extended: true}));

router.use(authenticate);

router.get("/sim", (req, res) =>{
	SimManager.SendSimOptions(res);
});

// NOTE: SIMOPTIONS is assumed to be normalised through checkConfig -RG
router.post("/sim", checkConfig, (req, res) =>{
    ConfigManager.CreateConfig(req.body.sim_config, req.body.sim_params, res)
    .then((configID)=>{
        res.status(200).json({'configID': configID});
    })
    .catch((err)=>{
        console.log('[ERROR] Error in CreateConfig: ' + err);
        res.status(500).send('Unable to create config files');
    });
});

router.put("/sim", checkConfig, (req, res) =>{
    // TODO add route to update configs
    res.status(400).json({message: "Unable to PUT /api/sim"});
});


router.get("/sim/start/:configID", checkConfigID, (req, res)=>{
    const configID = req.params.configID;
    SimManager.StartSim(configID)
    .then(()=>{
        res.status(200).json({'configID': configID});
    })
    .catch(()=>{
        res.status(500).send('Unable to start simulation');
    });
});


router.get("/sim/updates/:configID", checkConfigID, (req, res) =>{
    const configID = req.params.configID;
    UpdateManager.ProvideUpdates(configID, res)
    .catch((err)=>{
        console.log("[ERROR] Error in sim updates: " + err);
        res.status(500).json({message: "Unable to provide simulation Updates"})
    });
});


router.get("/sim/behaviors", (req, res)=>{
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
                res.status(404).json({error: "Invalid Request", detail: "No Behavior with provided name"});
                break;
            case Status.UNAUTHORIZED:
                res.status(401).json({error: "Unauthorized", detail: "Not authorized to access this resource"});
                break;
            case Status.INTERNAL_ERROR:
                res.status(500).json({message: "Unable to Create Behavior", detail: "An Unknown error occured on the server"});
                break;
            default:
                console.log(`[ERROR] Unhandled status in Create Behavior`);
                res.status(500).json({message: "Unable to Create Behavior", detail: "An Unknown error occured on the server"});
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
        if(deleted){
            res.status(200).json({message: `Behavior Deleted`});
        }else{
            res.status(404).json({error: "Bad Request", detail: "No Behavior with provided name"}); 
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Delete Behavior: " + err);
        res.status(500).json({error: "Unable to delete behavior", detail: "An Unknown error occured on the server"});
    });
})

module.exports = router