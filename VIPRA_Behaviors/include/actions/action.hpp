#ifndef ACTION_HPP
#define ACTION_HPP

#include <optional>

#include <spdlog/spdlog.h>

#include "definitions/behavior_context.hpp"
#include "definitions/sim_pack.hpp"
#include "definitions/type_definitions.hpp"

#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

#include "actions/atom.hpp"
#include "conditions/condition.hpp"

#include "targets/target_selector.hpp"
#include "targets/target_selectors/target_self.hpp"

#include "time/time.hpp"

#include "util/class_types.hpp"
#include "util/timed_latch.hpp"

#include "values/numeric_value.hpp"

namespace BHVR {
class Action {
  DEFAULT_CONSTRUCTIBLE(Action)
  COPYABLE(Action)
  MOVEABLE(Action)

 public:
  void initialize(Simpack pack);

  void perform_action(Simpack pack, VIPRA::idx);

  void add_condition(const Condition&);
  void add_atom(const Atom&);
  void add_duration(const BHVR::NumericValue&);
  void add_target(TargetSelector&&);

 private:
  std::vector<Atom>                   _atoms;
  std::optional<Condition>            _condition;
  std::optional<TimedLatchCollection> _duration;
  TargetSelector                      _targets{TargetSelf{}};

  [[nodiscard]] inline auto evaluate(Simpack pack, VIPRA::idx, Target) -> bool;
};

}  // namespace BHVR

#endif