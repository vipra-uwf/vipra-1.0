

#include "conditions/subconditions/subcondition_exists.hpp"

#include <spdlog/spdlog.h>
#include <utility>

#include "targets/target.hpp"

namespace BHVR {
SubConditionExists::SubConditionExists(TargetModifier modifier, SubConditionAttribute condition)
    : _modifier(std::move(modifier)), _attributeCond(condition) {}

/**
 * @brief Returns true if there exists a target that matches the modifier and attribute condition
 * 
 */
auto SubConditionExists::operator()(Simpack pack, VIPRA::idx self, Target /*unused*/) const -> bool {
  for (auto idx : pack.get_groups().at(0)) {
    if (_modifier.check(pack, idx, self) && _attributeCond(pack, self, {TargetType::PEDESTRIAN, idx})) {
      return true;
    }
  }

  return false;
}
}  // namespace BHVR