
#include <actions/action.hpp>
#include <actions/atom_map.hpp>
#include <actions/atoms/atom_stop.hpp>

void
Action::performAction(const ObstacleSet&            obsSet,
                      const PedestrianSet&          pedSet,
                      const Goals&                  goals,
                      const BehaviorContext&        context,
                      VIPRA::idx                    pedIdx,
                      VIPRA::delta_t                dT,
                      std::shared_ptr<VIPRA::State> state) {
  std::for_each(atoms.begin(), atoms.end(), [&](std::unique_ptr<Atom>& atom) {
    atom->performAction(obsSet, pedSet, goals, context, pedIdx, dT, state);
  });
}

// ------------------------------------------ CONSTRUCTORS ------------------------------------------------------------------------

Action::Action(Action&& other) noexcept : atoms(std::move(other.atoms)) {}

Action&
Action::operator=(Action&& other) noexcept {
  atoms = std::move(other.atoms);
  return (*this);
}

// ------------------------------------------ END CONSTRUCTORS ------------------------------------------------------------------------