#ifndef VIPRA_SUBCONDITION_EVENT_HPP
#define VIPRA_SUBCONDITION_EVENT_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>

namespace Behaviors {
struct SubCondition_Event_Occurred {
  SubCondition_Event_Occurred() = delete;
  SubCondition_Event_Occurred(Event*);

  bool operator()(const PedestrianSet&,
                  const ObstacleSet&,
                  const Goals&,
                  const BehaviorContext&,
                  VIPRA::idx,
                  VIPRA::delta_t);

 private:
  bool occurred;
};
}  // namespace Behaviors

#endif