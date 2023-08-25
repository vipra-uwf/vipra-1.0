# Simulation Output

Output is handled through `Output Sinks`.

## Selecting A Sink

`Sinks` are selected in the `sim.config` file.

```
"modules": {
  ... other modules

  "output_sink": "dkSDMqF7Q55UWSxva6pm",

  ... other modules
}
```

More on `sim.config` files is in [Running The Simulation](../Running.md)

## Available Output Sinks

### File Sink

The `File Sink` outputs to a JSON file at the provided file path from the command line.

ID: dkSDMqF7Q55UWSxva6pm