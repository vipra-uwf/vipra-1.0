#ifndef VIPRA_ATOM_CHANGE_SPEED_HPP
#define VIPRA_ATOM_CHANGE_SPEED_HPP

#include <generated/BehaviorParser.h>
#include <actions/atom.hpp>

namespace BHVR {
struct AtomChangeSpeed {
  float change;
  void  operator()(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx, VIPRA::delta_t, VIPRA::State&) const;
};
}  // namespace BHVR

#endif