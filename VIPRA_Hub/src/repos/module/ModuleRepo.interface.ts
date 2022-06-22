import { Status }                   from "../../data_models/Status";
import { ModuleMeta, ModuleType, Module }   from "../../data_models/Module";

export interface IModuleRepo{
    connect(dbURI : string, stagingDir : string) : void;
    getOptions(type : ModuleType) : Promise<ModuleMeta[]>;
    getModuleInfo(type : ModuleType, name : string) : Promise<{status : Status, moduleMeta : ModuleMeta}>;
    createModule(module : Module) : Promise<Status>;
    deleteModule(type : ModuleType, name : string) : Promise<Status>;
    updateModuleSource(name : string, source : string) : Promise<Status>;
    updateModuleHeader(name : string, header : string) : Promise<Status>;
    stageModule(type : ModuleType, name: string) : Promise<{status: Status, dirPath: string}>;
}