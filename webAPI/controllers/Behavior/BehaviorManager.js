
const { WriteNewFile } = require('../Files/FileOperations');
const { BEHAVIOR_FOLDER_PATH } = require('../../configurations/File_Paths')

const { Status } = require('../../configurations/Status');



// TODO Cache behaviors and keep track of whether they are up to date etc.

class BehaviorController{

    #repo;

    constructor(behaviorRepo){
        this.#repo = behaviorRepo;
    }

    #CheckNewBehavior(behavior){
        if(!(behavior.name && behavior.content && behavior.publish)){
            return false;
        }
        return true;
    }

    async CreateBehavior(behaviorJSON, auth){
        if(auth === null){
            return Status.UNAUTHORIZED;
        }
        if(this.#CheckNewBehavior(behaviorJSON)){
            const name = behaviorJSON.name;
            const content = behaviorJSON.content;
            const publish = behaviorJSON.publish;
            const creator = auth.email;
            const saved = await this.#repo.Create(name, content, creator, publish);
            if(saved){
                return Status.CREATED;
            }else{
                return Status.BAD_REQUEST;
            }
        }else{
            return Status.BAD_REQUEST;
        }
    }

    async UpdateBehavior(behaviorJSON, auth){
        if(auth){
            const name = behaviorJSON.name;
            const content = behaviorJSON.content;
            const publish = behaviorJSON.publish;
            if(name && (content || publish)){
                const isCreator = await this.#isCreator(name, auth) 
                switch(isCreator){
                    case Status.SUCCESS:
                        const updated = await this.#repo.Update(name, content, publish);
                        if(updated){
                            return Status.SUCCESS;
                        }else{
                            return Status.NOT_FOUND;
                        }
                        break;
                    default:
                        return isCreator;
                }
            }else{
                return Status.BAD_REQUEST;
            }
        }else{
            return Status.UNAUTHORIZED;
        }
    }

    async UnStageBehavior(behaviorName){
        // TODO remove the behavior, low priority as it doesn't mess anything up with them being there -RG
        return Status.SUCCESS;
    }

    async #isCreator(behaviorName, auth){
        if(!auth){
            return Status.UNAUTHORIZED;
        }
        const behavior = await this.#repo.GetBehavior(behaviorName);
        if(behavior){
            if(auth.email === behavior.creator){
                return Status.SUCCESS;
            }else{
                return Status.FORBIDDEN;
            }
        }else{
            return Status.NOT_FOUND;
        }
    }

    async StageBehavior(behaviorName, stagePath){
        const behaviorJSON = await this.#repo.GetBehavior(behaviorName);
        if(behaviorJSON){
            if(!behaviorJSON.publish){
                return Status.FORBIDDEN;
            }
            if(WriteNewFile(behaviorJSON.content, stagePath.concat('/', behaviorName, '.behavior'))){
                return Status.SUCCESS;
            }else{
                return Status.INTERNAL_ERROR;
            }
        }else{
            return Status.NOT_FOUND;
        }
    }

    async DeleteBehavior(name, auth){
        if(!auth){
            return Status.UNAUTHORIZED;
        }
        const isCreator = await this.#isCreator(name, auth);
        if(isCreator === Status.SUCCESS){
            return await this.#repo.Delete(name);
        }else{
            return isCreator;
        }
    }

    async GetBehaviorOptions(auth){
        return await this.#repo.GetOptions(auth);
    }
}

module.exports = BehaviorController;