

#include <spdlog/spdlog.h>

#include <actions/atoms/atom_be.hpp>

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
Atom_Be::operator()(PedestrianSet&,
                    ObstacleSet&,
                    Goals&,
                    BehaviorContext& context,
                    VIPRA::idx       index,
                    VIPRA::delta_t,
                    std::shared_ptr<VIPRA::State>) {
  if (context.pedStates[index] != state) {
    spdlog::debug("Setting Pedestrian {} to State: {}", index, state);
    context.pedStates[index] = state;
  }
}

}  // namespace Behaviors