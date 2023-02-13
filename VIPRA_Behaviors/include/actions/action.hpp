#ifndef ACTION_HPP
#define ACTION_HPP

#include <spdlog/spdlog.h>

#include <actions/action_atom.hpp>
#include <actions/atom_map.hpp>
#include <conditions/condition.hpp>
#include <definitions/behavior_context.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

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

  void performAction(const PedestrianSet&,
                     const ObstacleSet&,
                     const Goals&,
                     const BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>);

  void addCondition(Condition&& condition);

  template <typename... P> void addAtom(const std::string& atomName, P... params) {
    auto iter = AtomMap.find(atomName);
    if (iter == AtomMap.end()) {
      spdlog::error("Invalid Action Atom: {}", atomName);
      return;
    }

    auto                  func = std::any_cast<std::function<std::unique_ptr<Atom>(P...)>>(iter->second);
    std::unique_ptr<Atom> atom = func(std::forward<P>(params)...);
    atoms.emplace_back(std::move(atom));
  }

 private:
  std::vector<std::unique_ptr<Atom>> atoms;
  std::optional<Condition>           condition;
};

#endif