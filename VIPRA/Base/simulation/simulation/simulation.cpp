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

void
Simulation::run(Goals&                   goals,
                PedestrianSet&           pedestrianSet,
                ObstacleSet&             obstacleSet,
                PedestrianDynamicsModel& pedestrianDynamicsModel,
                HumanBehaviorModel&      humanBehaviorModel,
                PolicyModel&             policyModel,
                SimulationOutputHandler& simulationOutputHandler) {

  while (!goals.isSimulationGoalMet()) {}
}