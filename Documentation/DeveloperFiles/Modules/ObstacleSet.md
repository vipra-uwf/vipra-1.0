# Obstacle Set

The `Obstacle Set` class handles collision detection with walls/obstacles. As well as the locations of points of interest (ex. exits/windows/etc.)


## Methods To Override

### configure(const VIPRA::Config& configMap) -> void

Takes in the [module parameters](Parameters.md).

Called right after construction.

Params:
- const [VIPRA::Config](Parameters.md)& : module parameters

### initialize(std::unique_ptr<VIPRA::MapData>) -> void

Loads the obstacle data that was loaded from the [MapLoader](Map_Loader.md) class

Params:
- std::unique_ptr<VIPRA::MapData> : map data loaded from file

### getMapDimensions() const -> std::pair<VIPRA::f3d, VIPRA::f3d>

Returns a pair of coordinates, the bottom left corner and top right corner of the rectangle that bounds all obstacles.

### getObjectTypes() const -> const std::vector<std::string>&

Returns the vector of all objects types in the map. (exits, water fountains, etc.)

### getObjectsofType(const std::string& type) const -> const VIPRA::f3dVec&

Returns the vector containing locations of all objects of a given type.

Params:
- const std::string& : object type to get positions of

### nearestObstacle(const VIPRA::PedestrianSet&) const -> VIPRA::f3dVec

Returns a vector containing the coordinates of the nearest obstacle to each pedestrian.

With the index of the obstacle being equal to the index of the pedestrian it is nearest to.

Params:
- const [VIPRA::PedestrianSet](PedestrianSet.md)& : pedestrian set

### nearestObstacleInDirection(const VIPRA::PedestrianSet&) const -> VIPRA::f3dVec

Returns a vector containing the nearest obstacle for each pedestrian in their direction of motion.

With the index of the obstacle being equal to the index of the pedestrian it is nearest to.

Params:
- const [VIPRA::PedestrianSet](PedestrianSet.md)& : pedestrian set

### nearestObstacle(VIPRA::f3d) const -> VIPRA::f3d

Returns the nearest obstacle to a coordinate

Params:
- [VIPRA::f3d](../VIPRATypes.md) : coordinate to find nearest obstacle of

### nearestObstacleInDirection(VIPRA::f3d, VIPRA::f3d) const -> VIPRA::f3d

Returns the nearest obstacle to a coordinate in the given direction

Params:
- [VIPRA::f3d](../VIPRATypes.md) : coordinate to find nearest obstacle of
- [VIPRA::f3d](../VIPRATypes.md) : direction vector (magnitude should have no affect)

### collision(VIPRA::f3d) const -> bool

Returns if a coordinate collides with an obstacle

Params:
- [VIPRA::f3d](../VIPRATypes.md) : coordinate to check

### rayHit(VIPRA::f3d, VIPRA::f3d) const -> float

Returns the distance at which a line intersects an obstacle, -1 if no intersection

Params:
- [VIPRA::f3d](../VIPRATypes.md) : start point, to get distance from
- [VIPRA::f3d](../VIPRATypes.md) : line end point