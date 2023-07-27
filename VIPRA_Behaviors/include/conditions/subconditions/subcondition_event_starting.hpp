#ifndef VIPRA_SUBCONDITION_EVENT_STARTING_HPP
#define VIPRA_SUBCONDITION_EVENT_STARTING_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
class SubConditionEventStarting {
 public:
  explicit SubConditionEventStarting(VIPRA::idx);

  bool operator()(Simpack, VIPRA::idx, Target) const;

 private:
  VIPRA::idx event;

 public:
  ~SubConditionEventStarting() = default;
  SubConditionEventStarting() = delete;
  SubConditionEventStarting(const SubConditionEventStarting&) = default;
  SubConditionEventStarting& operator=(const SubConditionEventStarting&) = default;
  SubConditionEventStarting(SubConditionEventStarting&&) noexcept = default;
  SubConditionEventStarting& operator=(SubConditionEventStarting&&) noexcept = default;
};
}  // namespace BHVR

#endif