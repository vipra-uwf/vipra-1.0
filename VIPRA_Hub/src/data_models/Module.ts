export enum ModuleType{
    MODEL                   = 'pedestrianmodel',
    GOALS                   = 'goals',
    OUTPUT_DATA_WRITER      = 'outputdatawriter',
    INPUT_DATA_LOADER       = 'inputdataloader',
    SIM_OUTPUT_HANDLER      = 'simulationoutputhandler',
    PEDESTRIAN_SET          = 'pedestrianset',
    OBSTACLE_SET            = 'obstacleset',
    ENTITY_SET_FACTORY      = 'entitysetfactory',
    HUMAN_BEHAVIOR_MODEL    = 'humanbehaviormodel'
}

export interface ModuleMeta{
    name: string;
    description: string;
    type : ModuleType;
}

export interface ModuleUpdate{
    name: string;
    type: ModuleType;
    description?: string;
    source?: string;
    header?: string;
    publish?: boolean;
}

export interface Module{
    name: string;
    description: string;
    type: ModuleType;
    source?: string;
    header?: string;
    publish: boolean;
}

// TODO NEXT add unique ids to modules -RG
// TODO add params to modules

export const toString = (meta : ModuleMeta) : string => {
    return `{\"name\": \"${meta.name}\", \"description\": \"${meta.description}\", \"type\": \"${meta.type}\"}`;
};

export const typeFromString = (type : string) : ModuleType =>{
    if(Object.values(ModuleType).some(
        (t : string) => t === type.toLowerCase())
        ){
        return type as ModuleType;
    }else{
        return null;
    }
};