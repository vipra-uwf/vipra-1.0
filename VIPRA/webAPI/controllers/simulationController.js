
// All Functions for setting up and running a simulation


const { SIM_OPTIONS_PATH, SIM_CONFIG_PATH, OUTPUT_DATA_PATH, SIM_RUN_PATH } = require('./../File_Paths.js');
const spawn                                                                 = require('child_process').spawn;
const fs                                                                    = require('fs');

// TODO remove console logs from this file


// TODO Spawn a proper process and feed it with the unique id for the configuration chosen -RG
const spawnSimulation = (id) => {
    spawn(SIM_RUN_PATH, [id]);
}


const sendSimOptions = async (response)=>{

    //TODO on error send proper response -RG
    console.log("Sending Options");

    return fs.readFile(SIM_OPTIONS_PATH, (err, data)=>{
        if(err){
            response.send("Error Reading From Options File");
        }else{
            response.send(data);
        }
    });
}

// TODO actually run the simulation and get the pid
const StartSim = (configID) => {
    console.log("STARTING SIMULATION");
    //spawnSimulation(configID);
}


// TODO generate unique ID -RG
// NOTE: might be able to change this to use indexes of options instead of bulky JSON -RG
// NOTE: configJSON is assumed to be normalised through -RG
const setSimConfig = (configJSON)=>{
    console.log("Setting Simulation Config File");
    let id = 'TEMP_ID'
    fs.writeFile(SIM_CONFIG_PATH.concat(id, '.json'), JSON.stringify(configJSON), (err) =>{
        return undefined;
    });
    return id
}


module.exports = 
{
    sendSimOptions,
    StartSim,
    setSimConfig
}