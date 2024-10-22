# Pedestrian Dynamics Model

The `Pedestrian Dynamics Model` module handles calculating how pedestrians move over the course of a simulation.

## Modules To Overload

```C++
void configure(const VIPRA::Config&);
void initialize(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&, const VIPRA::Goals&);
void timestep(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&, const VIPRA::Goals&, VIPRA::State&, VIPRA::delta_t, VIPRA::t_step);
```

### configure(const VIPRA::Config& configMap) -> void

Takes in the module parameters for configuration.

Called after construction

### initialize(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&, const VIPRA::Goals&) -> void

Initializes any model specific pedestrian data.

Called after `configure`

### timestep(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&, const VIPRA::Goals&, VIPRA::State&, VIPRA::delta_t, VIPRA::t_step) -> void

Calculates change in pedestrian position/velocity for each timestep of the simulation. Placing the updated values in the passed in [VIPRA::State](../VIPRATypes.md)&.

Called at the start of each simulation time step.

Params:
- const [VIPRA::PedestrianSet](PedestrianSet.md)& : pedestrian set module
- const [VIPRA::ObstacleSet](ObstacleSet.md)& : obstacle set module
- const [VIPRA::Goals](Goals.md)& : goals module
- [VIPRA::State](../VIPRATypes.md)& : out parameter for updated pedestrian positions
- [VIPRA::delta_t](../VIPRATypes.md) : simulated time since last time step (time step size)
- [VIPRA::t_step](../VIPRATypes.md) : current time step number