#include "calm_pedestrian_model.hpp"

struct Rect {
  VIPRA::f3d p1;
  VIPRA::f3d p2;
  VIPRA::f3d p3;
  VIPRA::f3d p4;
};

struct Line {
  VIPRA::f3d p1;
  VIPRA::f3d p2;
};

inline bool lineRectIntersects(const Rect& rect, const VIPRA::f3d& linep1, const VIPRA::f3d& linep2) noexcept;

inline bool lineIntersect(const VIPRA::f3d& start1,
                          const VIPRA::f3d& end1,
                          const VIPRA::f3d& linep1,
                          const VIPRA::f3d& linep2) noexcept;

inline Line getShoulderPoints(const VIPRA::f3d& coords, const VIPRA::f3d& velocity, float shoulderWidth);

CalmPedestrianModel::CalmPedestrianModel() {}

void
CalmPedestrianModel::initialize(const PedestrianSet&                pedestrianSet,
                                [[maybe_unused]] const ObstacleSet& obstacleSet,
                                [[maybe_unused]] const Goals&       goals) {
  pedestrianDistanceMatrix = new float[pedestrianSet.getNumPedestrians() * pedestrianSet.getNumPedestrians()];
  propulsionForces = VIPRA::f3dVec(pedestrianSet.getNumPedestrians(), VIPRA::f3d{0.0f, 0.0f});
  modelState = std::make_shared<CalmState>(pedestrianSet.getNumPedestrians());
  nearestNeighbors = std::vector<float>(pedestrianSet.getNumPedestrians());
}

std::shared_ptr<VIPRA::State>
CalmPedestrianModel::timestep(const PedestrianSet& pedestrianSet,
                              const ObstacleSet&   obstacleSet,
                              const Goals&         goals,
                              VIPRA::delta_t       timestep) {

  LJ::Debug(simLogger, "Calc DM");
  calculateDistanceMatrices(static_cast<const CalmPedestrianSet&>(pedestrianSet));
  LJ::Debug(simLogger, "Calc NN");
  calculateNeartestNeighbors(static_cast<const CalmPedestrianSet&>(pedestrianSet), obstacleSet, goals);
  LJ::Debug(simLogger, "Update DS");
  updateDesiredSpeeds(static_cast<const CalmPedestrianSet&>(pedestrianSet), static_cast<const CalmGoals&>(goals));
  LJ::Debug(simLogger, "Calc Propulsion");
  calculatePropulsion(static_cast<const CalmPedestrianSet&>(pedestrianSet), static_cast<const CalmGoals&>(goals));
  LJ::Debug(simLogger, "Update State");
  updateModelState(static_cast<const CalmPedestrianSet&>(pedestrianSet), timestep);
  LJ::Debug(simLogger, "Done");
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
      newPosition = VIPRA::f3d{(coordinateX + (newVelocity.x * time)), (coordinateY + (newVelocity.y * time))};
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
 * @brief Updates nearestNeighbors with the nearest pedestrian in front of the pedestrian
 * 
 * @param pedSet 
 */
void
CalmPedestrianModel::calculateNeartestNeighbors(const CalmPedestrianSet& pedSet,
                                                const ObstacleSet&       obsSet,
                                                const Goals&             goals) {

  const auto&       coords = pedSet.getPedestrianCoordinates();
  const auto&       velocities = pedSet.getVelocities();
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       shoulderLengths = pedSet.getShoulderLengths();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {

    if (goals.isPedestianGoalMet(i))
      continue;

    float nearestDist = std::numeric_limits<float>::max();

    for (VIPRA::idx j = 0; j < pedCnt; ++j) {
      if (i == j)
        continue;

      if (goals.isPedestianGoalMet(j))
        continue;

      LJ::Debug(simLogger, "Direction Test");
      if (!objectDirectionTest(coords.at(i), velocities.at(i), coords.at(j)))
        continue;

      LJ::Debug(simLogger, "Distance");
      float dist = getPedestrianDistance(pedSet, i, j);
      if (dist > nearestDist)
        continue;

      LJ::Debug(simLogger, "Shoulders");
      const Line secondPedShoulders = getShoulderPoints(coords.at(j), velocities.at(j), shoulderLengths.at(j));
      LJ::Debug(simLogger, "Spatial Test");
      if (!objectSpatialTest(
              coords.at(i), velocities.at(i), shoulderLengths.at(i), secondPedShoulders.p1, secondPedShoulders.p2))
        continue;

      nearestDist = dist;
    }

    LJ::Debug(simLogger, "Blocked Path");
    float obsDist = checkBlockedPath(coords.at(i), velocities.at(i), shoulderLengths.at(i), nearestDist, obsSet);
    if (obsDist != -1 && obsDist < nearestDist) {
      nearestDist = obsDist;
    }

    nearestNeighbors[i] = nearestDist;
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
CalmPedestrianModel::objectDirectionTest(const VIPRA::f3d& pedCoords,
                                         const VIPRA::f3d& pedVelocity,
                                         const VIPRA::f3d& objCoords) {
  const VIPRA::f3d displacement = pedCoords - objCoords;

  const float result =
      (displacement.x * pedVelocity.x) + (displacement.y * pedVelocity.y) + (displacement.z * pedVelocity.z);

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
CalmPedestrianModel::objectSpatialTest(const VIPRA::f3d& pedCoords,
                                       const VIPRA::f3d& pedVelocity,
                                       float             pedShoulderLength,
                                       const VIPRA::f3d& objLeft,
                                       const VIPRA::f3d& objRight) {

  // Creates a rectangle from the first pedestrians position, shoulders, and velocity
  // then checks if the second pedestrian intersects it

  const Line shoulders = getShoulderPoints(pedCoords, pedVelocity, pedShoulderLength);

  LJ::Debug(simLogger, "Rect");
  const VIPRA::f3d range = (pedVelocity.unit() * 5);
  const Rect       pedCollisionRect = {shoulders.p1, shoulders.p1 + range, shoulders.p2 + range, shoulders.p2};

  if (pedCollisionRect.p1 == pedCollisionRect.p2) {
    return false;
  }

  LJ::Debug(simLogger, "return");
  return lineRectIntersects(pedCollisionRect, objLeft, objRight);
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
  const auto& reactionTimes = pedestrianSet.getReactionTimes();

  for (VIPRA::idx i = 0; i < pedestrianSet.getNumPedestrians(); ++i) {

    if (goals.isPedestianGoalMet(i))
      continue;

    const VIPRA::f3d& velocity = velocities[i];
    const VIPRA::f3d& goal = currentGoals[i];
    const VIPRA::f3d& coord = coords[i];
    const float       mass = masses[i];
    const float       desiredSpeed = modelState->desiredSpeeds[i];
    const float       reactionTime = reactionTimes[i];

    const VIPRA::f3d direction = goal - coord;
    const VIPRA::f3d newVelocity = direction.unit() * desiredSpeed;

    propulsionForces.at(i) = (VIPRA::f3d{(newVelocity.x - velocity.x) * mass / reactionTime,
                                         (newVelocity.y - velocity.y) * mass / reactionTime});
  }
}

inline float
CalmPedestrianModel::checkBlockedPath(const VIPRA::f3d&  coords,
                                      const VIPRA::f3d&  velocity,
                                      float              shoulderWidth,
                                      float              checkDistance,
                                      const ObstacleSet& obsSet) {

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
CalmPedestrianModel::updateDesiredSpeeds(const CalmPedestrianSet& pedestrianSet, const CalmGoals& goals) {
  const VIPRA::size numPedestrians = pedestrianSet.getNumPedestrians();

  for (VIPRA::idx i = 0; i < numPedestrians; ++i) {
    if (goals.isPedestianGoalMet(i)) {
      modelState->desiredSpeeds[i] = 0;
      continue;
    }

    modelState->desiredSpeeds[i] = calculateDesiredSpeed(nearestNeighbors[i]);
  }
}

constexpr float
CalmPedestrianModel::calculateDesiredSpeed(float distance) {
  const float a = -2.4532;
  const float b = 0.138412;
  const float c = 0.87436;

  return (0.3 * (c - std::exp(a * (distance - b))));
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

std::vector<float>
CalmPedestrianModel::getNearestNeighbors() {
  return nearestNeighbors;
}

CalmPedestrianModel::~CalmPedestrianModel() {
  delete[] pedestrianDistanceMatrix;
}

void
CalmPedestrianModel::configure([[maybe_unused]] const VIPRA::ConfigMap& configMap) {}

/**
 * @brief returns true if the line intersects any of the sides of rect, also checks if it intersects the rect's internal diagonal
 * 
 * @param rect 
 * @param line 
 */
inline bool
lineRectIntersects(const Rect& rect, const VIPRA::f3d& linep1, const VIPRA::f3d& linep2) noexcept {
  if (lineIntersect(rect.p1, rect.p2, linep1, linep2))
    return true;
  if (lineIntersect(rect.p2, rect.p3, linep1, linep2))
    return true;
  if (lineIntersect(rect.p3, rect.p4, linep1, linep2))
    return true;
  if (lineIntersect(rect.p4, rect.p1, linep1, linep2))
    return true;
  if (lineIntersect(rect.p2, rect.p4, linep1, linep2))
    return true;

  return false;
}

/**
 * @brief returns true if the two lines intersect
 * 
 * @param start1 
 * @param end1 
 * @param line 
 */
inline bool
lineIntersect(const VIPRA::f3d& start1,
              const VIPRA::f3d& end1,
              const VIPRA::f3d& start2,
              const VIPRA::f3d& end2) noexcept {

  const float uA = ((end2.x - start2.x) * (start1.y - start2.y) - (end2.y - start2.y) * (start1.x - start2.x)) /
                   ((end2.y - start2.y) * (end1.x - start1.x) - (end2.x - start2.x) * (end1.y - start1.y));

  const float uB = ((end1.x - start1.x) * (start1.y - start2.y) - (end1.y - start1.y) * (start1.x - start2.x)) /
                   ((end2.y - start2.y) * (end1.x - start1.x) - (end2.x - start2.x) * (end1.y - start1.y));

  if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
    return true;
  }
  return false;
}

/**
 * @brief Get the Shoulder Points from a pedestrians position, velocity and shoulder width
 * 
 * @param coords 
 * @param velocity 
 * @param shoulderWidth 
 */
inline Line
getShoulderPoints(const VIPRA::f3d& coords, const VIPRA::f3d& velocity, float shoulderWidth) {
  return {(VIPRA::f3d{-velocity.y, velocity.x}.unit() * shoulderWidth) + coords,
          (VIPRA::f3d{velocity.y, -velocity.x}.unit() * shoulderWidth) + coords};
}
