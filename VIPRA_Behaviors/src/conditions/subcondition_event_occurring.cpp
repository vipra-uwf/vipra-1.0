

#include <conditions/subconditions/subcondition_event_occurring.hpp>

namespace Behaviors {
SubCondition_Event_Occurring::SubCondition_Event_Occurring(Event* event) : started(false), ended(false) {
  event->onStart([this]() { this->started = true; });
  event->onEnd([this]() { this->ended = true; });
}

bool
SubCondition_Event_Occurring::operator()(const PedestrianSet&,
                                         const ObstacleSet&,
                                         const Goals&,
                                         const BehaviorContext&,
                                         VIPRA::idx,
                                         VIPRA::delta_t) {
  return started && !ended;
}
}  // namespace Behaviors