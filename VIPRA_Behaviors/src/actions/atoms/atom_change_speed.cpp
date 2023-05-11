
#include <spdlog/spdlog.h>

#include "actions/atoms/atom_change_speed.hpp"

namespace Behaviors {

/**
 * @brief either slows/speeds up a pedestrian based on change
 * 
 * @param pedestrianSet : pedestrian set object
 * @param pedIndex : index of pedestrian to affect
 * @param dT : simulation time step size
 * @param state : state object to put result into
 */
void
Atom_Change_Speed::operator()(PedestrianSet& pedestrianSet,
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