import { Module } from "./module";



export interface SimConfig{
    id                          : string;
    name                        : string;
    description                 : string;
    input_data_loader           : Module;
    output_data_writer          : Module;
    simulation_output_handler   : Module;
    pedestrian_set              : Module;
    obstacle_set                : Module;
    entity_set_factor           : Module;
    goals                       : Module;
    pedestrian_dynamics_model   : Module;
    human_behavior_model        : Module;
}