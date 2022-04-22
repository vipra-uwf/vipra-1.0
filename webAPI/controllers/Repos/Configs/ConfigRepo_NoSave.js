
class ConfigRepo_NoSave{
    
    #configs;

    constructor(){
        this.#configs = new Map();
    }

    async GetConfig(configID){
        return this.#configs.get(configID);
    }

    async CreateSimConfig(configID, configJSON){
        this.#configs.set(configID, configJSON);
        return true;
    }

    async DeleteSimConfig(configID){
        return this.#configs.delete(configID);
    }
}


module.exports = ConfigRepo_NoSave;