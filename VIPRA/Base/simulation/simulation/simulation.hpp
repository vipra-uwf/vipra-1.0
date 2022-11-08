#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "../../../Extendable/pedestrianmodel/pedestrian_dynamics_model.hpp"
#include "../../humanbehavior/human_behavior_model.hpp"
#include "../../policyModel/policy_model.hpp"
#include "../clock/clock.hpp"

class SimulationOutputHandler;

class Simulation {
 private:
  int             timestep;
  FLOATING_NUMBER timestep_size;

 public:
  void configure(const CONFIG_MAP& config);

  void run(Goals&                   goals,
           PedestrianSet&           pedestrianSet,
           ObstacleSet&             obstacleSet,
           PedestrianDynamicsModel& pedestrianDynamicsModel,
           HumanBehaviorModel&      humanBehaviorModel,
           PolicyModel&             policyModel,
           SimulationOutputHandler& simulationOutputHandler);

  int getTimestep() const;
};

#endif