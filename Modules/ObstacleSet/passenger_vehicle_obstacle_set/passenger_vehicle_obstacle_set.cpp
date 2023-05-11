#include "passenger_vehicle_obstacle_set.hpp"

VIPRA::f3d  makeDimensions(const VIPRA::EntitySet& objects);
inline bool objectDirectionTest(const VIPRA::f3d& pedCoords, const VIPRA::f3d& pedVelocity, const VIPRA::f3d& objCoords);

VIPRA::f3d
makeDimensions(const VIPRA::EntitySet& objects) {
  VIPRA::f3d maxDim{0, 0, 0};
  for (auto mapIterator : objects) {
    for (size_t i = 0; i < mapIterator.second.size(); i++) {
      VIPRA::f3d coordinates = mapIterator.second[i];
      if (coordinates.x > maxDim.x)
        maxDim.x = coordinates.x;
      if (coordinates.y > maxDim.y)
        maxDim.y = coordinates.y;
      if (coordinates.z > maxDim.z)
        maxDim.z = coordinates.z;
    }
  }

  return maxDim;
}

void
PassengerVehicleObstacleSet::initialize(std::unique_ptr<VIPRA::MapData> map) {
  if (map->type != "PointMap") {
    ObstacleSetException::Throw("Improper Map Type, Expected \"PointMap\"");
  }
  objects = static_cast<PointMap*>(map.get())->entities;
  checkMap();
  mapDimensions = makeDimensions(objects);
}

void
PassengerVehicleObstacleSet::configure(const VIPRA::Config::Map& configMap) {
  obstacleCollisionDistance = configMap["obstacleCollisionDistance"].asFloat();
  obstacleCollisionDistanceSqrd = obstacleCollisionDistance * obstacleCollisionDistance;
}

VIPRA::f3dVec
PassengerVehicleObstacleSet::nearestObstacle(const PedestrianSet& PedSet) const {
  const VIPRA::f3dVec& coordinatesVector = PedSet.getPedestrianCoordinates();
  VIPRA::f3dVec        nearestObstacleVector;
  for (size_t j = 0; j < coordinatesVector.size(); j++) {
    VIPRA::f3d coordinates = coordinatesVector.at(j);
    size_t     min_index = 0;
    for (size_t i = 0; i < objects.at("obstacle").size(); i++) {
      if (coordinates.distanceTo(objects.at("obstacle").at(i)) <
          coordinates.distanceTo(objects.at("obstacle").at(min_index)))
        min_index = i;
    }
    nearestObstacleVector.push_back(objects.at("obstacle").at(min_index));
  }

  return nearestObstacleVector;
}

VIPRA::f3dVec
PassengerVehicleObstacleSet::nearestObstacleInDirection(const PedestrianSet& pedSet) const {

  const VIPRA::size pedCnt = pedSet.getNumPedestrians();
  const auto&       pedCoords = pedSet.getPedestrianCoordinates();
  const auto&       pedVels = pedSet.getVelocities();
  VIPRA::f3dVec     nearest = VIPRA::f3dVec(pedCnt);

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    nearest[i] = nearestObstacleInDirection(pedCoords.at(i), pedVels.at(i));
  }

  return nearest;
}

VIPRA::f3d
PassengerVehicleObstacleSet::nearestObstacle(const VIPRA::f3d coordinates) const {
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

VIPRA::f3d
PassengerVehicleObstacleSet::nearestObstacleInDirection(VIPRA::f3d coordinates, VIPRA::f3d velocity) const {
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
    return VIPRA::__emptyf3d__;
  }

  return obstacles.at(nearest);
}

const std::vector<VIPRA::f3d>&
PassengerVehicleObstacleSet::getObjectsofType(const std::string& type) const {
  return objects.at(type);
}

const std::vector<std::string>&
PassengerVehicleObstacleSet::getObjectTypes() const {
  return objectTypes;
}

VIPRA::f3d
PassengerVehicleObstacleSet::getMapDimensions() const {
  return mapDimensions;
}

float
PassengerVehicleObstacleSet::rayHit(VIPRA::f3d point1, VIPRA::f3d point2) const {
  const auto& obstacles = objects.at("obstacle");
  float       nearest = std::numeric_limits<float>::max();

  if (point1 == point2) {
    return -1;
  }

  for (const auto& obstacle : obstacles) {
    const VIPRA::f3d vAP = obstacle - point1;
    const VIPRA::f3d vAB = point2 - point1;

    const float sqDistanceAB = point1.distanceToSquared(point2);
    const float ABAPproduct = vAB.x * vAP.x + vAB.y * vAP.y;
    const float amount = ABAPproduct / sqDistanceAB;

    VIPRA::f3d intersect =
        VIPRA::f3d{(amount * (point2.x - point1.x)) + point1.x, (amount * (point2.y - point1.y)) + point1.y};

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

bool
PassengerVehicleObstacleSet::collision(VIPRA::f3d coords) const {
  return std::any_of(objects.at("obstacle").begin(), objects.at("obstacle").end(), [&](const VIPRA::f3d& obs) {
    if (obs.distanceTo(coords) < obstacleCollisionDistance) {
      return true;
    }
    return false;
  });
}

void
PassengerVehicleObstacleSet::checkMap() const {
  // check that seat, exit, aisle, and endOfAilse exists
  if (objects.find("exit") == objects.end()) {
    ObstacleSetException::Throw("PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"exit\"");
  }
  if (objects.find("endOfAisle") == objects.end()) {
    ObstacleSetException::Throw("PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"endOfAisle\"");
  }
  if (objects.find("aisle") == objects.end()) {
    ObstacleSetException::Throw("PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"aisle\"");
  }
  if (objects.find("seat") == objects.end()) {
    ObstacleSetException::Throw("PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"seat\"");
  }
  if (objects.find("obstacle") == objects.end()) {
    ObstacleSetException::Throw("PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"obstacle\"");
  }
}

inline bool
objectDirectionTest(const VIPRA::f3d& pedCoords, const VIPRA::f3d& pedVelocity, const VIPRA::f3d& objCoords) {
  const VIPRA::f3d displacement = pedCoords - objCoords;

  const float result =
      (displacement.x * pedVelocity.x) + (displacement.y * pedVelocity.y) + (displacement.z * pedVelocity.z);

  return result <= 0;
}