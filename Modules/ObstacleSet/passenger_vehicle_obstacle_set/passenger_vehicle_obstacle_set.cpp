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
PassengerVehicleObstacleSet::initialize(const std::unique_ptr<MapType> map) {
  if (map->type != "PointMap") {
    ObstacleSetException::Throw("Improper Map Type, Expected \"PointMap\"");
  }
  objects = static_cast<const PointMap*>(map.get())->entities;
  checkMap();
  mapDimensions = makeDimensions(objects);
}

void
PassengerVehicleObstacleSet::configure(const VIPRA::ConfigMap& configMap) {}

VIPRA::f3dVec
PassengerVehicleObstacleSet::nearestObstacle(const PedestrianSet& PedSet) const {
  const VIPRA::f3dVec& coordinatesVector = PedSet.getPedestrianCoordinates();
  VIPRA::f3dVec        nearestObstacleVector;
  for (size_t j = 0; j < coordinatesVector.size(); j++) {
    VIPRA::f3d coordinates = coordinatesVector.at(j);
    size_t     min_index = 0;
    for (size_t i = 0; i < objects.at("obstacles").size(); i++) {
      if (coordinates.distanceTo(objects.at("obstacles").at(i)) <
          coordinates.distanceTo(objects.at("obstacles").at(min_index)))
        min_index = i;
    }
    nearestObstacleVector.push_back(objects.at("obstacles").at(min_index));
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
  for (size_t i = 0; i < objects.at("obstacles").size(); i++) {
    if (coordinates.distanceTo(objects.at("obstacles").at(i)) <
        coordinates.distanceTo(objects.at("obstacles")[min_index]))
      min_index = i;
  }

  return objects.at("obstacles").at(min_index);
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

  for (size_t i = 0; i < objects.at("obstacles").size(); i++) {
    VIPRA::f3d coordinates = objects.at("obstacles")[i];

    if (coordinates.distanceTo(point1) + coordinates.distanceTo(point1) == point1.distanceTo(point2))
      return coordinates.distanceTo(point1);
  }

  return -1;
}

void
PassengerVehicleObstacleSet::checkMap() const {
  // check that seat, exit, aisle, and endOfAilse exists
  if (objects.find("exit") == objects.end()) {
    ObstacleSetException::Throw(
        "PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"exit\"");
  }
  if (objects.find("endOfAisle") == objects.end()) {
    ObstacleSetException::Throw(
        "PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"endOfAisle\"");
  }
  if (objects.find("aisle") == objects.end()) {
    ObstacleSetException::Throw(
        "PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"aisle\"");
  }
  if (objects.find("seat") == objects.end()) {
    ObstacleSetException::Throw(
        "PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"seat\"");
  }
  if (objects.find("obstacles") == objects.end()) {
    ObstacleSetException::Throw(
        "PassengerVehicleObstacleSet: Obstacle Map missing Objects of Type: \"obstacles\"");
  }
}