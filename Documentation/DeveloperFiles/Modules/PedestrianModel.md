# Pedestrian Dynamics Model

The `Pedestrian Dynamics Model` module handles calculating how pedestrians move over the course of a simulation.

## Modules To Overload

### configure(const VIPRA::Config& configMap) -> void

Takes in the module parameters for configuration.

Called after construction

### initialize(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&, const VIPRA::Goals&) -> void

Initializes any model specific pedestrian data.

Called after `configure`

### timestep(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&, const VIPRA::Goals&, VIPRA::delta_t, VIPRA::t_step) -> VIPRA::State&

Calculates change in pedestrian position/velocity for each timestep of the simulation. Returning it as a [VIPRA::State](../VIPRATypes.md)&.

Called at the start of each simulation time step.

Params:
- const [VIPRA::PedestrianSet](PedestrianSet.md)& : pedestrian set module
- const [VIPRA::ObstacleSet](ObstacleSet.md)& : obstacle set module
- const [VIPRA::Goals](Goals.md)& : goals module
- [VIPRA::delta_t](../VIPRATypes.md) : simulated time since last time step (time step size)
- [VIPRA::t_step](../VIPRATypes.md) : current time step number