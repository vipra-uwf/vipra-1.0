
const fs = require('fs');
const { BEHAVIOR_FOLDER_PATH } = require('../../configurations/File_Paths')


class BehaviorController{
    constructor(behaviorRepo){
        this._repo = behaviorRepo;
    }

    async CreateBehavior(behaviorJSON){
        const name = behaviorJSON.name;
        const content = behaviorJSON.content;
        const publish = behaviorJSON.publish;
        return this._repo.Save(name, content, publish);
    }

    async UpdateBehavior(behaviorJSON){
        const name = behaviorJSON.name;
        const content = behaviorJSON.content;
        const publish = behaviorJSON.publish;
        return this._repo.Update(name, content, publish);
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
        return await this._repo.Delete(name);
    }

    async GetBehaviorOptions(){
        return await this._repo.GetOptions();
    }
}

module.exports = BehaviorController;