
#include <array>
#include <cmath>
#include <limits>

#include "calm_pedestrian_model.hpp"
#include "definitions/type_definitions.hpp"

std::shared_ptr<VIPRA::State> CalmPedestrianModel::timestep(
    const PedestrianSet& pedestrianSet, const ObstacleSet& obstacleSet,
    const Goals& goals, VIPRA::delta_t time, VIPRA::t_step timestep) {
  const auto& pedSet = dynamic_cast<const CalmPedestrianSet&>(pedestrianSet);
  const auto& cGoals = dynamic_cast<const CalmGoals&>(goals);

  calculateNeartestNeighbors(pedSet, obstacleSet, goals);
  calculateBetas(pedSet);
  calculatePropulsion(pedSet, cGoals);
  updateModelState(pedSet, cGoals, time, timestep);

  // TODO(rolland) : re-enable collision detection
  // collision.raceDetection(dynamic_cast<const CalmPedestrianSet&>(pedestrianSet), goals,
  //                         timestep);

  return modelState;
}

/**
 * @brief Updates nearestNeighbors with the nearest pedestrian in front of the
 * pedestrian
 *
 * @param pedSet
 */
void CalmPedestrianModel::calculateNeartestNeighbors(const CalmPedestrianSet& pedSet,
                                                     const ObstacleSet&,
                                                     const Goals& goals) {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       coords = pedSet.getPedestrianCoordinates();
  const auto&       shldrs = pedSet.getShoulderLengths();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    if (goals.isPedestianGoalMet(i)) continue;

    VIPRA::pcoord pedCoords = coords.at(i);
    VIPRA::goal   pedGoal = goals.getCurrentGoal(i);
    Rect          pedRect = makeRectFromShldrs(pedCoords, pedGoal, shldrs.at(i));

    VIPRA::dist nearestDist = std::numeric_limits<VIPRA::dist>::max();

    for (VIPRA::idx j = 0; j < pedCnt; ++j) {
      if (i == j || goals.isPedestianGoalMet(j)) continue;

      auto        otherCoords = coords.at(j);
      VIPRA::dist distance = pedCoords.distanceTo(otherCoords);

      if (distance >= nearestDist) continue;

      Line otherShldrs =
          getShoulderPoints(otherCoords, goals.getCurrentGoal(j), shldrs.at(j));

      if (!isPedInDirectionOfGoal(pedCoords, pedGoal, otherCoords)) continue;

      if (!objectSpatialTest(pedRect, otherShldrs.p1, otherShldrs.p2)) continue;

      nearestDist = distance;
    }

    nearestNeighborDists.at(i) = nearestDist;
  }
}

void CalmPedestrianModel::calculateBetas(const CalmPedestrianSet& pedSet) {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    betas[i] = calculateBeta(nearestNeighborDists[i]);
  }
}

/**
 * @brief Calculates pedestrian Propulsion force and Updates propulsionForces
 *
 * @param pedestrianSet
 * @param goals
 */
void CalmPedestrianModel::calculatePropulsion(const CalmPedestrianSet& pedestrianSet,
                                              const CalmGoals&         goals) {
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
    VIPRA::f3d       desiredVelocity;
    desiredVelocity = direction.unit() * desiredSpeed * beta;
    propulsionForces.at(i) = ((desiredVelocity - velocity) * mass) / reactionTime;
  }
}

void CalmPedestrianModel::updateModelState(const CalmPedestrianSet& pedSet,
                                           const CalmGoals& goals, VIPRA::delta_t time,
                                           VIPRA::t_step) {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       coords = pedSet.getPedestrianCoordinates();
  const auto&       velocities = pedSet.getVelocities();
  const auto&       masses = pedSet.getMasses();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    if (collision.status(i) == WAIT) {
      modelState->velocities[i] = VIPRA::f3d{};
      continue;
    }

    const auto& pedCoord = coords.at(i);
    const auto& propulsion = propulsionForces.at(i);
    const auto& velocity = velocities.at(i);
    const float mass = masses.at(i);

    // Use Euler Method to update position and velocity
    modelState->velocities[i] = ((propulsion / mass) * time) + velocity;

    // TODO(rolland) : I believe Dr.Srinivasan said we shouldn't have to do this? It sets velocity to zero when a pedestrian reaches a goal to prevent sliding
    if (goals.timeSinceLastGoal(i) > 0 && goals.timeSinceLastGoal(i) <= slidingGoalTime) {
      this->modelState->velocities[i].x = 0;
      this->modelState->velocities[i].y = 0;
    }

    modelState->pedestrianCoordinates[i] = pedCoord + (modelState->velocities[i] * time);

    modelState->affector[i] = VIPRA::Affector::PED_MODEL;
  }
}

// --------------------------------------------- HELPER METHODS ----------------------------------------------------------------

bool CalmPedestrianModel::isPedInDirectionOfGoal(VIPRA::pcoord pedCoords,
                                                 VIPRA::goal goal, VIPRA::pcoord other) {
  VIPRA::f3d pedDirection = goal - pedCoords;
  VIPRA::f3d secondDirection = other - pedCoords;

  const float dotProduct = (pedDirection.x * secondDirection.x) +
                           (pedDirection.y * secondDirection.y) +
                           (pedDirection.z * secondDirection.z);

  return dotProduct > 0;
}

/**
 * @brief returns true if pedestrian at secondIdx is infront of firstIdx,
 * infront being in a 180 degree field in the direction of firstIdx's velocity
 *
 * @param pedSet
 * @param firstIdx
 * @param secondIdx
 */
bool CalmPedestrianModel::objectDirectionTest(VIPRA::pcoord pedCoords,
                                              VIPRA::veloc  pedVelocity,
                                              VIPRA::f3d    objCoords) {
  const VIPRA::f3d displacement = objCoords - pedCoords;

  const float dotProduct = (pedVelocity.x * displacement.x) +
                           (pedVelocity.y * displacement.y) +
                           (pedVelocity.z * displacement.z);

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
bool CalmPedestrianModel::objectSpatialTest(const Rect& collisionRect, VIPRA::f3d objLeft,
                                            VIPRA::f3d objRight) {
  if (collisionRect.p1 == collisionRect.p2) {
    return false;
  }

  VIPRA::f3d center = (objLeft + objRight) /= 2;

  return collisionRect.isPointInRect(objLeft) || collisionRect.isPointInRect(center) ||
         collisionRect.isPointInRect(objRight);
}

/**
 * @brief Checks if there is an obstacle in the way of the pedestrian, returns the
 * distance to the obstacle if there is
 *
 * @param coords :
 * @param velocity :
 * @param shldrWid :
 * @param checkDistance :
 * @param obsSet :
 * @return float
 */
float CalmPedestrianModel::checkBlockedPath(VIPRA::pcoord coords, VIPRA::veloc velocity,
                                            float shldrWid, VIPRA::dist maxDist,
                                            const ObstacleSet& obsSet) {
  const Line shoulders = getShoulderPoints(coords, velocity, shldrWid);
  if (shoulders.p1 == shoulders.p2) {
    return -1;
  }

  const float leftDist =
      obsSet.rayHit(shoulders.p1, shoulders.p1 + (velocity.unit() * maxDist));
  const float rightDist =
      obsSet.rayHit(shoulders.p2, shoulders.p2 + (velocity.unit() * maxDist));
  if (leftDist == -1) {
    return rightDist;
  }
  if (rightDist == -1) {
    return leftDist;
  }
  return std::min(leftDist, rightDist);
}

/**
 * @brief Calculates beta from a given distance
 * 
 * @param distance : 
 * @return float 
 */
inline float CalmPedestrianModel::calculateBeta(VIPRA::dist distance) {
  constexpr float valA = -2.11;
  constexpr float valB = 0.366;
  constexpr float valC = 0.966;
  return (valC - std::exp(valA * (distance - valB)));
}

/**
 * @brief Get the Shoulder Points for a pedestrian
 * @note All pedestrians face their current goal
 * @param coords
 * @param velocity
 * @param shldrWid
 */
Line CalmPedestrianModel::getShoulderPoints(VIPRA::pcoord coords, VIPRA::goal goal,
                                            float shldrWid) {
  VIPRA::f3d direction = (goal -= coords).unit();

  return {(VIPRA::f3d{-direction.y, direction.x}.unit() * shldrWid) + coords,
          (VIPRA::f3d{direction.y, -direction.x}.unit() * shldrWid) + coords};
}

Rect CalmPedestrianModel::makeRectFromShldrs(VIPRA::pcoord pedCoords, VIPRA::goal goal,
                                             float shldrWid) {
  const Line       pedShldr = getShoulderPoints(pedCoords, goal, shldrWid);
  const VIPRA::f3d range = (goal - pedCoords).unit();

  return Rect{pedShldr.p1, pedShldr.p1 + range, pedShldr.p2 + range, pedShldr.p2};
}

// NOLINTBEGIN : (rolland) - Debug output, so formatting isn't as important    :  ignoring(all)
VIPRA::f3d CalmPedestrianModel::calculateSpeedDensity(
    const PedestrianSet& pedestrianSet) {
  const auto&       pedSet = dynamic_cast<const CalmPedestrianSet&>(pedestrianSet);
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  // x less than 24.51 and greater than 20.51
  // y greater than 1.6 and less than 2

  const auto&   coords = pedSet.getPedestrianCoordinates();
  const auto&   velocities = pedSet.getVelocities();
  VIPRA::f3dVec dVelocities = VIPRA::f3dVec();
  float         area = 1.6;
  int           nt = 0;

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    if (coords.at(i).x < 24.51 && coords.at(i).x > 20.51 && coords.at(i).y < 2 &&
        coords.at(i).y > 1.6) {
      dVelocities.push_back(velocities.at(i));
      nt++;
    }
  }

  VIPRA::f3d meanVelocity = VIPRA::f3d();
  for (auto& dVelocitie : dVelocities) {
    meanVelocity.x += dVelocitie.x;
    meanVelocity.y += dVelocitie.y;
  }

  if (dVelocities.empty()) {
    meanVelocity.x = 0;
    meanVelocity.y = 0;
  } else {
    meanVelocity.x /= dVelocities.size();
    meanVelocity.y /= dVelocities.size();
  }

  float density = nt / area;
  spdlog::debug("Mean Velocity: {}, Density: {}", meanVelocity.magnitude(), density);

  return VIPRA::f3d{density, meanVelocity.magnitude(), 0};
}
// NOLINTEND

void CalmPedestrianModel::configure(const VIPRA::CONFIG::Map&) {}

void CalmPedestrianModel::initialize(const PedestrianSet& pedestrianSet,
                                     const ObstacleSet&, const Goals&) {
  propulsionForces =
      VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0F, 0.0F});
  modelState = std::make_shared<VIPRA::State>(pedestrianSet.getNumPedestrians());
  nearestNeighborDists = std::vector<VIPRA::dist>(pedestrianSet.getNumPedestrians());
  betas = std::vector<float>(pedestrianSet.getNumPedestrians());
  collision.initialize(pedestrianSet);
}