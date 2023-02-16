#ifndef VIPRA_ATOM_CHANGE_SPEED_HPP
#define VIPRA_ATOM_CHANGE_SPEED_HPP

#include "actions/action_atom.hpp"
#include "generated/BehaviorParser.h"

namespace Behaviors {
struct ChangeSpeedParams {
  float change;
  bool  faster;
};

ChangeSpeedParams getChangeSpeedParams(BehaviorParser::Action_atomContext*);

class Atom_Change_Speed : public Atom {
 public:
  Atom_Change_Speed() = delete;

  Atom_Change_Speed(float, bool);
  void performAction(const PedestrianSet&,
                     const ObstacleSet&,
                     const Goals&,
                     const BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>) override;

 private:
  VIPRA::f3d computeAlteredDimensions(VIPRA::f3d originalDimensions);

  float change;
  bool  faster;
};
}  // namespace Behaviors

#endif