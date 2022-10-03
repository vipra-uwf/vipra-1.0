import { File } from '../../controllers/module/filestore';

export enum ModuleType {
  MODEL                   = 'pedestrian_dynamics_model',
  GOALS                   = 'goals',
  OUTPUT_DATA_WRITER      = 'output_data_writer',
  INPUT_DATA_LOADER       = 'input_data_loader',
  SIM_OUTPUT_HANDLER      = 'simulation_output_handler',
  PEDESTRIAN_SET          = 'pedestrian_set',
  OBSTACLE_SET            = 'obstacle_set',
  HUMAN_BEHAVIOR_MODEL    = 'human_behavior_model',
  CONFIGURATION_READER    = 'configuration_reader',
  CLOCK                   = 'clock',
  SIMULATION              = 'simulation',
}

export interface ModuleRequest {
  body?: {
    module? : Partial<Module>;
  };
  files? : {
    source? : File,
    header? : File,
    meta? : File
  };
}


export interface ModuleParam {
  name:string;
  type:string;
  description:string;
  multiple:boolean;
}


export interface Module {
  id : string;
  name : string;
  description : string;
  params : ModuleParam[];
  type : ModuleType;
}

export interface ModuleUpload {
  module : Partial<Module>;
  files : Partial<{
    srcFile : File;
    headerFile : File;
    metaFile : File;
  }>;
}