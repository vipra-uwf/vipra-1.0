#ifndef VIPRA_SUBCONDITION_EVENT_OCCURRING_HPP
#define VIPRA_SUBCONDITION_EVENT_OCCURRING_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
class SubConditionEventOccurring {
 public:
  explicit SubConditionEventOccurring(VIPRA::idx);

  bool operator()(Simpack, VIPRA::idx, Target) const;

 private:
  VIPRA::idx event;

 public:
  ~SubConditionEventOccurring() = default;
  SubConditionEventOccurring() = delete;
  SubConditionEventOccurring(const SubConditionEventOccurring&) = default;
  SubConditionEventOccurring& operator=(const SubConditionEventOccurring&) = default;
  SubConditionEventOccurring(SubConditionEventOccurring&&) noexcept = default;
  SubConditionEventOccurring& operator=(SubConditionEventOccurring&&) noexcept = default;
};
}  // namespace BHVR

#endif