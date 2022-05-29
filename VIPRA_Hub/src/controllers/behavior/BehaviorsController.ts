import { IBehaviorRepo } from "../../repos/behavior/BehaviorRepo.interface";
import { Behavior } from "../../data_models/Behavior";
import { Status } from "../../data_models/Status";

export class BehaviorsContoller{

    private behaviorDB: IBehaviorRepo;

    constructor(behaviorDB: IBehaviorRepo){
        this.behaviorDB = behaviorDB;
    }

    public async createBehavior(behaviorJSON: JSON) : Promise<Status>{
        if(!this.checkBehavior(behaviorJSON)){
            return Status.BAD_REQUEST;
        }

        // TODO find a better way to do this, this is hideous -RG
        const behavior : Behavior = JSON.parse(JSON.stringify(behaviorJSON));
        const created : Status = await this.behaviorDB.createBehavior(behavior);
        return created;
    }

    // TODO refactor to one request -RG
    // TODO NEXT doesn't return the proper status if only one fails  -RG
    public async updateBehavior(name: string, content?: string, publish?: boolean) : Promise<Status>{
        let updated = Status.BAD_REQUEST;
        if(content){
            updated = await this.behaviorDB.updateContent(name, content);
        }
        if(publish !== undefined){
            updated = await this.behaviorDB.updatePublished(name, publish);
        }
        return updated;
    }

    public async deleteBehavior(name: string) : Promise<Status>{
        const deleted = await this.behaviorDB.deleteBehavior(name);
        return deleted;
    }

    // TODO cache options -RG
    // TODO take in authentication and return only published behaviors and those by user -RG
    public async getOptions() : Promise<string[]>{
        const behaviors: Behavior[] = await this.behaviorDB.getAll();
        return behaviors.map((behavior)=>{
            return behavior.name;
        });
    }

    private checkBehavior(behaviorJSON: JSON) : boolean{
        const passes = (
                        behaviorJSON.hasOwnProperty('name') &&
                        behaviorJSON.hasOwnProperty('content') &&
                        behaviorJSON.hasOwnProperty('creator') &&
                        behaviorJSON.hasOwnProperty('publish')
                    );
        return passes;
    }

}