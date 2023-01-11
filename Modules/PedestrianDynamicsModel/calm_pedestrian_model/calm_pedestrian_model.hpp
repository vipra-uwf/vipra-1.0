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
  float getPedestrianDistance(const CalmPedestrianSet&, VIPRA::idx firstPedestrian, VIPRA::idx secondPedestrian);
  std::vector<float> getNearestNeighbors();
  VIPRA::f3dVec      getPropulsionForces();

  void calculatePropulsion(const CalmPedestrianSet&, const CalmGoals&);
  void calculateNeartestNeighbors(const CalmPedestrianSet&, const ObstacleSet&, const Goals&);
  void calculateDistanceMatrices(const CalmPedestrianSet&);
  void updateDesiredSpeeds(const CalmPedestrianSet&, const CalmGoals&);

 private:
  VIPRA::f3dVec              propulsionForces;
  float*                     pedestrianDistanceMatrix;
  std::vector<float>         nearestNeighbors;
  std::shared_ptr<CalmState> modelState;

  void calculatePriority(const CalmPedestrianSet&, const Goals&);
  void calculateBeta();
  void raceDetection();

  void updateModelState(const CalmPedestrianSet&, VIPRA::delta_t);

  inline bool objectDirectionTest(const VIPRA::f3d& pedCoords,
                                  const VIPRA::f3d& pedVelocity,
                                  const VIPRA::f3d& objCoords);

  inline bool objectSpatialTest(const VIPRA::f3d& pedCoords,
                                const VIPRA::f3d& pedVelocity,
                                float             pedShoulderLength,
                                const VIPRA::f3d& objLeft,
                                const VIPRA::f3d& objRight);

  inline float checkBlockedPath(const VIPRA::f3d&  coords,
                                const VIPRA::f3d&  velocity,
                                float              shoulderWidth,
                                float              checkDistance,
                                const ObstacleSet& obsSet);

  constexpr float calculateDesiredSpeed(float distance);
};

#endif