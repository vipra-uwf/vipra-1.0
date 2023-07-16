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
#include <time/time.hpp>
#include <util/timed_latch.hpp>
#include "values/numeric_value.hpp"

namespace BHVR {
/**
 * @brief Affects pedestrians based on the atoms added to it
 * 
 */
class Action {
 public:
  ~Action() = default;
  Action() = default;
  Action(const Action&) = default;
  Action& operator=(const Action&) = default;
  Action(Action&&) noexcept = default;
  Action& operator=(Action&&) noexcept = default;

  void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&,
                  const BehaviorContext&);

  void performAction(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx,
                     VIPRA::delta_t, VIPRA::State&);

  void addCondition(const Condition&);
  void addAtom(const Atom&);
  void addDuration(const BHVR::NumericValue&);

 private:
  std::vector<Atom>                   atoms;
  std::optional<Condition>            condition;
  std::optional<TimedLatchCollection> duration;

  inline bool evaluate(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx,
                       VIPRA::delta_t);
};
}  // namespace BHVR

#endif