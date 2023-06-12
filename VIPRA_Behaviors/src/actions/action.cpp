
#include <actions/action.hpp>
#include <utility>
#include "spdlog/spdlog.h"
#include "time/time.hpp"
#include "util/timed_latch.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {

void Action::initialize(const PedestrianSet& pedSet, const ObstacleSet&, const Goals&,
                        const BehaviorContext&) {
  if (duration) {
    duration->resize(pedSet.getNumPedestrians());
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
void Action::performAction(PedestrianSet& pedSet, ObstacleSet& obsSet, Goals& goals,
                           BehaviorContext& context, VIPRA::idx pedIdx, VIPRA::delta_t dT,
                           VIPRA::State& state) {
  if (evaluate(pedSet, obsSet, goals, context, pedIdx, dT)) {
    std::for_each(atoms.begin(), atoms.end(), [&](Atom& atom) {
      atom(pedSet, obsSet, goals, context, pedIdx, dT, state);
    });
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
void Action::addDuration(const BHVR::NumericValue& dur) {
  duration = TimedLatchCollection(dur);
}

/**
 * @brief Checks whether the condition should
 * 
 */
inline bool Action::evaluate(PedestrianSet& pedSet, ObstacleSet& obsSet, Goals& goals,
                             BehaviorContext& context, VIPRA::idx pedIdx,
                             VIPRA::delta_t dT) {
  if (!condition) {
    return true;
  }

  bool run = condition->evaluate(pedSet, obsSet, goals, context, pedIdx, dT);
  if (duration) {
    if (run) {
      duration->latch(context.elapsedTime, pedIdx);
    }

    return duration->check(context.elapsedTime, pedIdx);
  }

  return run;
}
}  // namespace BHVR