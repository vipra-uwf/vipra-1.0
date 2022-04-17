
class ConfigRepo_NoSave{
    
    #configs;

    constructor(){
        this.#configs = new Map();
    }

    async GetConfig(configID){
        return this.#configs.get(configID);
    }

    // TODO: change this to return a status on whether it was successful
    async CreateSimConfig(configID, configJSON){
        this.#configs.set(configID, configJSON);
        return true;
    }

    // TODO doesn't check for errors
    async DeleteSimConfig(configID){
        this.#configs.delete(configID);
        return true;
    }
}


module.exports = ConfigRepo_NoSave;