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
  PedDynamicsException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw PedDynamicsException(message); }
};

class PedestrianDynamicsModel {
 public:
  virtual ~PedestrianDynamicsModel() = default;

  virtual void                          configure(const VIPRA::ConfigMap& configMap) = 0;
  virtual void                          initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) = 0;
  virtual std::shared_ptr<VIPRA::State> timestep(const PedestrianSet&,
                                                 const ObstacleSet&,
                                                 const Goals&,
                                                 VIPRA::delta_t,
                                                 VIPRA::t_step) = 0;
};

#endif
