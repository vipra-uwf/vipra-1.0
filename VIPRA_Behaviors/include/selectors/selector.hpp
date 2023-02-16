#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include <spdlog/spdlog.h>

#include "definitions/behavior_context.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

namespace Behaviors {
/**
 * A selector is used to decide if a pedestrian should be evaluated for a 
 * behavior. It has the entire pedestrian set available to help with the 
 * selection.
 */
class Selector {
 public:
  virtual ~Selector() = default;
  virtual const std::vector<VIPRA::idx>& getSelectedPeds(const PedestrianSet&,
                                                         const ObstacleSet&,
                                                         const Goals&,
                                                         const BehaviorContext&) = 0;

  virtual void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) = 0;
};
}  // namespace Behaviors

#endif