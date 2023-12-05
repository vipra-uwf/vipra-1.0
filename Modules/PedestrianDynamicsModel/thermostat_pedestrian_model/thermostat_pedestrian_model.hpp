#ifndef THERMOSTAT_PEDESTRIAN_MODEL_HPP
#define THERMOSTAT_PEDESTRIAN_MODEL_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <memory>
#include <vector>

#include "Goals/calm_goals/calm_goals.hpp"

#include "configuration/config.hpp"
#include "definitions/type_definitions.hpp"
#include "pedestrian_model/pedestrian_dynamics_model.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

#include "thermostat_collision.hpp"
#include "../model_helpers/rect.hpp"
#include "randomization/random.hpp"

class ThermostatPedestrianModel : public VIPRA::PedestrianDynamicsModel {
 public:
  // struct ModelData {
  //   std::vector<float>          betas;
  //   std::vector<float>          masses;
  //   std::vector<float>          desiredSpeeds;
  //   std::vector<float>          shoulders;
  //   std::vector<VIPRA::delta_t> reactionTimes;
  //   std::vector<VIPRA::dist>    nearestNeighborDists;
  //   VIPRA::f3dVec               propulsionForces;
  // };

  struct ConfigData {
    float meanMass;
    float massStdDev;
    float meanReactionTime;
    float reactionTimeStdDev;
    float meanMaxSpeed;
    float maxSpeedStdDev;
    float meanShoulderLen;
    float ShoulderLenStdDev;
  };

  void configure(const VIPRA::Config&) override;
  void initialize(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&,
                  const VIPRA::Goals&) override;
  void timestep(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&,
                const VIPRA::Goals&, VIPRA::State&, VIPRA::delta_t,
                VIPRA::t_step) override;

 private:
  ConfigData         config{};
  ModelData          peds;
  ThermostatCollision collision;
  VIPRA::pRNG_Engine rand{};

  std::vector<Line> pedShoulders;
  
  std::vector<RaceStatus> raceStatuses;
  std::vector<std::vector<bool>>  inRace;

  static constexpr VIPRA::delta_t slidingGoalTime = 0.1F;
  static constexpr float equilibriumDistance = 0.382;
  static constexpr float equilibriumResolution = 0.01F;

  void calculatePropulsion(const VIPRA::PedestrianSet&, const VIPRA::Goals&);
  void calculateRepulsion(const VIPRA::PedestrianSet&, const VIPRA::Goals&);
  void calculateBetas(const VIPRA::PedestrianSet&);

  void calculateShoulders(const VIPRA::PedestrianSet&, const VIPRA::Goals&);
  void calculateNeartestNeighbors(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&,
                                  const VIPRA::Goals&);
  void calculateDistanceMatrices(const VIPRA::PedestrianSet&);
  void updateModelState(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&, const VIPRA::Goals&, VIPRA::State&,
                        VIPRA::delta_t, VIPRA::t_step);

  [[nodiscard]] VIPRA::f3d thermostat(VIPRA::idx, 
                                           VIPRA::f3d,
                                           VIPRA::f3d,
                                           std::vector<float>,
                                           const VIPRA::ObstacleSet&,
                                           const VIPRA::Goals&);


  [[nodiscard]] static bool objectSpatialTest(const Rect&, VIPRA::f3d objLeft,
                                              VIPRA::f3d objRight);

  [[nodiscard]] static bool isPedInDirectionOfGoal(VIPRA::pcoord, VIPRA::goal,
                                                   VIPRA::pcoord other);
  [[nodiscard]] static bool objectDirectionTest(VIPRA::pcoord, VIPRA::veloc,
                                                VIPRA::f3d objCoords);
  [[nodiscard]] float checkBlockedPath(VIPRA::idx, VIPRA::veloc, VIPRA::dist maxDist,
                                       const VIPRA::ObstacleSet&);
  [[nodiscard]] Rect  makeRectFromShldrs(VIPRA::idx, VIPRA::pcoord, VIPRA::goal);
  [[nodiscard]] static VIPRA::f3d calculateSpeedDensity(const VIPRA::PedestrianSet&);
  [[nodiscard]] static float      calculateBeta(VIPRA::dist);

  void setModelData(const VIPRA::PedestrianSet&);

 public:
  ThermostatPedestrianModel(const ThermostatPedestrianModel&) = default;
  ThermostatPedestrianModel(ThermostatPedestrianModel&&) = delete;
  ThermostatPedestrianModel& operator=(const ThermostatPedestrianModel&) = default;
  ThermostatPedestrianModel& operator=(ThermostatPedestrianModel&&) = delete;
  ThermostatPedestrianModel() = default;
  ~ThermostatPedestrianModel() override = default;

};

#endif