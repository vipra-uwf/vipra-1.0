#ifndef VIPRA_ATOM_STOP_HPP
#define VIPRA_ATOM_STOP_HPP

#include <actions/atom.hpp>

namespace Behaviors {
struct Atom_Stop {
 public:
  void operator()(PedestrianSet&,
                  ObstacleSet&,
                  Goals&,
                  BehaviorContext&,
                  VIPRA::idx,
                  VIPRA::delta_t,
                  std::shared_ptr<VIPRA::State>);
};
}  // namespace Behaviors

#endif