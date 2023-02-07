#ifndef VIPRA_ATOM_STOP_HPP
#define VIPRA_ATOM_STOP_HPP

#include <actions/action_atom.hpp>

class Atom_Stop : public Atom {
 public:
  void performAction(const PedestrianSet&,
                     const ObstacleSet&,
                     const Goals&,
                     const BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>) override;
};

#endif