
const { WriteNewFile }              = require('../Files/FileOperations')
const { randomUUID }    = require('crypto');

class  ConfigManager{
    
    #ConfigRepo;

    constructor(ConfigRepo){
        this.#ConfigRepo = ConfigRepo;
    }

    async StageConfig(configID, stagePath){
        const configJSON = await this.#ConfigRepo.GetConfig(configID);
        if(configJSON){
            try{
                await WriteNewFile(JSON.stringify(configJSON.sim_config), stagePath.concat('/sim_config.json'));
                await WriteNewFile(JSON.stringify(configJSON.sim_params), stagePath.concat('/sim_params.json'));
            }catch(err){
                console.log(`[ERROR] Error in StageConfig: ${err}`);
                return false;
            }
            return true;
        }else{
            return false;
        }
    }

    async UnStageConfig(configID){
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

module.exports = ConfigManager;