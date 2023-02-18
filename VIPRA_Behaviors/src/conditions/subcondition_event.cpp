

#include <conditions/subconditions/subcondition_event.hpp>

namespace Behaviors {
SubCondition_Event_Occurred::SubCondition_Event_Occurred(Event* event) : occurred(false) {
  event->onStart([&]() { occurred = true; });
}

bool
SubCondition_Event_Occurred::operator()(const PedestrianSet&,
                                        const ObstacleSet&,
                                        const Goals&,
                                        const BehaviorContext&,
                                        VIPRA::idx,
                                        VIPRA::delta_t) {
  return occurred;
}
}  // namespace Behaviors