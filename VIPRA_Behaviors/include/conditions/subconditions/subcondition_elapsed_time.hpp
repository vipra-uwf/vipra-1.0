#ifndef VIPRA_SUBCONDITION_ELAPSED_TIME
#define VIPRA_SUBCONDITION_ELAPSED_TIME

#include <conditions/sub_condition.hpp>
#include <definitions/dsl_types.hpp>
#include <events/event.hpp>

namespace Behaviors {
class SubCondition_Elapsed_Time_From_Event : public SubCondition {
 public:
  SubCondition_Elapsed_Time_From_Event(VIPRA::delta_t, Event*);
  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx, VIPRA::delta_t)
      override;

 private:
  bool           started;
  VIPRA::delta_t elapsedTime;
  VIPRA::delta_t requiredTime;
};
}  // namespace Behaviors

#endif