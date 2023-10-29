#ifndef VIPRA_SUBCONDITION_EVENT_STARTING_HPP
#define VIPRA_SUBCONDITION_EVENT_STARTING_HPP

#include "conditions/sub_condition.hpp"
#include "definitions/sim_pack.hpp"
#include "events/event.hpp"
#include "util/class_types.hpp"

namespace BHVR {
class SubConditionEventStarting {
  NON_DEFAULT_CONSTRUCTIBLE(SubConditionEventStarting)
  COPYABLE(SubConditionEventStarting)
  MOVEABLE(SubConditionEventStarting)
 public:
  explicit SubConditionEventStarting(VIPRA::idx);

  [[nodiscard]] auto operator()(Simpack, VIPRA::idx, Target) const -> bool;

 private:
  VIPRA::idx _event;
};
}  // namespace BHVR

#endif