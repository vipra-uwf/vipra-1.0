
const { WriteNewFile } = require('../Files/FileOperations');
const { BEHAVIOR_FOLDER_PATH } = require('../../configurations/File_Paths')

const { Status } = require('../../configurations/Status');



// TODO NEXT this

class mock_BehaviorController{

    #repo;
    #callCounts;

    constructor(behaviorRepo){
        this.#repo = behaviorRepo;
    }

    Reset(){
        this.#callCounts = {
            "Create": 0,
            "Update": 0,
            "Stage": 0,
            "UnStage": 0,
            "Delete": 0,
            "GetOptions": 0
        };

        if(this.#repo.Reset){
            this.#repo.Reset();
        }
    }

    #CheckNewBehavior(behavior){

    }

    async CreateBehavior(behaviorJSON, auth){
        
    }

    async UpdateBehavior(behaviorJSON, auth){
        
    }

    async UnStageBehavior(behaviorName){
        return Status.SUCCESS;
    }

    async #isCreator(behaviorName, auth){
        
    }

    async StageBehavior(behaviorName, stagePath){
        
    }

    async DeleteBehavior(name, auth){
        
    }

    async GetBehaviorOptions(auth){
        
    }
}

module.exports = mock_BehaviorController;