const { Status } = require('../../../configurations/Status');


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
        return Status.SUCCESS;
    }

    async DeleteSimConfig(configID){
        if(this.#configs.delete(configID)){
            return Status.SUCCESS;
        }else{
            return Status.NOT_FOUND;
        }
    }
}


module.exports = ConfigRepo_NoSave;