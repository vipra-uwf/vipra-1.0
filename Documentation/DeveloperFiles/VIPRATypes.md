# VIPRA Types

## VIPRA::f3d

include: `Base/definitions/dimensions.hpp`

`VIPRA::f3d` is used for coordinate values. More information can be found in the API documentation

## VIPRA::State

include: `Base/definitions/state.hpp`

`VIPRA::State` is used to hold the new positions/velocities for pedestrians.

## Type Definitions

include: `Base/definitions/type_definitions.hpp`

The following are type definitions commonly Used for better understanding of the inteded use of variables/parameters/etc.
 
### goal = VIPRA::f3d
Used for goal points
### pcoord = VIPRA::f3d
Used for pedestrian coordinates
### veloc = VIPRA::f3d
Used for velocities
### dist = float
Used for distance 
### idx = uint64_t
Used for indexes into containers 
### size = uint64_t
Used for a count of container elements
### cnt = uint64_t
Used for counting
### t_step = uint64_t
Used for time step count 
### delta_t = float
Used for a change in time, in seconds 
### time_s = float
Used for a time value, in seconds 
### time_ms = float
Used for a time value, in milliseconds
### time_range_s = std::pair<VIPRA::time_s, VIPRA::time_s>
Used for a range of time, in seconds
### time_range_ms = std::pair<VIPRA::time_ms, VIPRA::time_ms>
Used for a range of time, in milliseconds
### idxVec = std::vector<idx>
Used for a vector of indexes

---

## Constexpr Values

### VIPRA::idx_INVALID : VIPRA::idx = std::numeric_limits\<VIPRA::idx>::max()
Used for an invalid index, where an exception is the wrong option