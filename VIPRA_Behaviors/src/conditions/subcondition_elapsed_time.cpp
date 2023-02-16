
#include <conditions/subconditions/subcondition_elapsed_time.hpp>

namespace Behaviors {
SubCondition_Elapsed_Time_From_Event::SubCondition_Elapsed_Time_From_Event(VIPRA::delta_t time, Event* event)
  : elapsedTime(0), requiredTime(time) {
  event->onStart([&]() { started = true; });
}

bool
SubCondition_Elapsed_Time_From_Event::operator()(const PedestrianSet&,
                                                 const ObstacleSet&,
                                                 const Goals&,
                                                 const BehaviorContext&,
                                                 VIPRA::idx,
                                                 VIPRA::delta_t dT) {
  if (started) {
    elapsedTime += dT;
    if (elapsedTime >= requiredTime) {
      started = false;
      elapsedTime = 0;
      return true;
    }
  }
  return false;
}
}  // namespace Behaviors