#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "behaviorModel/humanbehavior/human_behavior_model.hpp"
#include "clock/clock.hpp"
#include "definitions/state.hpp"
#include "logging/logging.hpp"
#include "pedestrianmodel/pedestrian_dynamics_model.hpp"
#include "policyModel/policy_model.hpp"
#include "simulationoutputhandler/simulation_output_handler.hpp"

class Simulation {

 public:
  void configure(const VIPRA::ConfigMap& config);
  void initialize();
  void run(Goals&                   goals,
           PedestrianSet&           pedestrianSet,
           ObstacleSet&             obstacleSet,
           PedestrianDynamicsModel& pedestrianDynamicsModel,
           HumanBehaviorModel&      humanBehaviorModel,
           PolicyModel&             policyModel,
           OutputDataWriter&        outputDataWriter,
           SimulationOutputHandler& simulationOutputHandler,
           Clock&                   clock);

  int getTimestep() const;

 private:
  int   timestep;
  float timestep_size;
};

#endif