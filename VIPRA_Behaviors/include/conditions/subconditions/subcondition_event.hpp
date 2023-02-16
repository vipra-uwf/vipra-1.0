#ifndef VIPRA_SUBCONDITION_EVENT_HPP
#define VIPRA_SUBCONDITION_EVENT_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>

namespace Behaviors {
class SubCondition_Event : public SubCondition {
 public:
  SubCondition_Event() = delete;

  SubCondition_Event(Event*);

  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx, VIPRA::delta_t)
      override;

 private:
  bool started;
  bool returned;
};
}  // namespace Behaviors

#endif