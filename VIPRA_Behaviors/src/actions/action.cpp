
#include <spdlog/spdlog.h>
#include <actions/action.hpp>
#include <definitions/sim_pack.hpp>
#include <targets/target.hpp>
#include <time/time.hpp>
#include <util/timed_latch.hpp>
#include <utility>
#include <values/numeric_value.hpp>
#include "targets/target_selector.hpp"

namespace BHVR {

void Action::initialize(Simpack pack) {
  if (duration) {
    duration->resize(pack.pedSet.getNumPedestrians());
  }
}

/**
 * @brief Checks that the action conditions are met, if it is, each atom is run on the pedestrian
 * 
 * @param pedSet : pedestrian set module
 * @param obsSet : obstacle set module
 * @param goals : goals module
 * @param context : behavior context
 * @param pedIdx : index of pedestrian to affect
 * @param dT : simulation timestep size
 * @param state : state object to apply changes to
 */
void Action::performAction(Simpack pack, VIPRA::idx pedIdx, VIPRA::State& state) {
  Target self = {TargetType::PEDESTRIAN, pedIdx};
  Target target = targets.getTarget(pack, self);
  if (evaluate(pack, pedIdx, target)) {
    std::for_each(atoms.begin(), atoms.end(), [&](Atom& atom) { atom(pack, self, target, state); });
  }
}

/**
 * @brief Sets the condition for the action
 * 
 * @param cond : Condition object
 */
void Action::addCondition(const Condition& cond) { condition = cond; }

/**
 * @brief Adds an atom to the action
 * 
 * @param atom : 
 */
void Action::addAtom(const Atom& atom) { atoms.emplace_back(atom); }

/**
 * @brief Adds a time range for the action to take place
 * 
 * @param range
 */
void Action::addDuration(const BHVR::NumericValue& dur) { duration = TimedLatchCollection(dur); }

/**
 * @brief Checks whether the condition should
 * 
 */
inline bool Action::evaluate(Simpack pack, VIPRA::idx pedIdx, Target target) {
  if (!condition) {
    return true;
  }

  bool run = condition->evaluate(pack, pedIdx, target);
  if (duration) {
    if (run) {
      duration->latch(pack.context.elapsedTime, pedIdx);
    }

    return duration->check(pack.context.elapsedTime, pedIdx);
  }

  return run;
}

void Action::addTarget(TargetSelector&& target) { targets = target; }

}  // namespace BHVR