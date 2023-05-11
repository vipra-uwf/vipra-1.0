#ifndef VIPRA_START_EVENT_HPP
#define VIPRA_START_EVENT_HPP

#include <definitions/behavior_context.hpp>
#include <events/event.hpp>

namespace Behaviors {
struct SubCondition_Start {
  bool operator()(const PedestrianSet&,
                  const ObstacleSet&,
                  const Goals&,
                  const BehaviorContext&,
                  VIPRA::idx,
                  VIPRA::delta_t);
};
}  // namespace Behaviors

#endif