import { IBehaviorRepo } from "../repos/behavior/BehaviorRepo.interface";
import { BehaviorRepo } from "../repos/behavior/MongoDB/BehaviorRepo.Mongo";

export const config = {
    port: 3000,
    Behavior:{
        DB_URI: "mongodb+srv://vipratest:PmD1Sf3rdwmOFdRJ@cluster0.nugoo.mongodb.net/?retryWrites=true&w=majority",
        BehaviorRepo: (): IBehaviorRepo => { return new BehaviorRepo(); }
    }
};