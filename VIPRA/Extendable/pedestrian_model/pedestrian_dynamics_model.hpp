#ifndef PEDESTRIAN_DYNAMICS_MODEL_HPP
#define PEDESTRIAN_DYNAMICS_MODEL_HPP

#include "definitions/config_map.hpp"
#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"

#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

class PedDynamicsException : public std::runtime_error {
 public:
  explicit PedDynamicsException(const std::string& message) : std::runtime_error(message) {}
  static void error(const std::string& message) { throw PedDynamicsException(message); }
};

class PedestrianDynamicsModel {
 public:
  virtual void                          configure(const VIPRA::CONFIG::Map& configMap) = 0;
  virtual void                          initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) = 0;
  virtual std::shared_ptr<VIPRA::State> timestep(const PedestrianSet&, const ObstacleSet&, const Goals&, VIPRA::delta_t,
                                                 VIPRA::t_step) = 0;


  PedestrianDynamicsModel(const PedestrianDynamicsModel&) = default;
  PedestrianDynamicsModel(PedestrianDynamicsModel&&) = delete;
  PedestrianDynamicsModel& operator=(const PedestrianDynamicsModel&) = default;
  PedestrianDynamicsModel& operator=(PedestrianDynamicsModel&&) = delete;
  PedestrianDynamicsModel() = default;
  virtual ~PedestrianDynamicsModel() = default;
};

#endif
