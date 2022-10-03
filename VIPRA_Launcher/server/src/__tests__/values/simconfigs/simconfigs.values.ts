import { SimConfig } from "src/types/simconfig/simconfig.types";



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



export {
  properSimConfig,
};