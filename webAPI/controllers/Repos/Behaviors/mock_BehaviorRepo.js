const { Status } = require("../../../configurations/Status");

class mock_BehaviorRepo{

    #pass;
    #options;
    #callCounts;

    constructor(){
        this.Reset();
    }

    SetPassOrFail(pass){
        this.#pass = pass;
    }

    Reset(){
        this.#pass = true;
        this.#callCounts = {
            "GetBehavior": 0,
            "Create": 0,
            "Delete": 0,
            "Update": 0,
            "GetOptions": 0
        };
        this.#options = [
            {
                name: "exampleBehavior",
                content: "this is an example",
                creator: "testing@email.com",
                publish: true
            },
            {
                name: "secondBehavior",
                content: "another example",
                creator: "other@email.com",
                publish: true
            },
            {
                name: "unpublished",
                content: "unpublished example",
                creator: "test@email.com",
                publish: false
            }
        ]
    }

    CallCounts(){
        return this.#callCounts;
    }



    async GetBehavior(bname){
        this.#callCounts["GetBehavior"]++;
        if(this.#pass){
            const behavior = this.#options.find((behavior) =>{
                if(behavior.name === bname){
                    return behavior;
                }
            });
            return behavior;
        }else{
            return null;
        }
    }

    async Create(bname, bcontent, bcreator, bpublish=false){
        this.#callCounts["Create"]++;
        if(this.#pass){
            if(bname && bcontent && bcreator){
                const behavior = {
                    "name": bname,
                    "content": bcontent,
                    "creator": bcreator,
                    "publish": bpublish
                }
                this.#options.push(behavior);
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }


    async Delete(bname){
        this.#callCounts["Delete"]++;
        if(this.#pass){
            if(this.#options.some(option => option.name === bname)){
                return Status.SUCCESS;
            }else{
                return Status.NOT_FOUND;
            }
        }else{
            return Status.BAD_REQUEST;
        }
    }

    async Update(name, content=null, publish=null){
        this.#callCounts["Update"]++;
        if(name && (content || publish)){
            return true;
        }else{
            return false;
        }
    }

    async GetOptions(userAuth){
        this.#callCounts["GetOptions"]++;
        let ret = [];
        this.#options.forEach((behavior)=>{
            if(behavior.publish || userAuth.email === behavior.creator)
            ret.push({
                name: behavior.name,
                publish: behavior.publish,
                creator: behavior.creator
            });
        });
        return ret;
    }
}

module.exports = mock_BehaviorRepo;