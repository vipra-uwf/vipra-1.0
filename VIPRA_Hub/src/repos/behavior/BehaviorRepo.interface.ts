import { Status } from "../../data_models/Status";
import { Behavior } from "../../data_models/Behavior";


export interface IBehaviorRepo{
    connect(dbURI: string): Status;
    getAll(): Promise<Behavior[]>;
    getBehavior(behaviorName: string): Promise<Behavior>;
    createBehavior(behavior: Behavior): Promise<Status>;
    deleteBehavior(behaviorName: string): Promise<Status>;
    updatePublished(behaviorName: string, publish: boolean): Promise<Status>;
    updateContent(behaviorName: string, content: string): Promise<Status>;
}
