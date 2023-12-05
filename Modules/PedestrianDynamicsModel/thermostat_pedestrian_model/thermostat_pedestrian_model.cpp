
#include <array>
#include <cmath>
#include <limits>
#include <memory>

#include "thermostat_pedestrian_model.hpp"
#include "definitions/dimensions.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

#include <distributions/distributions.hpp>

void ThermostatPedestrianModel::timestep(const VIPRA::PedestrianSet& pedSet,
                                   const VIPRA::ObstacleSet&   obstacleSet,
                                   const VIPRA::Goals& goals, VIPRA::State& state,
                                   VIPRA::delta_t time, VIPRA::t_step timestep) {
  calculateShoulders(pedSet, goals);
  calculateNeartestNeighbors(pedSet, obstacleSet, goals);
  calculateBetas(pedSet);
  calculatePropulsion(pedSet, goals);
  updateModelState(pedSet, obstacleSet, goals, state, time, timestep);

  if (timestep > 0) {
    collision.raceDetection(pedSet, peds, goals, timestep, obstacleSet);
    collision.assignRaceStatuses(raceStatuses, inRace);
  }
}

/**
 * @brief Updates nearestNeighbors with the nearest pedestrian in front of the
 * pedestrian
 *
 * @param pedSet
 */
void ThermostatPedestrianModel::calculateNeartestNeighbors(const VIPRA::PedestrianSet& pedSet,
                                                     const VIPRA::ObstacleSet&,
                                                     const VIPRA::Goals& goals) {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       coords = pedSet.getCoordinates();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    if (goals.isPedestianGoalMet(i)) continue;

    VIPRA::pcoord pedCoords = coords.at(i);
    VIPRA::goal   pedGoal = goals.getCurrentGoal(i);
    Rect          pedRect = makeRectFromShldrs(i, pedCoords, pedGoal);

    VIPRA::dist nearestDist = std::numeric_limits<VIPRA::dist>::max();
    for (VIPRA::idx j = 0; j < pedCnt; ++j) {
      if (i == j || goals.isPedestianGoalMet(j)) continue;

      auto        otherCoords = coords.at(j);
      VIPRA::dist distance = pedCoords.distanceTo(otherCoords);

      if (distance >= nearestDist) continue;

      if ((raceStatuses.at(i) == 0 && raceStatuses.at(j) == 1) ||
          std::fabs(distance - equilibriumDistance) < equilibriumResolution)
        continue;

      if (!isPedInDirectionOfGoal(pedCoords, pedGoal, otherCoords)) continue;

      if (!objectSpatialTest(pedRect, pedShoulders.at(j).p1, pedShoulders.at(j).p2))
        continue;

      nearestDist = distance;
    }
    peds.nearestNeighborDists.at(i) = nearestDist;
  }
}

void ThermostatPedestrianModel::calculateBetas(const VIPRA::PedestrianSet& pedSet) {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    peds.betas[i] = calculateBeta(peds.nearestNeighborDists[i]);
  }
}

/**
 * @brief Calculates pedestrian Propulsion force and Updates propulsionForces
 *
 * @param pedSet
 * @param goals
 */
void ThermostatPedestrianModel::calculatePropulsion(const VIPRA::PedestrianSet& pedSet,
                                              const VIPRA::Goals&         goals) {
  const auto& currentGoals = goals.getAllCurrentGoals();
  const auto& velocities = pedSet.getVelocities();
  const auto& coords = pedSet.getCoordinates();

  for (VIPRA::idx i = 0; i < pedSet.getNumPedestrians(); ++i) {
    if (goals.isPedestianGoalMet(i)) {
      peds.propulsionForces.at(i) = VIPRA::f3d{0, 0, 0};
      continue;
    }

    const VIPRA::f3d& velocity = velocities[i];
    const VIPRA::f3d& goal = currentGoals[i];
    const VIPRA::f3d& coord = coords[i];
    const float       desiredSpeed = peds.desiredSpeeds[i];
    const float       mass = peds.masses[i];
    const float       reactionTime = peds.reactionTimes[i];
    float             beta = peds.betas[i];

    const VIPRA::f3d direction = goal - coord;
    VIPRA::f3d       desiredVelocity;
    desiredVelocity = direction.unit() * desiredSpeed * beta;
    peds.propulsionForces.at(i) = ((desiredVelocity - velocity) * mass) / reactionTime;
  }
}

void ThermostatPedestrianModel::updateModelState(const VIPRA::PedestrianSet& pedSet,
                                           const VIPRA::ObstacleSet& obsSet,
                                           const VIPRA::Goals& goals, VIPRA::State& state,
                                           VIPRA::delta_t time, VIPRA::t_step) {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       coords = pedSet.getCoordinates();
  const auto&       velocities = pedSet.getVelocities();
  // const auto&       masses = pedSet.getMasses();
  // const auto&       currentGoals = goals.getAllCurrentGoals();

  std::vector<float> rands = VIPRA::makeDistribution<VIPRA::normal_distribution<>>(pedCnt, 0, 10, rand);

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    if (collision.status(i) == WAIT) {
      state.velocities[i] = VIPRA::f3d{};
      continue;
    }

    const auto& pedCoord = coords.at(i);
    const auto& propulsion = peds.propulsionForces.at(i);
    const auto& velocity = velocities.at(i);
    const float mass = peds.masses.at(i);

    const VIPRA::f3d randomVelocity = thermostat(i, pedCoord, velocity, rands, obsSet, goals);

    // Use Euler Method to update position and velocity
    state.velocities[i] = ((propulsion / mass) * time) + randomVelocity;

    // TODO(rolland) : I believe Dr.Srinivasan said we shouldn't have to do this? It sets velocity to zero when a pedestrian reaches a goal to prevent sliding
    if (goals.timeSinceLastGoal(i) > 0 && goals.timeSinceLastGoal(i) <= slidingGoalTime) {
      state.velocities[i].x = 0;
      state.velocities[i].y = 0;
    }

    state.coords[i] = pedCoord + (state.velocities[i] * time);
  }
}

/**
 *  @brief Returns randomized velocity based on distance to obstacle
 * 
 * @param pedID
 * @param pedCoord
 * @param pedVel
 * @param rands
 * @param obsSet
 * @param goals
*/
VIPRA::f3d ThermostatPedestrianModel::thermostat(VIPRA::idx pedID, 
                                           VIPRA::f3d pedCoord,
                                           VIPRA::f3d pedVel,
                                           std::vector<float> rands,
                                           const VIPRA::ObstacleSet& obsSet,
                                           const VIPRA::Goals& goals) {

    auto goal1 = goals.getCurrentGoal(pedID);

    VIPRA::f3d newVel = pedVel * (rands[pedID] / 100);

    VIPRA::f3d randVel = pedVel + newVel;

    VIPRA::f3d directionToGoal = goal1 - pedCoord;
    VIPRA::f3d nearestObs = obsSet.nearestObstacleInDirection(pedCoord, directionToGoal);

    VIPRA::f3d spedFormula4 = randVel*(1 - (0.02/nearestObs.distanceTo(pedCoord)));

    return spedFormula4;
}

// --------------------------------------------- HELPER METHODS ----------------------------------------------------------------

bool ThermostatPedestrianModel::isPedInDirectionOfGoal(VIPRA::pcoord pedCoords,
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
bool ThermostatPedestrianModel::objectDirectionTest(VIPRA::pcoord pedCoords,
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
bool ThermostatPedestrianModel::objectSpatialTest(const Rect& collisionRect, VIPRA::f3d objLeft,
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
float ThermostatPedestrianModel::checkBlockedPath(VIPRA::idx pedIdx, VIPRA::veloc velocity,
                                            VIPRA::dist               maxDist,
                                            const VIPRA::ObstacleSet& obsSet) {
  Line& shoulders = pedShoulders.at(pedIdx);
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
inline float ThermostatPedestrianModel::calculateBeta(VIPRA::dist distance) {
  constexpr float valA = -2.11;
  constexpr float valB = 0.366;
  constexpr float valC = 0.966;
  return (valC - std::exp(valA * (distance - valB)));
}

Rect ThermostatPedestrianModel::makeRectFromShldrs(VIPRA::idx pedIdx, VIPRA::pcoord pedCoords,
                                             VIPRA::goal goal) {
  const Line&      pedShldr = pedShoulders.at(pedIdx);
  const VIPRA::f3d range = (goal - pedCoords).unit();

  return Rect{pedShldr.p1, pedShldr.p1 + range, pedShldr.p2 + range, pedShldr.p2};
}

void ThermostatPedestrianModel::calculateShoulders(const VIPRA::PedestrianSet& pedSet,
                                             const VIPRA::Goals&         goals) {
  VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto& coords = pedSet.getCoordinates();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    VIPRA::f3d coord = coords.at(i);
    VIPRA::f3d direction = (goals.getCurrentGoal(i) - coord).unit();

    pedShoulders.at(i) = {
        (VIPRA::f3d{-direction.y, direction.x}.unit() * peds.shoulders.at(i)) + coord,
        (VIPRA::f3d{direction.y, -direction.x}.unit() * peds.shoulders.at(i)) + coord};
  }
}

// NOLINTBEGIN : (rolland) - Debug output, so formatting isn't as important    :  ignoring(all)
VIPRA::f3d ThermostatPedestrianModel::calculateSpeedDensity(
    const VIPRA::PedestrianSet& pedSet) {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  // x less than 24.51 and greater than 20.51
  // y greater than 1.6 and less than 2

  const auto&   coords = pedSet.getCoordinates();
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

void ThermostatPedestrianModel::configure(const VIPRA::Config& confMap) {
  rand.reseed(confMap["seed"].get<VIPRA::size>());
  config.meanMass = confMap["meanMass"].get<float>();
  config.massStdDev = confMap["massStdDev"].get<float>();
  config.meanReactionTime = confMap["meanReactionTime"].get<float>();
  config.reactionTimeStdDev = confMap["reactionTimeStdDev"].get<float>();
  config.meanMaxSpeed = confMap["meanMaxSpeed"].get<float>();
  config.maxSpeedStdDev = confMap["maxSpeedStdDev"].get<float>();
  config.meanShoulderLen = confMap["meanShoulderLen"].get<float>();
  config.ShoulderLenStdDev = confMap["shoulderLenStdDev"].get<float>();
}

void ThermostatPedestrianModel::initialize(const VIPRA::PedestrianSet& pedSet,
                                     const VIPRA::ObstacleSet&,
                                     const VIPRA::Goals& goals) {
  setModelData(pedSet);
  collision.initialize(pedSet, goals, dynamic_cast<const ModelData&>(peds));
  collision.assignRaceStatuses(raceStatuses, inRace);
}

void ThermostatPedestrianModel::setModelData(const VIPRA::PedestrianSet& pedSet) {
  const auto pedCnt = pedSet.getNumPedestrians();
  peds.desiredSpeeds = VIPRA::makeDistribution<VIPRA::normal_distribution<>>(
      pedCnt, config.meanMaxSpeed, config.maxSpeedStdDev, rand);

  peds.reactionTimes = VIPRA::makeDistribution<VIPRA::normal_distribution<>>(
      pedCnt, config.meanReactionTime, config.reactionTimeStdDev, rand);

  peds.shoulders = VIPRA::makeDistribution<VIPRA::normal_distribution<>>(
      pedCnt, config.meanShoulderLen, config.ShoulderLenStdDev, rand);

  peds.masses = VIPRA::makeDistribution<VIPRA::normal_distribution<>>(
      pedCnt, config.meanMass, config.massStdDev, rand);

  peds.betas = std::vector<float>(pedCnt, 0);
  peds.nearestNeighborDists = std::vector<float>(pedCnt, 0);
  peds.propulsionForces = VIPRA::f3dVec(pedCnt, VIPRA::f3d{});

  pedShoulders = std::vector<Line>(pedCnt);
}