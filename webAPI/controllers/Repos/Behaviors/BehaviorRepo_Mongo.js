
class BehaviorRepo_Mongo{

    #dbModel;
    #options;

    constructor(DBCon){
        if(DBCon == null){
            throw '[FATAL] Database Connection is null';
        }
        this.#dbModel = DBCon;
        this.#LoadOptions();
    }

    async #LoadOptions(){
        const behaviors = await this.#dbModel.find({}, {name:1, _id:0});
        this.#options = [];
        behaviors.forEach((behavior)=>{
            this.#options.push({
                name: behavior.name,
                publish: behavior.publish,
                creator: behavior.creator
            });
        });
    }

    async GetBehavior(bname){
        const behavior = await this.#dbModel.findOne({name: bname});
        return behavior;
    }

    async Create(bname, bcontent, bcreator, bpublish){
        if(this.#options.includes(bname)){
            return false;
        }else{
            return await this.#dbModel.create(
                {
                    name: bname,
                    content: bcontent,
                    creator: bcreator,
                    publish: bpublish
                })
                .then((created)=>{
                        this.#options.push(created.name);
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
        let index = this.#options.indexOf(name);
        if (index !== -1) {
            this.#options.splice(index);
        }
    }

    // TODO make sure users can't delete arbitrary files -RG
    async Delete(bname){
        this._RemoveFromOptions(bname);
        const deleted = (await this.#dbModel.deleteOne({name: bname}));
        return deleted.deletedCount === 1;
    }

    async Update(name, content=null, publish=null){
        const behavior = await this.#dbModel.findOne({name});
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

    async GetOptions(userAuth){
        // TODO return options only if they are published or if the requestor is the creator -RG
        return this.#options;
    }
}

module.exports = BehaviorRepo_Mongo;