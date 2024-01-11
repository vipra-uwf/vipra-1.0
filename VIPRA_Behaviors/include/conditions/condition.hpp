#ifndef VIPRA_BEHAVIOR_CONDITION_HPP
#define VIPRA_BEHAVIOR_CONDITION_HPP

#include <memory>
#include <optional>
#include <vector>

#include <spdlog/spdlog.h>

#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

#include "conditions/sub_condition.hpp"
#include "definitions/sim_pack.hpp"
#include "definitions/type_definitions.hpp"
#include "targets/target.hpp"
#include "util/class_types.hpp"
#include "util/timed_latch.hpp"

namespace BHVR {
class Condition {
  DEFAULT_CONSTRUCTIBLE(Condition)
  COPYABLE(Condition)
  MOVEABLE(Condition)
 public:
  enum class OP { AND, OR, NOT };

  void initialize(const Simpack&);

  void evaluate(Simpack, const VIPRA::idxVec&, std::vector<bool>&, const std::vector<Target>&,
                std::optional<TimedLatchCollection>&);

  void add_operation(OP oper) { _steps.emplace_back(oper); }
  void add_subcondition(SubCondition&& condition) { _conditions.emplace_back(condition); }

 private:
  std::vector<SubCondition> _conditions;
  std::vector<OP>           _steps;
};
}  // namespace BHVR

#endif