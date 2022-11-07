#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "../../humanbehavior/human_behavior_model.hpp"
#include "../../policyModel/policy_model.hpp"
#include "../../simulationoutputhandler/simulation_output_handler.hpp"
#include "../clock/clock.hpp"

#include "../../../Extendable/pedestrianmodel/pedestrian_dynamics_model.hpp"

class SimulationOutputHandler;  // forward declaring

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
