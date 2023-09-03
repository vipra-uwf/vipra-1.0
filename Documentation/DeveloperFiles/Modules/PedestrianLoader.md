# Pedestrain Loader

The `Pedestrain Loader` class handles loading pedestrian starting locations from a file.

## Methods To Override

### configure(const VIPRA::Config& configMap) -> void

Takes in the module parameters.

Params:
- const [VIPRA::Config](Parameters.md)& : module parameters

### initialize() -> void

Used to setup any necessary components before loading the map file

Called before `loadPedestrians()`


### loadPedestrians(const std::string&) const -> std::vector<VIPRA::pcoord>

Loads the pedestrian start positions from the file at the provided path.

Params:
- const std::string& : file path to pedestrian start positions