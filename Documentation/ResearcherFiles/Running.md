# Running The Simulation

The command for running a simulation is:
```
// under `/VIPRA/`

./VIPRA_SIM *Sim Config Path* *Module Params Path* *Pedestrians File Path* *Obstacle File Path* *Output File Path*
```

An example `sim.config` and `module_params.json` are found in `SimConfigs/ExampleConfig/`

Example Command using the example config and the A320 obstacle map:
```
./VIPRA_SIM ../SimConfigs/ExampleConfig/sim.config ../SimConfigs/ExampleConfig/module_params.json ../Maps/pedestrian_maps/a320_144_pedestrians/a320_144_pedestrians.pmap ../Maps/obstacle_maps/a320_144_pedestrians/a320_144_pedestrians.omap output.json
```

Simply replace the paths to change what map or config is being used.

---

# Sim.Config

The `sim.config` file tells the simulation which modules to use for a run.

Simulation configs should be placed under `SimConfigs/*config name*/`

More on `sim.config` files is in **Changing Simulation Modules** below.

---

# Module Params

The `module_params.json` file inputs parameters for each module.

The exact parameters for each module can be found in that modules `.mm` file.

Module parameters should be placed in the same directory as the `sim.config` they apply to.

---

# Changing Simulation Modules

Each simulation run is given a sim.config file. These are found under the `SimConfigs` directory. Look at the example config file under `SimConfigs/ExampleConfig/sim.config`.

Each module has a unique ID, the `sim.config` file has a `modules` object that holds which modules to use for each module type. 

To use a different module simply switch the ID for the module type in the `sim.config`.

Example:
```
{
  "id": "ExampleConfig",
  "name": "exampleconfig",
  "description": "this is a test config",
  "modules": {
    ... other moduels

    "goals": "Xz59g1o8HcsnMJlKaiYw00wZ19rB7P",

    ... other modules
  }
}

{
  "id": "ExampleConfig",
  "name": "exampleconfig",
  "description": "this is a test config",
  "modules": {
    ... other moduels

    "goals": "yUrpDegeM7eWiWd5hUarehn", // Changed module ID to use a different Goal module
    
    ... other modules
  }
}
```

Module IDs are found in their accompanying `.mm` file.

Example:
```
// Modules/Goals/calm_goals/calm_goals.mm

{
    "id": "Xz59g1o8HcsnMJlKaiYw00wZ19rB7P",  // ID used in the sim.config file
    "name": "calm_goals",

    ... other information
}
```

New modules can be added by following the steps in [Adding Modules](./modules/Adding_Modules.md)

---

# Using Behaviors

VIPRA Behaviors are explained in [VIPRA Behaviors](./behaviors/VIPRA_Behaviors.md)

Behaviors are added to a simulation run with the steps in [Adding Behaviors](./behaviors/Adding_Behaviors.md)

---

[Back to Researchers Page](./Researchers.md)