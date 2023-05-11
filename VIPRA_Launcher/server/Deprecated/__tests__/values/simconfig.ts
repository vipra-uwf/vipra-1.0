
import { SimConfig } from "../../src/types/simconfig";


const goodConfig : Partial<SimConfig> = {
  name: "goodConfig",
  description: "this is a good config",
  moduleIDs: {
    pedestrian_dynamics_model: 'goodmodule',
    goals: 'goodmodule',
    output_data_writer: 'goodmodule',
    input_data_loader: 'goodmodule',
    simulation_output_handler: 'goodmodule',
    pedestrian_set: 'goodmodule',
    obstacle_set: 'goodmodule',
    entity_set_factory: 'goodmodule',
    human_behavior_model: 'goodmodule',
    configuration_reader: 'goodmodule',
    clock: 'goodmodule',
    data: 'goodmodule',
    simulation: 'goodmodule',
  }
}

const goodConfigUpdate : Partial<SimConfig> = {
  description: "this is an updated config"
}

const badConfig : Partial<SimConfig> = {
  name: "goodConfig",
  description: "this is a good config",
  moduleIDs: {
    pedestrian_dynamics_model: "goodmodule",
    goals: 'goodmodule',
    output_data_writer: 'goodmodule',
    input_data_loader: 'goodmodule',
    simulation_output_handler: 'goodmodule',
    pedestrian_set: 'badmodule',
    obstacle_set: 'goodmodule',
    entity_set_factory: 'goodmodule',
    human_behavior_model: 'goodmodule',
    configuration_reader: 'goodmodule',
    clock: 'goodmodule',
    data: 'goodmodule',
    simulation: 'goodmodule'
  }
} 

const NONEXISTANTID = 'notaconfig';

export {
  goodConfig,
  goodConfigUpdate,
  badConfig,
  NONEXISTANTID
}