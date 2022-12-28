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
  calculateNeartestNeighbors(static_cast<const CalmPedestrianSet&>(pedestrianSet));
  calculateDesiredSpeeds(static_cast<const CalmPedestrianSet&>(pedestrianSet),
                         static_cast<const CalmGoals&>(goals));
  calculatePropulsion(static_cast<const CalmPedestrianSet&>(pedestrianSet),
                      static_cast<const CalmGoals&>(goals));
  updateModelState(static_cast<const CalmPedestrianSet&>(pedestrianSet), timestep);
  checkForBlockedPaths(pedestrianSet, obstacleSet);

  return modelState;
}

void
CalmPedestrianModel::updateModelState(const CalmPedestrianSet& pedestrianSet, VIPRA::delta_t time) {

  //Need some clarification on why we need this coeff... - NR
  float coeff = 0.01;

  VIPRA::f3dVec newVelocities = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});
  VIPRA::f3dVec newPositions = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});

  VIPRA::f3d newVelocity;
  float      newSpeed;
  VIPRA::f3d newPosition;

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

//TODO: Add Goals and ObstacleSet to Algorithm
void
CalmPedestrianModel::calculateDistanceMatrices(const CalmPedestrianSet& pedestrianSet) {
  // Update the pedestrians since they could have been removed from the
  // simulation at this point. Also update the obstacles just in case they
  // can be removed in the future.
  VIPRA::size numPedestrians = pedestrianSet.getNumPedestrians();

  //Updates pedestrian-to-pedestrian distance matrix and pedestrian-to-object distance matrix
  for (VIPRA::idx i = 0; i < numPedestrians; ++i) {
    for (VIPRA::idx j = 0; j < i; ++j) {
      float distance = pedestrianSet.getPedestrianCoordinates().at(i).distanceTo(
          pedestrianSet.getPedestrianCoordinates().at(j));

      pedestrianDistanceMatrix[(i * numPedestrians) + j] = distance;
    }
  }
}

/**
 * @brief If a pedestrian has been moved inside of an obstacle, move them back to their original coordinates, set velocity to zero
 * 
 * @param pedSet 
 * @param obsSet 
 */
void
CalmPedestrianModel::checkForBlockedPaths(const PedestrianSet& pedSet, const ObstacleSet& obsSet) {
  const auto& pedCoords = pedSet.getPedestrianCoordinates();
  VIPRA::idx  i = 0;
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

//TODO: Add Goals and ObstacleSet
void
CalmPedestrianModel::calculateNeartestNeighbors(const CalmPedestrianSet& pedSet) {

  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  // const auto&       shoulderLengths = pedSet.getShoulderLengths();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    float      nearestDist = std::numeric_limits<float>::max();
    VIPRA::idx nearestIdx = VIPRA::idx_INVALID;

    for (VIPRA::idx j = 0; j < pedCnt; ++j) {
      if (i == j)
        continue;

      if (neighborDirectionTest(pedSet, i, j)) {
        // && neighborSpacialTest(pedSet, i, j, shoulderLengths.at(i))) {
        float dist = getPedestrianDistance(pedSet, i, j);
        if (dist < nearestDist) {
          nearestDist = dist;
          nearestIdx = j;
        }
      }
    }
  }
}

inline bool
CalmPedestrianModel::neighborDirectionTest(const CalmPedestrianSet& pedSet,
                                           VIPRA::idx               firstIdx,
                                           VIPRA::idx               secondIdx)

{
  const auto& coords = pedSet.getPedestrianCoordinates();
  float       displacementX = (coords.at(firstIdx).x - coords.at(secondIdx).x);
  float       displacementY = (coords.at(firstIdx).y - coords.at(secondIdx).y);

  float directionX = (pedSet.getVelocities())[firstIdx].x;
  float directionY = (pedSet.getVelocities())[firstIdx].y;

  return ((displacementX * directionX) + (displacementY * directionY)) <= 0;
}

inline bool
CalmPedestrianModel::neighborSpacialTest(const CalmPedestrianSet& pedSet,
                                         VIPRA::idx               firstPedIdx,
                                         VIPRA::idx               secondPedIdx,
                                         float                    firstShoulderLength) {
  // float firstPedestrianDirectionX;
  // float firstPedestrianDirectionY;

  // float secondPedestrianDirectionX;
  // float secondPedestrianDirectionY;

  // float secondShoulderLength = 0;
  // float L;
  // float R;

  // int coordinateIndex;

  // firstPedestrianDirectionX = std::fabs((pedestrianSet.getVelocities())[firstPedestrianIndex].x);
  // firstPedestrianDirectionY = std::fabs((pedestrianSet.getVelocities())[firstPedestrianIndex].y);

  // if (originSet == "P") {
  //   secondPedestrianDirectionX = std::fabs((pedestrianSet.getVelocities())[secondPedestrianIndex].x);
  //   secondPedestrianDirectionY = std::fabs((pedestrianSet.getVelocities())[secondPedestrianIndex].y);

  //   if ((firstPedestrianDirectionX > firstPedestrianDirectionY &&
  //        secondPedestrianDirectionX > secondPedestrianDirectionY) ||
  //       (firstPedestrianDirectionY > firstPedestrianDirectionX &&
  //        secondPedestrianDirectionY > secondPedestrianDirectionX)) {
  //     secondShoulderLength = pedestrianSet.getShoulderLengths().at(secondPedestrianIndex);
  //   }
  // }

  // float pedestrianDisplacement;
  // float secondDisplacement;

  // //Set pedestrianDisplacement to either the X or Y coordinate if
  // //directionX is greater than directionY
  // if (firstPedestrianDirectionX > firstPedestrianDirectionY) {
  //   pedestrianDisplacement = pedestrianDisplacementY;
  //   secondDisplacement = secondDisplacementY;

  // } else {
  //   pedestrianDisplacement = pedestrianDisplacementX;
  //   secondDisplacement = secondDisplacementX;
  // }

  // L = std::max((pedestrianDisplacement - firstShoulderLength), (secondDisplacement - secondShoulderLength));

  // R = std::min((pedestrianDisplacement + firstShoulderLength), (secondDisplacement + secondShoulderLength));

  // return L <= R;
}

//determine pedestrian direction
void
CalmPedestrianModel::calculatePropulsion(const CalmPedestrianSet& pedestrianSet, const CalmGoals& goals) {
  const VIPRA::f3dVec& currentGoals = goals.getAllCurrentGoals();

  for (VIPRA::idx i = 0; i < pedestrianSet.getNumPedestrians(); ++i) {
    if (goals.isPedestianGoalMet(i))
      continue;

    float goalX = currentGoals[i].x;
    float goalY = currentGoals[i].y;
    float coordinateX = pedestrianSet.getPedestrianCoordinates()[i].x;
    float coordinateY = pedestrianSet.getPedestrianCoordinates()[i].y;
    float mass = pedestrianSet.getMasses()[i];
    float desiredSpeed = pedestrianSet.getDesiredSpeeds()[i];
    float velocityX = pedestrianSet.getVelocities()[i].x;
    float velocityY = pedestrianSet.getVelocities()[i].y;
    float reactionTime = pedestrianSet.getReactionTimes()[i];

    float directionX = goalX - coordinateX;
    float directionY = goalY - coordinateY;

    float mag = sqrt(directionX * directionX + directionY * directionY);

    VIPRA::f3d newVelocity = VIPRA::f3d{directionX / mag * desiredSpeed, directionY / mag * desiredSpeed};

    propulsionForces.at(i) = (VIPRA::f3d{(newVelocity.x - velocityX) * mass / reactionTime,
                                         (newVelocity.y - velocityY) * mass / reactionTime});
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

      modelState->desiredSpeeds[i] =
          (0.3 * (c - exp(a * distanceMinusB)));  // Might need to change this depending on goal.
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