

#include "simulation.hpp"
#include <chrono>

/**
 * @brief Gets simulation module params
 * 
 * @param config : 
 */
void Simulation::configure(const VIPRA::CONFIG::Map& config) {
  timestep = 0;
  timestep_size = config["time_step_size"].asFloat();
  maxTimeStep = config["max_timestep"].asUInt64();
}

/**
 * @brief Does nothing, each module has the function
 * 
 */
void Simulation::initialize() {}

/**
 * @brief Returns the current timestep number
 * 
 * @return VIPRA::t_step 
 */
VIPRA::t_step Simulation::getTimestep() const { return timestep; }

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
void Simulation::run(Goals& goals, PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet,
                     PedestrianDynamicsModel& pedestrianDynamicsModel,
                     HumanBehaviorModel& humanBehaviorModel, PolicyModel& policyModel,
                     OutputDataWriter&        outputDataWriter,
                     SimulationOutputHandler& simulationOutputHandler) {
  spdlog::info("Starting Simulation Loop");

  clock.start();
  while (!goals.isSimulationGoalMet() && timestep < maxTimeStep) {
    auto& pedState = pedestrianDynamicsModel.timestep(pedestrianSet, obstacleSet, goals,
                                                      timestep_size, timestep);
    policyModel.timestep(pedestrianSet, obstacleSet, goals, pedState, timestep_size);
    humanBehaviorModel.timestep(pedestrianSet, obstacleSet, goals, pedState,
                                timestep_size);

    pedestrianSet.updateState(pedState);

    if (simulationOutputHandler.isOutputCriterionMet(pedestrianSet, obstacleSet, goals,
                                                     timestep)) {
      spdlog::info("Writing To Document, Timestep: {}", timestep);
      simulationOutputHandler.writeOutput(outputDataWriter, pedestrianSet, timestep);
    }

    goals.updatePedestrianGoals(obstacleSet, pedestrianSet, timestep_size);
    ++timestep;
  }

  spdlog::info("Simulation Run Complete");
  printSimTime();
}

/**
 * @brief Outputs the simulated and real times for the simulation run
 * 
 */
void Simulation::printSimTime() {
  auto stopTime = clock.stop();
  spdlog::info("Simulation Real Run Time: {}", stopTime);

  const double simTime = timestep_size * static_cast<float>(timestep);
  const auto   stm = std::chrono::round<std::chrono::milliseconds>(
      std::chrono::duration<float>{simTime});
  spdlog::info("Simulated Time: {}", stm);
}