
#include <spdlog/spdlog.h>

#include "actions/atoms/atom_change_speed.hpp"

namespace Behaviors {
/**
 * @brief gets the parameters from the sentence describing it
 * 
 * @param atom : the atom context
 * @return ChangeSpeedParams 
 */
float
getChangeSpeedParams(BehaviorParser::Action_atomContext* atom) {
  float change = std::stof(atom->action_atom_Percent_Walk_Speed()->FLOAT()->toString());
  spdlog::debug("Speed Change: {}", change);
  return change;
}

Atom_Change_Speed::Atom_Change_Speed(float percent) : change(percent) {}

/**
 * @brief either slows/speeds up a pedestrian based on change
 * 
 * @param pedestrianSet : pedestrian set object
 * @param pedIndex : index of pedestrian to affect
 * @param dT : simulation time step size
 * @param state : state object to put result into
 */
void
Atom_Change_Speed::performAction(PedestrianSet& pedestrianSet,
                                 ObstacleSet&,
                                 Goals&,
                                 BehaviorContext&,
                                 VIPRA::idx                    pedIndex,
                                 VIPRA::delta_t                dT,
                                 std::shared_ptr<VIPRA::State> state) {
  VIPRA::f3d originalPos = pedestrianSet.getPedCoords(pedIndex);
  VIPRA::f3d tempVel = state->velocities[pedIndex] * change;

  state->pedestrianCoordinates[pedIndex] = originalPos + (tempVel * dT);
}
}  // namespace Behaviors