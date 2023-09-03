# Pedestrian Set

The pedestrian set holds pedestrian locations and velocities, as well as handles nearest neighbor calculations.

## Methods To Override

### configure(const [VIPRA::Config](Parameters.md)&) -> void

Takes in the module parameters.

Params:
- const [VIPRA::Config](Parameters.md)& : module parameters

### initialize(const std::vector<[VIPRA::pcoord](../VIPRATypes.md)>&) -> void

Used to initialize any data structures for holding the pedestrians

Params:
- const std::vector<[VIPRA::pcoord](../VIPRATypes.md)>& : pedestrian starting positions

### updateState([VIPRA::State](../VIPRATypes.md)&) -> void

Takes in a [VIPRA::State](../VIPRATypes.md) and updates pedestrian positions/velocities.

Params:
- [VIPRA::State](../VIPRATypes.md)& : new pedestrian positions/velocities

### getNumPedestrians() const -> [VIPRA::size](../VIPRATypes.md)

Returns the number of pedestrians

### getCoordinates() const -> const [VIPRA::f3dVec](../VIPRATypes.md)&

Returns a vector holding each pedestrian's position.

### getVelocities() const -> const [VIPRA::f3dVec](../VIPRATypes.md)&

Returns a vector holding each pedestrian's velocity

### getPedCoords([VIPRA::idx](../VIPRATypes.md)) const -> const [VIPRA::pcoord](../VIPRATypes.md)&

Returns the given pedestrian's position

Params:
- [VIPRA::idx](../VIPRATypes.md) : pedestrian's index to get position of

### getPedVelocity([VIPRA::idx](../VIPRATypes.md)) const -> const [VIPRA::veloc](../VIPRATypes.md)&

Returns the given pedestrian's velocity

Params:
- [VIPRA::idx](../VIPRATypes.md) : pedestrian's index

### getNearestPedestrian([VIPRA::idx](../VIPRATypes.md), const [VIPRA::ObstacleSet](ObstalceSet.md)&) const -> std::pair<[VIPRA::f3d](../VIPRATypes.md), [VIPRA::idx](../VIPRATypes.md)>

Returns the position and index of the nearest pedestrian to the given pedestrian. (Ignoring pedestrians through walls)

Params:
- [VIPRA::idx](../VIPRATypes.md) : index of pedestrian to find nearest to
- const [VIPRA::ObstacleSet](ObstalceSet.md)& : obstacle set