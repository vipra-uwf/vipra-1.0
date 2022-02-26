
// Creates router for /api routes -RG

const express                                       = require('express');
const bodyParser                                    = require('body-parser');

const { checkOptions }                              = require('./../middleware/optionsCheck');
const { checkConfigID }                             = require('../middleware/checkConfigID');

const config                                        = require('./../configurations/config');
const FileCreator_Type                              = config.fileIO.FileCreator;
const SimManager_Type                               = config.simulation.SimManager;
const IDManager_Type                                = config.simulation.IDManager;
const UpdateManager_Type                            = config.simulation.UpdateManager;


const router        = express.Router();
const SimManager    = new SimManager_Type();
const FileCreator   = new FileCreator_Type();
const IDManager     = new IDManager_Type();
const UpdateManager = new UpdateManager_Type(SimManager);

router.use(bodyParser.json());
router.use(bodyParser.urlencoded({extended: true}));

router.get("/", (req, res) =>{
	SimManager.SendSimOptions(res);
});


// NOTE: SIMOPTIONS is assumed to be normalised through checkOptions -RG
router.post("/sim", checkOptions, (req, res) =>{
    const configID = IDManager.GetID(req);
    FileCreator.SaveSimConfig(configID, req.body.sim_config, req.body.sim_params, res)
    .then(()=>{
        res.status(200).json({'configID': configID});
    })
    .catch(()=>{
        res.status(500).send('Unable to create config files');
    });
});


// TODO doesn't properly respond that the task has been started
router.get("/sim/start", checkConfigID, (req, res)=>{
    const configID = IDManager.GetID(req);
    SimManager.StartSim(configID)
    .then(()=>{
        res.status(200).json({'configID': configID});
    })
    .catch(()=>{
        res.status(500).send('Unable to start simulation');
    });
});


router.get("/sim/updates/:configID", checkConfigID, (req, res) =>{
    console.log(req.params.configID);
    UpdateManager.ProvideUpdates(req.params.configID, res)
    .catch((err)=>{
        res.end("An Error Occured: " + err);
    });
});

module.exports = router