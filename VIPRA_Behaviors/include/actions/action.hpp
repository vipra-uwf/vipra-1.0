#ifndef ACTION_HPP
#define ACTION_HPP

#include <optional>

#include <spdlog/spdlog.h>

#include <actions/atom.hpp>
#include <conditions/condition.hpp>
#include <definitions/behavior_context.hpp>
#include <definitions/type_definitions.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include <util/timed_latch.hpp>

namespace BHVR {
class Action {
 public:
  ~Action() = default;
  Action() = default;
  Action(const Action&) = default;
  Action& operator=(const Action&) = default;
  Action(Action&&) noexcept = default;
  Action& operator=(Action&&) noexcept = default;

  void performAction(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx, VIPRA::delta_t, VIPRA::State&);

  void addCondition(const Condition&);
  void addAtom(const Atom&);
  void addDuration(VIPRA::time_range_s, BHVR::seed);

 private:
  std::vector<Atom>                    atoms;
  std::optional<Condition>             condition;
  std::optional<BHVR::LatchCollection> latches;

  inline bool evaluate(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx, VIPRA::delta_t);
};
}  // namespace BHVR

#endif