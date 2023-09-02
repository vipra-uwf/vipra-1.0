# Map Loader

The map loader reads an obstacle map file putting it into a `VIPRA::MapData` derived class.

This allows for loading any format for obstacle maps.

A more standardized format for obstacle maps will be added in the future.

## VIPRA::MapData

The `VIPRA::MapData` is the base class for obstacle map data loaded into the `ObstacleSet` class.

Constructed with
```
MapData(std::string type);
```


## Methods To Override

### configure(const [VIPRA::Config](Parameters.md)&) -> void

Takes in [module parameters](Parameters.md) to configure the module.

Called right after construction.

Params:
- const [VIPRA::Config](Parameters.md)& : module parameters

### initialize() -> void

Used to setup any necessary components before loading the map file

Called before `loadMap()`

### loadMap(const std::string&) const -> std::unique_ptr<VIPRA::MapData>

Loads the map located at the provided file path.

Called before initializing `ObstacleSet`.

Params:
- const std::string& : file path to map