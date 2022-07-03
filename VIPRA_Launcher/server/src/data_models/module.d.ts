import { ParamSet } from "./simparam";


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

export interface Module{
    id          : string;
    name        : string;
    description : string;
    dirPath     : string;
    type        : ModuleType;
    params      : ParamSet;
}