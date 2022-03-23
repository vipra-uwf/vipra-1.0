
const { randomUUID } = require('crypto')

class  SimConfigManager_NoSave{
    
    #ConfigRepo;

    constructor(ConfigRepo){
        this.#ConfigRepo = ConfigRepo;
    }

    async StageConfig(configID){
        // NOTE: already staged, just here for completeness -RG
    }

    async CreateConfig(configJSON, paramsJSON){
        const configID = randomUUID();
        this.#ConfigRepo.CreateSimConfig(configID, configJSON, paramsJSON);
        return configID;
    }
}

module.exports = SimConfigManager_NoSave;