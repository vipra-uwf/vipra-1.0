#include "simulation.hpp"

const VIPRA::f2dVec VIPRA::__emptyf2d_Vec__ = VIPRA::f2dVec{};
const VIPRA::f3dVec VIPRA::__emptyf3d_Vec__ = VIPRA::f3dVec{};

void
Simulation::configure(const VIPRA::Config::Map& config) {
  timestep = 0;
  timestep_size = config["time_step_size"].asFloat();
  maxTimeStep = config["max_timestep"].asUInt64();
}

void
Simulation::initialize() {}

VIPRA::t_step
Simulation::getTimestep() const {
  return timestep;
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
  spdlog::info("Starting Simulation Loop");

  while (!goals.isSimulationGoalMet() && timestep < maxTimeStep) {
    auto pedState{pedestrianDynamicsModel.timestep(pedestrianSet, obstacleSet, goals, timestep_size, timestep)};
    policyModel.timestep(pedestrianSet, obstacleSet, goals, pedState, timestep_size);
    humanBehaviorModel.timestep(pedestrianSet, obstacleSet, goals, pedState, timestep_size);

    pedestrianSet.updateState(pedState);

    if (simulationOutputHandler.isOutputCriterionMet(pedestrianSet, obstacleSet, goals, timestep)) {
      spdlog::info("Writing To Document, Timestep: {}", timestep);
      simulationOutputHandler.writeOutput(outputDataWriter, pedestrianSet, timestep);
    }

    goals.updatePedestrianGoals(obstacleSet, pedestrianSet, timestep);
    ++timestep;
    clock.addSimulationTimeMs(timestep_size);
  }

  spdlog::info("Simulation Run Complete");

  clock.stop();
  clock.printRealEndTime();
  clock.printRealDuration();
  clock.printSimulationDuration();

}  // namespace Vipra