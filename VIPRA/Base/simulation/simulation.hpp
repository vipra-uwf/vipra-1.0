#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <spdlog/spdlog.h>

#include <clock/clock.hpp>
#include <definitions/config_map.hpp>
#include <definitions/state.hpp>
#include <human_behavior/human_behavior_model.hpp>
#include <pedestrian_model/pedestrian_dynamics_model.hpp>
#include <policy_model/policy_model.hpp>
#include <simulation_output_handler/simulation_output_handler.hpp>

/**
 * @brief Main Simulation Class
 * 
 */
class Simulation {
 public:
  void configure(const VIPRA::CONFIG::Map& config);
  void initialize();
  void run(Goals& goals, PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet,
           PedestrianDynamicsModel& pedestrianDynamicsModel,
           HumanBehaviorModel& humanBehaviorModel, PolicyModel& policyModel,
           OutputDataWriter&        outputDataWriter,
           SimulationOutputHandler& simulationOutputHandler);

  [[nodiscard]] VIPRA::t_step getTimestep() const;

 private:
  VIPRA::t_step  timestep{};
  VIPRA::delta_t timestep_size{};
  VIPRA::t_step  maxTimeStep{};
  VIPRA::Clock<> clock;

  void printSimTime();
};

#endif