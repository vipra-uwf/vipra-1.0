# M. Modules

**File Path:** [Home](../MainPage.md) / [Developers](Developers.md) / [Modules Overview](ModulesOverview.md)

## M.1. Extendable Modules

Extendable Modules are the modules that are meant to be implemented by end users.

1. [Pedestrian Model](Modules/Pedestrian_Model.md)
2. [Goals](Modules/Goals.md)
3. [Obstacle Set](Modules/Obstalce_Set.md)
4. [Pedestrian Set](Modules/Pedestrian_Set.md)
5. [Map Loader](Modules/Map_Loader.md)
6. [Pedestrian Loader](Modules/Pedestrian_Loader.md)


### M.1.1. Pedestrian Model

`/VIPRA/Extendable/pedestrian_model/pedestrian_dynamics_model.hpp`

The [Pedestrian Model](PedestrianModel.md) module is the pedestrian dynamics model that dictates how the pedestrians move.

### M.1.2. Goals

`/VIPRA/Extendable/goals/goals.hpp`

The [Goals](Goals.md) module is what does all the path finding for pedestrians, it also determines the end goal for the overall simulation. *(for example: all pedestrians reach the exit)*

### M.1.3. Obstacle Set

`/VIPRA/Extendable/obstacle_set/obstacle_set.hpp`

The [Obstacle Set](Obstacle.md) module holds the map information; including obstacles and object. The [Obstacle Set](ObstacleSet.md) is also responsible for collision detection.

### M.1.4. Pedestrian Set

`/VIPRA/Extendable/pedestrian_set/pedestrian_set.hpp`

The [Pedestrian Set](PedestrianSet.md) module holds information about pedestrians, for example their position, velocity, etc.

### M.1.5. Map Loader

`/VIPRA/Extendable/map_loader/map_loader.hpp`

The [Map Loader](Map_Loader.md) module is responsible for loading map files into [Obstacle Sets](ObstacleSet.md).

### M.1.6. Pedestrian Loader

`/VIPRA/Extendable/pedestrian_loader/pedestrian_loader.hpp`

The [Pedestrian Loader](PedestrianLoader.md) module is responsible for loading pedestrian files into [Pedestrian Sets](PedestrianSet.md).

---
## M.2. Base Modules

Base Modules are the modules that the VIPRA team implements, end users can extend them, but the idea is that they do not have to.

1. Human Behavior Model
2. Policy Model
3. Output Sinks

### M.2.1. Human Behavior Model

`/VIPRA/Base/human_behavior/human_behavior_model.hpp`

The `Human Behavior Model` orchestrates the `Behaviors` that are enabled for a simulation run 

### M.2.2. Policy Model
*Not Currently Implemented*

`/VIPRA/Base/policy_model/policy_model.hpp`

The `Policy Model` will, in the future, handle any policies (like airplane boarding order)

### M.2.3. Output Sink

`/VIPRA/Base/output/sink.hpp`

The `Sink` module handles routing output.

Currently, only a `FileSink` is implemented, that writes output to a JSON file.

---

[Return to Getting Started - Developers](../Developers.md)