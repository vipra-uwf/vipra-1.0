#ifndef VIPRA_BEHAVIOR_CONDITION_HPP
#define VIPRA_BEHAVIOR_CONDITION_HPP

#include <memory>
#include <vector>

#include <spdlog/spdlog.h>

#include <conditions/condition_map.hpp>
#include <conditions/sub_condition.hpp>
#include <definitions/behavior_context.hpp>
#include <definitions/type_definitions.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

namespace Behaviors {
class Condition {
 public:
  Condition(const Condition&) = delete;
  Condition& operator=(const Condition&) = delete;

  Condition() = default;
  ~Condition() = default;

  Condition(Condition&&) noexcept;
  Condition& operator=(Condition&&) noexcept;

  void addAndOr(bool);

  template <typename... P> void addSubCondition(const std::string& condName, P... params) {
    auto iter = CondMap.find(condName);
    if (iter == CondMap.end()) {
      spdlog::error("Invalid SubCondition: {}", condName);
      exit(1);
      return;
    }

    auto                          func = std::any_cast<std::function<std::unique_ptr<SubCondition>(P...)>>(iter->second);
    std::unique_ptr<SubCondition> cond = func(std::forward<P>(params)...);
    conditions.emplace_back(std::move(cond));
  }

  bool evaluate(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx, VIPRA::delta_t)
      const;

 private:
  std::vector<bool>                          operations;
  std::vector<std::unique_ptr<SubCondition>> conditions;
};
}  // namespace Behaviors

#endif