#include "simulation.hpp"

void
Simulation::configure(const CONFIG_MAP& config) {
  this->timestep = 0;
  this->timestep_size = std::stof(config.at("time_step_size"));
}

int
Simulation::getTimestep() const {
  return this->timestep;
}

inline void
combineStates(const size_t pedCnt, State& state, std::shared_ptr<State> other) {
  other->affector = state.affector;
  for (size_t i = 0; i < pedCnt; ++i) {
    if (state.affector[i] != PED_MODEL) {
      other->pedestrianCoordinates[i] = state.pedestrianCoordinates[i];
      other->velocities[i] = state.velocities[i];
    }
  }
}

/**
 * @brief Main Loop of Simulation
 * 
 * @param goals - Goals implementation
 * @param pedestrianSet - PedestrianSet implementation
 * @param obstacleSet - ObstacleSet implementation
 * @param pedestrianDynamicsModel - PedestrianDynamicsModel implementation
 * @param humanBehaviorModel - HumanBehaviorModel implementation
 * @param policyModel - PolicyModel implementation
 * @param outputDataWriter - OutputDataWriter implementation
 * @param simulationOutputHandler - SimulationOutputHandler implementation
 * @param clock - Clock implementation
 */
void
Simulation::run(Goals&                   goals,
                PedestrianSet&           pedestrianSet,
                ObstacleSet&             obstacleSet,
                PedestrianDynamicsModel& pedestrianDynamicsModel,
                // HumanBehaviorModel&      humanBehaviorModel,
                PolicyModel&             policyModel,
                OutputDataWriter&        outputDataWriter,
                SimulationOutputHandler& simulationOutputHandler,
                Clock&                   clock) {

  clock.start();
  const size_t pedCnt = pedestrianSet.getNumPedestrians();
  State        proposedState(pedCnt);
  Info("Starting Simulation Loop");
  while (timestep < 1000) {
    // while (!goals.isSimulationGoalMet()) {
    Debug("Timestep: {}", timestep);
    policyModel.timestep(pedestrianSet, obstacleSet, goals, timestep_size, proposedState);
    // humanBehaviorModel.timestep(pedestrianSet, obstacleSet, goals, timestep_size, proposedState);
    auto pedState{pedestrianDynamicsModel.timestep(pedestrianSet, obstacleSet, goals, timestep_size)};

    combineStates(pedCnt, proposedState, pedState);
    pedestrianSet.updateState(pedState);

    if (simulationOutputHandler.isOutputCriterionMet(pedestrianSet, obstacleSet, goals, timestep)) {
      Debug("Writing To Document");
      simulationOutputHandler.writeToDocument(outputDataWriter, pedestrianSet, timestep);
    }

    goals.updatePedestrianGoals(obstacleSet, pedestrianSet);
    ++timestep;
    clock.addSimulationTimeMs(this->timestep_size);
    std::fill(proposedState.affector.begin(), proposedState.affector.end(), PED_MODEL);
  }

  Info("Simulation Run Complete");

  clock.stop();
  clock.printRealEndTime();
  clock.printRealDuration();
  clock.printSimulationDuration();

}  // namespace Vipra