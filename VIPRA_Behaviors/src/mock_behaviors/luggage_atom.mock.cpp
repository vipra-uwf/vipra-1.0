

#include <mock_behaviors/luggage_atom.mock.hpp>

namespace Behaviors {
Atom_Luggage_Mock::Atom_Luggage_Mock(float timeToGetLuggage) : luggageTime(timeToGetLuggage) {
  spdlog::debug("Setting Luggage Time To: {}s", timeToGetLuggage);
}

void
Atom_Luggage_Mock::construct(const PedestrianSet& pedSet) {
  constructed = true;
  gottenLuggage = std::vector<bool>(pedSet.getNumPedestrians(), false);
}

void
Atom_Luggage_Mock::performAction(PedestrianSet& pedSet,
                                 ObstacleSet&,
                                 Goals& goals,
                                 BehaviorContext&,
                                 VIPRA::idx pedIdx,
                                 VIPRA::delta_t,
                                 std::shared_ptr<VIPRA::State> state) {

  if (!constructed) {
    construct(pedSet);
  }

  if (!gottenLuggage.at(pedIdx)) {
    VIPRA::delta_t lastGoalTime = goals.timeSinceLastGoal(pedIdx);
    if (lastGoalTime > 0) {
      if (lastGoalTime < luggageTime) {
        state->pedestrianCoordinates[pedIdx] = pedSet.getPedCoords(pedIdx);
        state->velocities[pedIdx] = pedSet.getPedVelocity(pedIdx);
      } else {
        spdlog::debug("Pedestrian {}, Done Getting Luggage", pedIdx);
        gottenLuggage[pedIdx] = true;
      }
    }
  }
}
}  // namespace Behaviors