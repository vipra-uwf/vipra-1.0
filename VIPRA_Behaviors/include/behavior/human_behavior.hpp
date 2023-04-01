#ifndef VIPRA_HUMAN_BEHAVIOR_HPP
#define VIPRA_HUMAN_BEHAVIOR_HPP

#include <actions/action.hpp>
#include <definitions/behavior_context.hpp>
#include <definitions/type_definitions.hpp>
#include <events/event.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include <selectors/selector.hpp>
#include <spdlog/spdlog.h>

#include <definitions/dsl_types.hpp>

namespace Behaviors {
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
  void timestep(PedestrianSet&, ObstacleSet&, Goals&, std::shared_ptr<VIPRA::State>, VIPRA::delta_t);

  void   addAction(Action&&);
  void   addParameter(std::string);
  Event* addEvent(Event&&);

  size_t actionCount() const;
  size_t eventCount() const;

  /**
   * @brief Constructs a selector of type S in place
   * 
   * @tparam S : Selector Type
   * @tparam P : Selector Constructor Parameter Types list
   * @param params : parameters to use in selector constructor
   */
  template <typename S, typename... P, class = typename std::enable_if<std::is_base_of<Selector, S>::value>::type>
  void addSelector(P... params) {
    selector = std::make_unique<S>(std::forward<P>(params)...);
  }

 private:
  std::string              name;
  BehaviorContext          context;
  std::vector<std::string> parameters;

  std::unique_ptr<Selector> selector;

  std::vector<Event>  events;
  std::vector<Action> pedActions;
};
}  // namespace Behaviors

#endif
