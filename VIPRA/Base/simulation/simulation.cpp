

#include "simulation.hpp"

#include "output/output.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

namespace VIPRA {
/**
 * @brief Gets simulation module params
 * 
 * @param config : 
 */
void Simulation::configure(const VIPRA::Config& config) {
  timestep = 0;
  timestep_size = config["time_step_size"].get<float>();
  maxTimeStep = config["max_timestep"].get<VIPRA::size>();
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
void Simulation::run(VIPRA::Goals& goals, VIPRA::PedestrianSet& pedestrianSet,
                     VIPRA::ObstacleSet&      obstacleSet,
                     PedestrianDynamicsModel& pedestrianDynamicsModel,
                     HumanBehaviorModel& humanBehaviorModel, PolicyModel& policyModel) {
  spdlog::info("Starting Simulation Loop");
  clock.start();

  VIPRA::State pedState{pedestrianSet.getNumPedestrians()};
  while (!goals.isSimulationGoalMet() && timestep < maxTimeStep) {
    pedestrianDynamicsModel.timestep(pedestrianSet, obstacleSet, goals, pedState,
                                     timestep_size, timestep);
    policyModel.timestep(pedestrianSet, obstacleSet, goals, pedState, timestep_size);
    humanBehaviorModel.timestep(pedestrianSet, obstacleSet, goals, pedState,
                                timestep_size);

    pedestrianSet.updateState(pedState);
    goals.updatePedestrianGoals(obstacleSet, pedestrianSet, timestep_size);

    outputPositions(pedestrianSet);

    ++timestep;
    Output::nextTimestep();
  }

  if (timestep >= maxTimeStep) {
    spdlog::warn("Simulation Reached Max Timestep");
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

void Simulation::outputPositions(const PedestrianSet& pedSet) {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       coords = pedSet.getCoordinates();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    Output::pedTimestepValue(i, "position", coords.at(i));
  }
}
}  // namespace VIPRA