
const randomUUID = require('crypto').randomUUID;

class  SimConfigManager_Local{
    constructor(ConfigRepo){
        this._ConfigRepo = ConfigRepo
    }

    async CreateConfig(configJSON, paramsJSON){
        const configID = randomUUID();
        this._ConfigRepo.CreateSimConfig(configID, configJSON, paramsJSON);
        return configID;
    }
}

module.exports = SimConfigManager_Local;