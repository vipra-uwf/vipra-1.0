# M. Modules

**File Path:** [Home](../MainPage.md) / [Developers](Developers.md) / [Modules Overview](ModulesOverview.md)

## M.1. Extendable Modules

Extendable Modules are the modules that are meant to be implemented by end users.

1. Pedestrian Model
2. Goals
3. Obstacle Set
4. Pedestrian Set
5. Map Loader
6. Pedestrian Loader


### M.1.1. Pedestrian Model

`/VIPRA/Extendable/pedestrian_model/pedestrian_dynamics_model.hpp`

The `Pedestrian Model`module is the main pedestrian dynamics model that, in conjunction with the `Behavior Model`, models how the pedestrians move through the simulation.

### M.1.2. Goals

`/VIPRA/Extendable/goals/goals.hpp`

The `Goals` module is what does all the path finding for pedestrians, it also determines the end goal for the overall simulation. *(for example: all pedestrians exit the plane)*

### M.1.3. Obstacle Set

`/VIPRA/Extendable/obstacle_set/obstacle_set.hpp`

The `Obstacle Set` module holds the map information; including obstacles and object. The `Obstacle Set` is also responsible for collision detection.

### M.1.4. Pedestrian Set

`/VIPRA/Extendable/pedestrian_set/pedestrian_set.hpp`

The `Pedestrian Set` module holds information about pedestrians, for example their position, velocity, etc.

### M.1.5. Map Loader

`/VIPRA/Extendable/map_loader/map_loader.hpp`

The `Map Loader` module is responsible for loading map files into `Obstacle Sets`.

### M.1.6. Pedestrian Loader

`/VIPRA/Extendable/pedestrian_loader/pedestrian_loader.hpp`

The `Pedestrian Loader` module is responsible for loading pedestrian files into `Pedestrian Sets`.

---
## M.2. Base Modules

Base Modules are the modules that the VIPRA team implements, end users can extend them, but the idea is that they do not have to.

1. Human Behavior Model
2. Policy Model
3. Output Data Writer
4. Output Handler

### M.2.1. Human Behavior Model

`/VIPRA/Base/human_behavior/human_behavior_model.hpp`

The `Human Behavior Model` orchestrates the `Behaviors` that are enabled for a simulation run 

### M.2.2. Policy Model
*Not Currently Implemented*

`/VIPRA/Base/policy_model/policy_model.hpp`

The `Policy Model` will, in the future, handle any policies (like airplane boarding order)

### M.2.3. Output Data Writer

`/VIPRA/Base/output_data_writer/output_data_writer.hpp`

The `Output Data Writer` module handles writing output to files.

### M.2.4. Output Handler

`/VIPRA/Base/simulation_output_handler/simulation_output_handler.hpp`

The `Output Handler` module handles determining when to write output and what output to write.


---

[Return to Getting Started - Developers](Developers.md)