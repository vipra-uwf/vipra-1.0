
#include <mock_behaviors/disembark_atom.mock.hpp>

void
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