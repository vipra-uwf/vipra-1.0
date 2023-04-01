#ifndef VIPRA_ATOM_BE_HPP
#define VIPRA_ATOM_BE_HPP

#include <grammar/generated/BehaviorParser.h>

#include <actions/action_atom.hpp>

#include <definitions/dsl_types.hpp>

namespace Behaviors {

class Atom_Be : public Atom {
 public:
  Atom_Be() = delete;

  Atom_Be(stateUID);

  void performAction(PedestrianSet&,
                     ObstacleSet&,
                     Goals&,
                     BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>) override;

 private:
  stateUID state;
};
}  // namespace Behaviors

#endif