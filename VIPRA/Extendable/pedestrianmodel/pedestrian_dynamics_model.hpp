#ifndef PEDESTRIAN_DYNAMICS_MODEL_HPP
#define PEDESTRIAN_DYNAMICS_MODEL_HPP

#include "../../Base/definitions/type_definitions.hpp"

#include "../goals/goals.hpp"
#include "../obstacleset/obstacle_set.hpp"
#include "../pedestrianset/pedestrian_set.hpp"

class PedestrianDynamicsModel {
 public:
  virtual ~PedestrianDynamicsModel() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;

  virtual void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) = 0;

  virtual DimVector timestep(const PedestrianSet&,
                             const ObstacleSet&,
                             const Goals&,
                             FLOATING_NUMBER timstep_size) = 0;
};

#endif
