#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <math.h>
#include <algorithm>
#include <cmath>
#include <vector>

#include "../../VIPRA_DEV/Extendable/pedestrianmodel/pedestrian_dynamics_model.hpp"
#include "../airplane_obstacle_set/airplane_obstacle_set.hpp"
#include "../calm_pedestrian_set/calm_pedestrian_set.hpp"
#include "../../../VIPRA/Base/definitions/type_definitions.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel {
 public:
 
        void      configure(const CONFIG_MAP& configMap);
        void      initialize(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet,
                            Goals& goals);
        DimVector update(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet,
                            Goals& goals);

 private:
        CalmPedestrianSet&                          pedestrianSet;
        ObstacleSet&                                obstacleSet;
        Goals&                                      goals;
        FLOATING_NUMBER                             timestep;

        std::vector<FLOATING_NUMBER>                holds;
        std::vector<bool>                           aislePermissions;

        int                                         currentPriority;

        void calculateDistanceMatrices();
        FLOATING_NUMBER getPedestrianDistance(int firstIndex, int secondIndex);
        FLOATING_NUMBER getObstacleDistance(int pedIndex, int obsIndex);
};

#endif