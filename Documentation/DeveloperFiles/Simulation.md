# S. Simulation

**File Path:** [Home](../MainPage.md) / [Developers](Developers.md) / [Simulation](Simulation.md)

The main path a simulation takes is as follows:

## S.1. Module Selection / Configuration

Each simulation run is provided a `sim.config` file that holds the IDs for each module the simulation should use. *(one for each type of module)*

An instance of each of these modules is then created and configured, using the `module_params.json` file that is also provided to the simulation.

Each of the modules is then passed into the main simulation object. *Defined in `/VIPRA/Base/simulation/simulation.hpp`*

## S.2. Simulation Loop

The simulation loops until the `Goals` module says that the simulation has met its end goal, or until the maximum number of time steps has been reached.

Each time step the simulation:

1. Calls the `Pedestrian Model` module, which provides a shared pointer to a `State` object that has the updated positions and velocities of each pedestrian
2. Calls the `Policy Model` module, which modifies the `State` given by the `Pedestrian Model` *(Not currently Implemented)*
3. Calls the `Behavior Model` module, which modifies the `State` given by the `Pedestrian Model` and `Policy Model`
4. Checks if output should be written, writes if so
5. Calls the `Goals` module to update any goals
6. Loops

## S.3. Output

Once the simulation is finished the buffered output is written to an output file.

More on output can be found in [Output](Output.md)

---

[Return to Getting Started - Developers](Developers.md)