
const { randomUUID } = require('crypto')

class  SimConfigManager_NoSave{
    
    #ConfigRepo;

    constructor(ConfigRepo){
        this.#ConfigRepo = ConfigRepo;
    }

    async StageConfig(configID){
        this.#ConfigRepo.StageConfig(configID);
    }

    async UnStage(configID){
        this.#ConfigRepo.DeleteSimConfig(configID);
    }

    async CreateConfig(configJSON, paramsJSON){
        const configID = randomUUID();
        this.#ConfigRepo.CreateSimConfig(configID, configJSON, paramsJSON);
        return configID;
    }
}

module.exports = SimConfigManager_NoSave;