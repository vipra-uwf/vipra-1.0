
const { WriteNewFile }  = require('../Files/FileOperations')
const { randomUUID }    = require('crypto');
const { Status }        = require('../../configurations/Status');


// TODO NEXT finish this

class  mock_ConfigManager{
    
    #ConfigRepo;
    #callCounts;

    constructor(ConfigRepo){
        this.#ConfigRepo = ConfigRepo;
        this.Reset();
    }

    Reset(){
        this.#callCounts = {
            "StageConfig": 0,
            "UnStageConfig": 0,
            "Create": 0,
            "Delete": 0,
        };
        if(this.#ConfigRepo.Reset){
            this.#ConfigRepo.Reset();
        }
    }

    CallCounts(){
        return this.#callCounts;
    }

    ConfigRepo(){
        return this.#ConfigRepo;
    }

    async StageConfig(configID, stagePath){
        
    }

    async UnStageConfig(configID){
        
    }


    async CreateConfig(configJSON, paramsJSON){
        
    }

    async DeleteConfig(configID){
        
    }
}

module.exports = mock_ConfigManager;