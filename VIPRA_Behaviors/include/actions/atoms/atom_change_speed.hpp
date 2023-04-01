#ifndef VIPRA_ATOM_CHANGE_SPEED_HPP
#define VIPRA_ATOM_CHANGE_SPEED_HPP

#include "actions/action_atom.hpp"
#include "generated/BehaviorParser.h"

namespace Behaviors {

float getChangeSpeedParams(BehaviorParser::Action_atomContext*);

class Atom_Change_Speed : public Atom {
 public:
  Atom_Change_Speed() = delete;

  Atom_Change_Speed(float);
  void performAction(PedestrianSet&,
                     ObstacleSet&,
                     Goals&,
                     BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>) override;

 private:
  float change;
};
}  // namespace Behaviors

#endif