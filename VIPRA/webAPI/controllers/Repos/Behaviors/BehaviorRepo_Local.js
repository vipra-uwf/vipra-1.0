const fs = require('fs');
const path = require('path');

const { BEHAVIOR_FOLDER_PATH } = require('../../../configurations/File_Paths');

class BehaviorRepo_Local{
    constructor(){
        this._LoadOptions();
    }

    async _LoadOptions(){
        this._options = fs.readdirSync(BEHAVIOR_FOLDER_PATH);
        this._options.forEach((file, index, options)=>{
            options[index] = path.parse(options[index]).name;
        });
    }

    _DoesExist(name){
        return this._options.includes(name);
    }

    async Load(behaviorID){
        // NOTE: already in folder so no need to load them from local repo
    }

    async Save(name, content, publish){
        if(this._DoesExist(name)){
            return false;
        }else{
            const filename = BEHAVIOR_FOLDER_PATH.concat('/', name, '.behavior');
            fs.writeFileSync(filename, content);
            this._options.push(name);
            return true;
        }
    }

    _RemoveFromOptions(name){
        let index = this._options.indexOf(name);
        if (index !== -1) {
            this._options.splice(index);
        }
    }

    // TODO make sure users can't delete arbitrary files
    async Delete(name){
        const filename = BEHAVIOR_FOLDER_PATH.concat('/', name, '.behavior');
        if(fs.existsSync(filename)){
            fs.rmSync(filename);
            this._RemoveFromOptions(name);
            return true;
        }else{
            return false;
        }
    }

    async Update(name, content, publish){
        if(this._DoesExist(name)){
            const filename = BEHAVIOR_FOLDER_PATH.concat('/', name, '.behavior');
            fs.writeFileSync(filename, content);
            this._options.push(name);
            return true;
        }else{
            return false;
        }
    }

    async GetOptions(){
        return this._options;
    }
}

/*


behavior:{
    published: true,
    content: "aerboiaervpoanervpionaerf",

}

*/

module.exports = BehaviorRepo_Local;