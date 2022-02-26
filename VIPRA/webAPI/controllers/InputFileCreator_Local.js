
const fs = require('fs');
const { INPUT_DATA_PATH } = require('../configurations/File_Paths');

class InputFileCreator_Local{
    constructor(){

    }

    async SaveSimConfig(configID, configJSON, paramsJSON){
        this._CREATE_FOLDER(configID);
        this._CREATE_SIM_CONFIG(configID, configJSON);
        this._CREATE_SIM_PARAMS(configID, paramsJSON);
    }

    _CREATE_FOLDER(configID){
        const folderPath = INPUT_DATA_PATH.concat('/', configID);
        return fs.mkdirSync(folderPath);
    }

    _CREATE_SIM_CONFIG(configID, configJSON){
        const filePath = INPUT_DATA_PATH.concat('/', configID, '/sim_config.json');
        return fs.writeFileSync(filePath, JSON.stringify(configJSON));
    }

    _CREATE_SIM_PARAMS(configID, paramsJSON){
        const filePath = INPUT_DATA_PATH.concat('/', configID, '/sim_params.json');
        return fs.writeFileSync(filePath, JSON.stringify(paramsJSON));
    }

    // Leaving this here for the moment -RG
    // _CREATE_INPUT_FILES(configID){
    //     const filePath = INPUT_DATA_PATH.concat('/', configID, '/input_files.json');
    //     return fs.writeFileSync(filePath, "{\"pedestrian_set\": \"pedestrian_set\",\"obstacle_set\": \"obstacle_set\",\"simulation_parameters\": \"simulation_parameters\",\"sim_configuration\": \"input_data/"+configID+"/config_" + configID + ".json\",\"configuration_options\": \"input_data/sim_options.json\"}");
    // }
}

module.exports = InputFileCreator_Local;