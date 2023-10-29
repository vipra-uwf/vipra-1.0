# Running The Simulation

This page only goes over running a simple simulation. VIPRA can also be used to run a [Parameter Sweep](ParameterSweep.md).

The command for running a simple simulation is:
```
// under `VIPRA/`

./VIPRA_SIM 1 *Sim Config Path* *Module Params Path* *Pedestrians File Path* *Obstacle File Path*
```

An example simulation config and module parameters are found in `SimConfigs/ExampleConfig/`

Example Command using the example config and the A320 obstacle map:
```
// under `VIPRA/`

./VIPRA_SIM 1 ../SimConfigs/ExampleConfig/sim.config ../SimConfigs/ExampleConfig/module_params.json ../Maps/pedestrian_maps/a320_144_pedestrians/a320_144_pedestrians.pmap ../Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.omap
```

Simply replace the paths to change what map or config is being used.

The second argument `1` is explained in [Parameter Sweep](ParameterSweep.md).

---

# Simulation Config

The simulation config file tells the simulation which modules to use for a run.

Simulation configs are generally placed under `SimConfigs/*config name*/`. Though, they can be placed anywhere.

More on simulation config files is in **Changing Simulation Modules** below.

---

# Module Params

The module parameters file provides the parameters for each module.

The exact parameters for each module can be found in that modules `.mm` file.

Example:
```
// Modules/Goals/calm_goals/calm_goals.mm
{
    "id": "Xz59g1o8HcsnMJlKaiYw00wZ19rB7P",
    "name": "calm_goals",
    "description": "TODO",
    "params": [                                     // "params" lists the parameters the module accepts
        {
            "name": "endGoalType",
            "type": "string",
            "description": "Type of Object that All Pedestrians Attempt to move towards, available options depend on obstacle map used"
        },
        {
            "name": "goalRange",
            "type": "float",
            "description": "Range from a goal a pedestrian needs to reach before considered reaching a goal"
        }
    ],
    "className": "CalmGoals",
    "type": "goals"
}

// module_params.json

{
  ... other modules

  "goals": {
    "endGoalType": "exit",
    "gridSize": 0.1
  },

  ... other modules
}

```

---

## Changing Simulation Modules

Each simulation run is given a simulation configuration file. These are, generally, placed under the `SimConfigs` directory. Look at the example config file under `SimConfigs/ExampleConfig/sim.config`.

Each module has a unique ID, the simulation config file has a `modules` object that holds which modules to use for each module type. 

To use a different module simply switch the ID for the module type in the simulation config.

Example:
```
{
  "id": "ExampleConfig",
  "name": "exampleconfig",
  "description": "this is a test config",
  "seed": 12345,
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
  "seed": 12345
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

### Parameter Types

Each parameter has a "type".

The current types are:
- "string" : any sequence of characters or numbers, surrounded by double quotations
- "float" : any numerical value

---

# Using Behaviors

VIPRA Behaviors are explained in [VIPRA Behaviors](./behaviors/VIPRA_Behaviors.md)

Behavior files are held under `Behaviors/`.

To use behaviors in simulations add the behavior's file name (without the `.behavior`) to the module parameters file under `human_behavior_model`.

Example:
```
// Using the "example.behavior" Behavior file

"human_behavior_model": {
    "seed": 4525,
    "behaviors": [
      "example"       // Add behavior name here without ".behavior"
    ]
},
```

---

[Back to Researchers Page](./Researchers.md)