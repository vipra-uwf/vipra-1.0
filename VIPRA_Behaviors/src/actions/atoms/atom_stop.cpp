
#include "actions/atoms/atom_stop.hpp"

namespace Behaviors {
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
void
Atom_Stop::performAction(const PedestrianSet&          pedSet,
                         const ObstacleSet&            obsSet,
                         const Goals&                  goals,
                         const BehaviorContext&        context,
                         VIPRA::idx                    pedIdx,
                         VIPRA::delta_t                dT,
                         std::shared_ptr<VIPRA::State> state) {
  state->pedestrianCoordinates[pedIdx] = pedSet.getPedCoords(pedIdx);
  state->velocities[pedIdx] = pedSet.getPedVelocity(pedIdx);
}
}  // namespace Behaviors