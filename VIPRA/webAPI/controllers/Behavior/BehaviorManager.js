
const fs = require('fs');
const { BEHAVIOR_FOLDER_PATH } = require('../../configurations/File_Paths')

const { Status } = require('../../configurations/Status');


class BehaviorController{

    #repo;

    constructor(behaviorRepo){
        this.#repo = behaviorRepo;
    }

    #CheckNewBehavior(behavior){
        if(behavior.name === null || behavior.content === null || behavior.publish === null){
            console.log("Behavior missing params");
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
                return Status.SUCCESS;
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
            if(name === null || (content === null && publish === null)){
                return Status.BAD_REQUEST;
            }
            if(this.#isCreator(name, auth)){
                const updated = await this.#repo.Update(name, content, publish);
                if(updated){
                    return Status.SUCCESS;
                }else{
                    return Status.BAD_REQUEST;
                }
            }
        }else{
            return Status.UNAUTHORIZED;
        }
    }

    async #isCreator(behaviorName, auth){
        const behavior = this.#repo.GetBehavior(behaviorName);
        if(behavior){
            return auth.email === behavior.creator;
        }
        return false;
    }

    async StageBehavior(behaviorName){
        const behaviorJSON = await this.#repo.Load(behaviorName);
        if(behaviorJSON){
            const filePath = BEHAVIOR_FOLDER_PATH.concat('/', behaviorJSON.name.concat('.behavior'));
            fs.writeFileSync(filePath, behaviorJSON.content);
            return behaviorJSON.name;
        }else{
            return null;
        }
    }

    async DeleteBehavior(name, auth){
        // TODO only delete if auth.email is creator -RG
        return await this.#repo.Delete(name);
    }

    async GetBehaviorOptions(auth){
        // TODO show all published options and unpublished created by auth.email -RG
        return await this.#repo.GetOptions();
    }
}

module.exports = BehaviorController;