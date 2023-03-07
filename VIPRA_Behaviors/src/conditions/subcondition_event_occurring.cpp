

#include <conditions/subconditions/subcondition_event_occurring.hpp>

namespace Behaviors {
SubCondition_Event_Occurring::SubCondition_Event_Occurring(Event* event) : occurring(false) {
  event->onStart([this]() { this->occurring = true; });
  event->onEnd([this]() { this->occurring = false; });
}

bool
SubCondition_Event_Occurring::operator()(const PedestrianSet&,
                                         const ObstacleSet&,
                                         const Goals&,
                                         const BehaviorContext&,
                                         VIPRA::idx,
                                         VIPRA::delta_t) {
  return occurring;
}
}  // namespace Behaviors