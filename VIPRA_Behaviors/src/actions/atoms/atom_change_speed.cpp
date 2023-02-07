
#include "actions/atoms/atom_change_speed.hpp"

Atom_Change_Speed::Atom_Change_Speed(float percent, bool faster) : change(percent), faster(faster) {}

void
Atom_Change_Speed::performAction(const ObstacleSet&            obstacleSet,
                                 const PedestrianSet&          pedestrianSet,
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
