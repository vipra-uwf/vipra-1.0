# VIPRA Modules

VIPRA is broken up into several modules you will change regularly:
1. Pedestrian Loader
2. Pedestrian Set
3. Map Loader
4. Obstacle Set
5. Goals
6. Output Sink

For more details on each module scroll down to `Modules Overview`.

# Adding New Modules

See [Adding Modules](Adding_Modules.md)


Pedestrian Dynamics Model
Configuration Reader
Simulation
Policy Model
Human Behavior Model

# Modules Overview

The following modules are the ones that will users will change regularly.

### Pedestrian Model

The `Pedestrian Model` module is the pedestrian dynamics model that dictates how the pedestrians move.

### Goals

The `Goals` module is what does all the path finding for pedestrians, it also determines the end goal for the overall simulation. *(for example: all pedestrians exit the plane)*

### Obstacle Set

The `Obstacle Set` module holds the map information; including obstacles and object. The `Obstacle Set` is also responsible for collision detection.

### Pedestrian Set

The `Pedestrian Set` module holds information about pedestrians, for example their position, velocity, etc.

### Map Loader

The `Map Loader` module is responsible for loading map files into `Obstacle Sets`.

### Pedestrian Loader

The `Pedestrian Loader` module is responsible for loading pedestrian files into `Pedestrian Sets`.

### Output Sink

`/VIPRA/Base/output/sink.hpp`

The `Sink` module handles routing output.

Currently, only a `FileSink` is implemented, that writes output to a JSON file.

---

## Static Modules

These modules are generally the same for each simulation run

1. Human Behavior Model
2. Policy Model
3. Configuration Reader
4. Simulation

### Human Behavior Model

`/VIPRA/Base/human_behavior/human_behavior_model.hpp`

The `Human Behavior Model` orchestrates the `Behaviors` that are enabled for a simulation run 

### Policy Model
*Not Currently Implemented*

`/VIPRA/Base/policy_model/policy_model.hpp`

The `Policy Model` will, in the future, handle any policies (like airplane boarding order)

---