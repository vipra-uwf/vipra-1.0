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
#include "definitions/sim_pack.hpp"
#include "targets/target_selector.hpp"
#include "targets/target_selectors/target_self.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {
class Action {
 public:
  ~Action() = default;
  Action() = default;
  Action(const Action&) = default;
  Action& operator=(const Action&) = default;
  Action(Action&&) noexcept = default;
  Action& operator=(Action&&) noexcept = default;

  void initialize(Simpack pack);

  void performAction(Simpack pack, VIPRA::idx);

  void addCondition(const Condition&);
  void addAtom(const Atom&);
  void addDuration(const BHVR::NumericValue&);
  void addTarget(TargetSelector&&);

 private:
  std::vector<Atom>                   atoms;
  std::optional<Condition>            condition;
  std::optional<TimedLatchCollection> duration;
  TargetSelector                      targets{TargetSelf{}};

  inline bool evaluate(Simpack pack, VIPRA::idx, Target);
};

}  // namespace BHVR

#endif