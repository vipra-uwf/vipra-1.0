import { SimConfig, SimConfigUpload } from '../../../types/simconfig/simconfig.types';

const properSimConfig : SimConfig = {
  id: 'properSimConfig',
  name: 'properSimConfig',
  description: 'this is a proper simconfig description',
  modules: {
    pedestrian_dynamics_model: 'good',
    goals: 'good',
    output_data_writer: 'good',
    input_data_loader: 'good',
    simulation_output_handler: 'good',
    pedestrian_set: 'good',
    obstacle_set: 'good',
    human_behavior_model: 'good',
    configuration_reader: 'good',
    clock: 'good',
    simulation: 'good',
  },
};

const properSimConfigUpload : SimConfigUpload = properSimConfig;

const missingNameSimConfigUpload : SimConfigUpload = {
  id: 'missingName',
  description: 'this is a proper simconfig description',
  modules: {
    pedestrian_dynamics_model: 'good',
    goals: 'good',
    output_data_writer: 'good',
    input_data_loader: 'good',
    simulation_output_handler: 'good',
    pedestrian_set: 'good',
    obstacle_set: 'good',
    human_behavior_model: 'good',
    configuration_reader: 'good',
    clock: 'good',
    simulation: 'good',
  },
};

const missingModuleSimConfigUpload : SimConfigUpload = {
  id: 'missingModule',
  name: 'missingModule',
  description: 'this is a proper simconfig description',
  modules: {
    goals: 'good',
    output_data_writer: 'good',
    input_data_loader: 'good',
    simulation_output_handler: 'good',
    pedestrian_set: 'good',
    obstacle_set: 'good',
    human_behavior_model: 'good',
    configuration_reader: 'good',
    clock: 'good',
    simulation: 'good',
  },
};

const badModuleSimConfigUpload : SimConfigUpload = {
  id: 'badModule',
  name: 'badModule',
  description: 'this is a proper simconfig description',
  modules: {
    goals: 'good',
    output_data_writer: 'good',
    input_data_loader: 'good',
    simulation_output_handler: 'bad',
    pedestrian_set: 'good',
    obstacle_set: 'good',
    human_behavior_model: 'good',
    configuration_reader: 'good',
    clock: 'good',
    simulation: 'good',
  },
};

const properSimConfigUpdate : Partial<SimConfigUpload> = {
  description : 'this is an updated description',
  modules: {
    input_data_loader: 'updatedid',
  },
};

const updatedSimConfig : SimConfig = {
  id: 'properSimConfig',
  name: 'properSimConfig',
  description: 'this is an updated description',
  modules: {
    pedestrian_dynamics_model: 'good',
    goals: 'good',
    output_data_writer: 'good',
    input_data_loader: 'updatedid',
    simulation_output_handler: 'good',
    pedestrian_set: 'good',
    obstacle_set: 'good',
    human_behavior_model: 'good',
    configuration_reader: 'good',
    clock: 'good',
    simulation: 'good',
  },
};

const idSimConfigUpdate : Partial<SimConfigUpload> = {
  id: 'shouldntchange',
};

const nameSimConfigUpdate : Partial<SimConfigUpload> = {
  name: 'shouldntchange',
};

const emptySimConfigUpdate : Partial<SimConfigUpload> = {

};

const moduleSimConfigUpdate : Partial<SimConfigUpload> = {
  modules: {
    goals: 'updatedid',
  },
};

export {
  properSimConfig,
  properSimConfigUpload,
  properSimConfigUpdate,
  updatedSimConfig,
  missingModuleSimConfigUpload,
  missingNameSimConfigUpload,
  badModuleSimConfigUpload,
  moduleSimConfigUpdate,
  emptySimConfigUpdate,
  nameSimConfigUpdate,
  idSimConfigUpdate,
};