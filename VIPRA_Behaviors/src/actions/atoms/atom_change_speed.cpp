
#include "actions/atoms/atom_change_speed.hpp"

ChangeSpeedParams
getChangeSpeedParams(BehaviorParser::Action_atomContext* atom) {
  float change = std::stof(atom->action_atom_Percent_Walk_Speed()->NUMBER()->toString());
  bool  faster = atom->action_atom_Percent_Walk_Speed()->FASTERorSLOWER()->toString() == "faster";
  return {change, faster};
}

Atom_Change_Speed::Atom_Change_Speed(float percent, bool faster) : change(percent), faster(faster) {}

void
Atom_Change_Speed::performAction(const PedestrianSet&          pedestrianSet,
                                 const ObstacleSet&            obstacleSet,
                                 const Goals&                  goals,
                                 const BehaviorContext&        context,
                                 VIPRA::idx                    pedIndex,
                                 VIPRA::delta_t                time,
                                 std::shared_ptr<VIPRA::State> state) {

  VIPRA::f3d originalPos = pedestrianSet.getPedCoords(pedIndex);
  state->velocities[pedIndex] = computeAlteredDimensions(state->velocities[pedIndex]);
  state->pedestrianCoordinates[pedIndex] = originalPos + state->velocities[pedIndex];
}

VIPRA::f3d
Atom_Change_Speed::computeAlteredDimensions(VIPRA::f3d originalDimensions) {
  VIPRA::f3d diff = originalDimensions *= change;
  if (faster) {
    return originalDimensions + diff;
  } else {
    return originalDimensions - diff;
  }
}
