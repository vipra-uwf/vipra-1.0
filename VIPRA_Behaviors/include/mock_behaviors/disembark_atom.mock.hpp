#ifndef VIPRA_DISEMBARK_MOCK_BEHAVIOR_HPP
#define VIPRA_DISEMBARK_MOCK_BEHAVIOR_HPP

#include <actions/action_atom.hpp>
#include <behavior/human_behavior.hpp>

class Atom_Disembark_Mock : public Atom {
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