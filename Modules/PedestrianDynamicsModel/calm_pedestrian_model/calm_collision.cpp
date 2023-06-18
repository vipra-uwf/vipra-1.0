

#include "calm_collision.hpp"
#include "PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

namespace {
inline Line getShoulderPoints(const VIPRA::f3d& coords, const VIPRA::f3d& velocity,
                              float shoulderWidth) noexcept {
  if (velocity == VIPRA::f3d{0, 0, 0}) {
    return {(VIPRA::f3d{0, shoulderWidth}), (VIPRA::f3d{0, -shoulderWidth})};
  }
  return {(VIPRA::f3d{-velocity.y, velocity.x}.unit() * shoulderWidth) + coords,
          (VIPRA::f3d{velocity.y, -velocity.x}.unit() * shoulderWidth) + coords};
}
}  // namespace

/**
 * @brief The race detection function which resolves race conditions in the simulation
 * 
 */
void Collision::raceDetection(const PedestrianSet& pedestrianSet, const ModelData& data,
                              const Goals& goals, VIPRA::t_step timestep) {
  calcCollisionRectangles(pedestrianSet, data);

  const VIPRA::size pedCnt = pedestrianSet.getNumPedestrians();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    if (goals.isPedestianGoalMet(i)) continue;

    bool check = checkIfHighestPriority(pedestrianSet, goals, i, timestep);
    if (check)
      raceStatuses.at(i) = NO_RACE;
    else
      raceStatuses.at(i) = WAIT;

    // spdlog::debug("Race Status of {} is {}, its x is {}, its y is {} and its goal is {}, {}. Its velocity is {} x and {} y.", i, static_cast<int>(raceStatuses.at(i)), pedestrianSet.getPedCoords(i).x, pedestrianSet.getPedCoords(i).y, goals.getCurrentGoal(i).x, goals.getCurrentGoal(i).y,pedestrianSet.getPedVelocity(i).x,pedestrianSet.getPedVelocity(i).y);
  }
}

RaceStatus Collision::status(VIPRA::idx index) const { return raceStatuses.at(index); }

/**
 * @brief Calculates the collision rectangles for all pedestrians
 * 
 */
void Collision::calcCollisionRectangles(const PedestrianSet& pedestrianSet,
                                        const ModelData&     data) {
  const auto&       coords = pedestrianSet.getCoordinates();
  const auto&       velocities = pedestrianSet.getVelocities();
  const auto&       shldrs = data.shoulders;
  const VIPRA::size pedCnt = pedestrianSet.getNumPedestrians();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    VIPRA::f3d pedVel = velocities.at(i);

    if (pedVel.magnitudeSquared() < minspeed) continue;

    const Line       shoulders = getShoulderPoints(coords.at(i), pedVel, shldrs.at(i));
    const VIPRA::f3d range = (pedVel.unit() * 0.575);
    collisionRectangles.at(i) = {shoulders.p1, shoulders.p1 + range, shoulders.p2 + range,
                                 shoulders.p2};
  }
}

/**
 * @brief Checks if the current index has the highest priority within its collision boundary
 * 
 */
bool Collision::checkIfHighestPriority(const PedestrianSet& pedestrianSet,
                                       const Goals& goals, VIPRA::idx index,
                                       VIPRA::t_step) {
  bool flag = true;
  for (VIPRA::idx i = 0; i < pedestrianSet.getNumPedestrians(); i++) {
    if (i == index) continue;

    if (goals.isPedestianGoalMet(i)) continue;

    if (!checkIfCollide(index, i)) {
      if (inRace.at(index).at(i)) {
        inRace.at(index).at(i) = false;
        inRace.at(i).at(index) = false;

        raceOpponents.at(i).erase(index);
        raceOpponents.at(index).erase(i);

        raceCounter.at(i).at(index) = 0;
        raceCounter.at(index).at(i) = 0;
      }
      continue;
    }

    VIPRA::f3d collisionMidpoint;
    if (!inRace.at(index).at(i) || raceCounter.at(index).at(i) > maxCount) {
      collisionMidpoint = getCollisionAreaMidpoint(index, i);

      intersectionMidpoints.at(index).at(i) = collisionMidpoint;
      intersectionMidpoints.at(i).at(index) = collisionMidpoint;

      inRace.at(i).at(index) = true;
      inRace.at(index).at(i) = true;
      raceOpponents.at(i).insert(index);
      raceOpponents.at(index).insert(i);

      raceCounter.at(i).at(index) = 0;
      raceCounter.at(index).at(i) = 0;

    } else {
      collisionMidpoint = intersectionMidpoints.at(index).at(i);
    }
  }
  return flag;
}

/**
 * @brief Checks if two indices' collision rectangles collide
 * 
 * @param index1 : 
 * @param index2 : 
 * @return true 
 * @return false 
 */
bool Collision::checkIfCollide(VIPRA::idx index1, VIPRA::idx index2) const {
  const Rect& r1 = collisionRectangles.at(index1);
  const Rect& r2 = collisionRectangles.at(index2);
  return r1.doesIntersect(r2);
}

/**
 * @brief If Rectangles intersect, get intersection area midpoint
 * 
 * @param index1 : 
 * @param index2 : 
 * @return VIPRA::f3d 
 */
VIPRA::f3d Collision::getCollisionAreaMidpoint(VIPRA::idx index1, VIPRA::idx index2) {
  const Rect& r1 = collisionRectangles.at(index1);
  const Rect& r2 = collisionRectangles.at(index2);

  std::array<Line, 4> s1{
      Line{r1.p1, r1.p2}, {r1.p2, r1.p3}, {r1.p3, r1.p4}, {r1.p4, r1.p1}};
  std::array<Line, 4> s2{
      Line{r2.p1, r2.p2}, {r2.p2, r2.p3}, {r2.p3, r2.p4}, {r2.p4, r2.p1}};

  VIPRA::f3dVec intersectionPoints;
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
      if (s1.at(i).doesIntersect(s2.at(j))) {
        addIntersectionPoints(s1.at(i).p1, s1.at(i).p2, s2.at(j).p1, s2.at(j).p2,
                              intersectionPoints);
      }
    }
  }

  VIPRA::f3d midpoint(0, 0, 0);
  for (const auto& intersectionPoint : intersectionPoints) {
    midpoint += intersectionPoint;
  }
  midpoint /= intersectionPoints.size();

  return midpoint;
}

/// @brief Add intersection points of p1q1 and p2q2 to the intersectionPoints vector
/// @param p1
/// @param q1
/// @param p2
/// @param q2
/// @param intersectionPoints
void Collision::addIntersectionPoints(VIPRA::f3d p1, VIPRA::f3d q1, VIPRA::f3d p2,
                                      VIPRA::f3d q2, VIPRA::f3dVec& intersectionPoints) {
  float a1 = q1.y - p1.y;
  float b1 = p1.x - q1.x;
  float a2 = q2.y - p2.y;
  float b2 = p2.x - q2.x;
  float c1 = a1 * p1.x + b1 * p1.y;
  float c2 = a2 * p2.x + b2 * p2.y;

  float det = a1 * b2 - a2 * b1;

  if (det == 0) {
    if (Line::checkIfOnLineSegment(p1, q1, p2)) intersectionPoints.push_back(p2);
    if (Line::checkIfOnLineSegment(p1, q1, q2)) intersectionPoints.push_back(q2);
    if (Line::checkIfOnLineSegment(p2, q2, p1)) intersectionPoints.push_back(p1);
    if (Line::checkIfOnLineSegment(p2, q2, q1)) intersectionPoints.push_back(q1);
  } else {
    float pX{};
    float pY{};
    pX = (b2 * c1 - b1 * c2) / det;
    pY = -(a2 * c1 - a1 * c2) / det;
    intersectionPoints.emplace_back(pX, pY);
  }
}

void Collision::initialize(const PedestrianSet& pedestrianSet) {
  raceStatuses = std::vector<RaceStatus>(pedestrianSet.getNumPedestrians(), NO_RACE);
  raceOpponents = std::vector<std::set<VIPRA::idx>>(pedestrianSet.getNumPedestrians());
  raceCounter = std::vector<std::vector<VIPRA::cnt>>(
      pedestrianSet.getNumPedestrians(),
      std::vector<VIPRA::cnt>(pedestrianSet.getNumPedestrians(), 0));
  inRace = std::vector<std::vector<bool>>(
      pedestrianSet.getNumPedestrians(),
      std::vector<bool>(pedestrianSet.getNumPedestrians(), false));

  intersectionMidpoints = std::vector<std::vector<VIPRA::f3d>>(
      pedestrianSet.getNumPedestrians(),
      VIPRA::f3dVec(pedestrianSet.getNumPedestrians()));
  collisionRectangles = std::vector<Rect>(pedestrianSet.getNumPedestrians());
}