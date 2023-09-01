# Parameter Sweep

A Parameter sweep is run with the same command as a simple simulation.

```
// under `/VIPRA/`

./VIPRA_SIM *# Simulations* *Sim Config Path* *Module Params Path* *Pedestrians File Path* *Obstacle File Path*
```

## Module Parameters

The Module Parameters file needs to be editted to run a parameter sweep.

Module parameters created for a parameter sweep can be used in a single simulation run. However, any parameters that have a Randomized value type will be randomized.

### Randomized Value Types

#### 1. Range Values

Range values have a minimum and a maximum, with the exact value used being randomized between those values.

Range values only work for `float` parameter values.

Example:
```
 "goals": {
    "range_value_example" : {
      "min" : 1,
      "max" : 4.2
    }
 }
```

#### 2. Select Values

Select values randomly choose a value from a list of values.

Select values can apply for any type, but generally each choice should be of the same type as each other.

Example:
```
  "goals": {
    "select_value_example": [ "value1", "value2", "value3" ]
  }

// or

  "goals": {
    "select_value_example": [ 1, 4, 26 ]
  }
```

### Example

Here is a shortened version of the Calm Pedestrian Model's .mm file
```
{
  "id"          : "VbGjNW5NCkOmKAxvFmz5KwUV2zz469",
  "name"        : "calm_pedestrian_model",
  "description" : "The CALM Pedestrian dynamics model",
  "params"      : [
    {
      "name": "meanMass",
      "type": "float",
      "description": "Mean value for pedestrian mass",
      "multiple": false
    },
    {
      "name": "massStdDev",
      "type": "float",
      "description": "Standard Deviation for pedestrian mass",
      "multiple": false
    }
  ],
  "className"   : "CalmPedestrianModel",
  "type"        : "pedestrian_dynamics_model"
}
```

A simple module parameters file might look like the following
```
{
  ... other modules

  "pedestrian_dynamics_model": {
    "meanMass": 1.0,
    "massStdDev": 0.1
  },

  ... other modules
}
```

A possible parameter sweep module parameters files might look like this:
```
{
  ... other modules

  "pedestrian_dynamics_model": {
    "meanMass": { "min": 0.8, "max": 1.2 },  // Range value, chooses random value between 0.8 and 1.2
    "massStdDev": [ 0.08, 0.1, 0.15, 0.2 ]   // Select value, chooses one of the 4 values randomly
  }

  ... other modules
}
```

## Randomization Seed

Parameters are randomized using a the `seed` value from the simulation configuration file.

Using the same seed will produce the same set of simulations.

Example: 
```
// sim.config
{
  "id": "ExampleConfig",
  "name": "exampleconfig",
  "description": "This is the example config file",
  "seed": 12345,              // This seed value is what affects the randomization
  "modules": {
    ... modules
  }
}
```

## Multi-Threaded Parameter Sweep

Using `MPI` VIPRA can run a parameter sweep in parallel over multiple cores.

This example uses `openMPI`, though other `MPI` programs exist.

```
mpirun -np *# threads* ./VIPRA_SIM *# Simulations* *Sim Config Path* *Module Params Path* *Pedestrians File Path* *Obstacle File Path*
```

This will spread *# Simulations* over *# threads* as evenly as possible.

## Parameter Sweep Output

Simulation Results are produced through an [output sink](./output/Output.md) just as a simple simulation run.

The exact parameters used for a given simulation are written out to `/VIPRA/params/*id*`.
- with \*id* being the same as the filename of the output