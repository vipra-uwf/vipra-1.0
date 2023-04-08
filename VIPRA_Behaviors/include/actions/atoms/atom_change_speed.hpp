#ifndef VIPRA_ATOM_CHANGE_SPEED_HPP
#define VIPRA_ATOM_CHANGE_SPEED_HPP

#include <actions/atom.hpp>
#include <generated/BehaviorParser.h>

namespace Behaviors {
struct Atom_Change_Speed {
  float change;
  void  operator()(PedestrianSet&,
                  ObstacleSet&,
                  Goals&,
                  BehaviorContext&,
                  VIPRA::idx,
                  VIPRA::delta_t,
                  std::shared_ptr<VIPRA::State>);
};
}  // namespace Behaviors

#endif