#ifndef VIPRA_SUBCONDITION_EVENT_HPP
#define VIPRA_SUBCONDITION_EVENT_HPP

#include "conditions/sub_condition.hpp"
#include "definitions/sim_pack.hpp"
#include "events/event.hpp"
#include "util/class_types.hpp"

namespace BHVR {
class SubConditionEventOccurred {
  NON_DEFAULT_CONSTRUCTIBLE(SubConditionEventOccurred)
  COPYABLE(SubConditionEventOccurred)
  MOVEABLE(SubConditionEventOccurred)
 public:
  explicit SubConditionEventOccurred(VIPRA::idx);

  [[nodiscard]] auto operator()(Simpack, VIPRA::idx, Target) const -> bool;

 private:
  VIPRA::idx _event;
};

}  // namespace BHVR

#endif