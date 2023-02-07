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

  void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&);
  void timestep(const ObstacleSet&, const PedestrianSet&, const Goals&, std::shared_ptr<VIPRA::State>, VIPRA::delta_t);

  template <typename S, typename... P, class = typename std::enable_if<std::is_base_of<Selector, S>::value>::type>
  void addSelector(P... params) {
    selector = std::make_unique<S>(std::forward<P>(params)...);
  }

  template <typename PT, typename... P, class = typename std::enable_if<std::is_base_of<Transition, PT>::value>::type>
  void addPedTransition(P... params) {
    pedTransitions.emplace_back(std::make_unique<PT>(std::forward<P>(params)...));
  }

  template <typename ET, typename... P, class = typename std::enable_if<std::is_base_of<Transition, ET>::value>::type>
  void addEnvTransition(P... params) {
    envTransitions.emplace_back(std::make_unique<ET>(std::forward<P>(params)...));
  }

  void addAction(Action&&);

  void addParameter(std::string);

 private:
  std::string                              name;
  std::unique_ptr<Selector>                selector;
  std::vector<std::unique_ptr<Transition>> pedTransitions;
  std::vector<std::unique_ptr<Transition>> envTransitions;
  std::vector<Action>                      pedActions;
  BehaviorContext                          context;

  std::vector<std::string> parameters;
};

#endif
