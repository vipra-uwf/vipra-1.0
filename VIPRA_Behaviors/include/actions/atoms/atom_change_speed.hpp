#ifndef VIPRA_ATOM_CHANGE_SPEED_HPP
#define VIPRA_ATOM_CHANGE_SPEED_HPP

#include <generated/BehaviorParser.h>
#include <actions/atom.hpp>
#include <values/numeric_value.hpp>

namespace BHVR {
struct AtomChangeSpeed {
  NumericValue change;
  void operator()(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx,
                  VIPRA::delta_t, VIPRA::State&) const;
};
}  // namespace BHVR

#endif