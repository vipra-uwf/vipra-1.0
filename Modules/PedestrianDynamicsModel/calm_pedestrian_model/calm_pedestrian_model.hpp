#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <math.h>
#include <algorithm>
#include <cmath>
#include <vector>

#include "../../VIPRA_DEV/Extendable/pedestrianmodel/pedestrian_dynamics_model.hpp"
#include "../airplane_obstacle_set/airplane_obstacle_set.hpp"
#include "../calm_pedestrian_set/calm_pedestrian_set.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel {
 public:
  void      configure(const CONFIG_MAP& configMap) override;
  void      initialize(const PedestrianSet&, const ObstacleSet&,
                       const Goals&) override;
  DimVector timestep(const PedestrianSet&, const ObstacleSet&,
                     const Goals&) override;

 private:

};

#endif