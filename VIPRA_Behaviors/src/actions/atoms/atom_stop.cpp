
#include "actions/atoms/atom_stop.hpp"

void
Atom_Stop::performAction(const ObstacleSet&            obsSet,
                         const PedestrianSet&          pedSet,
                         const Goals&                  goals,
                         const BehaviorContext&        context,
                         VIPRA::idx                    pedIdx,
                         VIPRA::delta_t                dT,
                         std::shared_ptr<VIPRA::State> state) {
  state->pedestrianCoordinates[pedIdx] = pedSet.getPedCoords(pedIdx);
  state->velocities[pedIdx] = pedSet.getPedVelocity(pedIdx);
}