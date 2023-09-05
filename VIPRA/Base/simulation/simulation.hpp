#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <spdlog/spdlog.h>

#include "clock/clock.hpp"
#include "configuration/config.hpp"
#include "definitions/state.hpp"
#include "human_behavior/human_behavior_model.hpp"
#include "pedestrian_model/pedestrian_dynamics_model.hpp"
#include "pedestrian_set/pedestrian_set.hpp"
#include "policy_model/policy_model.hpp"

namespace VIPRA {
/**
 * @brief Main Simulation Class
 * 
 */
class Simulation {
 public:
  void configure(const VIPRA::Config& config);
  void initialize();
  void run(VIPRA::Goals& goals, VIPRA::PedestrianSet& pedestrianSet,
           VIPRA::ObstacleSet&      obstacleSet,
           PedestrianDynamicsModel& pedestrianDynamicsModel,
           HumanBehaviorModel& humanBehaviorModel, PolicyModel& policyModel);

  [[nodiscard]] VIPRA::t_step getTimestep() const;

 private:
  VIPRA::t_step  timestep{};
  VIPRA::delta_t timestep_size{};
  VIPRA::t_step  maxTimeStep{};
  VIPRA::Clock<> clock;

  void printSimTime();

  static void outputPositions(const PedestrianSet&);
};
}  // namespace VIPRA

#endif