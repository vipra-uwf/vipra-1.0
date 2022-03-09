
// Creates router for /api routes -RG

const express                                       = require('express');
const bodyParser                                    = require('body-parser');

const { checkOptions }                              = require('../middleware/optionsCheck');
const { checkConfigID }                             = require('../middleware/checkConfigID');
const { checkPermissions }                          = require('../middleware/checkPermissions');

const config                                        = require('../configurations/config');


const router        = express.Router();
const SimManager    = new config.simulation.SimManager();
const UpdateManager = new config.simulation.UpdateManager(SimManager);
const ConfigRepo    = new config.repos.ConfigRepo();
const ConfigManager = new config.simulation.ConfigManager(ConfigRepo);

router.use(bodyParser.json());
router.use(bodyParser.urlencoded({extended: true}));

router.get("/", checkPermissions, (req, res) =>{
	SimManager.SendSimOptions(res);
});

// NOTE: SIMOPTIONS is assumed to be normalised through checkOptions -RG
router.post("/sim", checkOptions, checkPermissions, (req, res) =>{
    ConfigManager.CreateConfig(req.body.sim_config, req.body.sim_params, res)
    .then((configID)=>{
        res.status(200).json({'configID': configID});
    })
    .catch((err)=>{
        console.log('[ERROR] Error in CreateConfig: ' + err);
        res.status(500).send('Unable to create config files');
    });
});


router.put("/sim", checkOptions, checkPermissions, (req, res) =>{
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

module.exports = router