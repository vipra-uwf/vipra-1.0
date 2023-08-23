# O. Output

**File Path:** [Home](../MainPage.md) / [Developers](Developers.md) / [Output](Output.md)

Output is produced in a JSON format.

Output is buffered throughout the simulation and written to a `Sink` upon completion.

Available `Sinks` are in section O.5.

Output is produced using:
- Simulation Values
- Time Step Values
- Pedestrian Values
- Pedestrian Time Step Values

## O.1 Simulation Values

`Simulation Values` are values for the over all simulation run.

To produce call: `VIPRA::Output::simValue(const char* key, T&& value)`

The value will be placed in:
```
{ "*key*" : "*value*" }
```

## O.2. Time Step Values

`Time Step Values` are values that hold true for a given time step.

`Time Step Values` will ONLY be written to output in time steps that match the `outputFrequency` value for `Output` in the `module_params.json` file.
- Example: `outputFrequency` of 100 will produce output at time step 0, 100, 200, etc.

To produce call: `VIPRA::Output::timestepValue(const char* key, T&& value)`

The value will be placed in:
```
{ 
  "timesteps": [
    ... previous timesteps
    { "*key*" : *value* },
    ... following timesteps
  ]
}
```


## O.3. Pedestrian Values

`Pedestrian Values` are values for a specific pedestrian that hold true for the entire simulation.
- Example: Mass, Speed, etc. (though these examples will generally be found in `module_params.json`, depending on the implementation)

To produce call: `VIPRA::Output::pedValue(VIPRA::idx pedIndex, const char* key, T&& value)`

The value will be placed in:
```
{ 
  "pedestrians" : {
    "*pedIdx*" : {
      "*key*" : *value*
    }
  }
}
```


## O.4. Pedestrian Time Step Values

`Pedestrian Time Step Values` are values for a specific pedestrian in a specific time step.

To produce call: `VIPRA::Output::pedTimestepValue(VIPRA::idx pedIdx, const char* key, T&& value)`

The value will be placed in:
```
{
  "timesteps":[
    "pedestrians":[
      {
        "*key*": *value*
      }
    ]
  ]
}
```

## O.5. Output Sinks

### O.5.1. File Sink

This sink writes output to a JSON file at the path in `filepath` in the `module_params.json` file

---