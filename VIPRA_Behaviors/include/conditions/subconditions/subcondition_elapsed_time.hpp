#ifndef VIPRA_SUBCONDITION_ELAPSED_TIME
#define VIPRA_SUBCONDITION_ELAPSED_TIME

#include <conditions/sub_condition.hpp>
#include <definitions/dsl_types.hpp>
#include <definitions/type_definitions.hpp>
#include <events/event.hpp>
#include <time/time.hpp>
#include <util/timed_latch.hpp>
#include <values/numeric_value.hpp>

namespace BHVR {
/**
 * @brief Returns true after a given duration from an event starting
 * 
 */
class SubConditionElapsedTimeFromEvent {
 public:
  SubConditionElapsedTimeFromEvent(BHVR::NumericValue, VIPRA::idx);

  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&,
                  const BehaviorContext&, VIPRA::idx, VIPRA::delta_t);

 private:
  VIPRA::idx         event;
  BHVR::NumericValue requiredTime;
  VIPRA::time_s      startTime;

 public:
  ~SubConditionElapsedTimeFromEvent() = default;
  SubConditionElapsedTimeFromEvent(const SubConditionElapsedTimeFromEvent&) = default;
  SubConditionElapsedTimeFromEvent& operator=(const SubConditionElapsedTimeFromEvent&) =
      default;
  SubConditionElapsedTimeFromEvent(SubConditionElapsedTimeFromEvent&&) noexcept = default;
  SubConditionElapsedTimeFromEvent& operator=(
      SubConditionElapsedTimeFromEvent&&) noexcept = default;
};
}  // namespace BHVR

#endif