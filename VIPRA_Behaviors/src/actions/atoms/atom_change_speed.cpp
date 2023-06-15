
#include <spdlog/spdlog.h>

#include <actions/atoms/atom_change_speed.hpp>

namespace BHVR {

/**
 * @brief either slows/speeds up a pedestrian based on change
 * 
 * @param pedestrianSet : pedestrian set object
 * @param pedIndex : index of pedestrian to affect
 * @param dT : simulation time step size
 * @param state : state object to put result into
 */
void AtomChangeSpeed::operator()(PedestrianSet& pedestrianSet, ObstacleSet& /*obsset*/,
                                 Goals& /*goals*/, BehaviorContext& /*context*/,
                                 VIPRA::idx pedIndex, VIPRA::delta_t dT,
                                 VIPRA::State& state) const {
  VIPRA::f3d originalPos = pedestrianSet.getPedCoords(pedIndex);
  VIPRA::f3d tempVel = state.velocities[pedIndex] * change.value(pedIndex);

  state.pedestrianCoordinates[pedIndex] = originalPos + (tempVel * dT);
}
}  // namespace BHVR