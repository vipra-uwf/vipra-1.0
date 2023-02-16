#ifndef VIPRA_START_EVENT_HPP
#define VIPRA_START_EVENT_HPP

#include <definitions/behavior_context.hpp>
#include <events/event.hpp>

namespace Behaviors {
class SubCondition_Start : public SubCondition {
 public:
  SubCondition_Start() = default;
  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx, VIPRA::delta_t)
      override;
};
}  // namespace Behaviors

#endif