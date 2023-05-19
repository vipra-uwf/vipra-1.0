#ifndef VIPRA_ATOM_STOP_HPP
#define VIPRA_ATOM_STOP_HPP

#include <actions/atom.hpp>

namespace BHVR {
struct AtomStop {
 public:
  void operator()(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx, VIPRA::delta_t, VIPRA::State&) const;
};
}  // namespace BHVR

#endif