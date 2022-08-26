/**
 * @module SimConfig
 */

// import { Module } from "./module";

// export interface SimConfigIDs{
//     name                            : string;
//     description                     : string;
//     input_data_loader               : {id: string};
//     output_data_writer              : {id: string};
//     simulation_output_handler       : {id: string};
//     pedestrian_set                  : {id: string};
//     obstacle_set                    : {id: string};
//     entity_set_factory              : {id: string};
//     goals                           : {id: string};
//     pedestrian_dynamics_model       : {id: string};
//     human_behavior_model            : {id: string};
//     configuration_reader            : {id: string};
//     clock                           : {id: string};
//     data                            : {id: string};
//     simulation                      : {id: string};
// }


// export const hasAllTypes = (simConfig : SimConfigIDs) : boolean => {
//     return (
//         "input_data_loader"               in simConfig &&
//         "output_data_writer"              in simConfig &&
//         "simulation_output_handler"       in simConfig &&
//         "pedestrian_set"                  in simConfig &&
//         "obstacle_set"                    in simConfig &&
//         "entity_set_factory"              in simConfig &&
//         "goals"                           in simConfig &&
//         "pedestrian_dynamics_model"       in simConfig &&
//         "human_behavior_model"            in simConfig &&
//         "configuration_reader"            in simConfig &&
//         "clock"                           in simConfig &&
//         "data"                            in simConfig &&
//         "simulation"                      in simConfig
//     );
// };

// export interface SimConfig{
//     id                              : string;
//     name                            : string;
//     description                     : string;
//     input_data_loader?              : Module;
//     output_data_writer?             : Module;
//     simulation_output_handler?      : Module;
//     pedestrian_set?                 : Module;
//     obstacle_set?                   : Module;
//     entity_set_factory?             : Module;
//     goals?                          : Module;
//     pedestrian_dynamics_model?      : Module;
//     human_behavior_model?           : Module;
//     configuration_reader?           : Module;
//     clock?                          : Module;
//     data?                           : Module;
//     simulation?                     : Module;
// }

// export const addModule = (simConfig : SimConfig, module : Module) : void => {
//     simConfig[module.type] = module;
// };

// export const configIsSame = (conf1 : SimConfigIDs, conf2 : SimConfig) : boolean => {
//     return(
//         conf1.entity_set_factory.id         === conf2.entity_set_factory.id &&
//         conf1.goals.id                      === conf2.goals.id &&
//         conf1.output_data_writer.id         === conf2.output_data_writer.id &&
//         conf1.simulation_output_handler.id  === conf2.simulation_output_handler.id &&
//         conf1.pedestrian_dynamics_model.id  === conf2.pedestrian_dynamics_model.id &&
//         conf1.obstacle_set.id               === conf2.obstacle_set.id &&
//         conf1.pedestrian_set.id             === conf2.pedestrian_set.id &&
//         conf1.human_behavior_model.id       === conf2.human_behavior_model.id &&
//         conf1.input_data_loader.id          === conf2.input_data_loader.id
//     );
// };