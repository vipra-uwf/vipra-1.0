#include "calm_pedestrian_model.hpp"

CalmPedestrianModel::CalmPedestrianModel() {}

void
CalmPedestrianModel::initialize(const PedestrianSet& pedestrianSet,
                                const ObstacleSet&   obstacleSet,
                                const Goals&         goals) {
  pedestrianDistanceMatrix = new float[pedestrianSet.getNumPedestrians() * pedestrianSet.getNumPedestrians()];
  propulsionForces = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});
  modelState = std::make_shared<CalmState>(pedestrianSet.getNumPedestrians());
  nearestNeighbors = std::vector<VIPRA::idx>(pedestrianSet.getNumPedestrians());
}

std::shared_ptr<VIPRA::State>
CalmPedestrianModel::timestep(const PedestrianSet& pedestrianSet,
                              const ObstacleSet&   obstacleSet,
                              const Goals&         goals,
                              VIPRA::delta_t       timestep) {

  calculateDistanceMatrices(static_cast<const CalmPedestrianSet&>(pedestrianSet));
  calculateNeartestNeighbors(static_cast<const CalmPedestrianSet&>(pedestrianSet), goals);
  calculateDesiredSpeeds(static_cast<const CalmPedestrianSet&>(pedestrianSet),
                         static_cast<const CalmGoals&>(goals));
  calculatePropulsion(static_cast<const CalmPedestrianSet&>(pedestrianSet),
                      static_cast<const CalmGoals&>(goals));
  updateModelState(static_cast<const CalmPedestrianSet&>(pedestrianSet), timestep);
  checkForBlockedPaths(static_cast<const CalmPedestrianSet&>(pedestrianSet), obstacleSet);

  return modelState;
}

void
CalmPedestrianModel::updateModelState(const CalmPedestrianSet& pedestrianSet, VIPRA::delta_t time) {

  //Need some clarification on why we need this coeff... - NR
  float coeff = 0.01;

  VIPRA::f3dVec newVelocities = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});
  VIPRA::f3dVec newPositions = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});

  VIPRA::f3d newVelocity;
  VIPRA::f3d newPosition;
  float      newSpeed;

  VIPRA::size numPedestrians = pedestrianSet.getNumPedestrians();
  for (VIPRA::idx i = 0; i < numPedestrians; ++i) {

    float propulsiveX = propulsionForces.at(i).x;
    float propulsiveY = propulsionForces[i].y;
    float velocityX = pedestrianSet.getVelocities()[i].x;
    float velocityY = pedestrianSet.getVelocities()[i].y;
    float mass = pedestrianSet.getMasses()[i];
    float desiredSpeed = pedestrianSet.getDesiredSpeeds()[i];
    float coordinateX = pedestrianSet.getPedestrianCoordinates()[i].x;
    float coordinateY = pedestrianSet.getPedestrianCoordinates()[i].y;

    newVelocity =
        (VIPRA::f3d{(propulsiveX * (time / mass) + velocityX), (propulsiveY * (time / mass) + velocityY)});

    newSpeed = ((newVelocity.x * newVelocity.x) + (newVelocity.y * newVelocity.y));

    if (newSpeed < (desiredSpeed * desiredSpeed)) {
      newPosition =
          VIPRA::f3d{(coordinateX + (newVelocity.x * time)), (coordinateY + (newVelocity.y * time))};
    } else {
      newPosition = VIPRA::f3d{coordinateX + (newVelocity.x * (desiredSpeed / (newSpeed + coeff)) * time),
                               coordinateY + (newVelocity.y * (desiredSpeed / (newSpeed + coeff)) * time)};
    }

    modelState->velocities[i] = newVelocity;
    modelState->pedestrianCoordinates[i] = newPosition;
    modelState->affector[i] = VIPRA::Affector::PED_MODEL;
  }
}

/**
 * @brief Updates pedestrianDistanceMatrix with the coresponding distances between pedestrians
 * @todo TODO: Add Goals and ObstacleSet to Algorithm
 */
void
CalmPedestrianModel::calculateDistanceMatrices(const CalmPedestrianSet& pedestrianSet) {
  // Update the pedestrians since they could have been removed from the
  // simulation at this point. Also update the obstacles just in case they
  // can be removed in the future.
  VIPRA::size numPedestrians = pedestrianSet.getNumPedestrians();
  const auto& pedCoords = pedestrianSet.getPedestrianCoordinates();

  //Updates pedestrian-to-pedestrian distance matrix and pedestrian-to-object distance matrix
  for (VIPRA::idx i = 0; i < numPedestrians; ++i) {
    for (VIPRA::idx j = 0; j < i; ++j) {
      float distance = pedCoords.at(i).distanceTo(pedCoords.at(j));
      pedestrianDistanceMatrix[(i * numPedestrians) + j] = distance;
    }
  }
}

/**
 * @brief If a pedestrian has been moved inside of an obstacle, move them back to their original coordinates, set velocity to zero
 * @todo TODO needs to check for shoulders, currently only checks the position of the pedestrian
 * @param pedSet 
 * @param obsSet 
 */
void
CalmPedestrianModel::checkForBlockedPaths(const CalmPedestrianSet& pedSet, const ObstacleSet& obsSet) {

  const auto& pedCoords = pedSet.getPedestrianCoordinates();

  VIPRA::idx i = 0;
  std::for_each(modelState->pedestrianCoordinates.begin(),
                modelState->pedestrianCoordinates.end(),
                [&](VIPRA::f3d& pos) {
                  if (obsSet.collision(pos)) {
                    pos = pedCoords.at(i);
                    modelState->velocities[i] = VIPRA::f3d{0, 0, 0};
                  }
                  ++i;
                });
}

/**
 * @brief Updates nearestNeighbors with the nearest pedestrian in front of the pedestrian
 * 
 * @param pedSet 
 */
void
CalmPedestrianModel::calculateNeartestNeighbors(const CalmPedestrianSet& pedSet, const Goals& goals) {

  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       shoulderLengths = pedSet.getShoulderLengths();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    float      nearestDist = std::numeric_limits<float>::max();
    VIPRA::idx nearestIdx = VIPRA::idx_INVALID;

    for (VIPRA::idx j = 0; j < pedCnt; ++j) {
      if (i == j)
        continue;

      // if (goals.isPedestianGoalMet(i))
      //   continue;

      if (!neighborDirectionTest(pedSet, i, j))
        continue;

      if (!neighborSpacialTest(pedSet, i, j, shoulderLengths.at(i)))
        continue;

      float dist = getPedestrianDistance(pedSet, i, j);
      if (dist < nearestDist) {
        nearestDist = dist;
        nearestIdx = j;
      }
    }
    nearestNeighbors[i] = nearestIdx;
  }
}

/**
 * @brief returns true if pedestrian at secondIdx is infront of firstIdx, infront being in a 180 degree field in the direction of firstIdx's velocity
 * 
 * @param pedSet 
 * @param firstIdx 
 * @param secondIdx 
 */
inline bool
CalmPedestrianModel::neighborDirectionTest(const CalmPedestrianSet& pedSet,
                                           VIPRA::idx               firstIdx,
                                           VIPRA::idx               secondIdx)

{
  const auto& coords = pedSet.getPedestrianCoordinates();
  VIPRA::f3d  displacement = coords.at(firstIdx) - coords.at(secondIdx);
  VIPRA::f3d  direction = pedSet.getVelocities()[firstIdx];

  float result =
      (displacement.x * direction.x) + (displacement.y * direction.y) + (displacement.z * direction.z);

  return result <= 0;
}

/**
 * @brief Checks if two pedestrians can pass each other, by checking their shoulder widths
 * 
 * @param pedSet 
 * @param firstPedIdx 
 * @param secondPedIdx 
 * @param firstShoulderLength
 */
inline bool
CalmPedestrianModel::neighborSpacialTest(const CalmPedestrianSet& pedSet,
                                         VIPRA::idx               firstPedIdx,
                                         VIPRA::idx               secondPedIdx,
                                         float                    firstShoulderLength) {

  const auto&      velocities = pedSet.getVelocities();
  const VIPRA::f3d firstPedCoords = pedSet.getPedestrianCoordinates()[firstPedIdx];
  const VIPRA::f3d secondPedCoords = pedSet.getPedestrianCoordinates()[secondPedIdx];

  const VIPRA::f3d firstPedDirection = VIPRA::f3d{std::fabs(velocities[firstPedIdx].x),
                                                  std::fabs(velocities[firstPedIdx].y),
                                                  std::fabs(velocities[firstPedIdx].z)};

  const VIPRA::f3d secondPedDirection = VIPRA::f3d{std::fabs(velocities[secondPedIdx].x),
                                                   std::fabs(velocities[secondPedIdx].y),
                                                   std::fabs(velocities[secondPedIdx].z)};

  float secondShoulderLength = 0;

  if ((firstPedDirection.x > firstPedDirection.y && secondPedDirection.x > secondPedDirection.y) ||
      (firstPedDirection.y > firstPedDirection.x && secondPedDirection.y > secondPedDirection.x)) {
    secondShoulderLength = pedSet.getShoulderLengths().at(secondPedIdx);
  }

  float pedestrianDisplacement;
  float secondDisplacement;

  //Set pedestrianDisplacement to either the X or Y coordinate if
  //directionX is greater than directionY
  if (firstPedDirection.x > firstPedDirection.y) {
    pedestrianDisplacement = firstPedCoords.y;
    secondDisplacement = secondPedCoords.y;
  } else {
    pedestrianDisplacement = firstPedCoords.x;
    secondDisplacement = secondPedCoords.x;
  }

  float L =
      std::max((pedestrianDisplacement - firstShoulderLength), (secondDisplacement - secondShoulderLength));
  float R =
      std::min((pedestrianDisplacement + firstShoulderLength), (secondDisplacement + secondShoulderLength));

  return L <= R;
}

/**
 * @brief Calculates pedestrian Propulsion force and Updates propulsionForces
 * 
 * @param pedestrianSet 
 * @param goals 
 */
void
CalmPedestrianModel::calculatePropulsion(const CalmPedestrianSet& pedestrianSet, const CalmGoals& goals) {
  const auto& currentGoals = goals.getAllCurrentGoals();
  const auto& velocities = pedestrianSet.getVelocities();
  const auto& coords = pedestrianSet.getPedestrianCoordinates();
  const auto& masses = pedestrianSet.getMasses();
  const auto& desiredSpeeds = pedestrianSet.getDesiredSpeeds();
  const auto& reactionTimes = pedestrianSet.getReactionTimes();

  for (VIPRA::idx i = 0; i < pedestrianSet.getNumPedestrians(); ++i) {

    if (goals.isPedestianGoalMet(i))
      continue;

    VIPRA::f3d velocity = velocities[i];
    VIPRA::f3d goal = currentGoals[i];
    VIPRA::f3d coord = coords[i];
    float      mass = masses[i];
    float      desiredSpeed = desiredSpeeds[i];
    float      reactionTime = reactionTimes[i];

    VIPRA::f3d direction = goal - coord;
    VIPRA::f3d newVelocity = direction.unit() * desiredSpeed;

    propulsionForces.at(i) = (VIPRA::f3d{(newVelocity.x - velocity.x) * mass / reactionTime,
                                         (newVelocity.y - velocity.y) * mass / reactionTime});
  }
}

//Change to calculatePropulsion
void
CalmPedestrianModel::calculateDesiredSpeeds(const CalmPedestrianSet& pedestrianSet, const CalmGoals& goals) {
  VIPRA::size numPedestrians = pedestrianSet.getNumPedestrians();
  float       a = -2.4532;
  float       b = 0.138412;
  float       c = 0.87436;

  for (VIPRA::idx i = 0; i < numPedestrians; ++i) {
    if (goals.isPedestianGoalMet(i)) {

      modelState->desiredSpeeds[i] = 0;

    } else {
      VIPRA::idx nearestNeighborIndex = nearestNeighbors[i];

      float distanceMinusB = 1;

      if (nearestNeighborIndex == VIPRA::idx_INVALID) {
        distanceMinusB = ((1) - b);  //1 value might need to change
      } else {
        distanceMinusB = (getPedestrianDistance(pedestrianSet, i, nearestNeighborIndex)) - b;
      }

      float desiredSpeed =
          (0.3 * (c - exp(a * distanceMinusB)));  // Might need to change this depending on goal.

      modelState->desiredSpeeds[i] = desiredSpeed;
    }
  }
}

float
CalmPedestrianModel::getPedestrianDistance(const CalmPedestrianSet& pedestrianSet,
                                           VIPRA::idx               firstPedestrian,
                                           VIPRA::idx               secondPedestrian) {

  if (firstPedestrian == secondPedestrian) {
    return 0;
  }

  if (firstPedestrian > secondPedestrian) {
    return pedestrianDistanceMatrix[(pedestrianSet.getNumPedestrians() * firstPedestrian) + secondPedestrian];
  } else {
    return pedestrianDistanceMatrix[(pedestrianSet.getNumPedestrians() * secondPedestrian) + firstPedestrian];
  }
}

VIPRA::f3dVec
CalmPedestrianModel::getPropulsionForces() {
  return propulsionForces;
}

std::vector<VIPRA::idx>
CalmPedestrianModel::getNearestNeighbors() {
  return nearestNeighbors;
}

CalmPedestrianModel::~CalmPedestrianModel() {
  //delete[] obstacleDistanceMatrix;
  delete[] pedestrianDistanceMatrix;
}

void
CalmPedestrianModel::configure(const VIPRA::ConfigMap& configMap) {}