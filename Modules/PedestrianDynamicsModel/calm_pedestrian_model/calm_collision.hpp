#ifndef CALM_COLLISION_HPP
#define CALM_COLLISION_HPP

#include <set>

#include <Goals/calm_goals/calm_goals.hpp>
#include <PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp>

#include <definitions/type_definitions.hpp>

#include "calm_rect.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

enum RaceStatus { NO_RACE, WAIT };

class Collision {
 public:
  void initialize(const PedestrianSet&);
  void raceDetection(const CalmPedestrianSet&, const Goals&, VIPRA::t_step);

  [[nodiscard]] RaceStatus status(VIPRA::idx) const;

 private:
  std::vector<RaceStatus>              raceStatuses;
  std::vector<Rect>                    collisionRectangles;
  std::vector<std::set<VIPRA::idx>>    raceOpponents;
  std::vector<std::vector<bool>>       inRace;
  std::vector<std::vector<VIPRA::cnt>> raceCounter;
  std::vector<std::vector<VIPRA::f3d>> intersectionMidpoints;

  static constexpr VIPRA::cnt maxCount = 500;
  static constexpr float      minspeed = 0.0001F;

  void calcCollisionRectangles(const CalmPedestrianSet&);

  static void        addIntersectionPoints(VIPRA::f3d, VIPRA::f3d, VIPRA::f3d, VIPRA::f3d,
                                           VIPRA::f3dVec&);
  [[nodiscard]] bool checkIfCollide(VIPRA::size, VIPRA::size) const;
  [[nodiscard]] VIPRA::f3d getCollisionAreaMidpoint(VIPRA::idx, VIPRA::idx);
  [[nodiscard]] bool       checkIfHighestPriority(const CalmPedestrianSet&, const Goals&,
                                                  VIPRA::idx, VIPRA::t_step);
};

#endif