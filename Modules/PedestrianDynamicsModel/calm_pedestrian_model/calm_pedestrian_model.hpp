#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>

#include "Goals/calm_goals/calm_goals.hpp"
#include "ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"
#include "PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"
#include "pedestrianmodel/pedestrian_dynamics_model.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel {
 public:
  CalmPedestrianModel();
  ~CalmPedestrianModel();

  void configure(const VIPRA::ConfigMap& configMap) override;
  void initialize(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet, Goals& goals) override;
  std::shared_ptr<VIPRA::State> timestep(PedestrianSet& pedestrianSet,
                                         ObstacleSet&   obstacleSet,
                                         Goals&         goals,
                                         float          time);

  //Getters and Setters
  float getPedestrianDistance(CalmPedestrianSet& pedestrianSet, int firstPedestrian, int secondPedestrian);
  std::vector<std::pair<std::string, int>> getNearestNeighbors();
  VIPRA::f3dVec                            getPropulsionForces();

  void calculatePropulsion(CalmPedestrianSet& pedestrianSet, CalmGoals& goals);
  void calculateNeartestNeighbors(CalmPedestrianSet& pedestrianSet);
  void calculateDistanceMatrices(CalmPedestrianSet& pedestrianSet);
  void calculateDesiredSpeeds(CalmPedestrianSet& pedestrianSet, CalmGoals& goals);

 private:
  std::vector<float> holds;
  std::vector<bool>  aislePermissions;

  int currentPriority;

  VIPRA::f3dVec racePositions;
  VIPRA::f3dVec propulsionForces;

  std::vector<std::pair<std::string, int>> nearestNeighbors;
  std::vector<float>                       priorities;

  std::vector<int> raceCounter;
  std::vector<int> opponentIDs;
  std::vector<int> startingAisles;

  std::vector<bool> raceFinished;
  std::vector<bool> released;

  float* pedestrianDistanceMatrix;
  float* obstacleDistanceMatrix;

  std::shared_ptr<VIPRA::State> modelState;

  void calculatePriority(CalmPedestrianSet& pedestrianSet, Goals& goals);
  void calculateBeta();
  void raceDetection();

  void updateModelState(CalmPedestrianSet& pedestrianSet, float time);

  inline bool neighborDirectionTest(CalmPedestrianSet& pedestrianSet,
                                    int                firstPedestrianIndex,
                                    int                secondPedestrianIndex,
                                    float              pedestrianDisplacementX,
                                    float              pedestrianDisplacementY,
                                    float              secondDisplacementX,
                                    float              secondDisplacementY);

  inline bool neighborSpacialTest(CalmPedestrianSet& pedestrianSet,
                                  int                firstPedestrianIndex,
                                  int                secondPedestrianIndex,
                                  float              pedestrianDisplacementX,
                                  float              pedestrianDisplacementY,
                                  float              secondDisplacementX,
                                  float              secondDisplacementY,
                                  std::string        originSet,
                                  float              firstShoulderLength);

  float getObstacleDistance(int pedIndex, int obsIndex);
};

#endif