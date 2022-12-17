#include "airplane_obstacle_set.hpp"

void
AirplaneObstacleSet::initialize(const std::unique_ptr<MapType> map) {
  if (map->type != "PointMap") {
    throw std::runtime_error("Improper Map Type, Expected \"PointMap\"");
  }
  objects = static_cast<const PointMap*>(map.get())->entities;
}

void
AirplaneObstacleSet::configure(const VIPRA::ConfigMap& configMap) {
  configurationMap = configMap;
}

void
AirplaneObstacleSet::addObjects(const std::string& type, const std::vector<VIPRA::f3d>& locations) {
  this->objects[type] = locations;
  for (unsigned int i = 0; i < objectTypes.size(); i++) {
    if (objectTypes.at(i) == type)
      return;
  }
  objectTypes.push_back(type);
}

void
AirplaneObstacleSet::setObstacleCoords(const std::vector<VIPRA::f3d>& coordinates) {
  this->objects["obstacles"] = coordinates;
}

int
AirplaneObstacleSet::getNumObstacles() const noexcept {
  return this->objects.at("obstacles").size();
}

const std::vector<VIPRA::f3d>&
AirplaneObstacleSet::getObstacleCoordinates() const noexcept {
  return this->objects.at("obstacles");
}

const VIPRA::f3d
AirplaneObstacleSet::NearestObstacle(const VIPRA::f3d coordinates, const VIPRA::f3d velocity) const {
  int min_index = 0;
  for (unsigned int i = 0; i < objects.at("obstacles").size(); i++) {
    if (coordinates.distanceTo(objects.at("obstacles").at(i)) <
        coordinates.distanceTo(objects.at("obstacles")[min_index]))
      min_index = i;
  }

  return objects.at("obstacles").at(min_index);
}

const VIPRA::f3dVec
AirplaneObstacleSet::NearestObstacle(const PedestrianSet& PedSet) const {
  const VIPRA::f3dVec& coordinatesVector = PedSet.getPedestrianCoordinates();
  VIPRA::f3dVec        nearestObstacleVector;
  for (unsigned int j = 0; j < coordinatesVector.size(); j++) {
    VIPRA::f3d coordinates = coordinatesVector.at(j);
    int        min_index = 0;
    for (int i = 0; i < objects.at("obstacles").size(); i++) {
      if (coordinates.distanceTo(objects.at("obstacles").at(i)) <
          coordinates.distanceTo(objects.at("obstacles").at(min_index)))
        min_index = i;
    }
    nearestObstacleVector.push_back(objects.at("obstacles").at(min_index));
  }

  return nearestObstacleVector;
}

const std::vector<VIPRA::f3d>&
AirplaneObstacleSet::getObjectsofType(const std::string& type) const noexcept {
  return objects.at(type);
}

const std::vector<std::string>&
AirplaneObstacleSet::getObjectTypes() const noexcept {
  return objectTypes;
}

const VIPRA::f3d
AirplaneObstacleSet::getDimensions() const noexcept {
  float maxX = 0, maxY = 0, maxZ = 0;
  for (auto mapIterator : objects) {
    for (unsigned int i = 0; i < mapIterator.second.size(); i++) {
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

float
AirplaneObstacleSet::rayHit(VIPRA::f3d point1, VIPRA::f3d point2) const noexcept {

  for (unsigned int i = 0; i < objects.at("obstacles").size(); i++) {
    VIPRA::f3d coordinates = objects.at("obstacles")[i];

    if (coordinates.distanceTo(point1) + coordinates.distanceTo(point1) == point1.distanceTo(point2))
      return coordinates.distanceTo(point1);
  }

  return -1;
}