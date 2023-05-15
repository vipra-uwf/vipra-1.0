#ifndef VIPRA_START_EVENT_HPP
#define VIPRA_START_EVENT_HPP

#include <definitions/behavior_context.hpp>
#include <events/event.hpp>

namespace BHVR {
class SubConditionStart {
 public:
  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx,
                  VIPRA::delta_t) const;
};
}  // namespace BHVR

#endif