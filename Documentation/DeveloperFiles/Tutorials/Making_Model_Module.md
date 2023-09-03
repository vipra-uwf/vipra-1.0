# Making a Pedestrian Dynamics Model

This tutorial goes over creating a new pedestrian dynamics model and using it in a simulation.

We will make a dynamics model where pedestrians simply spin in circles.

The steps are the same for each module type with the only differences being:
1. Methods to Override
2. Module Type for .mm file
3. Location in modules.json file

## 1. Create Files

In `Modules/PedestrianDynamicsModel/`, we create a new directory `ExampleModel`.

In this new directory create three files:
1. exampleModel.hpp
2. exampleModel.cpp
3. exampleModel.mm

They should all have the same name.

## 2. Creating The Model Class

In `Modules/PedestrianDynamicsModel/ExampleModel/ExampleModel.hpp`, we create a new class `ExampleModel` that inherits from `VIPRA::PedestrianDynamicsModel`.

```C++
#ifndef VIPRA_EXAMPLE_MODEL_HPP
#define VIPRA_EXAMPLE_MODEL_HPP

#include "pedestrian_model/pedestrian_dynamics_model.hpp"

class ExampleModel : public VIPRA::PedestrianDynamicsModel {
 public:
  void configure(const VIPRA::Config&) override;

  void initialize(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&,
                  const VIPRA::Goals&) override;

  void timestep(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&,
                const VIPRA::Goals&, VIPRA::State&, VIPRA::delta_t, VIPRA::t_step) override;
};
#endif
```

## 3. Creating Module Parameters

Most models will take in parameters for pedestrian mass, max speed, etc. 

Our example model will take in two parameters:
1. Speed - how fast pedestrians move
2. Direction - which direction they spin in

We need to add these parameters, along with other module information, to the module's `.mm` file

```JSON
{
  "id": "zoumfgHMPhEUue9juYzbd",              // A random string sufficiently random to reduce likelyhood of collisions
  "name": "exampleModel",                     // Name of module files (exampleModel.hpp, exampleModel.cpp, exampleModel.mm)
  "description": "An Example Pedestrian dynamics model",  // Simple description, not used right now but will be in the future
  "params": [
    { 
      "name": "speed",    // Parameter name
      "type": "float",    // Parameter type, currently only float or string
      "description": "Speed pedestrians move"  // description of use
    },
    {
      "name": "direction",
      "type": "string",
      "description": "Direction of spin, right or left"
    }
  ],
  "className": "ExampleModel",          // Name of class
  "type": "pedestrian_dynamics_model"   // Module Type, lowercase with spaces replaced by underscores
}
```

## 4. Implementation

Next is to code the implementation of the model.

```C++
#include "exampleModel.hpp"
#include <cmath>

// configure takes in the module parameters from a file
void ExampleModel::configure(const VIPRA::Config& config) {
  speed = config["speed"].get<float>();
  direction = config["direction"].get<std::string>() == "right";

  if (direction) {
    speed *= -1;
  }
}

// initialize sets up any data, stuctures, etc. needed
void ExampleModel::initialize(const VIPRA::PedestrianSet& pedSet,
                              const VIPRA::ObstacleSet&, const VIPRA::Goals&) {
  startingCoords = pedSet.getCoordinates();
}

// timestep is called for each timestep of the simulation, with the new positions/velocities being placed in the passed in VIPRA::State&
void ExampleModel::timestep(const VIPRA::PedestrianSet& pedSet, const VIPRA::ObstacleSet&,
                            const VIPRA::Goals&, VIPRA::State& state, VIPRA::delta_t dT,
                            VIPRA::t_step currStep) {
  const VIPRA::cnt pedCnt = pedSet.getNumPedestrians();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    auto& start = startingCoords.at(i);

    // The VIPRA::State& is were our updates for the next time step are placed
    state.coords[i] = start + (VIPRA::f3d{static_cast<float>(std::cos(speed * currStep * dT)),
                                          static_cast<float>(std::sin(speed * currStep * dT))} *
                               0.25F);
  }
}
```

An actual model will likely use the [PedestrianSet](../Modules/PedestrianSet.md), [ObstacleSet](../Modules/ObstacleSet.md), and [Goals](../Modules/Goals.md).
For collision detection, calculating repulsive forces, finding direction of travel, etc.

Take a look at the other module pages to see what they can do, or see the [modules overview](../Modules/ModulesOverview.md).

## 5. Adding Model to modules.json

We need to add our new module in `VIPRA/modules.json`, this makes it available for use in the simulation.

```JSON
{
  ... other module types

  "pedestrian_dynamics_model": [
    {
      "id": "VbGjNW5NCkOmKAxvFmz5KwUV2zz469",
      "name": "calm_pedestrian_model",
      "className": "CalmPedestrianModel",
      "dirPath": "../Modules/PedestrianDynamicsModel/calm_pedestrian_model"
    },
    {                                   // Add our new model under "pedestrian_dynamics_model"
      "id": "zoumfgHMPhEUue9juYzbd",    // id from .mm file
      "name": "exampleModel",           // file names
      "className": "ExampleModel",      // C++ Class name
      "dirPath": "../Modules/PedestrianDynamicsModel/ExampleModel" // relative or absolute path to module directory (relative from VIPRA/ directory)
    }
  ],

  ... other module types
}
```

## 6. Compilation

Since we added a new module the simulation needs to be recompiled.

In `VIPRA/` run:
```
make release
```

## 7. Running The Simulation

First we need to set the simulation to use our new model, in a new simulation configuration file.

```JSON
{
  "id": "ExampleConfig",
  "name": "exampleconfig",
  "description": "This is the example config file",
  "seed": 2453254734347,
  "modules": {
    "output_sink": "dkSDMqF7Q55UWSxva6pm",
    "pedestrian_set": "jLcPe7ZP8G15AFH5vPb6Wz2DrIVT94",
    "obstacle_set": "MTpemEr4jv5XTvgwO7q54Qco97Pnt4",
    "goals": "Xz59g1o8HcsnMJlKaiYw00wZ19rB7P",
    "pedestrian_dynamics_model": "zoumfgHMPhEUue9juYzbd", // The id of our new model module
    "map_loader": "YKzTon61i8LuHr9l15mCY3",
    "pedestrian_loader": "8oGawQjwJZutb4Us6lDU7R",
    "policy_model": "6xc3IZPOYEcdNhPd8x1kWP",
    "configuration_reader": "5E4V21CyOwU5iMBfH97qlFDn6DlAlf",
    "human_behavior_model": "e3y1yG6PSjrWzsptf6jHdfBElwFugQ",
    "simulation": "QQgWGHtxsVWT1jIEXbxjKG1HA3iqI0"
  }
}
```

Next we can create a [module parameters](../Modules/Parameters.md) file and add our parameters.

```JSON
... other module parameters

  "pedestrian_dynamics_model": {
      "speed": 1.0,
      "direction": "right"
  },

... other module parameters
```

[Run the simulation](../../ResearcherFiles/Running.md), with the paths to the simulation config and parameters.

In my case:
```
./VIPRA_SIM 1 ../SimConfigs/TestConfig/sim.config ../SimConfigs/TestConfig/module_params.json ../Maps/pedestrian_maps/a320_144_pedestrians/a320_144_pedestrians.pmap ../Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.omap
```