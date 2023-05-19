#ifndef VIPRA_ATOM_BE_HPP
#define VIPRA_ATOM_BE_HPP

#include <actions/atom.hpp>
#include <definitions/dsl_types.hpp>

namespace BHVR {
struct AtomBe {
  BHVR::stateUID state;
  void operator()(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx, VIPRA::delta_t, VIPRA::State&) const;
};
}  // namespace BHVR

#endif