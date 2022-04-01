
const randomUUID = require('crypto').randomUUID;

class  SimConfigManager_Local{

    #ConfigRepo;

    constructor(ConfigRepo){
        this.#ConfigRepo = ConfigRepo;
    }

    // TODO add return value boolean -RG
    async StageConfig(configID){
        this.#ConfigRepo.StageSimConfig(configID);
    }

    // TODO add return value boolean -RG
    //          maybe status, if so update readme
    async UnStage(configID){
        return await this.#ConfigRepo.DeleteSimConfig(configID);
    }

    async CreateConfig(configJSON, paramsJSON){
        const configID = randomUUID();
        this.#ConfigRepo.CreateSimConfig(configID, configJSON, paramsJSON);
        return configID;
    }

    async DeleteConfig(configID){
        return await this.#ConfigRepo.DeleteSimConfig(configID);
    }
}

module.exports = SimConfigManager_Local;