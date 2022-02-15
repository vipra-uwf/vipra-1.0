const { Console } = require('console');
const express = require('express');
const fs = require('fs');
const path = require('path');
const bodyParser = require('body-parser')
const router = express.Router();


const simulation = "../run";
const runSim = require("child_process").exec(process);



// TODO may not be async
const sim_options = fs.readFileSync(path.resolve(__dirname, './../../input_data/sim_options.json'));
const input_data_options = path.resolve(__dirname, './../../input_data/sim_config.json');

const output_data_path = path.resolve(__dirname, './../../output_data/pedestrian_trajectory.json');

router.use(bodyParser.json());
router.use(bodyParser.urlencoded({ extended: false }));

router.get("/api", (req, res) =>{
	// send sim_options.json
	res.send(JSON.parse(sim_options));
});

// TODO run the json through a middleware to make sure its correct
router.post("/api", (req, res) =>{
	// user sends json of options for their sim in requests body simoptions
	const options = req.body.SIMOPTIONS;

	// run the code gen with the options
	fs.writeFile(input_data_options, JSON.stringify(options), 'utf-8', (err)=>{
		
	});

	// run the simulation
	runSim.stdout.pipe(process)
    runSim.on('exit', ()=>{
        // simulation has finished
        // output data is in output_data
        // read the data
        // send it back

        const output =  fs.readFileSync(output_data_path);
        res.send(JSON.parse(output));

    })
});


module.exports = router


// TODO currently only one person can use this at a time
// TODO organize this into controllers and routes