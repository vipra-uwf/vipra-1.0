const express                                       = require('express');
const bodyParser                                    = require('body-parser');

const { checkConfig }                               = require('../middleware/checkConfig');
const { checkConfigID }                             = require('../middleware/checkConfigID');
const { checkPermissions }                          = require('../middleware/checkPermissions');

const config                                        = require('../configurations/config');

const router        = express.Router();

const SimManager    = new config.simulation.SimManager();
const UpdateManager = new config.simulation.UpdateManager(SimManager);

const ConfigRepo    = new config.repos.ConfigRepo();
const ConfigManager = new config.simulation.ConfigManager(ConfigRepo);

const BehaviorRepo      = new config.repos.BehaviorRepo(config.database.BehaviorDB_Con);
const BehaviorManager   = new config.behavior.BehaviorManager(BehaviorRepo);

router.use(bodyParser.json());
router.use(bodyParser.urlencoded({extended: true}));

router.get("/sim", checkPermissions, (req, res) =>{
	SimManager.SendSimOptions(res);
});

// NOTE: SIMOPTIONS is assumed to be normalised through checkConfig -RG
router.post("/sim", checkConfig, checkPermissions, (req, res) =>{
    ConfigManager.CreateConfig(req.body.sim_config, req.body.sim_params, res)
    .then((configID)=>{
        res.status(200).json({'configID': configID});
    })
    .catch((err)=>{
        console.log('[ERROR] Error in CreateConfig: ' + err);
        res.status(500).send('Unable to create config files');
    });
});


router.put("/sim", checkConfig, checkPermissions, (req, res) =>{
    // TODO add route to update configs
    res.status(400).json({message: "Unable to PUT /api/sim"});
});


router.get("/sim/start/:configID", checkConfigID, checkPermissions, (req, res)=>{
    const configID = req.params.configID;
    SimManager.StartSim(configID)
    .then(()=>{
        res.status(200).json({'configID': configID});
    })
    .catch(()=>{
        res.status(500).send('Unable to start simulation');
    });
});


router.get("/sim/updates/:configID", checkConfigID, checkPermissions, (req, res) =>{
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
    BehaviorManager.CreateBehavior(req.body.behavior)
    .then((created)=>{
        if(created){
            res.status(200).json({message: "Behavior Created"});
        }else{
            res.status(400).json({error: "Invalid Request", "detail": "Invalid Behavior Parameters or Behavior already exists, to update use PUT request"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Create Behavior: " + err);
        res.status(500).json({error: "Unable to create behavior"});
    });
});

router.put("/sim/behaviors", (req, res)=>{
    BehaviorManager.UpdateBehavior(req.body.behavior)
    .then((updated)=>{
        if(updated){
            res.status(200).json({message: "Behavior Updated"});
        }else{
            res.status(404).json({error: "Invalid Request", "detail": "No Behavior with provided name"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Create Behavior: " + err);
        res.status(500).json({error: "Unable to create behavior"});
    });
});

router.delete("/sim/behaviors/:name", (req, res)=>{
    BehaviorManager.DeleteBehavior(req.params.name)
    .then((deleted)=>{
        if(deleted){
            res.status(200).json({message: `${req.params.name} Deleted`});
        }else{
            res.status(404).json({error: "Bad Request", "detail": "No Behavior with provided name"}); 
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Delete Behavior: " + err);
        res.status(500).json({message: "Unable to delete behavior"});
    });
})

module.exports = router