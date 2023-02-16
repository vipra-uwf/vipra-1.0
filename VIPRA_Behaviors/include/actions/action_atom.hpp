#ifndef VIPRA_ACTION_ATOM_HPP
#define VIPRA_ACTION_ATOM_HPP

#include "definitions/behavior_context.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

namespace Behaviors {
class Atom {
 public:
  virtual ~Atom() = default;
  virtual void performAction(const PedestrianSet&,
                             const ObstacleSet&,
                             const Goals&,
                             const BehaviorContext&,
                             VIPRA::idx,
                             VIPRA::delta_t,
                             std::shared_ptr<VIPRA::State>) = 0;
};
}  // namespace Behaviors

#endif