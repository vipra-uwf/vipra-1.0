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
        const behavior : Behavior = JSON.parse(JSON.stringify(behaviorJSON)) as Behavior;
        const created : Status = await this.behaviorDB.createBehavior(behavior);
        return created;
    }

    // TODO refactor to one request -RG
    public async updateBehavior(name: string, content?: string, publish?: boolean) : Promise<Status>{
        if(content){
            const updatedContent = await this.behaviorDB.updateContent(name, content);
            if(updatedContent !== Status.SUCCESS){
                return updatedContent;
            }
        }
        if(publish){
            const updatedPublish = await this.behaviorDB.updatePublished(name, publish);
            if(updatedPublish !== Status.SUCCESS){
                return updatedPublish;
            }
        }
        return Status.SUCCESS;
    }

    public async getBehavior(name: string) : Promise<{behavior: Behavior; status: Status}>{
        const behavior = await this.behaviorDB.getBehavior(name);
        return behavior;
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