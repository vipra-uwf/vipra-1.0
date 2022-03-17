const mongooose = require('mongoose');

class BehaviorRepo_Mongo{
    constructor(DBCon){
        if(DBCon == null){
            throw '[FATAL] Database Connection is null';
        }
        this._dbModel = DBCon;
        this._LoadOptions();
    }

    async _LoadOptions(){
        const behaviors = await this._dbModel.find({}, {name:1, _id:0});
        this._options = [];
        behaviors.forEach((behavior)=>{
            this._options.push(behavior.name);
        });
        console.log(`Behavior Options Loaded: ${this._options}`);
    }

    async Load(bname){
        return await this._dbModel.findOne({name: bname});
    }

    async Save(bname, bcontent, bcreator, bpublish){
        if(this._options.includes(bname)){
            return false;
        }else{
            return await this._dbModel.create(
                {
                    name: bname,
                    content: bcontent,
                    creator: bcreator,
                    publish: bpublish
                })
                .then((created)=>{
                        this._options.push(created.name);
                        if(created){
                            return true;
                        }else{
                            return false;
                        }
                })
                .catch(err=>{
                    console.log(`[ERROR] Error in BehaviorRepo Save: ${err}`);
                });
        }
    }

    _RemoveFromOptions(name){
        let index = this._options.indexOf(name);
        if (index !== -1) {
            this._options.splice(index);
        }
    }

    // TODO make sure users can't delete arbitrary files
    // TODO check that the user calling the delete is the creator or has permissions
    async Delete(bname){
        this._RemoveFromOptions(bname);
        const deleted = (await this._dbModel.deleteOne({name: bname}));
        return deleted.deletedCount === 1;
    }

    async Update(name, content=null, publish=null){
        const behavior = await this._dbModel.findOne({name});
        if(behavior){
            if(content !== null){
                behavior.content = content;
            }
            if(publish !== null){
                behavior.publish = publish;
            }

            await behavior.save()
            .catch((err)=>{
                console.log(`[ERROR] Error in BehaviorDB Update: ${err}`);
                return false;
            });
            return true;
        }else{
            return false;
        }
    }

    async GetOptions(user){
        // TODO return options only if they are published or if the requestor is the creator
        return this._options;
    }
}

module.exports = BehaviorRepo_Mongo;