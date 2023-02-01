#ifndef VIPRA_HUMAN_BEHAVIOR_HPP
#define VIPRA_HUMAN_BEHAVIOR_HPP

#include "actions/action.hpp"
#include "definitions/behavior_context.hpp"
#include "definitions/type_definitions.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"
#include "selectors/selector.hpp"
#include "transitions/transition.hpp"
#include <spdlog/spdlog.h>

#include "definitions/dsl_types.hpp"

/**
 * Describes a specific human behavior. Implementations can either define the behavior directly in C++ or use a DSL.
 */
class HumanBehavior {
 public:
  void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&);

  void timestep(const ObstacleSet&, const PedestrianSet&, const Goals&, std::shared_ptr<VIPRA::State>, VIPRA::delta_t);

 private:
  // The definitions of the states as read in by the behavior file.
  std::vector<std::string> stateDefinitions;
  std::vector<std::string> environmentStateDefinitions;

  std::vector<std::unique_ptr<Selector>>   selector;
  std::vector<std::unique_ptr<Transition>> pedTransitions;
  std::vector<std::unique_ptr<Transition>> envTransitions;
  std::vector<std::unique_ptr<Action>>     stateActions;

  BehaviorContext context;
};

#endif
