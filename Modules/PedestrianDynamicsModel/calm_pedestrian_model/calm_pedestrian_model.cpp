#include "calm_pedestrian_model.hpp"

CalmPedestrianModel::CalmPedestrianModel() {}

CalmPedestrianModel::~CalmPedestrianModel() {
  delete[] pedestrianDistanceMatrix;
}

void
CalmPedestrianModel::configure([[maybe_unused]] const VIPRA::Config::Map& configMap) {}

void
CalmPedestrianModel::initialize(const PedestrianSet&                pedestrianSet,
                                [[maybe_unused]] const ObstacleSet& obstacleSet,
                                [[maybe_unused]] const Goals&       goals) {
  pedestrianDistanceMatrix = new float[pedestrianSet.getNumPedestrians() * pedestrianSet.getNumPedestrians()];
  propulsionForces = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});
  modelState = std::make_shared<VIPRA::State>(pedestrianSet.getNumPedestrians());
  nearestNeighbors = std::vector<float>(pedestrianSet.getNumPedestrians());
  betas = std::vector<float>(pedestrianSet.getNumPedestrians());
  nearestNeighborIndex = std::vector<VIPRA::idx>(pedestrianSet.getNumPedestrians());


  raceStatuses = std::vector<RaceStatus>(pedestrianSet.getNumPedestrians(), NO_RACE);
  raceOpponents = std::vector<VIPRA::idx>(pedestrianSet.getNumPedestrians());
  raceCounter = std::vector<int>(pedestrianSet.getNumPedestrians(),0);
}

bool
CalmPedestrianModel::checkIfIntersect(const CalmPedestrianSet& pedestrianSet,
                                      const VIPRA::size        index1,
                                      const VIPRA::size        index2) {
  const auto& coords = pedestrianSet.getPedestrianCoordinates();
  auto        coord1 = coords[index1];
  auto        coord2 = coords[index2];

  const float xdiff = 0.2, ydiff = 0.4;
  // spdlog::debug("X:{} to {}, Y:{} to {} for {}", coord1.x - xdiff, coord1.x + xdiff, coord2.y - ydiff, coord2.y + ydiff, index1);
  if (coord1.x - xdiff > coord2.x + xdiff || coord2.x - xdiff > coord1.x + xdiff)
    return false;

  if (coord1.y - ydiff > coord2.y + ydiff || coord2.y - ydiff > coord1.y + ydiff)
    return false;

  return true;
}

VIPRA::f3d CalmPedestrianModel::getGoalIntersection(const CalmPedestrianSet& pedestrianSet, const Goals& goals, VIPRA::idx idx1, VIPRA::idx idx2)
{
  VIPRA::f3d p1 = pedestrianSet.getPedCoords(idx1);
  VIPRA::f3d p2 = pedestrianSet.getPedCoords(idx2);
  VIPRA::f3d g1 = goals.getCurrentGoal(idx1);
  VIPRA::f3d g2 = goals.getCurrentGoal(idx2);

  float a1 = g1.y - p1.y, b1 = p1.x - g1.x;
  float a2 = g2.y - p2.y, b2 = p2.x - g2.x;
  float c1 = a1*p1.x + b1*p1.y;
  float c2 = a2*p2.x + b2*p2.y;

  float det = a1*b2 - a2*b1;
  
  if(det==0)
  {
    if(g1==g2)
      return g1;
    else if(g1.distanceTo(p1)+g1.distanceTo(p2) < g2.distanceTo(p1)+g2.distanceTo(p2))
      return g1;
    else
      return g2;
  }
  else
  {
    float x,y;
    x = (b2*c1 - b1*c2)/det;
    y = -(a2*c1 - a1*c2)/det;
    return VIPRA::f3d(x,y);
  }
  
}

float CalmPedestrianModel::shortestDistanceToLineSegment(VIPRA::f3d point, VIPRA::f3d start, VIPRA::f3d end) {

  float dotProd = (end.x - start.x)*(point.x - start.x) + (end.y - start.y)*(point.y - start.y);

  float segLenSq = start.distanceToSquared(end);
  
  if(segLenSq == 0)
    return point.distanceTo(start);
  
  float distRat = dotProd/segLenSq;
  if(distRat >= 1)
  {
    if(point.distanceTo(start) < point.distanceTo(end))
      return point.distanceTo(start);
    else
      return point.distanceTo(end);
  }
  else
  {
    float bX = start.x + distRat*(end.x - start.x);
    float bY = start.y + distRat*(end.y - start.y);
    return sqrt((point.x - bX)*(point.x - bX) + (point.y - bY)*(point.y - bY));
  }
}

void
CalmPedestrianModel::raceDetection(const CalmPedestrianSet& pedestrianSet, const Goals& goals) {
  
  for(VIPRA::idx i = 0; i < pedestrianSet.getNumPedestrians(); i++)
  {
    if(pedestrianSet.getPedCoords(i).x >= 24)
    {
      raceStatuses.at(i) = NO_RACE;
      continue;
    }

    bool check = checkIfHighestPriority(pedestrianSet,goals,i);
    if(check)
      raceStatuses.at(i) = NO_RACE;
    else
      raceStatuses.at(i) = WAIT;

    // spdlog::debug("Race Status of {} is {}, its x is {}, its y is {} and its goal is {}, {}.", i, static_cast<int>(raceStatuses.at(i)), pedestrianSet.getPedCoords(i).x, pedestrianSet.getPedCoords(i).y, goals.getCurrentGoal(i).x, goals.getCurrentGoal(i).y);
    // spdlog::debug("Nearest Neighbour of {} is {}.",i,nearestNeighborIndex.at(i));
  }
  
}

bool CalmPedestrianModel::checkIfHighestPriority(const CalmPedestrianSet& pedestrianSet, const Goals& goals, VIPRA::idx index)
{
  float distErr = 0.2;
  for(VIPRA::idx i = 0; i < pedestrianSet.getNumPedestrians(); i++)
  {
    if(i == index)
      continue;
    
    if(!checkIfIntersect(pedestrianSet,index,i))
      continue;

    // spdlog::debug("For index: {}, pedestrian {} is considered", index, i);
    auto coords1 = pedestrianSet.getPedCoords(index);
    auto coords2 = pedestrianSet.getPedCoords(i);

    auto goal1 = goals.getCurrentGoal(index);
    auto goal2 = goals.getCurrentGoal(i);

    auto endgoal1 = goals.getEndGoal(index);
    auto endgoal2 = goals.getEndGoal(i);

    if(goal1 == goal2)
    {
      if(coords1.distanceTo(goal1)>coords2.distanceTo(goal2))
        return false;
      else if(coords1.distanceTo(goal1)==coords2.distanceTo(goal2))
      {
        if(index < i)
          return false;
      }
    }
    else if(lineIntersect(coords1,goal1,coords2,goal2))
    {
      auto goalIntersection = getGoalIntersection(pedestrianSet,goals,index,i);
      // spdlog::debug("The goal intersection with {} is x:{}, y:{}",i,goalIntersection.x,goalIntersection.y);
      if(coords1.distanceTo(goalIntersection) > coords2.distanceTo(goalIntersection))
        return false;
      else if(coords1.distanceTo(goalIntersection) == coords2.distanceTo(goalIntersection))
      {
        if(index < i)
          return false;
      }
    }
    
    else if(shortestDistanceToLineSegment(goal1, coords2, goal2) <= distErr)
    {
      if(coords1.distanceTo(goal1) + coords1.distanceTo(endgoal1) > coords2.distanceTo(goal1) + coords2.distanceTo(endgoal2))
        return false;
      else if(coords1.distanceTo(goal1) + coords1.distanceTo(endgoal1) == coords2.distanceTo(goal1) + coords2.distanceTo(endgoal2))
      {
        if(index < i)
          return false;
      }
    }
    else if(shortestDistanceToLineSegment(goal2, coords1, goal1) <= distErr)
    {
      if(coords1.distanceTo(goal2) + coords1.distanceTo(endgoal1)> coords2.distanceTo(goal2) + coords2.distanceTo(endgoal2))
        return false;
      else if(coords1.distanceTo(goal2) + coords1.distanceTo(endgoal1) == coords2.distanceTo(goal2) + coords2.distanceTo(endgoal2))
      {
        if(index < i)
          return false;
      }
    }
    else
    {
      if(goal1.distanceTo(goals.getEndGoal(index)) > goal2.distanceTo(goals.getEndGoal(i)))
        return false;
      else if(goal1.distanceTo(goals.getEndGoal(index)) == goal2.distanceTo(goals.getEndGoal(i)))
      {
        if(index < i)
          return false;
      }
    }

    // if(abs(coords1.x - coords2.x) < xDistanceError)
    // {
    //   if(abs(coords1.y - aisle) > abs(coords2.y - aisle))
    //     return false;
    //   else if(abs(coords1.y - aisle) == abs(coords2.y - aisle))
    //   {
    //     if(index < i)
    //       return false;
    //   }
    //   else
    //     continue;
    // }
    // else
    // {
    //   if(coords1.x < coords2.x)
    //     return false;
    //   else
    //     continue;
    // }
  }
  return true;
}

std::shared_ptr<VIPRA::State>
CalmPedestrianModel::timestep(const PedestrianSet& pedestrianSet,
                              const ObstacleSet&   obstacleSet,
                              const Goals&         goals,
                              VIPRA::delta_t       time,
                              VIPRA::t_step        timestep) {

  calculateNeartestNeighbors(static_cast<const CalmPedestrianSet&>(pedestrianSet), obstacleSet, goals);
  calculateBetas(static_cast<const CalmPedestrianSet&>(pedestrianSet));
  calculatePropulsion(static_cast<const CalmPedestrianSet&>(pedestrianSet), static_cast<const CalmGoals&>(goals));
  updateModelState(
      static_cast<const CalmPedestrianSet&>(pedestrianSet), static_cast<const CalmGoals&>(goals), time, timestep);

  // ---------------- Writing Debug Output ----------------
  #ifdef DEBUG_OUTPUT
    if(timestep % 100 == 0)
    {
      spdlog::debug("Writing Speed Densities");
      VIPRA::f3d speedDensity = calculateSpeedDensity(static_cast<const CalmPedestrianSet&>(pedestrianSet));
      std::ofstream output("speedDensity.csv", std::ios_base::app);
      if(output.is_open()) {
        output << speedDensity.x << ", " << speedDensity.y << "\n";
      }
      output.close();
    }
  #endif

  raceDetection(static_cast<const CalmPedestrianSet&>(pedestrianSet), goals);

  return modelState;
}




VIPRA::f3d 
CalmPedestrianModel::calculateSpeedDensity(const PedestrianSet& pedestrianSet) {
  const CalmPedestrianSet& pedSet = static_cast<const CalmPedestrianSet&>(pedestrianSet);
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  //x less than 24.51 and greater than 20.51
  //y greater than 1.6 and less than 2

  const auto& coords = pedSet.getPedestrianCoordinates();
  const auto& velocities = pedSet.getVelocities();
  VIPRA::f3dVec dVelocities = VIPRA::f3dVec();
  float area = 1.6;
  int Nt = 0;

  for(VIPRA::idx i = 0; i < pedCnt; ++i) {
      if(coords.at(i).x < 24.51 && coords.at(i).x > 20.51 &&
          coords.at(i).y < 2 && coords.at(i).y > 1.6) {
            dVelocities.push_back(velocities.at(i));
            Nt++;
      }
  }

  VIPRA::f3d meanVelocity = VIPRA::f3d();
  for(size_t i = 0; i < dVelocities.size(); i++) {
    meanVelocity.x += dVelocities.at(i).x;
    meanVelocity.y += dVelocities.at(i).y;
  }
  if(dVelocities.size() == 0) {
    meanVelocity.x = 0;
    meanVelocity.y = 0;
  } else {
    meanVelocity.x /= dVelocities.size();
    meanVelocity.y /= dVelocities.size();
  }


  float density = Nt / area;
  spdlog::debug("Mean Velocity: {}, Density: {}", meanVelocity.magnitude(), density);


  return VIPRA::f3d{density, meanVelocity.magnitude(), 0};


}

/**
 * @brief Updates nearestNeighbors with the nearest pedestrian in front of the pedestrian
 * 
 * @param pedSet 
 */
void
CalmPedestrianModel::calculateNeartestNeighbors(const CalmPedestrianSet& pedSet,
                                                const ObstacleSet&       obsSet,
                                                const Goals&             goals) noexcept {

  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       coords = pedSet.getPedestrianCoordinates();
  const auto&       velocities = pedSet.getVelocities();
  const auto&       shoulderLengths = pedSet.getShoulderLengths();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {

    if (goals.isPedestianGoalMet(i))
      continue;

    const auto pedCoords = coords.at(i);
    const auto velocity = velocities.at(i);

    float      nearestDist = std::numeric_limits<float>::max();
    VIPRA::idx index = 0;

    for (VIPRA::idx j = 0; j < pedCnt; ++j) {
      if (i == j || goals.isPedestianGoalMet(j))
        continue;

      const auto secondCoords = coords.at(j);
      if (!isPedInFront(pedCoords, velocity, shoulderLengths.at(i), secondCoords, velocities.at(j), shoulderLengths.at(j)))
        continue;

      if (!isPedInDirectionOfGoal(goals.getCurrentGoal(i), pedCoords, secondCoords))
        continue;

      float dist = pedCoords.distanceTo(secondCoords);
      if (dist < nearestDist) {
        nearestDist = dist;
        index = j;
      }
    }

    // float obsDist = checkBlockedPath(coords.at(i), velocities.at(i), shoulderLengths.at(i), nearestDist, obsSet);
    // if (obsDist != -1 && obsDist < nearestDist) {
    //   nearestDist = obsDist;
    // }

    nearestNeighborIndex[i] = index;
    nearestNeighbors[i] = nearestDist;
  }
}

bool
CalmPedestrianModel::isPedInDirectionOfGoal(const VIPRA::f3d& goalCoords,
                                            const VIPRA::f3d& pedCoords,
                                            const VIPRA::f3d& secondCoords) const noexcept {

  const VIPRA::f3d& pedDirection = goalCoords - pedCoords;
  const VIPRA::f3d& secondDirection = secondCoords - pedCoords;

  const float dotProduct =
      (pedDirection.x * secondDirection.x) + (pedDirection.y * secondDirection.y) + (pedDirection.z * secondDirection.z);

  return dotProduct > 0;
}

bool
CalmPedestrianModel::isPedInFront(const VIPRA::f3d& pedCoords,
                                  const VIPRA::f3d& pedVel,
                                  const float       shoulderLen,
                                  const VIPRA::f3d& secondCoords,
                                  const VIPRA::f3d& secondVel,
                                  const float       secondShoulderLen) const noexcept {
  // if (!objectDirectionTest(pedCoords, pedVel, secondCoords))
  //   return false;

  // const Line secondPedShoulders = getShoulderPoints(secondCoords, secondVel, secondShoulderLen);
  // if (!objectSpatialTest(pedCoords, pedVel, shoulderLen, secondPedShoulders.p1, secondPedShoulders.p2))
  //   return false;

  return true;
}

/**
 * @brief returns true if pedestrian at secondIdx is infront of firstIdx, infront being in a 180 degree field in the direction of firstIdx's velocity
 * 
 * @param pedSet 
 * @param firstIdx 
 * @param secondIdx 
 */
bool
CalmPedestrianModel::objectDirectionTest(const VIPRA::f3d& pedCoords,
                                         const VIPRA::f3d& pedVelocity,
                                         const VIPRA::f3d& objCoords) const noexcept {
  const VIPRA::f3d displacement = objCoords - pedCoords;

  const float dotProduct =
      (pedVelocity.x * displacement.x) + (pedVelocity.y * displacement.y) + (pedVelocity.z * displacement.z);

  return dotProduct > 0;
}

/**
 * @brief Checks if two pedestrians can pass each other, by checking their shoulder widths
 * 
 * @param pedSet 
 * @param firstPedIdx 
 * @param secondPedIdx 
 * @param firstShoulderLength
 */
bool
CalmPedestrianModel::objectSpatialTest(const VIPRA::f3d& pedCoords,
                                       const VIPRA::f3d& pedVelocity,
                                       float             pedShoulderLength,
                                       const VIPRA::f3d& objLeft,
                                       const VIPRA::f3d& objRight) const noexcept {

  // Creates a rectangle from the first pedestrians position, shoulders, and velocity
  // then checks if the second pedestrian intersects it

  const Line       shoulders = getShoulderPoints(pedCoords, pedVelocity, pedShoulderLength);
  const VIPRA::f3d range = (pedVelocity.unit() * 4);

  const Rect pedCollisionRect = {shoulders.p1, shoulders.p1 + range, shoulders.p2 + range, shoulders.p2};

  if (pedCollisionRect.p1 == pedCollisionRect.p2) {
    return false;
  }

  return isPointInRect(pedCollisionRect, objLeft) || isPointInRect(pedCollisionRect, objRight);
}

float
CalmPedestrianModel::checkBlockedPath(const VIPRA::f3d&  coords,
                                      const VIPRA::f3d&  velocity,
                                      float              shoulderWidth,
                                      float              checkDistance,
                                      const ObstacleSet& obsSet) const noexcept {

  const Line shoulders = getShoulderPoints(coords, velocity, shoulderWidth);
  if (shoulders.p1 == shoulders.p2) {
    return -1;
  }

  const float leftDist = obsSet.rayHit(shoulders.p1, shoulders.p1 + (velocity.unit() * checkDistance));
  const float rightDist = obsSet.rayHit(shoulders.p2, shoulders.p2 + (velocity.unit() * checkDistance));
  if (leftDist == -1) {
    return rightDist;
  }
  if (rightDist == -1) {
    return leftDist;
  }
  return std::min(leftDist, rightDist);
}

void
CalmPedestrianModel::calculateBetas(const CalmPedestrianSet& pedSet) noexcept {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    betas[i] = calculateBeta(nearestNeighbors[i]);
  }
}

inline float
CalmPedestrianModel::calculateBeta(float distance) const noexcept {
  constexpr float a = -2.11;
  constexpr float b = 0.366;
  constexpr float c = 0.966;

  return (c - std::exp(a * (distance - b)));
}

/**
 * @brief Calculates pedestrian Propulsion force and Updates propulsionForces
 * 
 * @param pedestrianSet
 * @param goals
 */
void
CalmPedestrianModel::calculatePropulsion(const CalmPedestrianSet& pedestrianSet, const CalmGoals& goals) noexcept {
  const auto& currentGoals = goals.getAllCurrentGoals();
  const auto& velocities = pedestrianSet.getVelocities();
  const auto& desiredSpeeds = pedestrianSet.getDesiredSpeeds();
  const auto& coords = pedestrianSet.getPedestrianCoordinates();
  const auto& masses = pedestrianSet.getMasses();
  const auto& reactionTimes = pedestrianSet.getReactionTimes();

  for (VIPRA::idx i = 0; i < pedestrianSet.getNumPedestrians(); ++i) {
    
    if (goals.isPedestianGoalMet(i)) {
      propulsionForces.at(i) = VIPRA::f3d{0, 0, 0};
      continue;
    }

    const VIPRA::f3d& velocity = velocities[i];
    const VIPRA::f3d& goal = currentGoals[i];
    const VIPRA::f3d& coord = coords[i];
    const float       desiredSpeed = desiredSpeeds[i];
    const float       mass = masses[i];
    const float       reactionTime = reactionTimes[i];
    float             beta = betas[i];

    const VIPRA::f3d direction = goal - coord;
    VIPRA::f3d desiredVelocity;
    desiredVelocity = direction.unit() * desiredSpeed * beta;
    propulsionForces.at(i) = ((desiredVelocity - velocity) * mass) / reactionTime;
  }
}

void
CalmPedestrianModel::updateModelState(const CalmPedestrianSet& pedSet,
                                      const CalmGoals&         goals,
                                      VIPRA::delta_t           time,
                                      VIPRA::t_step            timestep) noexcept {

  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       coords = pedSet.getPedestrianCoordinates();
  const auto&       velocities = pedSet.getVelocities();
  const auto&       masses = pedSet.getMasses();
  const auto&       desiredSpeeds = pedSet.getDesiredSpeeds();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {

    if (raceStatuses[i] == WAIT)
    {
      modelState->velocities[i] = VIPRA::f3d{0,0,0};
      continue;
    }

    const auto& pedCoord = coords.at(i);
    const auto& propulsion = propulsionForces.at(i);
    const auto& velocity = velocities.at(i);
    const float mass = masses.at(i);
    const float desiredSpeed = desiredSpeeds.at(i);

    //Use Euler Method to update position and velocity
    modelState->velocities[i] = ((propulsion / mass) * time) + velocity;

    if (goals.timeSinceLastGoal(i) > 0 && goals.timeSinceLastGoal(i) <= 0.1) {
      this->modelState->velocities[i].x = 0;
      this->modelState->velocities[i].y = 0;
    }

    modelState->pedestrianCoordinates[i] = pedCoord + (modelState->velocities[i] * time);

    modelState->affector[i] = VIPRA::Affector::PED_MODEL;
  }
}

// CalmPedestrianModel::~CalmPedestrianModel() {
//   delete[] pedestrianDistanceMatrix;
// }

/**
 * @brief returns true if the line intersects any of the sides of rect, also checks if it intersects the rect's internal diagonal
 * @note requires rect points to go clockwise from points 1-4
 * 
 * @param rect 
 * @param line 
 */
bool
CalmPedestrianModel::isPointInRect(const Rect& rect, const VIPRA::f3d& p1) const noexcept {
  if (p1 == rect.p1 || p1 == rect.p2 || p1 == rect.p3 || p1 == rect.p4)
    return true;

  if (lineIntersect(rect.p1, p1, rect.p2, rect.p3))
    return false;
  if (lineIntersect(rect.p1, p1, rect.p3, rect.p4))
    return false;

  if (lineIntersect(rect.p2, p1, rect.p3, rect.p4))
    return false;
  if (lineIntersect(rect.p2, p1, rect.p4, rect.p1))
    return false;

  if (lineIntersect(rect.p3, p1, rect.p4, rect.p1))
    return false;
  if (lineIntersect(rect.p3, p1, rect.p1, rect.p2))
    return false;

  if (lineIntersect(rect.p4, p1, rect.p1, rect.p2))
    return false;
  if (lineIntersect(rect.p4, p1, rect.p2, rect.p3))
    return false;

  return true;
}

/**
 * @brief returns true if the two lines intersect
 * 
 * @param start1 
 * @param end1 
 * @param line 
 */
bool
CalmPedestrianModel::lineIntersect(const VIPRA::f3d& start1,
                                   const VIPRA::f3d& end1,
                                   const VIPRA::f3d& start2,
                                   const VIPRA::f3d& end2) const noexcept {

  if (start1 == end1 || start2 == end2) {
    return false;
  }

  const float det = (end1.x - start1.x) * (end2.y - start2.y) - (end2.x - start2.x) * (end1.y - start1.y);
  if (det == 0) {
    
    if(start1.distanceTo(start2)+end1.distanceTo(start2)==start1.distanceTo(end1) || abs(start1.distanceTo(end2)+end1.distanceTo(end2))==start1.distanceTo(end1))
      return true;

    return false;
  } else {
    const float lambda = ((end2.y - start2.y) * (end2.x - start1.x) + (start2.x - end2.x) * (end2.y - start1.y)) / det;
    const float gamma = ((start1.y - end1.y) * (end2.x - start1.x) + (end1.x - start1.x) * (end2.y - start1.y)) / det;
    return (0 < lambda && lambda < 1) && (0 < gamma && gamma < 1);
  }
}

/**
 * @brief Get the Shoulder Points from a pedestrians position, velocity and shoulder width
 * 
 * @param coords 
 * @param velocity 
 * @param shoulderWidth 
 */
Line
CalmPedestrianModel::getShoulderPoints(const VIPRA::f3d& coords,
                                       const VIPRA::f3d& velocity,
                                       float             shoulderWidth) const noexcept {
  if (velocity == VIPRA::f3d{0, 0, 0}) {
    return {(VIPRA::f3d{0, shoulderWidth}), (VIPRA::f3d{0, -shoulderWidth})};
  }
  return {(VIPRA::f3d{-velocity.y, velocity.x}.unit() * shoulderWidth) + coords,
          (VIPRA::f3d{velocity.y, -velocity.x}.unit() * shoulderWidth) + coords};
}