const { Console } = require('console');
const express = require('express');
const fs = require('fs');
const path = require('path');
const bodyParser = require('body-parser')
const router = express.Router();

const exec = require("child_process").exec;

const runSim = ()=>{
    console.log("Running Sim");
    let vipraProcess = exec('./../run');
    vipraProcess.stdout.on('data', function(data) {
            console.log(data);
    });
}

const input_data_options = path.resolve(__dirname, './../../input_data/sim_config.json');

const sim_options = fs.readFileSync(path.resolve(__dirname, './../../input_data/sim_options.json'));


router.use(bodyParser.json());
router.use(bodyParser.urlencoded({ extended: false }));

const home = async function (req, res) {
	res.send("Hello!\n");
}

router.get("/api", (req, res) =>{
	// send sim_options.json
	res.send(JSON.parse(sim_options));
});

// TODO run the json through a middleware to make sure its correct
router.post("/api", (req, res) =>{
	// user sends json of options for their sim in requests body simoptions
	const options = req.body.SIMOPTIONS;
	
	console.log(JSON.stringify(options));
	// run the code gen with the options
	fs.writeFile(input_data_options, JSON.stringify(options), 'utf-8', (err)=>{
		
	});

	// run the simulation
	runSim();

});


module.exports = router