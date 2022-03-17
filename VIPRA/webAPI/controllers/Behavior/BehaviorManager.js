
const fs = require('fs');
const { BEHAVIOR_FOLDER_PATH } = require('../../configurations/File_Paths')


class BehaviorController{
    constructor(behaviorRepo){
        this._repo = behaviorRepo;
    }

    _CheckNewBehavior(behavior){
        if(behavior.name === null || behavior.content === null || behavior.publish === null || behavior.creator === null){
            console.log("Behavior missing params");
            return false;
        }
        return true;
    }

    async CreateBehavior(behaviorJSON){
        this._CheckNewBehavior(behaviorJSON);
        const name = behaviorJSON.name;
        const content = behaviorJSON.content;
        const publish = behaviorJSON.publish;
        const creator = behaviorJSON.creator;
        return await this._repo.Save(name, content, creator, publish);
    }

    async UpdateBehavior(behaviorJSON){
        const name = behaviorJSON.name;
        const content = behaviorJSON.content;
        const publish = behaviorJSON.publish;
        if(content === null && publish === null){
            return false;
        }
        return await this._repo.Update(name, content, publish);
    }

    async StageBehavior(behaviorName){
        const behaviorJSON = await this._repo.Load(behaviorName);
        if(behaviorJSON){
            const filePath = BEHAVIOR_FOLDER_PATH.concat('/', behaviorJSON.name.concat('.behavior'));
            fs.writeFileSync(filePath, behaviorJSON.content);
            return behaviorJSON.name;
        }else{
            return null;
        }
    }

    async DeleteBehavior(name){
        return await this._repo.Delete(name);;
    }

    async GetBehaviorOptions(){
        return await this._repo.GetOptions();
    }
}

module.exports = BehaviorController;