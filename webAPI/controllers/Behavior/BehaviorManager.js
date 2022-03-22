
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
            if(name && (content || publish)){
                if(this.#isCreator(name, auth)){
                    const updated = await this.#repo.Update(name, content, publish);
                    if(updated){
                        return Status.SUCCESS;
                    }else{
                        return Status.NOT_FOUND;
                    }
                }
            }else{
                return Status.BAD_REQUEST;
            }
        }else{
            return Status.UNAUTHORIZED;
        }
    }

    async #isCreator(behaviorName, auth){
        const behavior = this.#repo.GetBehavior(behaviorName);
        if(behavior && auth){
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
        if(this.#isCreator(name, auth)){
            const deleted = await this.#repo.Delete(name);
            if(deleted){
                return Status.SUCCESS;
            }else{
                return Status.NOT_FOUND;
            }
        }else{
            return Status.UNAUTHORIZED;
        }
    }

    async GetBehaviorOptions(auth){
        // TODO show all published options and unpublished created by auth.email -RG
        if(auth){
            return await this.#repo.GetOptions();
        }else{
            return null
        }
    }
}

module.exports = BehaviorController;