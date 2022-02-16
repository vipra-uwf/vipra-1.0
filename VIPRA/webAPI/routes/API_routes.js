const { Console } = require('console');
const express = require('express');
const fs = require('fs');
const path = require('path');
const bodyParser = require('body-parser')
const router = express.Router();
const exec = require("child_process").exec;

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


// TODO Might try to send output data even if the simulation errors out
const simulation = path.resolve(__dirname, './../run');
const runSim = (res)=>{
    let ps = exec(simulation, (err, stdout, stderr)=>{
        if(err){
            console.log(err);
        }
        if(stdout){
            console.log(stdout);
        }
        if(stderr){
            console.log(stderr);
        }
    }).on('close', ()=>{
        console.log("close");
        const output = fs.readFileSync(output_data_path);
        res.send(output);
    });

    ps.stdout.on('data', (data)=>{
        console.log(data);
    });
    ps.stderr.on('data', (data)=>{
        console.log(data)
    })
}


// TODO run the json through a middleware to make sure its correct
router.post("/api", (req, res) =>{
	// user sends json of options for their sim in requests body simoptions
	const options = req.body.SIMOPTIONS;

    console.log(JSON.stringify(options));

	// run the code gen with the options
	fs.writeFile(input_data_options, JSON.stringify(options), 'utf-8', (err)=>{
		
	});

    runSim(res);
});


module.exports = router


// TODO currently only one person can use this at a time
// TODO organize this into controllers and routes