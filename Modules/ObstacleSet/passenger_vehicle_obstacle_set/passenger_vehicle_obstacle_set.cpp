#include "passenger_vehicle_obstacle_set.hpp"

inline bool objectDirectionTest(const VIPRA::f3d& pedCoords,
                                const VIPRA::f3d& pedVelocity,
                                const VIPRA::f3d& objCoords);

/**
 * @brief Calculates the maximum dimensions among the entities.
 *
 * @param objects The entity set.
 * @return The maximum dimensions as a 3D vector.
 */
std::pair<VIPRA::f3d, VIPRA::f3d> makeDimensions(const VIPRA::EntitySet& objects) {
  VIPRA::f3d minDim = VIPRA::_emptyf3d_;
  VIPRA::f3d maxDim = -VIPRA::_emptyf3d_;
  for (const auto& mapIterator : objects) {
    for (auto coordinates : mapIterator.second) {
      if (coordinates.x > maxDim.x) {
        maxDim.x = coordinates.x;
      }
      if (coordinates.y > maxDim.y) {
        maxDim.y = coordinates.y;
      }
      if (coordinates.z > maxDim.z) {
        maxDim.z = coordinates.z;
      }
      if (coordinates.x < minDim.x) {
        minDim.x = coordinates.x;
      }
      if (coordinates.y < minDim.y) {
        minDim.y = coordinates.y;
      }
      if (coordinates.z < minDim.z) {
        minDim.z = coordinates.z;
      }
    }
  }

  return {minDim, maxDim};
}

/**
 * @brief Initializes the PassengerVehicleObstacleSet with the given map data.
 *
 * @param map The map data.
 */
void PassengerVehicleObstacleSet::initialize(std::unique_ptr<VIPRA::MapData> map) {
  if (map->type != "PointMap") {
    ObstacleSetException::error("Improper Map Type, Expected \"PointMap\"");
  }
  objects = dynamic_cast<PointMap*>(map.get())->entities;
  mapDimensions = makeDimensions(objects);
}

/**
 * @brief Configures the PassengerVehicleObstacleSet with the given configuration map.
 *
 * @param configMap The configuration map.
 */
void PassengerVehicleObstacleSet::configure(const VIPRA::CONFIG::Map& configMap) {
  obstacleCollisionDistance = configMap["obstacleCollisionDistance"].asFloat();
  obstacleCollisionDistanceSqrd = obstacleCollisionDistance * obstacleCollisionDistance;
}

/**
 * @brief Finds the nearest obstacles for each pedestrian in the PedestrianSet.
 *
 * @param PedSet The PedestrianSet.
 * @return A vector containing the nearest obstacles for each pedestrian.
 */
VIPRA::f3dVec PassengerVehicleObstacleSet::nearestObstacle(
    const PedestrianSet& PedSet) const {
  const VIPRA::f3dVec& coordinatesVector = PedSet.getCoordinates();
  VIPRA::f3dVec        nearestObstacleVector;
  for (auto coordinates : coordinatesVector) {
    size_t minIndex = 0;
    for (size_t i = 0; i < objects.at("obstacle").size(); i++) {
      if (coordinates.distanceTo(objects.at("obstacle").at(i)) <
          coordinates.distanceTo(objects.at("obstacle").at(minIndex))) {
        minIndex = i;
      }
    }
    nearestObstacleVector.push_back(objects.at("obstacle").at(minIndex));
  }

  return nearestObstacleVector;
}

/**
 * @brief Finds the nearest obstacles in the direction of each pedestrian's velocity in the PedestrianSet.
 *
 * @param pedSet The PedestrianSet.
 * @return A vector containing the nearest obstacles in the direction of each pedestrian's velocity.
 */
VIPRA::f3dVec PassengerVehicleObstacleSet::nearestObstacleInDirection(
    const PedestrianSet& pedSet) const {
  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       pedCoords = pedSet.getCoordinates();
  const auto&       pedVels = pedSet.getVelocities();
  VIPRA::f3dVec     nearest = VIPRA::f3dVec(pedCnt);

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    nearest[i] = nearestObstacleInDirection(pedCoords.at(i), pedVels.at(i));
  }

  return nearest;
}

/**
 * @brief Finds the nearest obstacle to the given coordinates.
 *
 * @param coordinates The coordinates.
 * @return The nearest obstacle.
 */
VIPRA::f3d PassengerVehicleObstacleSet::nearestObstacle(
    const VIPRA::f3d coordinates) const {
  const auto&       obs = objects.at("obstacle");
  const VIPRA::size obCnt = obs.size();
  VIPRA::idx        closest = VIPRA::idx_INVALID;
  float             cDist = std::numeric_limits<float>::max();

  for (VIPRA::idx i = 0; i < obCnt; ++i) {
    float dist = obs.at(i).distanceTo(coordinates);
    if (dist < cDist) {
      cDist = dist;
      closest = i;
    }
  }
  return obs.at(closest);
}

/**
 * @brief Finds the nearest obstacle in the direction of the given coordinates and velocity.
 *
 * @param coordinates The coordinates.
 * @param velocity The velocity.
 * @return The nearest obstacle in the given direction.
 */
VIPRA::f3d PassengerVehicleObstacleSet::nearestObstacleInDirection(
    VIPRA::f3d coordinates, VIPRA::f3d velocity) const {
  const auto&       obstacles = objects.at("obstacle");
  const VIPRA::size obsCnt = obstacles.size();
  VIPRA::idx        nearest = VIPRA::idx_INVALID;
  float             cDist = std::numeric_limits<float>::max();

  for (VIPRA::idx i = 0; i < obsCnt; ++i) {
    if (objectDirectionTest(coordinates, velocity, obstacles.at(i))) {
      float dist = obstacles.at(i).distanceToSquared(coordinates);
      if (dist < cDist) {
        cDist = dist;
        nearest = i;
      }
    }
  }

  if (nearest == VIPRA::idx_INVALID) {
    return VIPRA::_emptyf3d_;
  }

  return obstacles.at(nearest);
}

/**
 * @brief Retrieves the objects of the specified type from the obstacle set.
 *
 * @param type The type of objects.
 * @return A reference to the vector of objects.
 */
const std::vector<VIPRA::f3d>& PassengerVehicleObstacleSet::getObjectsofType(
    const std::string& type) const {
  return objects.at(type);
}

/**
 * @brief Retrieves the types of objects in the obstacle set.
 *
 * @return A reference to the vector of object types.
 */
const std::vector<std::string>& PassengerVehicleObstacleSet::getObjectTypes() const {
  return objectTypes;
}

/**
 * @brief Retrieves the dimensions of the map.
 *
 * @return The map dimensions as a pair of VIPRA::f3d.
 */
std::pair<VIPRA::f3d, VIPRA::f3d> PassengerVehicleObstacleSet::getMapDimensions() const {
  return mapDimensions;
}

/**
 * @brief Performs a ray hit test between two points in the obstacle set.
 *
 * @param point1 The first point.
 * @param point2 The second point.
 * @return The distance of the hit point from point1 if a hit occurs, or -1 if no hit occurs.
 */
float PassengerVehicleObstacleSet::rayHit(VIPRA::f3d point1, VIPRA::f3d point2) const {
  const auto& obstacles = objects.at("obstacle");
  float       nearest = std::numeric_limits<float>::max();

  if (point1 == point2) {
    return -1;
  }

  for (const auto& obstacle : obstacles) {
    const VIPRA::f3d vAP = obstacle - point1;
    const VIPRA::f3d vAB = point2 - point1;

    const float sqDistanceAB = point1.distanceToSquared(point2);
    const float abapProduct = vAB.x * vAP.x + vAB.y * vAP.y;
    const float amount = abapProduct / sqDistanceAB;

    VIPRA::f3d intersect = VIPRA::f3d{(amount * (point2.x - point1.x)) + point1.x,
                                      (amount * (point2.y - point1.y)) + point1.y};

    if (intersect.distanceToSquared(obstacle) < obstacleCollisionDistanceSqrd) {
      const float dist = intersect.distanceTo(point1);
      if (dist < nearest) {
        nearest = dist;
      }
    }
  }

  if (nearest == std::numeric_limits<float>::max()) {
    return -1;
  }
  return nearest;
}

/**
 * @brief Checks if a collision occurs at the given coordinates.
 *
 * @param coords The coordinates.
 * @return True if a collision occurs, false otherwise.
 */
bool PassengerVehicleObstacleSet::collision(VIPRA::f3d coords) const {
  return std::any_of(objects.at("obstacle").begin(), objects.at("obstacle").end(),
                     [&](const VIPRA::f3d& obs) {
                       return obs.distanceTo(coords) < obstacleCollisionDistance;
                     });
}

/**
 * @brief Tests if an object is in the opposite direction of the pedestrian's movement.
 *
 * @param pedCoords The pedestrian coordinates.
 * @param pedVelocity The pedestrian velocity.
 * @param objCoords The object coordinates.
 * @return True if the object is in the opposite direction, false otherwise.
 */
inline bool objectDirectionTest(const VIPRA::f3d& pedCoords,
                                const VIPRA::f3d& pedVelocity,
                                const VIPRA::f3d& objCoords) {
  const VIPRA::f3d displacement = pedCoords - objCoords;

  const float result = (displacement.x * pedVelocity.x) +
                       (displacement.y * pedVelocity.y) +
                       (displacement.z * pedVelocity.z);

  return result <= 0;
}