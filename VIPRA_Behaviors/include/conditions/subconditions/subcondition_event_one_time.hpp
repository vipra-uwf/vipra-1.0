#ifndef VIPRA_SUBCONDITION_EVENT_ONE_TIME_HPP
#define VIPRA_SUBCONDITION_EVENT_ONE_TIME_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>

namespace Behaviors {
struct SubCondition_Event_One_Time {
  SubCondition_Event_One_Time() = delete;
  SubCondition_Event_One_Time(bool, Event*);

  bool operator()(const PedestrianSet&,
                  const ObstacleSet&,
                  const Goals&,
                  const BehaviorContext&,
                  VIPRA::idx,
                  VIPRA::delta_t);

 private:
  bool  run;
  float startTime;
};
}  // namespace Behaviors

#endif