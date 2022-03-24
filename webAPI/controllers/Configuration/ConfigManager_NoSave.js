
const { randomUUID } = require('crypto')

class  SimConfigManager_NoSave{
    
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
        this.#ConfigRepo.DeleteSimConfig(configID);
    }

    async CreateConfig(configJSON, paramsJSON){
        const configID = randomUUID();
        this.#ConfigRepo.CreateSimConfig(configID, configJSON, paramsJSON);
        return configID;
    }

    // TODO add deletesimconfig -RG

}

module.exports = SimConfigManager_NoSave;