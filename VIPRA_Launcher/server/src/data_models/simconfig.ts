import { Module } from "./module";

export interface SimConfigIDs{
    input_data_loader               : string;
    output_data_writer              : string;
    simulation_output_handler       : string;
    pedestrian_set                  : string;
    obstacle_set                    : string;
    entity_set_factory              : string;
    goals                           : string;
    pedestrian_dynamics_model       : string;
    human_behavior_model            : string;
    configuration_reader            : string;
    clock                           : string;
    data                            : string;
    simulation                      : string;
}


export const hasAllTypes = (simConfig : SimConfigIDs) : boolean => {
    return (
        "input_data_loader"               in simConfig &&
        "output_data_writer"              in simConfig &&
        "simulation_output_handler"       in simConfig &&
        "pedestrian_set"                  in simConfig &&
        "obstacle_set"                    in simConfig &&
        "entity_set_factory"              in simConfig &&
        "goals"                           in simConfig &&
        "pedestrian_dynamics_model"       in simConfig &&
        "human_behavior_model"            in simConfig &&
        "configuration_reader"            in simConfig &&
        "clock"                           in simConfig &&
        "data"                            in simConfig &&
        "simulation"                      in simConfig
    );
};

export interface SimConfig{
    id                              : string;
    name                            : string;
    description                     : string;
    input_data_loader?              : Module;
    output_data_writer?             : Module;
    simulation_output_handler?      : Module;
    pedestrian_set?                 : Module;
    obstacle_set?                   : Module;
    entity_set_factory?             : Module;
    goals?                          : Module;
    pedestrian_dynamics_model?      : Module;
    human_behavior_model?           : Module;
    configuration_reader?           : Module;
    clock?                          : Module;
    data?                           : Module;
    simulation?                     : Module;
}

export const addModule = (simConfig : SimConfig, module : Module) : void => {
    simConfig[module.type] = module;
};

export const configIsSame = (conf1 : SimConfigIDs, conf2 : SimConfig) : boolean => {
    return(
        conf1.entity_set_factory         === conf2.entity_set_factory.id &&
        conf1.goals                      === conf2.goals.id &&
        conf1.output_data_writer         === conf2.output_data_writer.id &&
        conf1.simulation_output_handler  === conf2.simulation_output_handler.id &&
        conf1.pedestrian_dynamics_model  === conf2.pedestrian_dynamics_model.id &&
        conf1.obstacle_set               === conf2.obstacle_set.id &&
        conf1.pedestrian_set             === conf2.pedestrian_set.id &&
        conf1.human_behavior_model       === conf2.human_behavior_model.id &&
        conf1.input_data_loader          === conf2.input_data_loader.id
    );
};