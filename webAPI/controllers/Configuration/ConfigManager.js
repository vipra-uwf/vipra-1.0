
const fs                = require('fs');
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
                fs.writeFileSync(stagePath.concat('/sim_config.json'), JSON.stringify(configJSON.sim_config));
                fs.writeFileSync(stagePath.concat('/sim_params.json'), JSON.stringify(configJSON.sim_params));
            }catch(err){
                console.log(`[ERROR] Error in StageConfig: ${err}`);
                return false;
            }
            return true;
        }else{
            return false;
        }
    }

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

module.exports = ConfigManager;