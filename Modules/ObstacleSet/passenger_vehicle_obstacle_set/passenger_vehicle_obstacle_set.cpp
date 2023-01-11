#include "passenger_vehicle_obstacle_set.hpp"

VIPRA::f3d makeDimensions(const VIPRA::EntitySet& objects);

VIPRA::f3d
makeDimensions(const VIPRA::EntitySet& objects) {
  float maxX = 0, maxY = 0, maxZ = 0;
  for (auto mapIterator : objects) {
    for (size_t i = 0; i < mapIterator.second.size(); i++) {
      VIPRA::f3d coordinates = mapIterator.second[i];
      if (coordinates.x > maxX)
        maxX = coordinates.x;
      if (coordinates.y > maxY)
        maxY = coordinates.y;
      if (coordinates.z > maxZ)
        maxZ = coordinates.z;
    }
  }
  VIPRA::f3d returnDimension(maxX, maxY, maxZ);

  return returnDimension;
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
PassengerVehicleObstacleSet::configure(const VIPRA::ConfigMap& configMap) {
  obstacleCollisionDistance = std::stof(configMap.at("obstacleCollisionDistance"));
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
  // TODO
  return {};
}

VIPRA::f3d
PassengerVehicleObstacleSet::nearestObstacle(const VIPRA::f3d coordinates) const {
  // TODO
  return VIPRA::f3d{};
}

VIPRA::f3d
PassengerVehicleObstacleSet::nearestObstacleInDirection(const VIPRA::f3d coordinates,
                                                        const VIPRA::f3d velocity) const {
  size_t min_index = 0;
  for (size_t i = 0; i < objects.at("obstacle").size(); i++) {
    if (coordinates.distanceTo(objects.at("obstacle").at(i)) <
        coordinates.distanceTo(objects.at("obstacle")[min_index]))
      min_index = i;
  }

  return objects.at("obstacle").at(min_index);
}

const std::vector<VIPRA::f3d>&
PassengerVehicleObstacleSet::getObjectsofType(const std::string& type) const noexcept {
  return objects.at(type);
}

const std::vector<std::string>&
PassengerVehicleObstacleSet::getObjectTypes() const noexcept {
  return objectTypes;
}

VIPRA::f3d
PassengerVehicleObstacleSet::getMapDimensions() const noexcept {
  return mapDimensions;
}

float
PassengerVehicleObstacleSet::rayHit(VIPRA::f3d point1, VIPRA::f3d point2) const noexcept {
  const auto& obstacles = objects.at("obstacle");
  float       nearest = std::numeric_limits<float>::max();

  for (const auto& obstacle : obstacles) {
    const VIPRA::f3d vAP = obstacle - point1;
    const VIPRA::f3d vAB = point2 - point1;

    float sqDistanceAB = point1.distanceToSquared(point2);
    float ABAPproduct = vAB.x * vAP.x + vAB.y * vAP.y;
    float amount = ABAPproduct / sqDistanceAB;

    VIPRA::f3d intersect =
        VIPRA::f3d{(amount * (point2.x - point1.x)) + point1.x, (amount * (point2.y - point1.y)) + point1.y};

    if (intersect.distanceTo(obstacle) < obstacleCollisionDistance) {
      float dist = intersect.distanceTo(point1);
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
    ObstacleSetException::Throw(
        "PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"endOfAisle\"");
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