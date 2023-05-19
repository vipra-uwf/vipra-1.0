#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <vector>


#include <Goals/calm_goals/calm_goals.hpp>
#include <ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp>
#include <PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp>
#include <pedestrian_model/pedestrian_dynamics_model.hpp>

#include "calm_rect.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel {
 public:
  ~CalmPedestrianModel() override;

  void                          configure(const VIPRA::CONFIG::Map& configMap) override;
  void                          initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) override;
  std::shared_ptr<VIPRA::State> timestep(const PedestrianSet&, const ObstacleSet&, const Goals&, VIPRA::delta_t,
                                         VIPRA::t_step) override;

 protected:
  VIPRA::f3dVec      propulsionForces;
  std::vector<float> betas;

  float*                        pedestrianDistanceMatrix;
  std::vector<float>            nearestNeighbors;
  std::vector<VIPRA::idx>       nearestNeighborIndex;
  std::shared_ptr<VIPRA::State> modelState;

  enum RaceStatus { NO_RACE, WAIT };
  std::vector<RaceStatus>        raceStatuses;
  std::vector<VIPRA::size>       raceOpponents;
  std::vector<std::vector<bool>> inRace;
  std::vector<int>               raceCounter;

  std::vector<std::vector<VIPRA::f3d>> intersectionMidpoints;
  std::vector<Rect>                    collisionRectangle;
  VIPRA::f3dVec                        velDir;


  void updateModelState(const CalmPedestrianSet&, const CalmGoals&, VIPRA::delta_t, VIPRA::t_step) noexcept;
  void raceDetection(const CalmPedestrianSet& pedestrianSet, const Goals& goals, VIPRA::t_step timestep);

  void calculatePropulsion(const CalmPedestrianSet&, const CalmGoals&) noexcept;
  void calculateRepulsion(const CalmPedestrianSet&, const CalmGoals&) noexcept;
  void calculateBetas(const CalmPedestrianSet&) noexcept;
  void calculateNeartestNeighbors(const CalmPedestrianSet&, const ObstacleSet&, const Goals&) noexcept;
  void calculateDistanceMatrices(const CalmPedestrianSet&) noexcept;



  [[nodiscard]] static inline float calculateBeta(float) noexcept;


  [[nodiscard]] bool       checkIfCollide(const CalmPedestrianSet& pedestrianSet, const Goals&, VIPRA::size, VIPRA::size);
  [[nodiscard]] VIPRA::f3d getCollisionAreaMidpoint(const CalmPedestrianSet&, const Goals&, VIPRA::idx, VIPRA::idx);
  [[nodiscard]] bool checkIfHighestPriority(const CalmPedestrianSet& pedestrianSet, const Goals& goals, VIPRA::idx index,
                                            VIPRA::t_step timestep);


  [[nodiscard]] Rect getCollisionRectangle(const CalmPedestrianSet& pedestrianSet, const Goals&, VIPRA::idx, float shldrlen);
  static void        addIntersectionPoints(VIPRA::f3d, VIPRA::f3d, VIPRA::f3d, VIPRA::f3d, VIPRA::f3dVec&);
  [[nodiscard]] static bool        doRectanglesIntersect(Rect& r1, Rect& r2);
  [[nodiscard]] static bool        checkIfOnLineSegment(VIPRA::f3d, VIPRA::f3d, VIPRA::f3d);
  [[nodiscard]] static int         orientation(VIPRA::f3d, VIPRA::f3d, VIPRA::f3d);
  [[nodiscard]] static bool        checkIfLineSegmentsIntersect(VIPRA::f3d, VIPRA::f3d, VIPRA::f3d, VIPRA::f3d);
  [[nodiscard]] static float       shortestDistanceToLineSegment(VIPRA::f3d, VIPRA::f3d, VIPRA::f3d);
  [[nodiscard]] static inline bool lineIntersect(VIPRA::f3d start1, VIPRA::f3d end1, VIPRA::f3d start2,
                                                 VIPRA::f3d end2) noexcept;
  [[nodiscard]] static inline bool isPointInRect(const Rect& rect, VIPRA::f3d p1) noexcept;


  [[nodiscard]] bool               checkBehind(const PedestrianSet&, VIPRA::f3d pedCoords, VIPRA::f3d pedVelocity);
  [[nodiscard]] static inline bool isPedInDirectionOfGoal(VIPRA::f3d goalCoords, VIPRA::f3d pedCoords,
                                                          VIPRA::f3d secondCoords) noexcept;


  [[nodiscard]] static inline Line  getShoulderPoints(VIPRA::f3d coords, VIPRA::f3d velocity, float shoulderWidth) noexcept;
  [[nodiscard]] static inline bool  objectDirectionTest(VIPRA::f3d pedCoords, VIPRA::f3d pedVelocity,
                                                        VIPRA::f3d objCoords) noexcept;
  [[nodiscard]] static inline bool  objectSpatialTest(VIPRA::f3d pedCoords, VIPRA::f3d pedVelocity, float pedShoulderLength,
                                                      VIPRA::f3d objLeft, VIPRA::f3d objRight) noexcept;
  [[nodiscard]] static inline float checkBlockedPath(VIPRA::f3d coords, VIPRA::f3d velocity, float shoulderWidth,
                                                     float checkDistance, const ObstacleSet& obsSet) noexcept;



  [[nodiscard]] static VIPRA::f3d calculateSpeedDensity(const PedestrianSet&);
};

#endif