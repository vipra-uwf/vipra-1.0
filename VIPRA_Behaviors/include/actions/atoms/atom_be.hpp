#ifndef VIPRA_ATOM_BE_HPP
#define VIPRA_ATOM_BE_HPP

#include <actions/atom.hpp>
#include <definitions/dsl_types.hpp>

namespace Behaviors {

struct Atom_Be {
  stateUID state;
  void     operator()(PedestrianSet&,
                  ObstacleSet&,
                  Goals&,
                  BehaviorContext&,
                  VIPRA::idx,
                  VIPRA::delta_t,
                  std::shared_ptr<VIPRA::State>);
};
}  // namespace Behaviors

#endif