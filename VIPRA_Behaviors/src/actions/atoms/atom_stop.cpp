
#include <spdlog/spdlog.h>

#include <actions/atoms/atom_stop.hpp>

namespace BHVR {
/**
   * @brief Stops a pedestrians motion
   * 
   * @param pedSet : pedestrian set object
   * @param obsSet : obstacle set object
   * @param goals : goals object
   * @param context : behavior context
   * @param pedIdx : index of pedestrian
   * @param dT : simulation timestep size
   * @param state : state object to put result to
   */
void AtomStop::operator()(PedestrianSet& pedSet, ObstacleSet& /*obsset*/,
                          Goals& /*goals*/, BehaviorContext& /*context*/,
                          VIPRA::idx    pedIdx, VIPRA::delta_t /*dT*/,
                          VIPRA::State& state) const {
  state.pedestrianCoordinates[pedIdx] = pedSet.getPedCoords(pedIdx);
  state.velocities[pedIdx] = VIPRA::f3d{0, 0, 0};
}
}  // namespace BHVR