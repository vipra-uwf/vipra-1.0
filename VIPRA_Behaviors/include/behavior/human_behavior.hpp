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
  HumanBehavior& operator=(const HumanBehavior&) = delete;
  HumanBehavior(const HumanBehavior&) = delete;

  HumanBehavior() = default;
  ~HumanBehavior() = default;

  HumanBehavior(std::string);
  HumanBehavior(HumanBehavior&&) noexcept;
  HumanBehavior& operator=(HumanBehavior&&) noexcept;

  const std::string& getName() const noexcept;

  void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&);
  void timestep(const PedestrianSet&, const ObstacleSet&, const Goals&, std::shared_ptr<VIPRA::State>, VIPRA::delta_t);

  void addAction(Action&&);
  void addPedTransition(Transition&&);
  void addEnvTransition(Transition&&);
  void addParameter(std::string);

  template <typename S, typename... P, class = typename std::enable_if<std::is_base_of<Selector, S>::value>::type>
  void addSelector(P... params) {
    selector = std::make_unique<S>(std::forward<P>(params)...);
  }

 private:
  std::string               name;
  std::unique_ptr<Selector> selector;
  std::vector<Transition>   pedTransitions;
  std::vector<Transition>   envTransitions;
  std::vector<Action>       pedActions;
  BehaviorContext           context;

  std::vector<std::string> parameters;
};

#endif
