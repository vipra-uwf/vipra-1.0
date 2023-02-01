#ifndef VIPRA_BEHAVIOR_CONDITION_HPP
#define VIPRA_BEHAVIOR_CONDITION_HPP

#include <memory>
#include <vector>

#include "../definitions/behavior_context.hpp"
#include "definitions/type_definitions.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"
#include "sub_condition.hpp"

class Condition {
 public:
  void addSubCondition(bool, std::unique_ptr<SubCondition>);
  bool evaluate(const ObstacleSet&, const PedestrianSet&, const Goals&, const BehaviorContext&, VIPRA::idx) const;

 private:
  std::vector<bool>                          operations;
  std::vector<std::unique_ptr<SubCondition>> conditions;
};

#endif