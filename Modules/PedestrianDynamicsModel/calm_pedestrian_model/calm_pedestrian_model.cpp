#include "calm_pedestrian_model.hpp"

CalmPedestrianModel::CalmPedestrianModel() {}

void
CalmPedestrianModel::configure([[maybe_unused]] const VIPRA::ConfigMap& configMap) {}

void
CalmPedestrianModel::initialize(const PedestrianSet&                pedestrianSet,
                                [[maybe_unused]] const ObstacleSet& obstacleSet,
                                [[maybe_unused]] const Goals&       goals) {
  pedestrianDistanceMatrix = new float[pedestrianSet.getNumPedestrians() * pedestrianSet.getNumPedestrians()];
  propulsionForces = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});
  modelState = std::make_shared<VIPRA::State>(pedestrianSet.getNumPedestrians());
  nearestNeighbors = std::vector<float>(pedestrianSet.getNumPedestrians());
  betas = std::vector<float>(pedestrianSet.getNumPedestrians());
}

std::shared_ptr<VIPRA::State>
CalmPedestrianModel::timestep(const PedestrianSet& pedestrianSet,
                              const ObstacleSet&   obstacleSet,
                              const Goals&         goals,
                              VIPRA::delta_t       timestep) {

  calculateNeartestNeighbors(static_cast<const CalmPedestrianSet&>(pedestrianSet), obstacleSet, goals);
  calculateBetas(static_cast<const CalmPedestrianSet&>(pedestrianSet));
  calculatePropulsion(static_cast<const CalmPedestrianSet&>(pedestrianSet), static_cast<const CalmGoals&>(goals));
  updateModelState(static_cast<const CalmPedestrianSet&>(pedestrianSet), timestep);
  return modelState;
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

    float nearestDist = std::numeric_limits<float>::max();

    for (VIPRA::idx j = 0; j < pedCnt; ++j) {
      if (i == j || goals.isPedestianGoalMet(j))
        continue;

      const auto secondCoords = coords.at(j);
      if (!isPedInFront(pedCoords, velocity, shoulderLengths.at(i), secondCoords, velocities.at(j), shoulderLengths.at(j)))
        continue;

      float dist = pedCoords.distanceTo(secondCoords);
      if (dist < nearestDist)
        nearestDist = dist;
    }

    // float obsDist = checkBlockedPath(coords.at(i), velocities.at(i), shoulderLengths.at(i), nearestDist, obsSet);
    // if (obsDist != -1 && obsDist < nearestDist) {
    //   nearestDist = obsDist;
    // }

    nearestNeighbors[i] = nearestDist;
  }
}

bool
CalmPedestrianModel::isPedInFront(const VIPRA::f3d& pedCoords,
                                  const VIPRA::f3d& pedVel,
                                  const float       shoulderLen,
                                  const VIPRA::f3d& secondCoords,
                                  const VIPRA::f3d& secondVel,
                                  const float       secondShoulderLen) const noexcept {
  if (!objectDirectionTest(pedCoords, pedVel, secondCoords))
    return false;

  const Line secondPedShoulders = getShoulderPoints(secondCoords, secondVel, secondShoulderLen);
  if (!objectSpatialTest(pedCoords, pedVel, shoulderLen, secondPedShoulders.p1, secondPedShoulders.p2))
    return false;

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

  return dotProduct >= 0;
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
  constexpr float a = -2.4532;
  constexpr float b = 0.138412;
  constexpr float c = 0.87436;

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

    const VIPRA::f3d direction = goal - coord;
    const VIPRA::f3d desiredVelocity = direction.unit() * desiredSpeed * betas[i];

    propulsionForces.at(i) = ((desiredVelocity - velocity) * mass) / reactionTime;
  }
}

void
CalmPedestrianModel::updateModelState(const CalmPedestrianSet& pedSet, VIPRA::delta_t time) noexcept {

  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       coords = pedSet.getPedestrianCoordinates();
  const auto&       velocities = pedSet.getVelocities();
  const auto&       masses = pedSet.getMasses();
  const auto&       desiredSpeeds = pedSet.getDesiredSpeeds();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {

    const auto& pedCoord = coords.at(i);
    const auto& propulsion = propulsionForces.at(i);
    const auto& velocity = velocities.at(i);
    const float mass = masses.at(i);
    const float desiredSpeed = desiredSpeeds.at(i);

    //Use Euler Method to update position and velocity
    modelState->velocities[i] = ((propulsion / mass) * time) + velocity;

    // if (checkBehind(pedSet, pedCoord, modelState->velocities[i])) {
    //   modelState->velocities[i] = VIPRA::f3d{0, 0, 0};
    // }

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

bool
CalmPedestrianModel::checkBehind(const PedestrianSet& pedSet, const VIPRA::f3d& pedCoords, const VIPRA::f3d& pedVelocity) {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       coords = pedSet.getPedestrianCoordinates();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    for (VIPRA::idx j = 0; j < pedCnt; ++j) {
      if (i == j)
        continue;

      if (isPedInFront(pedCoords, -pedVelocity, ))
    }
  }
  return false;
}
