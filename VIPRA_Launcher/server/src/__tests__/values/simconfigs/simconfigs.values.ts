import { SimConfig, SimConfigUpload } from "../../../types/simconfig/simconfig.types";



const properSimConfig : SimConfig = {
  id: "properSimConfig",
  name: "properSimConfig",
  description: "this is a proper simconfig description",
  modules: {
    pedestrian_dynamics_model: 'asdfasdf',
    goals: 'asdfasdf',
    output_data_writer: 'asdfasdf',
    input_data_loader: 'asdfasdf',
    simulation_output_handler: 'asdfasdf',
    pedestrian_set: 'asdfasdf',
    obstacle_set: 'asdfasdf',
    human_behavior_model: 'asdfasdf',
    configuration_reader: 'asdfasdf',
    clock: 'asdfasdf',
    simulation: 'asdfasdf',
  }
};

const properSimConfigUpload : SimConfigUpload = properSimConfig;

const missingNameSimConfigUpload : SimConfigUpload = {
  id: "properSimConfig",
  description: "this is a proper simconfig description",
  modules: {
    pedestrian_dynamics_model: 'asdfasdf',
    goals: 'asdfasdf',
    output_data_writer: 'asdfasdf',
    input_data_loader: 'asdfasdf',
    simulation_output_handler: 'asdfasdf',
    pedestrian_set: 'asdfasdf',
    obstacle_set: 'asdfasdf',
    human_behavior_model: 'asdfasdf',
    configuration_reader: 'asdfasdf',
    clock: 'asdfasdf',
    simulation: 'asdfasdf',
  }
};

const missingModuleSimConfigUpload : SimConfigUpload = {
  id: "properSimConfig",
  name: "properSimConfig",
  description: "this is a proper simconfig description",
  modules: {
    goals: 'asdfasdf',
    output_data_writer: 'asdfasdf',
    input_data_loader: 'asdfasdf',
    simulation_output_handler: 'asdfasdf',
    pedestrian_set: 'asdfasdf',
    obstacle_set: 'asdfasdf',
    human_behavior_model: 'asdfasdf',
    configuration_reader: 'asdfasdf',
    clock: 'asdfasdf',
    simulation: 'asdfasdf',
  }
}

const properSimConfigUpdate : Partial<SimConfigUpload> = {
  description : "this is an updated description",
  modules: {
    input_data_loader: "updatedid"
  }
}

const updatedSimConfig : SimConfig = {
  id: "properSimConfig",
  name: "properSimConfig",
  description: "this is an updated description",
  modules: {
    pedestrian_dynamics_model: 'asdfasdf',
    goals: 'asdfasdf',
    output_data_writer: 'asdfasdf',
    input_data_loader: 'updatedid',
    simulation_output_handler: 'asdfasdf',
    pedestrian_set: 'asdfasdf',
    obstacle_set: 'asdfasdf',
    human_behavior_model: 'asdfasdf',
    configuration_reader: 'asdfasdf',
    clock: 'asdfasdf',
    simulation: 'asdfasdf',
  }
};

const idSimConfigUpdate : Partial<SimConfigUpload> = {
  id: 'shouldntchange'
};

const nameSimConfigUpdate : Partial<SimConfigUpload> = {
  name: 'shouldntchange'
};

const emptySimConfigUpdate : Partial<SimConfigUpload> = {

};

const moduleSimConfigUpdate : Partial<SimConfigUpload> = {
  modules: {
    goals: 'updatedid'
  }
};

export {
  properSimConfig,
  properSimConfigUpload,
  properSimConfigUpdate,
  updatedSimConfig,
  missingModuleSimConfigUpload,
  missingNameSimConfigUpload,
  moduleSimConfigUpdate,
  emptySimConfigUpdate,
  nameSimConfigUpdate,
  idSimConfigUpdate,
};