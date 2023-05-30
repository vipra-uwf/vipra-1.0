
# VIPRA

VIPRA is a modular framework for pedestrian dynamics simulations.

The idea behind the project is for researchers to be able to test their pedestrian dynamics models without having to worry about programming an entire simulation.

# R. Requirements

The following are the requirements for running the VIPRA simulation.

1. `NodeJS` - version 17.0^
2. `CMake` - version 3.14^
3. `Make`
4. C++ compiler that supports C++17

Following are additional requirements for development

1. `ANTLR4` - version 4.11^

---
# SE. Setup

There are three main steps for setting up the simulation. *(This is temporary, a more permanent setup will be created in the future)*
1. ChainBuilder setup
2. VIPRA Launcher setup
3. Simulation Compilation

## SE.2. ChainBuilder

In `/ChainBuilder/` run:

1. `npm install`
2. `npm run build`
3. `npm pack`

## Se.3. VIPRA Launcher

In `/VIPRA_Launcher/server/` run:

1. `npm install`
2. `npm run build`

If you encounter errors with `npm install`:

1. Delete `package-lock.json`
2. Check that `typechain` in `package.json` points to the tarball created for ChainBuilder

If you encounter errors with `npm run build`:

*if you only get type errors, try moving on to the simulation compilation step*

1. Make sure you have Node 17 or later
2. Check that the `ChainBuilder` tarball was created properly

## SE.4. Simulation Compilation

In `/VIPRA/` run:

1. `make release` for compiling in release mode
 
or

1. `make debug` for compiling in debug mode

or

1. `make profiling` for compiling in release mode with profiling output
---
# Ru. Running

In `/VIPRA/` run:
`./VIPRA_SIM *Sim Config Path* *Module Params Path* *Pedestrians File Path* *Obstacle File Path* *Output File Path*`

An example `sim.config` and `module_params.json` are found in `SimConfigs/ExampleConfig/`

---

# U. Utility

## U.1. Visualizer

We have a Python script for viewing the output of a simulation.

`/UtilityScripts/Simulation_Output_Visualization/visualize.py`

To run:
1. `python3 visualize.py *Path to output.json* *Path to Obstacle File*`

---
# M. Modules

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

## S. Simulation

The main path a simulation takes is as follows:

### S.1. Module Selection / Configuration

Each simulation run is provided a `sim.config` file that holds the IDs for each module the simulation should use. *(one for each type of module)*

An instance of each of these modules is then created and configured, using the `module_params.json` file that is also provided to the simulation.

Each of the modules is then passed into the main simulation object. *Defined in `/VIPRA/Base/simulation/simulation.hpp`*

### S.2. Simulation Loop

The simulation loops until the `Goals` module says that the simulation has met its end goal, or until the maximum number of time steps has been reached.

Each time step the simulation:

1. Calls the `Pedestrian Model` module, which provides a shared pointer to a `State` object that has the updated positions and velocities of each pedestrian
2. Calls the `Policy Model` module, which modifies the `State` given by the `Pedestrian Model`
3. Calls the `Behavior Model` module, which modifies the `State` given by the `Pedestrian Model` and `Policy Model`
4. Checks if output should be written, writes if so
5. Calls the `Goals` module to update any goals
6. Loops

### S.3. Output

Once the simulation is finished the buffered output is written to an output file.


# T. Types

## T.1. VIPRA::f3d

`/VIPRA/Base/Definitions/dimensions.hpp`

`VIPRA::f3d` is a three-dimensional float, used for positions/vectors/etc.
`VIPRA::f3dVec` is a `std::vector<VIPRA::f3d>`, used for holding `VIPRA::f3ds`

There is also a `VIPRA::f2d`, though it is very rarely used.

### T.1.1. VIPRA::f3d Utility Member Methods
- `unit() -> VIPRA::f3d`
	- returns a unit vector in the direction of the VIPRA::f3d
- `magnitude() -> float`
	- returns the magnitude of the VIPRA::f3d
- `magnitudesquared() -> float`
	- returns the magnitude squared of the VIPRA::f3d *(saves a std::sqrt call)*
- `dot(const VIPRA::f3d&) -> float`
	- returns the dot product between two VIPRA::f3ds

## T.2. Type Defs
There are several type definitions that are used for clarity:
1. `VIPRA::idx` : for indexes into a container `uint64_t`
2. `VIPRA::size` : for counts of elements in a container `uint64_t`
3. `VIPRA::t_step` : for time step counts `uint64_t`
4. `VIPRA::delta_t` : for changes in time `float`
5. `VIPRA::time_s` : for time in seconds `float`
6. `VIPRA::time_ms` : for time in milliseconds `float`
7. `time_range_s` : for time ranges in seconds `std::pair<VIPRA::time_s, VIPRA::time_s>`
8. `time_range_ms` : for time ranges in milliseconds `std::pair<VIPRA::time_ms, VIPRA::time_ms>`
9. `idxVec` : for vectors of indexes `std::vector<idx>`


# F. Formatting

