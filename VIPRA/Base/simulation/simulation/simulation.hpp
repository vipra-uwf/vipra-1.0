#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "../../../Extendable/pedestrianmodel/pedestrian_dynamics_model.hpp"
#include "../../definitions/state.hpp"
#include "../../humanbehavior/human_behavior_model.hpp"
#include "../../policyModel/policy_model.hpp"
#include "../../simulationoutputhandler/simulation_output_handler.hpp"
#include "../clock/clock.hpp"

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
           OutputDataWriter&        outputDataWriter,
           SimulationOutputHandler& simulationOutputHandler,
           Clock&                   clock);

  int getTimestep() const;
};

#endif