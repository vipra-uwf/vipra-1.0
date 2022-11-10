#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <math.h>
#include <algorithm>
#include <cmath>
#include <vector>

#include "../../../VIPRA/Extendable/pedestrianmodel/pedestrian_dynamics_model.hpp"
//#include "../../ObstacleSet/airplane_obstacle_set/airplane_obstacle_set.hpp"
#include "../../PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"
//#include "../../Goals/calm_goals/calm_goals.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel {
 public:
       CalmPedestrianModel();
      ~CalmPedestrianModel();

       void      configure(const CONFIG_MAP& configMap) override;
       void      initialize(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet,
                     Goals& goals) override;
       DimVector update(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet,
                     Goals& goals, FLOATING_NUMBER time) override;

      void setPedestrianSet(PedestrianSet& pedestrianSet);

      void      initialize(PedestrianSet& pedestrianSet);
      DimVector update(PedestrianSet& pedestrianSet, FLOATING_NUMBER time);

      //Getters and Setters
      FLOATING_NUMBER getPedestrianDistance(CalmPedestrianSet& pedestrianSet, int firstPedestrian, int secondPedestrian);
      std::vector<std::pair<std::string, int>> getNearestNeighbors();



 private:


      std::vector<FLOATING_NUMBER>                holds;
      std::vector<bool>                           aislePermissions;

      int                                         currentPriority;

      DimVector                   racePositions;
      DimVector                   propulsionForces;

      std::vector<std::pair<std::string, int>>  nearestNeighbors;
      std::vector<FLOATING_NUMBER>              priorities;

      std::vector<int>                          raceCounter;
      std::vector<int>                          opponentIDs;
      std::vector<int>                          startingAisles;

      std::vector<bool>                         raceFinished;
      std::vector<bool>                         released;

      FLOATING_NUMBER*                          pedestrianDistanceMatrix;
      FLOATING_NUMBER*                          obstacleDistanceMatrix;


      void                                      calculatePriority();
      void                                      calculatePropulsion();
      void                                      calculateBeta();
      void                                      calculateNeartestNeighbors(CalmPedestrianSet& pedestrianSet);
       
      inline bool                               neighborDirectionTest(CalmPedestrianSet& pedestrianSet,
                                                        int firstPedestrianIndex, int secondPedestrianIndex,
                                                        FLOATING_NUMBER pedestrianDisplacementX, FLOATING_NUMBER pedestrianDisplacementY,
                                                        FLOATING_NUMBER secondDisplacementX, FLOATING_NUMBER secondDisplacementY);

      inline bool                               neighborSpacialTest(CalmPedestrianSet& pedestrianSet, int firstPedestrianIndex, int secondPedestrianIndex,
                                                        FLOATING_NUMBER pedestrianDisplacementX, FLOATING_NUMBER pedestrianDisplacementY,
                                                        FLOATING_NUMBER secondDisplacementX, FLOATING_NUMBER secondDisplacementY,
                                                        std::string originSet, FLOATING_NUMBER firstShoulderLength);                                                               
      void                                      raceDetection();

       void calculateDistanceMatrices(CalmPedestrianSet& pedestrianSet);
       FLOATING_NUMBER getObstacleDistance(int pedIndex, int obsIndex);

};

#endif