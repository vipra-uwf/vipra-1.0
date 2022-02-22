
const fs = require('fs');
const { SIM_OPTIONS_PATH, INPUT_DATA_PATH } = require('../configurations/File_Paths');

class InputFileCreator_Local{
    constructor(){

    }

    async SaveSimConfig(configID, configJSON){
        this._CREATE_FOLDER(configID);
        this._CREATE_SIM_CONFIG(configID, configJSON);
        this._CREATE_INPUT_FILES(configID);
    }

    _CREATE_FOLDER(configID){
        const folderPath = INPUT_DATA_PATH.concat('/', configID);
        return fs.mkdirSync(folderPath);
    }

    _CREATE_SIM_CONFIG(configID, configJSON){
        const filePath = INPUT_DATA_PATH.concat('/', configID, '/sim_config.json');
        return fs.writeFileSync(filePath, JSON.stringify(configJSON));
    }

    // TODO input_files.json is hard coded
    _CREATE_INPUT_FILES(configID){
        const filePath = INPUT_DATA_PATH.concat('/', configID, '/input_files.json');
        return fs.writeFileSync(filePath, "{\"pedestrian_set\": \"pedestrian_set\",\"obstacle_set\": \"obstacle_set\",\"simulation_parameters\": \"simulation_parameters\",\"sim_configuration\": \"input_data/"+configID+"/config_" + configID + ".json\",\"configuration_options\": \"input_data/sim_options.json\"}");
    }
}

module.exports = InputFileCreator_Local;