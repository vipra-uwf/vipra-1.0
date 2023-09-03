
# Goals

The `Goals` module handles pathfinding.

## Methods To Override

```C++
void configure(const VIPRA::Config&);
void initialize(const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&);
void updatePedestrianGoals(const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&, VIPRA::delta_t);
const VIPRA::f3d&    getCurrentGoal(VIPRA::idx) const;
const VIPRA::f3d&    getEndGoal(VIPRA::idx) const;
const VIPRA::f3dVec& getAllCurrentGoals() const;
const VIPRA::f3dVec& getAllEndGoals() const;
VIPRA::delta_t       timeSinceLastGoal(VIPRA::idx) const;
bool                 isPedestianGoalMet(VIPRA::idx) const;
bool                 isSimulationGoalMet() const;
```

### configure(const VIPRA::Config&) -> void

Takes in the [module parameters](Parameters.md) as a nlohmann::json object.

Called right after construction.

Params:
- const [VIPRA::Config](Parameters.md)& : module parameters

### initialize(const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&) -> void

Used to initialize paths for pedestrians.

Called before first time step.

Params:
- const [VIPRA::ObstacleSet](ObstacleSet.md)& : obstacle set
- const [VIPRA::PedestrianSet](PedestrianSet.md)& : pedestrian set

### updatePedestrianGoals(const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&, VIPRA::delta_t) -> void

Used to update each pedestrians current goal.

Called at the end of each time step.

Params:
- const [VIPRA::ObstacleSet](ObstacleSet.md)& : obstacle set
- const VIPRA::PedestainSet& : pedestrian set
- [VIPRA::delta_t](../VIPRATypes.md) : time since last time step

### getCurrentGoal(VIPRA::idx) const -> const VIPRA::f3d&

Returns the coordinates of the current point a given pedestrian is heading towards (not necessarily the end goal).

Params:
- [VIPRA::idx](../VIPRATypes.md) : pedestrian index

### getEndGoal(VIPRA::idx) const -> const VIPRA::f3d&

Returns the coordinates of the given pedestrian's end goal.

Params:
- [VIPRA::idx](../VIPRATypes.md) : pedestrian index

### getAllCurrentGoals() const -> const VIPRA::f3dVec&

Returns a vector with all of the current goals for pedestrians.

### getAllEndGoals() const -> const VIPRA::f3dVec&

Returns a vector with all of the end goals for pedestrians.

### timeSinceLastGoal(VIPRA::idx) const -> VIPRA::delta_t

Returns how long it has been since a pedestrian reached their last goal.

Params:
- [VIPRA::idx](../VIPRATypes.md) : pedestrian idx

### isPedestianGoalMet(VIPRA::idx) const -> bool

Returns true if the given pedestrian has reached their end goal.

Params:
- [VIPRA::idx](../VIPRATypes.md) : pedestrian idx

### isSimulationGoalMet() const -> bool

Returns true if the simulation should exit. (ex. because all pedestrians reached the exit, etc.)