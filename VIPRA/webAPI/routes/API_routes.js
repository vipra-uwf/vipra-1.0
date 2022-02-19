
// Creates router for /api routes -RG


// TODO remove console logging from this file

const express                                       = require('express');
const bodyParser                                    = require('body-parser');
const { randomUUID }                                = require('crypto');

const { sendSimOptions, StartSim }                  = require('./../controllers/simulationController');
const { provideUpdates }                            = require('./../controllers/apiController');
const { createConfigFiles }                         = require('./../controllers/fileController')

const { checkOptions }                              = require('./../middleware/optionsCheck');
const { checkUserID }                               = require('./../middleware/checkUserID');


const router = express.Router();

router.use(bodyParser.json());
router.use(bodyParser.urlencoded({extended: true}));

router.get("/", (req, res) =>{
	sendSimOptions(res);
});



// NOTE: might be able to change this to use indexes of options instead of bulky JSON -RG
// NOTE: configJSON is assumed to be normalised through checkOptions -RG
router.post("/sim", checkOptions, (req, res) =>{
    console.log("Received Config");
    let configID = randomUUID();
    createConfigFiles(configID, req.body.SIMOPTIONS, res);
});

// TODO doesn't properly respond that the task has been started
router.get("/sim/start", checkUserID, (req, res)=>{
    let configID = req.body.configID;
    console.log(configID);
    let started = StartSim(configID);
    if(started){
        res.json({'configID': configID});
    }else{
        res.status(500).send("Unable To Start Simulation");
    }
});

// TODO make function to setup SSE -RG
router.get("/sim/updates", checkUserID, (req, res) =>{
    const configID = req.body.configID;
    provideUpdates(res, configID);
});

module.exports = router