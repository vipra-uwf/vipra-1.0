
#include <spdlog/spdlog.h>

#include "actions/atoms/atom_change_speed.hpp"

namespace Behaviors {
/**
 * @brief gets the parameters from the sentence describing it
 * 
 * @param atom : the atom context
 * @return ChangeSpeedParams 
 */
ChangeSpeedParams
getChangeSpeedParams(BehaviorParser::Action_atomContext* atom) {
  float change = std::stof(atom->action_atom_Percent_Walk_Speed()->NUMBER()->toString()) / 100;
  bool  faster = atom->action_atom_Percent_Walk_Speed()->FASTERorSLOWER()->toString() == "faster";
  spdlog::debug("Change: {}, Faster: {}", change, (faster ? "True" : "False"));
  return {change, faster};
}

Atom_Change_Speed::Atom_Change_Speed(float percent, bool faster) : change(percent), faster(faster) {}

/**
 * @brief either slows/speeds up a pedestrian based on change and faster
 * 
 * @param pedestrianSet : pedestrian set object
 * @param pedIndex : index of pedestrian to affect
 * @param dT : simulation time step size
 * @param state : state object to put result into
 */
void
Atom_Change_Speed::performAction(const PedestrianSet& pedestrianSet,
                                 const ObstacleSet&,
                                 const Goals&,
                                 const BehaviorContext&,
                                 VIPRA::idx                    pedIndex,
                                 VIPRA::delta_t                dT,
                                 std::shared_ptr<VIPRA::State> state) {
  VIPRA::f3d originalPos = pedestrianSet.getPedCoords(pedIndex);

  state->velocities[pedIndex] = computeAlteredDimensions(state->velocities[pedIndex]);
  state->pedestrianCoordinates[pedIndex] = originalPos + (state->velocities[pedIndex] * dT);
}

/**
 * @brief calculates the vector with change applied to it
 * 
 * @param originalDimensions
 * @return VIPRA::f3d 
 */
VIPRA::f3d
Atom_Change_Speed::computeAlteredDimensions(VIPRA::f3d originalDimensions) {
  VIPRA::f3d diff = originalDimensions * change;
  if (faster) {
    return originalDimensions + diff;
  } else {
    return originalDimensions - diff;
  }
}
}  // namespace Behaviors