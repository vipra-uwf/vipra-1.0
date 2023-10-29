#ifndef VIPRA_SUBCONDITION_LEAVE_HPP
#define VIPRA_SUBCONDITION_LEAVE_HPP

#include "conditions/sub_condition.hpp"

#include "definitions/sim_pack.hpp"
#include "util/class_types.hpp"

namespace BHVR {
class SubConditionLeave {
  NON_DEFAULT_CONSTRUCTIBLE(SubConditionLeave)
  COPYABLE(SubConditionLeave)
  MOVEABLE(SubConditionLeave)
 public:
  explicit SubConditionLeave(VIPRA::idx);

  [[nodiscard]] auto operator()(Simpack, VIPRA::idx, Target) -> bool;

 private:
  VIPRA::idx _location;

  // TODO (rolland) temporary fix for not having pedestrian memory
  std::vector<bool> _left;
};
}  // namespace BHVR

#endif