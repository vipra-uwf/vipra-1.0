
#include <actions/action.hpp>
#include <actions/atom_map.hpp>
#include <actions/atoms/atom_stop.hpp>

namespace Behaviors {
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