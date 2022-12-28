#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <math.h>
#include <vector>

#include "Goals/calm_goals/calm_goals.hpp"
#include "ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"
#include "PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"
#include "pedestrianmodel/pedestrian_dynamics_model.hpp"

#include "definitions/config_map.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel {
 public:
  CalmPedestrianModel();
  ~CalmPedestrianModel();

  void                          configure(const VIPRA::ConfigMap& configMap) override;
  void                          initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) override;
  std::shared_ptr<VIPRA::State> timestep(const PedestrianSet&,
                                         const ObstacleSet&,
                                         const Goals&,
                                         VIPRA::delta_t) override;

  //Getters and Setters
  float                   getPedestrianDistance(const CalmPedestrianSet&,
                                                VIPRA::idx firstPedestrian,
                                                VIPRA::idx secondPedestrian);
  std::vector<VIPRA::idx> getNearestNeighbors();
  VIPRA::f3dVec           getPropulsionForces();

  void calculatePropulsion(const CalmPedestrianSet&, const CalmGoals&);
  void calculateNeartestNeighbors(const CalmPedestrianSet&);
  void calculateDistanceMatrices(const CalmPedestrianSet&);
  void calculateDesiredSpeeds(const CalmPedestrianSet&, const CalmGoals&);

 private:
  std::vector<float> holds;
  std::vector<bool>  aislePermissions;

  VIPRA::idx currentPriority;

  VIPRA::f3dVec racePositions;
  VIPRA::f3dVec propulsionForces;

  std::vector<bool>       pathBlocked;
  std::vector<VIPRA::idx> nearestNeighbors;
  std::vector<float>      priorities;

  std::vector<int>        raceCounter;
  std::vector<VIPRA::uid> opponentIDs;
  std::vector<int>        startingAisles;

  std::vector<bool> raceFinished;
  std::vector<bool> released;

  float* pedestrianDistanceMatrix;
  float* obstacleDistanceMatrix;

  std::shared_ptr<CalmState> modelState;

  void calculatePriority(const CalmPedestrianSet&, const Goals&);
  void calculateBeta();
  void raceDetection();

  void updateModelState(const CalmPedestrianSet&, VIPRA::delta_t);

  inline bool neighborDirectionTest(const CalmPedestrianSet& pedestrianSet,
                                    VIPRA::idx               firstPedestrianIndex,
                                    VIPRA::idx               secondPedestrianIndex);

  inline bool neighborSpacialTest(const CalmPedestrianSet& pedestrianSet,
                                  VIPRA::idx               firstPedestrianIndex,
                                  VIPRA::idx               secondPedestrianIndex,
                                  float                    firstShoulderLength);

  float getObstacleDistance(VIPRA::idx pedIndex, VIPRA::idx obsIndex);

  void checkForBlockedPaths(const PedestrianSet&, const ObstacleSet&);
};

#endif