#ifndef VIPRA_SUB_CONDITION_HPP
#define VIPRA_SUB_CONDITION_HPP

#include "../definitions/behavior_context.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

class SubCondition {
 public:
  virtual bool operator()(const ObstacleSet&,
                          const PedestrianSet&,
                          const Goals&,
                          const BehaviorContext&,
                          VIPRA::idx) const = 0;
};

#endif