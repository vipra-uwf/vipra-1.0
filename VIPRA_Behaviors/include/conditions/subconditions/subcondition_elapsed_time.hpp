#ifndef VIPRA_SUBCONDITION_ELAPSED_TIME
#define VIPRA_SUBCONDITION_ELAPSED_TIME

#include <conditions/sub_condition.hpp>
#include <definitions/dsl_types.hpp>
#include <events/event.hpp>

namespace BHVR {
class SubConditionElapsedTimeFromEvent {
 public:
  SubConditionElapsedTimeFromEvent(VIPRA::delta_t, VIPRA::idx);
  SubConditionElapsedTimeFromEvent(const SubConditionElapsedTimeFromEvent&) = default;
  SubConditionElapsedTimeFromEvent& operator=(const SubConditionElapsedTimeFromEvent&) = default;
  SubConditionElapsedTimeFromEvent(SubConditionElapsedTimeFromEvent&&) noexcept = default;
  SubConditionElapsedTimeFromEvent& operator=(SubConditionElapsedTimeFromEvent&&) noexcept = default;

  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx,
                  VIPRA::delta_t) const;

 private:
  VIPRA::delta_t requiredTime;
  VIPRA::idx     event;
};
}  // namespace BHVR

#endif