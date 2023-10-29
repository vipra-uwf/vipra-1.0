#ifndef VIPRA_BEHAVIOR_CONDITION_HPP
#define VIPRA_BEHAVIOR_CONDITION_HPP

#include <memory>
#include <vector>

#include <spdlog/spdlog.h>

#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

#include "conditions/sub_condition.hpp"
#include "definitions/type_definitions.hpp"

#include "definitions/sim_pack.hpp"
#include "targets/target.hpp"
#include "util/class_types.hpp"

namespace BHVR {
class Condition {
  DEFAULT_CONSTRUCTIBLE(Condition)
  COPYABLE(Condition)
  MOVEABLE(Condition)
 public:
  void add_and_or(bool);

  void add_sub_condition(SubCondition&&);

  [[nodiscard]] auto evaluate(Simpack, VIPRA::idx, Target) const -> bool;

 private:
  std::vector<bool>         _operations;
  std::vector<SubCondition> _conditions;
};
}  // namespace BHVR

#endif