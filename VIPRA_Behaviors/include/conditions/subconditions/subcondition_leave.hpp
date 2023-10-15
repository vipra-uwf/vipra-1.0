#ifndef VIPRA_SUBCONDITION_LEAVE_HPP
#define VIPRA_SUBCONDITION_LEAVE_HPP

#include <conditions/sub_condition.hpp>

#include "definitions/sim_pack.hpp"

namespace BHVR {
class SubConditionLeave {
 public:
  explicit SubConditionLeave(VIPRA::idx);

  bool operator()(Simpack, VIPRA::idx, Target);

 private:
  VIPRA::idx location;

  // TODO (rolland) temporary fix for not having pedestrian memory
  std::vector<bool> left;

 public:
  ~SubConditionLeave() = default;
  SubConditionLeave() = delete;
  SubConditionLeave(const SubConditionLeave&) = default;
  SubConditionLeave& operator=(const SubConditionLeave&) = default;
  SubConditionLeave(SubConditionLeave&&) noexcept = default;
  SubConditionLeave& operator=(SubConditionLeave&&) noexcept = default;
};
}  // namespace BHVR

#endif