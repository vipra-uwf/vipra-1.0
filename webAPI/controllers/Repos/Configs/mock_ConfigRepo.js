const { Status } = require('../../../configurations/Status');


class ConfigRepo_NoSave{
    
    #configs;
    #callCounts;

    constructor(){
        this.#configs = new Map();
    }

    Reset(){
        this.#callCounts = {
            "GetConfig": 0,
            "Create": 0,
            "Delete": 0
        };
        this.#configs.clear();
        this.#configs.set("first", {"sim_config": "test config", "sim_params": "test params"});
        this.#configs.set("second", {"sim_config": "second config", "sim_params": "second params"});
    }

    CallCounts(){
        return this.#callCounts;
    }

    async GetConfig(configID){
        this.#callCounts["GetConfig"]++;
        return this.#configs.get(configID);
    }

    async CreateSimConfig(configID, configJSON){
        this.#callCounts["Create"]++;
        this.#configs.set(configID, configJSON);
        return Status.SUCCESS;
    }

    async DeleteSimConfig(configID){
        this.#callCounts["Delete"]++;
        if(this.#configs.delete(configID)){
            return Status.SUCCESS;
        }else{
            return Status.NOT_FOUND;
        }
    }
}


module.exports = ConfigRepo_NoSave;