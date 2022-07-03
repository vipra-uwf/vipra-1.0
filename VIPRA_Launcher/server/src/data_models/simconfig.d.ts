
export interface SimConfig{
    id                              : string;
    name                            : string;
    description                     : string;
    input_data_loader_id            : string;
    output_data_writer_id           : string;
    simulation_output_handler_id    : string;
    pedestrian_set_id               : string;
    obstacle_set_id                 : string;
    entity_set_factory_id           : string;
    goals_id                        : string;
    pedestrian_dynamics_model_id    : string;
    human_behavior_model_id         : string;
}