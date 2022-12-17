#include "calm_pedestrian_model.hpp"

CalmPedestrianModel::CalmPedestrianModel() {}

void
CalmPedestrianModel::initialize(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet, Goals& goals) {
  pedestrianSet = static_cast<CalmPedestrianSet&>(pedestrianSet);
  this->pedestrianDistanceMatrix =
      new float[pedestrianSet.getNumPedestrians() * pedestrianSet.getNumPedestrians()];
  this->propulsionForces = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});
  this->modelState = std::make_shared<VIPRA::State>(pedestrianSet.getNumPedestrians());
}

std::shared_ptr<VIPRA::State>
CalmPedestrianModel::timestep(PedestrianSet& pedestrianSet,
                              ObstacleSet&   obstacleSet,
                              Goals&         goals,
                              float          time) {

  CalmPedestrianSet           calmPedestrianSet = static_cast<CalmPedestrianSet&>(pedestrianSet);
  PassengerVehicleObstacleSet airObstacleSet = static_cast<PassengerVehicleObstacleSet&>(obstacleSet);
  CalmGoals                   calmGoals = static_cast<CalmGoals&>(goals);

  calculateDistanceMatrices(calmPedestrianSet);
  calculateNeartestNeighbors(calmPedestrianSet);
  calculateDesiredSpeeds(calmPedestrianSet, calmGoals);
  calculatePropulsion(calmPedestrianSet, calmGoals);
  updateModelState(calmPedestrianSet, time);

  return this->modelState;
}

void
CalmPedestrianModel::updateModelState(CalmPedestrianSet& pedestrianSet, float time) {

  //Need some clarification on why we need this coeff... - NR
  float coeff = 0.01;

  VIPRA::f3dVec newVelocities = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});
  VIPRA::f3dVec newPositions = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});

  VIPRA::f3d newVelocity;
  float      newSpeed;
  VIPRA::f3d newPosition;

  int numPedestrians = pedestrianSet.getNumPedestrians();
  for (int i = 0; i < numPedestrians; ++i) {

    float propulsiveX = this->propulsionForces.at(i).x;
    float propulsiveY = this->propulsionForces[i].y;
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

    this->modelState->velocities[i] = newVelocity;
    this->modelState->pedestrianCoordinates[i] = newPosition;
    this->modelState->affector[i] = VIPRA::Affector::PED_MODEL;
  }
}

//TODO: Add Goals and ObstacleSet to Algorithm
void
CalmPedestrianModel::calculateDistanceMatrices(CalmPedestrianSet& pedestrianSet) {
  // Update the pedestrians since they could have been removed from the
  // simulation at this point. Also update the obstacles just in case they
  // can be removed in the future.
  int numPedestrians = pedestrianSet.getNumPedestrians();

  //Added firstPedestrianCoordinateX and Y to be used in second for loop
  float firstPedestrianCoordinateX;
  float firstPedestrianCoordinateY;

  //Updates pedestrian-to-pedestrian distance matrix and pedestrian-to-object distance matrix
  for (int i = 0; i < numPedestrians; ++i) {
    for (int j = 0; j < i; ++j) {
      float distance = pedestrianSet.getPedestrianCoordinates().at(i).distanceTo(
          pedestrianSet.getPedestrianCoordinates().at(j));

      this->pedestrianDistanceMatrix[(i * numPedestrians) + j] = distance;
    }
  }
}

//TODO: Add Goals and ObstacleSet
void
CalmPedestrianModel::calculateNeartestNeighbors(CalmPedestrianSet& pedestrianSet) {
  int nearestIndex, localNearestIndex;

  std::string originSet, localOriginSet;

  float nearestDistance, localNearestDistance;

  float pedestrianShoulderLength;

  float firstPedestrianX, firstPedestrianY, secondPedestrianX, secondPedestrianY;

  int       numPedestrians = pedestrianSet.getNumPedestrians();
  const int NOT_FOUND = -1;

  for (int pedestrianIndex = 0; pedestrianIndex < numPedestrians; ++pedestrianIndex) {
    nearestIndex = NOT_FOUND;
    localNearestIndex = NOT_FOUND;

    originSet = "P";
    localOriginSet = "P";

    nearestDistance = __FLT_MAX__;
    localNearestDistance = __FLT_MAX__;

    pedestrianShoulderLength = pedestrianSet.getShoulderLengths().at(pedestrianIndex);
    ;

    firstPedestrianX = pedestrianSet.getPedestrianCoordinates().at(pedestrianIndex).x;
    firstPedestrianY = pedestrianSet.getPedestrianCoordinates().at(pedestrianIndex).y;

    std::pair<std::string, int> newNearestNeighbor;

    for (int j = 0; j < numPedestrians; ++j) {

      secondPedestrianX = pedestrianSet.getPedestrianCoordinates().at(j).x;
      secondPedestrianY = pedestrianSet.getPedestrianCoordinates().at(j).y;

      if (pedestrianIndex != j && j < numPedestrians &&
          neighborDirectionTest(pedestrianSet,
                                pedestrianIndex,
                                j,
                                firstPedestrianX,
                                firstPedestrianY,
                                secondPedestrianX,
                                secondPedestrianY) &&
          neighborSpacialTest(pedestrianSet,
                              pedestrianIndex,
                              j,
                              firstPedestrianX,
                              firstPedestrianY,
                              secondPedestrianX,
                              secondPedestrianY,
                              "P",
                              pedestrianShoulderLength)) {

        float distance = getPedestrianDistance(pedestrianSet, pedestrianIndex, j);
        if (localNearestIndex == NOT_FOUND || distance < localNearestDistance) {
          localNearestIndex = j;
          localOriginSet = "P";
          localNearestDistance = distance;
        }
      }
    }

    if (localNearestDistance < nearestDistance) {
      nearestIndex = localNearestIndex;
      originSet = localOriginSet;
      nearestDistance = localNearestDistance;
    }

    this->nearestNeighbors.push_back(std::make_pair(std::string(originSet), nearestIndex));
  }
}

inline bool
CalmPedestrianModel::neighborDirectionTest(CalmPedestrianSet& pedestrianSet,
                                           int                firstPedestrianIndex,
                                           int                secondPedestrianIndex,
                                           float              pedestrianDisplacementX,
                                           float              pedestrianDisplacementY,
                                           float              secondDisplacementX,
                                           float              secondDisplacementY) {
  float displacementX;
  float displacementY;
  float directionX;
  float directionY;

  float dotProduct;

  displacementX = (pedestrianDisplacementX - secondDisplacementX);
  displacementY = (pedestrianDisplacementY - secondDisplacementY);

  directionX = (pedestrianSet.getVelocities())[firstPedestrianIndex].x;

  directionY = (pedestrianSet.getVelocities())[firstPedestrianIndex].y;

  dotProduct = (displacementX * directionX) + (displacementY * directionY);

  return dotProduct <= 0;
}

inline bool
CalmPedestrianModel::neighborSpacialTest(CalmPedestrianSet& pedestrianSet,
                                         int                firstPedestrianIndex,
                                         int                secondPedestrianIndex,
                                         float              pedestrianDisplacementX,
                                         float              pedestrianDisplacementY,
                                         float              secondDisplacementX,
                                         float              secondDisplacementY,
                                         std::string        originSet,
                                         float              firstShoulderLength) {
  float firstPedestrianDirectionX;
  float firstPedestrianDirectionY;

  float secondPedestrianDirectionX;
  float secondPedestrianDirectionY;

  float secondShoulderLength = 0;
  float L;
  float R;

  int coordinateIndex;

  firstPedestrianDirectionX = std::fabs((pedestrianSet.getVelocities())[firstPedestrianIndex].x);
  firstPedestrianDirectionY = std::fabs((pedestrianSet.getVelocities())[firstPedestrianIndex].y);

  if (originSet == "P") {
    secondPedestrianDirectionX = std::fabs((pedestrianSet.getVelocities())[secondPedestrianIndex].x);
    secondPedestrianDirectionY = std::fabs((pedestrianSet.getVelocities())[secondPedestrianIndex].y);

    if (firstPedestrianDirectionX > firstPedestrianDirectionY &&
            secondPedestrianDirectionX > secondPedestrianDirectionY ||
        firstPedestrianDirectionY > firstPedestrianDirectionX &&
            secondPedestrianDirectionY > secondPedestrianDirectionX) {
      secondShoulderLength = pedestrianSet.getShoulderLengths().at(secondPedestrianIndex);
    }
  }

  float pedestrianDisplacement;
  float secondDisplacement;

  //Set pedestrianDisplacement to either the X or Y coordinate if
  //directionX is greater than directionY
  if (firstPedestrianDirectionX > firstPedestrianDirectionY) {
    pedestrianDisplacement = pedestrianDisplacementY;
    secondDisplacement = secondDisplacementY;

  } else {
    pedestrianDisplacement = pedestrianDisplacementX;
    secondDisplacement = secondDisplacementX;
  }

  L = std::max((pedestrianDisplacement - firstShoulderLength), (secondDisplacement - secondShoulderLength));

  R = std::min((pedestrianDisplacement + firstShoulderLength), (secondDisplacement + secondShoulderLength));

  return L <= R;
}

//determine pedestrian direction
void
CalmPedestrianModel::calculatePropulsion(CalmPedestrianSet& pedestrianSet, CalmGoals& goals) {
  const VIPRA::f3dVec& currentGoals = goals.getAllCurrentGoals();
  const VIPRA::f3dVec& endGoals = goals.getAllEndGoals();
  float                xAisleCoefficent = 0.5;
  float                yAisleCoefficent = 0.9;

  for (int i = 0; i < pedestrianSet.getNumPedestrians(); ++i) {

    if (!goals.isPedestianGoalMet(i)) {
      VIPRA::f3d newVelocity = pedestrianSet.getVelocities().at(i);
      VIPRA::f3d newPropulsiveForce = this->propulsionForces.at(i);

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

      newVelocity = VIPRA::f3d{directionX / mag * desiredSpeed, directionY / mag * desiredSpeed};
      newPropulsiveForce = (VIPRA::f3d{(newVelocity.x - velocityX) * mass / reactionTime,
                                       (newVelocity.y - velocityY) * mass / reactionTime});

      // if (directionX <= 0 && directionY <= 0) {
      //   newVelocity =
      //       (VIPRA::f3d{-1.0f * desiredSpeed * xAisleCoefficent, -1.0f * desiredSpeed * yAisleCoefficent});
      // } else if (directionX <= 0 && directionY >= 0) {
      //   newVelocity = (VIPRA::f3d{-1.0f * desiredSpeed * xAisleCoefficent, desiredSpeed * yAisleCoefficent});
      // } else if (directionX >= 0 && directionY >= 0) {
      //   newVelocity = (VIPRA::f3d{desiredSpeed * xAisleCoefficent, desiredSpeed * yAisleCoefficent});
      // } else if (directionX >= 0 && directionY <= 0) {
      //   newVelocity = (VIPRA::f3d{desiredSpeed * xAisleCoefficent, -1.0f * desiredSpeed * yAisleCoefficent});
      // } else {
      //   newVelocity = (VIPRA::f3d{0.0, 0.0});
      // }

      // newPropulsiveForce = (VIPRA::f3d{(newVelocity.x - velocityX) * mass / reactionTime,
      //                                  (newVelocity.y - velocityY) * mass / reactionTime});

      this->propulsionForces.at(i) = std::move(newPropulsiveForce);
    }
  }
}

//Change to calculatePropulsion
void
CalmPedestrianModel::calculateDesiredSpeeds(CalmPedestrianSet& pedestrianSet, CalmGoals& goals) {
  std::vector<float> newDesiredSpeeds;
  int                numPedestrians = pedestrianSet.getNumPedestrians();
  float              a = -2.4532;
  float              b = 0.138412;
  float              c = 0.87436;

  for (int i = 0; i < numPedestrians; ++i) {
    if (!goals.isPedestianGoalMet(i)) {
      int         nearestNeighborIndex = this->nearestNeighbors[i].second;
      std::string nearestNeighborOrigin = this->nearestNeighbors[i].first;

      float distanceMinusB = 1;

      if (nearestNeighborIndex == -1) {
        distanceMinusB = ((1) - b);  //1 value might need to change
      } else {
        distanceMinusB = (getPedestrianDistance(pedestrianSet, i, nearestNeighborIndex)) - b;
      }

      newDesiredSpeeds.push_back(
          0.3 * (c - exp(a * distanceMinusB)));  // Might need to change this depending on goal.
    } else {
      newDesiredSpeeds.push_back(0);
    }
  }
  pedestrianSet.setDesiredSpeeds(newDesiredSpeeds);
}
float
CalmPedestrianModel::getPedestrianDistance(CalmPedestrianSet& pedestrianSet,
                                           int                firstPedestrian,
                                           int                secondPedestrian) {

  if (firstPedestrian == secondPedestrian) {
    return 0;
  }

  if (firstPedestrian > secondPedestrian) {
    return this
        ->pedestrianDistanceMatrix[(pedestrianSet.getNumPedestrians() * firstPedestrian) + secondPedestrian];
  } else {
    return this
        ->pedestrianDistanceMatrix[(pedestrianSet.getNumPedestrians() * secondPedestrian) + firstPedestrian];
  }
}

VIPRA::f3dVec
CalmPedestrianModel::getPropulsionForces() {
  return this->propulsionForces;
}

std::vector<std::pair<std::string, int>>
CalmPedestrianModel::getNearestNeighbors() {
  return this->nearestNeighbors;
}

CalmPedestrianModel::~CalmPedestrianModel() {
  //delete[] this->obstacleDistanceMatrix;
  delete[] this->pedestrianDistanceMatrix;
}

void
CalmPedestrianModel::configure(const VIPRA::ConfigMap& configMap) {}