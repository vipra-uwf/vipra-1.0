#ifndef PEDESTRIAN_DYNAMICS_MODEL_HPP
#define PEDESTRIAN_DYNAMICS_MODEL_HPP

#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"

#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class PedDynamicsException : public std::runtime_error {
 public:
  PedDynamicsException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw PedDynamicsException(message); }
};

class PedestrianDynamicsModel {
 public:
  virtual ~PedestrianDynamicsModel() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;
  virtual void initialize(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet, Goals& goals) = 0;
  virtual std::shared_ptr<State> timestep(PedestrianSet&  pedestrianSet,
                                          ObstacleSet&    obstacleSet,
                                          Goals&          goals,
                                          FLOATING_NUMBER time) = 0;
};

#endif
