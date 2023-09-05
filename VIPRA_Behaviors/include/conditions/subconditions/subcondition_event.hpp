#ifndef VIPRA_SUBCONDITION_EVENT_HPP
#define VIPRA_SUBCONDITION_EVENT_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
class SubConditionEventOccurred {
 public:
  explicit SubConditionEventOccurred(VIPRA::idx);

  bool operator()(Simpack, VIPRA::idx, Target) const;

 private:
  VIPRA::idx event;

 public:
  ~SubConditionEventOccurred() = default;
  SubConditionEventOccurred() = delete;
  SubConditionEventOccurred(const SubConditionEventOccurred&) = default;
  SubConditionEventOccurred& operator=(const SubConditionEventOccurred&) = default;
  SubConditionEventOccurred(SubConditionEventOccurred&&) noexcept = default;
  SubConditionEventOccurred& operator=(SubConditionEventOccurred&&) noexcept = default;
};

}  // namespace BHVR

#endif