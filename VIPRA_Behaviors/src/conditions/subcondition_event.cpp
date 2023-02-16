

#include <conditions/subconditions/subcondition_event.hpp>

namespace Behaviors {
SubCondition_Event::SubCondition_Event(Event* event) : started(false), returned(false) {
  event->onStart([&]() { started = true; });
}

bool
SubCondition_Event::operator()(const PedestrianSet&,
                               const ObstacleSet&,
                               const Goals&,
                               const BehaviorContext&,
                               VIPRA::idx,
                               VIPRA::delta_t) {
  if (!returned) {
    return started;
  }

  return false;
}
}  // namespace Behaviors