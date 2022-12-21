#include "stop_movement_action.hpp"

StopMovementAction::StopMovementAction(SimulationContext* simContext) : Action(simContext, "STOPPED") {}

void
StopMovementAction::performAction([[maybe_unused]] const ObstacleSet&   obstacleSet,
                                  [[maybe_unused]] const PedestrianSet& pedestrianSet,
                                  [[maybe_unused]] const Goals&         goals,
                                  VIPRA::idx                            pedestrianIndex,
                                  [[maybe_unused]] VIPRA::delta_t       time,
                                  std::shared_ptr<VIPRA::State>         state) {
  state->velocities[pedestrianIndex] = VIPRA::f3d{0, 0, 0};
}
