// TODO remove this in favor of an environment variable -RG
import path from "path";

import { IBehaviorRepo } from "../repos/behavior/BehaviorRepo.interface";
import { BehaviorRepo } from "../repos/behavior/MongoDB/BehaviorRepo.Mongo";

import { IMapRepo } from "../repos/map/MapRepo.interface";
import { MapRepo } from "../repos/map/MongoDB/MapRepo.Mongo";

import { IModuleRepo } from "../repos/module/ModuleRepo.interface";
import { ModuleRepo } from "../repos/module/Mongo/ModuleRepo.Mongo";


// TODO!!!!! Setup environment variables for these -RG

export const config = {
    port: 3000,
    Behavior:{
        DB_URI: "mongodb+srv://vipratest:PmD1Sf3rdwmOFdRJ@cluster0.nugoo.mongodb.net/?retryWrites=true&w=majority",
        BehaviorRepo: (): IBehaviorRepo => { return new BehaviorRepo(); }
    },
    Map:{
        DB_URI: "mongodb+srv://vipratest:PmD1Sf3rdwmOFdRJ@cluster0.nugoo.mongodb.net/?retryWrites=true&w=majority",
        MapRepo: (): IMapRepo => { return new MapRepo(); }
    },
    Module:{
        DB_URI: 'mongodb+srv://vipratest:PmD1Sf3rdwmOFdRJ@cluster0.nugoo.mongodb.net/?retryWrites=true&w=majority',
        TempDir: path.resolve('./MODULE_TEMP'),
        ModuleRepo: (): IModuleRepo => { return new ModuleRepo(); }
    },
};