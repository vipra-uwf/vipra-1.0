const fs = require('fs');
const path = require('path');

const { BEHAVIOR_FOLDER_PATH } = require('../../../configurations/File_Paths');

class BehaviorRepo_Local{
    constructor(){
        this.#LoadOptions();
    }

    async #LoadOptions(){
        this.#options = fs.readdirSync(BEHAVIOR_FOLDER_PATH);
        this.#options.forEach((file, index, options)=>{
            options[index] = path.parse(options[index]).name;
        });
    }

    #DoesExist(name){
        return this.#options.includes(name);
    }

    async Load(behaviorID){
        // NOTE: already in folder so no need to load them from local repo
    }

    async Save(name, content, publish){
        if(this.#DoesExist(name)){
            return false;
        }else{
            const filename = BEHAVIOR_FOLDER_PATH.concat('/', name, '.behavior');
            fs.writeFileSync(filename, content);
            this.#options.push(name);
            return true;
        }
    }

    #RemoveFromOptions(name){
        let index = this.#options.indexOf(name);
        if (index !== -1) {
            this.#options.splice(index);
        }
    }

    // TODO make sure users can't delete arbitrary files -RG
    async Delete(name){
        const filename = BEHAVIOR_FOLDER_PATH.concat('/', name, '.behavior');
        if(fs.existsSync(filename)){
            fs.rmSync(filename);
            this.#RemoveFromOptions(name);
            return true;
        }else{
            return false;
        }
    }

    async Update(name, content, publish){
        if(this.#DoesExist(name)){
            const filename = BEHAVIOR_FOLDER_PATH.concat('/', name, '.behavior');
            fs.writeFileSync(filename, content);
            this.#options.push(name);
            return true;
        }else{
            return false;
        }
    }

    async GetOptions(){
        return this.#options;
    }
}

module.exports = BehaviorRepo_Local;