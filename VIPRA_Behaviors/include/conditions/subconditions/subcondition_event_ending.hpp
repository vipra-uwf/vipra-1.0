#ifndef VIPRA_SUBCONDITION_EVENT_ENDING_HPP
#define VIPRA_SUBCONDITION_EVENT_ENDING_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
class SubConditionEventEnding {
 public:
  explicit SubConditionEventEnding(VIPRA::idx);

  bool operator()(Simpack, VIPRA::idx, Target) const;

 private:
  VIPRA::idx event;

 public:
  ~SubConditionEventEnding() = default;
  SubConditionEventEnding() = delete;
  SubConditionEventEnding(const SubConditionEventEnding&) = default;
  SubConditionEventEnding& operator=(const SubConditionEventEnding&) = default;
  SubConditionEventEnding(SubConditionEventEnding&&) noexcept = default;
  SubConditionEventEnding& operator=(SubConditionEventEnding&&) noexcept = default;
};
}  // namespace BHVR

#endif