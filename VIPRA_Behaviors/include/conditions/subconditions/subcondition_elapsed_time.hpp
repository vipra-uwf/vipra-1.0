#ifndef VIPRA_SUBCONDITION_ELAPSED_TIME
#define VIPRA_SUBCONDITION_ELAPSED_TIME

#include "conditions/sub_condition.hpp"
#include "definitions/dsl_types.hpp"
#include "definitions/sim_pack.hpp"
#include "definitions/type_definitions.hpp"
#include "events/event.hpp"
#include "time/time.hpp"
#include "util/class_types.hpp"
#include "util/timed_latch.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {
class SubConditionElapsedTimeFromEvent {
  NON_DEFAULT_CONSTRUCTIBLE(SubConditionElapsedTimeFromEvent)
  COPYABLE(SubConditionElapsedTimeFromEvent)
  MOVEABLE(SubConditionElapsedTimeFromEvent)
 public:
  SubConditionElapsedTimeFromEvent(BHVR::NumericValue time, VIPRA::idx event)
      : _event(event), _requiredTime(std::move(time)) {}

  void operator()(Simpack, const VIPRA::idxVec&, const std::vector<Target>&, std::vector<bool>&,
                  const std::vector<bool>&, BoolOp);

 private:
  VIPRA::idx         _event{};
  BHVR::NumericValue _requiredTime{};
  VIPRA::time_s      _startTime{};
};
}  // namespace BHVR

#endif