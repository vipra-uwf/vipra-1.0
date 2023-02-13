#ifndef VIPRA_SUB_CONDITION_HPP
#define VIPRA_SUB_CONDITION_HPP

#include "../definitions/behavior_context.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

class SubCondition {
 public:
  virtual ~SubCondition() = default;
  virtual bool operator()(const PedestrianSet&,
                          const ObstacleSet&,
                          const Goals&,
                          const BehaviorContext&,
                          VIPRA::idx,
                          VIPRA::delta_t) const = 0;
};

#endif