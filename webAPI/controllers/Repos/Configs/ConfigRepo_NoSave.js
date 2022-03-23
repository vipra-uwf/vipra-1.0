
const fs                    = require('fs');
const { INPUT_DATA_PATH }   = require('../../../configurations/File_Paths');


class ConfigRepo_Local{
    constructor(){}

    StageSimConfig(configID){}

    CreateSimConfig(configID, configJSON, paramsJSON){
        this.#CREATE_FOLDER(configID);
        this.#CREATE_SIM_PARAMS(configID, paramsJSON);
        const filePath = INPUT_DATA_PATH.concat('/', configID, '/sim_config.json');
        return fs.writeFileSync(filePath, JSON.stringify(configJSON));
    }

    DeleteSimConfig(configID){
        const folderPath = INPUT_DATA_PATH.concat('/', configID);
        fs.rmdir(folderPath, {recursive: true});
    }

    #CREATE_FOLDER(configID){
        const folderPath = INPUT_DATA_PATH.concat('/', configID);
        return fs.mkdirSync(folderPath);
    }

    #CREATE_SIM_PARAMS(configID, paramsJSON){
        const filePath = INPUT_DATA_PATH.concat('/', configID, '/sim_params.json');
        return fs.writeFileSync(filePath, JSON.stringify(paramsJSON));
    }
}


module.exports = ConfigRepo_Local;