
const { response } = require('express');
const fs = require('fs');
const { SIM_OPTIONS_PATH, INPUT_DATA_PATH, OUTPUT_DATA_PATH, SIM_RUN_PATH, SIM_COMPILE_PATH } = require('./../File_Paths');

// TODO remove console logs in this file -RG



// TODO This is blocking -RG
const createConfigFolder = (configID, response) =>{
    console.log('Create Config Folder');
    const folderPath = INPUT_DATA_PATH.concat('/', configID);
    if(!fs.existsSync(folderPath)){
        fs.mkdirSync(folderPath, (err) =>{
            if(err){
                response.status(500).send("Error Creating Config Folders");
            }
        });
    }
}


// TODO This is hardcoded and needs updated at some point -RG
// TODO This is blocking -RG
const writeInput_Files = (configID, response) => {
    const inputFile = INPUT_DATA_PATH.concat('/', configID, '/input_files.json');
    fs.writeFileSync(inputFile ,"{\"pedestrian_set\": \"pedestrian_set\",\"obstacle_set\": \"obstacle_set\",\"simulation_parameters\": \"simulation_parameters\",\"sim_configuration\": \"input_data/"+configID+"/config_" + configID + ".json\",\"configuration_options\": \"input_data/sim_options.json\"}",
    (err)=>{
        if(err){
            console.log(err);
            response.status(500).send("Eror Creating Config Files");
        }else{
            response.json({'configID': configID});
        }
    });
}

// TODO This is blocking -RG
const writeConfigToFolder = (configID, configJSON, response) =>{
    console.log('Write to config folder');
    const configFile = INPUT_DATA_PATH.concat('/', configID, '/config_', configID, '.json');
    fs.writeFileSync(configFile, JSON.stringify(configJSON), (err)=>{
        if(err){
            response.status(500).send("Error Creating Config Files");
        }
    });
}

// TODO This is blocking -RG
const createConfigFiles = (configID, configJSON, response) =>{
    console.log('Create Config Files');
    createConfigFolder(configID, response);
    writeConfigToFolder(configID, configJSON, response);
    writeInput_Files(configID, response);
    response.json({'configID': configID});
}


module.exports = {
    createConfigFiles
}