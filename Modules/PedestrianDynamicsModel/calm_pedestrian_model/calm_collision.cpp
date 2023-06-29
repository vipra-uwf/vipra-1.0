

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
  calcCollisionRectangles(pedestrianSet, goals, data);

  const VIPRA::size pedCnt = pedestrianSet.getNumPedestrians();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    if (goals.isPedestianGoalMet(i)) continue;

    bool check = checkIfHighestPriority(pedestrianSet, goals, i, timestep);
    if (check)
      raceStatuses.at(i) = NO_RACE;
    else
      raceStatuses.at(i) = WAIT;

    // if (i == 62 || i == 108 || i == 127)
    //   spdlog::debug(
    //       "Race Status of {} is {}, its x is {}, its y is {} and its goal is {}, {}. Its "
    //       "velocity is {} x and {} y.",
    //       i, static_cast<int>(raceStatuses.at(i)), pedestrianSet.getPedCoords(i).x,
    //       pedestrianSet.getPedCoords(i).y, goals.getCurrentGoal(i).x,
    //       goals.getCurrentGoal(i).y, pedestrianSet.getPedVelocity(i).x,
    //       pedestrianSet.getPedVelocity(i).y);
  }
}

RaceStatus Collision::status(VIPRA::idx index) const { return raceStatuses.at(index); }

/**
 * @brief Calculates the collision rectangles for all pedestrians
 * 
 */
void Collision::calcCollisionRectangles(const PedestrianSet& pedestrianSet, const Goals& goals,
                                        const ModelData&     data) {
  const auto&       coords = pedestrianSet.getCoordinates();
  const auto&       velocities = pedestrianSet.getVelocities();
  const auto&       shldrs = data.shoulders;
  const VIPRA::size pedCnt = pedestrianSet.getNumPedestrians();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    VIPRA::f3d pedVel = velocities.at(i);

    // if(i==62||i==108||i==127)
    // spdlog::debug("Collision rectangle of {}: {}x {}y to {}x {}y",i,
    //               collisionRectangles.at(i).p1.x, collisionRectangles.at(i).p1.y,
    //               collisionRectangles.at(i).p3.x, collisionRectangles.at(i).p3.y);

    if (pedVel.magnitudeSquared() == 0) 
    {
      auto goalCoords = goals.getCurrentGoal(i);
      auto goalDirection = goalCoords - coords.at(i);

      auto shldr1 =
          (VIPRA::f3d{-goalDirection.y, goalDirection.x}.unit() * shldrs.at(i)) +
          coords.at(i);
      auto shldr2 =
          (VIPRA::f3d{goalDirection.y, -goalDirection.x}.unit() * shldrs.at(i)) +
          coords.at(i);

      const VIPRA::f3d range = (goalDirection.unit() * rectangleRange);
      collisionRectangles[i].p1 = shldr1;
      collisionRectangles[i].p2 = shldr1 + range;
      collisionRectangles[i].p3 = shldr2 + range;
      collisionRectangles[i].p4 = shldr2;
      continue;
    }

    const Line shoulders = getShoulderPoints(coords.at(i), pedVel, shldrs.at(i));
    const VIPRA::f3d range = (pedVel.unit() * rectangleRange);
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
                                       VIPRA::t_step ) {
  bool flag = true;
  // const auto& velocities = pedestrianSet.getVelocities();
  for (VIPRA::idx i = 0; i < pedestrianSet.getNumPedestrians(); i++) {
    if (i == index) continue;

    if (goals.isPedestianGoalMet(i)) continue;

    // if (index == 65 && timestep > 5000)
    //   spdlog::debug("For index: {}, pedestrian {}, flag is {}", index, i, flag);

    auto coords1 = pedestrianSet.getPedCoords(index);
    auto coords2 = pedestrianSet.getPedCoords(i);

    bool cr2in1 = isCoordInRectangle(coords2, collisionRectangles.at(index));
    bool cr1in2 = isCoordInRectangle(coords1, collisionRectangles.at(i));

    auto goal1 = goals.getCurrentGoal(index);
    auto goal2 = goals.getCurrentGoal(i);

    if(goal1!=goal2)
    {
      if (!cr2in1) {
        continue;
      }

      if (!cr1in2) {
        flag = false;
        continue;
      }
    }
    
    
    bool collisionCheck = checkIfCollide(index, i);

    if (!collisionCheck) {
      if (inRace.at(index).at(i)) {
        inRace.at(index).at(i) = false;
        inRace.at(i).at(index) = false;

        raceOpponents.at(i).erase(index);
        raceOpponents.at(index).erase(i);
      }
      continue;
    }

    if (goal1 == goal2) {
      if (coords1.distanceTo(goal1) > coords2.distanceTo(goal2)) flag = false;
      continue;
    }

    // if (index == 62)
    // spdlog::debug("For index: {}, pedestrian {} is considered", index, i);

    // if(index == 128 && i==54&&timestep>12000)
    //   spdlog::debug("Velocity dir of {} is {}x {}y and {} is {}x {}y", index, velocityDirections.at(index).x, velocityDirections.at(index).y, i, velocityDirections.at(i).x, velocityDirections.at(i).y);

    // if (index == 128 && i == 54 && timestep > 12000)
    //   spdlog::debug("Velocity of {} is {}x {}y and {} is {}x {}y", index, velocities.at(index).x, velocities.at(index).y, i, velocities.at(i).x, velocities.at(i).y);

    VIPRA::f3d collisionMidpoint;
    if (!inRace.at(index).at(i)) {
      collisionMidpoint = getCollisionAreaMidpoint(index, i);

      velocityDirections.at(index) = pedestrianSet.getPedVelocity(index).unit();

      intersectionMidpoints.at(index).at(i) = collisionMidpoint;
      intersectionMidpoints.at(i).at(index) = collisionMidpoint;

      inRace.at(i).at(index) = true;
      inRace.at(index).at(i) = true;
      raceOpponents.at(i).insert(index);
      raceOpponents.at(index).insert(i);

    } else {
      collisionMidpoint = intersectionMidpoints.at(index).at(i);
    }

    if (coords1.distanceTo(collisionMidpoint) > coords2.distanceTo(collisionMidpoint))
      flag = false;
    else if (coords1.distanceTo(collisionMidpoint) ==
              coords2.distanceTo(collisionMidpoint)) {
      if (index < i) flag = false;
    }

    // if (index == 101 || index == 57 || index == 56 || index == 122) {
    //   // spdlog::debug("Their collision midpoint is {}x, {}y", collisionMidpoint.x,collisionMidpoint.y);
    //   spdlog::debug("The distance between {} and {} is {}", index, i, coords1.distanceTo(coords2));
    //   spdlog::debug("Their overall midpoint is {}x, {}y", overallMidpoint.x,overallMidpoint.y);
    //   spdlog::debug(
    //       "Distance of {} to overall midpoint is {}. Distance of {} to overall midpoint "
    //       "is {}.",
    //       index, coords1.distanceTo(overallMidpoint), i,
    //       coords2.distanceTo(overallMidpoint));
    // }
    }
  return flag;
}

/**
 * @brief Checks if a point is on or inside the given rectangle
 * 
 * @param coords 
 * @param rect 
 * @return true 
 * @return false 
 */
bool Collision::isCoordInRectangle(VIPRA::f3d coords, Rect& rect) {
  
  std::vector<VIPRA::f3d> rectPoints{rect.p1,rect.p2,rect.p3,rect.p4};
  float maxX = rect.p1.x;
  for(auto & rectPoint : rectPoints)
  {
    maxX = max(maxX,rectPoint.x);
  }
  VIPRA::f3d ptInf(2*maxX, coords.y);
  
  int cnt = 0;
  for(size_t i = 0; i < rectPoints.size(); i++)
  {
    auto pt1 = rectPoints[i];
    auto pt2 = rectPoints[(i+1)%rectPoints.size()];
    if(orientation(pt1,coords,pt2)==0)
      return true;

    if(checkIfLineSegmentsIntersect(pt1, pt2, coords, ptInf))
      cnt++;
  }
  return (cnt%2==1);
}

/**
 * @brief Checks if two indices' collision rectangles collide
 * 
 * @param index1 : 
 * @param index2 : 
 * @return true 
 * @return false 
 */
bool Collision::checkIfCollide(VIPRA::idx index1, VIPRA::idx index2) {
  Rect& r1 = collisionRectangles.at(index1);
  Rect& r2 = collisionRectangles.at(index2);
  return doRectanglesIntersect(r1, r2);
}

/// @brief Returns the maximum value between a and b
/// @param a
/// @param b
/// @return a or b
float Collision::max(float a, float b) {
  if (a > b)
    return a;
  else
    return b;
}

/// @brief Returns the minimum value between a and b
/// @param a
/// @param b
/// @return a or b
float Collision::min(float a, float b) {
  if (a < b)
    return a;
  else
    return b;
}

/// @brief Check whether two rectangles intersect
/// @param r1
/// @param r2
/// @return true or false
bool Collision::doRectanglesIntersect(Rect& r1, Rect& r2) {
  std::vector<std::pair<VIPRA::f3d, VIPRA::f3d>> s1;
  std::vector<std::pair<VIPRA::f3d, VIPRA::f3d>> s2;
  s1.emplace_back(r1.p1, r1.p2);
  s1.emplace_back(r1.p2, r1.p3);
  s1.emplace_back(r1.p3, r1.p4);
  s1.emplace_back(r1.p4, r1.p1);

  s2.emplace_back(r2.p1, r2.p2);
  s2.emplace_back(r2.p2, r2.p3);
  s2.emplace_back(r2.p3, r2.p4);
  s2.emplace_back(r2.p4, r2.p1);

  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
      bool check = checkIfLineSegmentsIntersect(s1[i].first, s1[i].second, s2[j].first,
                                                s2[j].second);
      if (check) return true;
    }
  }

  return false;
}

/// @brief If p, q and pt are collinear, check if pt lies on segment pq
/// @param p
/// @param q
/// @param pt
/// @return true or false
bool Collision::checkIfOnLineSegment(VIPRA::f3d p, VIPRA::f3d q, VIPRA::f3d pt) {
  return pt.x <= max(p.x, q.x) && pt.y <= max(p.y, q.y) && pt.x >= min(p.x, q.x) &&
         pt.y >= min(p.y, q.y);
}

/// @brief
/// To find orientation of ordered triplet (p, q, r).
/// @param p
/// @param q
/// @param r
/// @return The function returns following values: 0 --> p, q and r are collinear; 1 --> Clockwise; 2 --> Counterclockwise
int Collision::orientation(VIPRA::f3d p, VIPRA::f3d q, VIPRA::f3d r) {
  float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0)  // collinear
    return 0;

  return (val > 0) ? 1 : 2;  // clockwise or counterclock wise
}

/// @brief Check if 2 line segments intersect, where p1 and q1 are endpoints of the first line segment, and p2 and q2 are endpoints of the second line segment
/// @param p1
/// @param q1
/// @param p2
/// @param q2
/// @return true or false
bool Collision::checkIfLineSegmentsIntersect(VIPRA::f3d p1, VIPRA::f3d q1, VIPRA::f3d p2,
                                             VIPRA::f3d q2) {
  if (p1 == p2 || p1 == q2 || q1 == p2 || q1 == q2) return true;

  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4) return true;

  if (o1 == 0 && checkIfOnLineSegment(p1, q1, p2)) return true;
  if (o2 == 0 && checkIfOnLineSegment(p1, q1, q2)) return true;
  if (o3 == 0 && checkIfOnLineSegment(p2, q2, p1)) return true;
  if (o4 == 0 && checkIfOnLineSegment(p2, q2, q1)) return true;

  return false;
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

void Collision::initializeRectangles(const PedestrianSet& pedestrianSet,
                                     const Goals& goals, const ModelData& data) {
  collisionRectangles = std::vector<Rect>(pedestrianSet.getNumPedestrians());
  const auto& shldrs = data.shoulders;
  for(size_t i = 0; i < collisionRectangles.size(); i++)
  {
    auto coords = pedestrianSet.getPedCoords(i);
    auto goalCoords = goals.getCurrentGoal(i);
    auto goalDirection = goalCoords - coords;

    auto shldr1 = (VIPRA::f3d{-goalDirection.y, goalDirection.x}.unit() * shldrs.at(i)) + coords;
    auto shldr2 = (VIPRA::f3d{goalDirection.y, -goalDirection.x}.unit() * shldrs.at(i)) + coords;

    const VIPRA::f3d range = (goalDirection.unit() * rectangleRange);
    collisionRectangles[i].p1 = shldr1;
    collisionRectangles[i].p2 = shldr1 + range;
    collisionRectangles[i].p3 = shldr2 + range;
    collisionRectangles[i].p4 = shldr2;
  }
}

void Collision::initialize(const PedestrianSet& pedestrianSet, const Goals& goals, const ModelData& data) {
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

  velocityDirections = std::vector<VIPRA::f3d>(pedestrianSet.getNumPedestrians());

  initializeRectangles(pedestrianSet, goals, data);
}