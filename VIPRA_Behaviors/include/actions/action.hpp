#ifndef ACTION_HPP
#define ACTION_HPP

#include <spdlog/spdlog.h>

#include <actions/atom.hpp>
#include <conditions/condition.hpp>
#include <definitions/behavior_context.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <optional>
#include <pedestrian_set/pedestrian_set.hpp>

namespace Behaviors {
/**
 * An action is something the pedestrian does, such as stopping movement.
 */
class Action {
 public:
  Action(const Action&) = delete;
  Action& operator=(const Action&) = delete;

  ~Action() = default;
  Action() = default;

  Action(Action&&) noexcept;
  Action& operator=(Action&&) noexcept;

  void performAction(PedestrianSet&,
                     ObstacleSet&,
                     Goals&,
                     BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>);

  void addCondition(Condition&&);
  void addAtom(Atom&&);

 private:
  std::vector<Atom>        atoms;
  std::optional<Condition> condition;
};
}  // namespace Behaviors

#endif