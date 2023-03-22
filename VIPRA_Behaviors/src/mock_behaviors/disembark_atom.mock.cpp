
#include <mock_behaviors/disembark_atom.mock.hpp>

namespace Behaviors {
void
/**
 * @brief Checks if any pedestrians in front of the current pedestrian has met any goals yet, if they haven't they are stopped
 * 
 * @note this doesn't work very well with the A* pathfinding as a pedestrian's first goal may not be the center of the aisle
 * 
 * @param pedSet : 
 * @param goals : 
 * @param pedIdx : 
 * @param state : 
 */
Atom_Disembark_Mock::performAction(const PedestrianSet& pedSet,
                                   const ObstacleSet&,
                                   const Goals& goals,
                                   const BehaviorContext&,
                                   VIPRA::idx pedIdx,
                                   VIPRA::delta_t,
                                   std::shared_ptr<VIPRA::State> state) {

  if (goals.timeSinceLastGoal(pedIdx) < 0 || goals.isPedestianGoalMet(pedIdx)) {
    return;
  }

  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       AllCoords = pedSet.getPedestrianCoordinates();
  const auto        pedCoords = AllCoords.at(pedIdx);

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    const auto otherCoords = AllCoords.at(i);
    if (otherCoords.x <= pedCoords.x + 0.2) {
      continue;
    }

    if (goals.timeSinceLastGoal(i) < 0) {
      state->pedestrianCoordinates[pedIdx] = pedSet.getPedCoords(pedIdx);
      state->velocities[pedIdx] = pedSet.getPedVelocity(pedIdx);
      return;
    }
  }
}
}  // namespace Behaviors