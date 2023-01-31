#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "../definitions/behavior_context.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"
#include <spdlog/spdlog.h>


/**
 * A selector is used to decide if a pedestrian should be evaluated for a 
 * behavior. It has the entire pedestrian set available to help with the 
 * selection.
 */
class Selector {
 public:
  explicit Selector();
  virtual bool select(const ObstacleSet&, const PedestrianSet&, const Goals&, const BehaviorContext&, VIPRA::idx) = 0;
  virtual void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&);
};

#endif