
// Creates router for /api routes -RG


// TODO remove console logging from this file

const express                                       = require('express');

const { checkOptions }                              = require('./../middleware/optionsCheck.js');
const { sendSimOptions, StartSim, setSimConfig }    = require('./../controllers/simulationController.js');
const { redirectToUpdates, provideUpdates }         = require('./../controllers/apiControllers.js');
const bodyParser                                    = require('body-parser');

const router = express.Router();

router.use(bodyParser.json());
router.use(bodyParser.urlencoded({extended: true}));

router.get("/", (req, res) =>{
	sendSimOptions(res);
});


// TODO make method that runs the simulation -RG
router.post("/sim", checkOptions, (req, res) =>{
    console.log("Received Config");
	let configID = setSimConfig(req.body.SIMOPTIONS);
    let pid = StartSim(configID);
    
    redirectToUpdates(res, pid);
});

router.get("/sim/updates", (req, res) =>{
    // TODO make function to setup SSE -RG
    const pid = req.query.PID;
    provideUpdates(res, pid);
});

module.exports = router