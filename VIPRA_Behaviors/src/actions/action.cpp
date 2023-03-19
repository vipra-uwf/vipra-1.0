
#include <actions/action.hpp>
#include <actions/atom_map.hpp>
#include <actions/atoms/atom_stop.hpp>

namespace Behaviors {

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
void
Action::performAction(const PedestrianSet&          pedSet,
                      const ObstacleSet&            obsSet,
                      const Goals&                  goals,
                      const BehaviorContext&        context,
                      VIPRA::idx                    pedIdx,
                      VIPRA::delta_t                dT,
                      std::shared_ptr<VIPRA::State> state) {
  bool run = true;
  if (condition) {
    run = condition->evaluate(pedSet, obsSet, goals, context, pedIdx, dT);
  }

  if (run) {
    std::for_each(atoms.begin(), atoms.end(), [&](std::unique_ptr<Atom>& atom) {
      atom->performAction(pedSet, obsSet, goals, context, pedIdx, dT, state);
    });
  }
}

/**
 * @brief Sets the condition for the action
 * 
 * @param cond : Condition object
 */
void
Action::addCondition(Condition&& cond) {
  condition = std::move(cond);
}

// ------------------------------------------ CONSTRUCTORS ------------------------------------------------------------------------

Action::Action(Action&& other) noexcept : atoms(std::move(other.atoms)), condition(std::move(other.condition)) {}

Action&
Action::operator=(Action&& other) noexcept {
  atoms = std::move(other.atoms);
  condition = std::move(other.condition);
  return (*this);
}

// ------------------------------------------ END CONSTRUCTORS ------------------------------------------------------------------------
}  // namespace Behaviors