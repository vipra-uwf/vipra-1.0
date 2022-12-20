#include "simulation.hpp"

void
Simulation::configure(const VIPRA::ConfigMap& config) {
  this->timestep = 0;
  this->timestep_size = std::stof(config.at("time_step_size"));
}

void
Simulation::initialize() {}

VIPRA::t_step
Simulation::getTimestep() const {
  return this->timestep;
}

inline void
combineStates(const VIPRA::size pedCnt, VIPRA::State& state, std::shared_ptr<VIPRA::State> other) {
  other->affector = state.affector;
  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    if (state.affector[i] != VIPRA::Affector::PED_MODEL) {
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
                HumanBehaviorModel&      humanBehaviorModel,
                PolicyModel&             policyModel,
                OutputDataWriter&        outputDataWriter,
                SimulationOutputHandler& simulationOutputHandler,
                Clock&                   clock) {

  clock.start();
  const VIPRA::size pedCnt = pedestrianSet.getNumPedestrians();
  VIPRA::State      proposedState(pedCnt);

  LJ::Info(simLogger, "Starting Simulation Loop");

  while (timestep < 20000) {
    policyModel.timestep(pedestrianSet, obstacleSet, goals, timestep_size, proposedState);
    humanBehaviorModel.timestep(pedestrianSet, obstacleSet, goals, timestep_size, proposedState);
    auto pedState{pedestrianDynamicsModel.timestep(pedestrianSet, obstacleSet, goals, timestep_size)};

    combineStates(pedCnt, proposedState, pedState);
    pedestrianSet.updateState(pedState);

    if (simulationOutputHandler.isOutputCriterionMet(pedestrianSet, obstacleSet, goals, timestep)) {
      LJ::Debug(simLogger, "Writing To Document, Timestep: {}", timestep);
      simulationOutputHandler.writeToDocument(outputDataWriter, pedestrianSet, timestep);
    }

    goals.updatePedestrianGoals(obstacleSet, pedestrianSet);
    ++timestep;
    clock.addSimulationTimeMs(this->timestep_size);
  }

  LJ::Info(simLogger, "Simulation Run Complete");

  clock.stop();
  clock.printRealEndTime();
  clock.printRealDuration();
  clock.printSimulationDuration();

}  // namespace Vipra