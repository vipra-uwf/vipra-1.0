#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

#include <Goals/calm_goals/calm_goals.hpp>
#include <ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp>
#include <PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp>

#include <definitions/config_map.hpp>
#include <definitions/type_definitions.hpp>
#include <pedestrian_model/pedestrian_dynamics_model.hpp>

#include "calm_collision.hpp"
#include "calm_line.hpp"
#include "calm_rect.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel {
 public:
  void configure(const VIPRA::CONFIG::Map&) override;
  void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) override;
  std::shared_ptr<VIPRA::State> timestep(const PedestrianSet&, const ObstacleSet&,
                                         const Goals&, VIPRA::delta_t,
                                         VIPRA::t_step) override;

 private:
  VIPRA::f3dVec                 propulsionForces;
  std::vector<float>            betas;
  std::vector<VIPRA::dist>      nearestNeighborDists;
  std::shared_ptr<VIPRA::State> modelState;
  Collision                     collision;

  static constexpr VIPRA::delta_t slidingGoalTime = 0.1F;

  void calculatePropulsion(const CalmPedestrianSet&, const CalmGoals&);
  void calculateRepulsion(const CalmPedestrianSet&, const CalmGoals&);
  void calculateBetas(const CalmPedestrianSet&);

  void calculateNeartestNeighbors(const CalmPedestrianSet&, const ObstacleSet&,
                                  const Goals&);
  void calculateDistanceMatrices(const CalmPedestrianSet&);
  void updateModelState(const CalmPedestrianSet&, const CalmGoals&, VIPRA::delta_t,
                        VIPRA::t_step);

  [[nodiscard]] static bool objectSpatialTest(const Rect&, VIPRA::f3d objLeft,
                                              VIPRA::f3d objRight);

  [[nodiscard]] static bool  isPedInDirectionOfGoal(VIPRA::pcoord, VIPRA::goal,
                                                    VIPRA::pcoord other);
  [[nodiscard]] static bool  objectDirectionTest(VIPRA::pcoord, VIPRA::veloc,
                                                 VIPRA::f3d objCoords);
  [[nodiscard]] static float checkBlockedPath(VIPRA::pcoord, VIPRA::veloc, float shldrWid,
                                              VIPRA::dist maxDist, const ObstacleSet&);
  [[nodiscard]] static Line  getShoulderPoints(VIPRA::pcoord, VIPRA::goal, float);
  [[nodiscard]] static Rect  makeRectFromShldrs(VIPRA::pcoord, VIPRA::goal, float);
  [[nodiscard]] static VIPRA::f3d calculateSpeedDensity(const PedestrianSet&);
  [[nodiscard]] static float      calculateBeta(VIPRA::dist);

 public:
  CalmPedestrianModel(const CalmPedestrianModel&) = default;
  CalmPedestrianModel(CalmPedestrianModel&&) = delete;
  CalmPedestrianModel& operator=(const CalmPedestrianModel&) = default;
  CalmPedestrianModel& operator=(CalmPedestrianModel&&) = delete;
  CalmPedestrianModel() = default;
  ~CalmPedestrianModel() override = default;
};

#endif