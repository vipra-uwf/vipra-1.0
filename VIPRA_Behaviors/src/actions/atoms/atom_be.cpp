

#include <spdlog/spdlog.h>

#include <actions/atoms/atom_be.hpp>

namespace BHVR {

/**
 * @brief either slows/speeds up a pedestrian based on change
 * 
 * @param pedestrianSet : pedestrian set object
 * @param pedIndex : index of pedestrian to affect
 * @param dT : simulation time step size
 * @param state : state object to put result into
 */
void AtomBe::operator()(PedestrianSet& /*pedset*/, ObstacleSet& /*obsset*/,
                        Goals& /*goals*/, BehaviorContext& context, VIPRA::idx index,
                        VIPRA::delta_t /*dT*/, VIPRA::State& /*state*/) const {
  if (context.pedStates[index] != state) {
    spdlog::debug("Setting Pedestrian {} to State: {}", index, state);
    context.pedStates[index] = state;
  }
}

}  // namespace BHVR