#ifndef VIPRA_SUBCONDITION_EVENT_ENDING_HPP
#define VIPRA_SUBCONDITION_EVENT_ENDING_HPP

#include "conditions/sub_condition.hpp"
#include "definitions/sim_pack.hpp"
#include "events/event.hpp"
#include "util/class_types.hpp"

namespace BHVR {
class SubConditionEventEnding {
  NON_DEFAULT_CONSTRUCTIBLE(SubConditionEventEnding)
  COPYABLE(SubConditionEventEnding)
  MOVEABLE(SubConditionEventEnding)
 public:
  explicit SubConditionEventEnding(VIPRA::idx);

  [[nodiscard]] auto operator()(Simpack, VIPRA::idx, Target) const -> bool;

 private:
  VIPRA::idx _event;
};
}  // namespace BHVR

#endif