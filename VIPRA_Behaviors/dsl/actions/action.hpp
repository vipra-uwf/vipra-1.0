#ifndef ACTION_HPP
#define ACTION_HPP

#include "../definitions/behavior_context.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

/**
 * An action is something the pedestrian does, such as stopping movement.
 */
class Action {
 public:
  virtual void performAction(const ObstacleSet&,
                             const PedestrianSet&,
                             const Goals&,
                             const BehaviorContext&,
                             VIPRA::idx,
                             VIPRA::delta_t,
                             std::shared_ptr<VIPRA::State>) = 0;
};

#endif