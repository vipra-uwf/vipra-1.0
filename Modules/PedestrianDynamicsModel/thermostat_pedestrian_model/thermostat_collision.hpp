#ifndef CALM_COLLISION_HPP
#define CALM_COLLISION_HPP

#include <set>
#include <stdlib.h>
#include <time.h>

#include "Goals/calm_goals/calm_goals.hpp"
#include "PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"

#include "definitions/type_definitions.hpp"

#include "../model_helpers/rect.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

enum RaceStatus { NO_RACE, WAIT };

struct ModelData {
  std::vector<float>          betas;
  std::vector<float>          masses;
  std::vector<float>          desiredSpeeds;
  std::vector<float>          shoulders;
  std::vector<VIPRA::delta_t> reactionTimes;
  std::vector<VIPRA::dist>    nearestNeighborDists;
  VIPRA::f3dVec               propulsionForces;
};

class ThermostatCollision {
 public:
  void initialize(const VIPRA::PedestrianSet&, const VIPRA::Goals&, const ModelData&);
  void raceDetection(const VIPRA::PedestrianSet&, const ModelData&, const VIPRA::Goals&,
                     VIPRA::t_step, const VIPRA::ObstacleSet&);

  void initializeRectangles(const VIPRA::PedestrianSet& pedestrianSet,
                            const VIPRA::Goals&         goals, const ModelData&);

  void assignRaceStatuses(std::vector<RaceStatus>&, std::vector<std::vector<bool>>&);

  [[nodiscard]] RaceStatus status(VIPRA::idx) const;

  [[nodiscard]] bool pedInRace(VIPRA::idx) const;

 private:
  std::vector<RaceStatus>              raceStatuses;
  std::vector<Rect>                    collisionRectangles;
  std::vector<std::vector<bool>>       inRace;
  std::vector<std::vector<VIPRA::f3d>> intersectionMidpoints;
  std::vector<VIPRA::f3d>              velocityDirections;
  bool                                 hasPriority;

  static constexpr VIPRA::cnt maxCount = 500;
  static constexpr float      minspeed = 0.00000001F;
  static constexpr float      rectangleRange = 0.4;

  void        calcCollisionRectangles(const VIPRA::PedestrianSet&, const VIPRA::Goals&,
                                      const ModelData&);
  static void addIntersectionPoints(VIPRA::f3d, VIPRA::f3d, VIPRA::f3d, VIPRA::f3d,
                                    VIPRA::f3dVec&);
  [[nodiscard]] bool       checkIfCollide(VIPRA::size, VIPRA::size);
  [[nodiscard]] VIPRA::f3d getCollisionAreaMidpoint(VIPRA::idx, VIPRA::idx);
  [[nodiscard]] bool       checkIfHighestPriority(const VIPRA::PedestrianSet&,
                                                  const VIPRA::Goals&, VIPRA::idx,
                                                  VIPRA::t_step);
  
};

#endif