#include "airplane_obstacle_set.hpp"

void
AirplaneObstacleSet::initialize(const std::unique_ptr<MapType> map) {
  if (map->type != "PointMap") {
    throw std::runtime_error("Improper Map Type, Expected \"PointMap\"");
  }
  objects = static_cast<const PointMap*>(map.get())->entities;
}

void
AirplaneObstacleSet::configure(const CONFIG_MAP& configMap) {
  configurationMap = configMap;
}

void
AirplaneObstacleSet::addObjects(const std::string& type, const std::vector<Dimensions>& locations) {
  this->objects[type] = locations;
  for (int i = 0; i < objectTypes.size(); i++) {
    if (objectTypes.at(i) == type)
      return;
  }
  objectTypes.push_back(type);
}

void
AirplaneObstacleSet::setObstacleCoords(const std::vector<Dimensions>& coordinates) {
  this->objects["obstacles"] = coordinates;
}

int
AirplaneObstacleSet::getNumObstacles() const noexcept {
  return this->objects.at("obstacles").size();
}

const std::vector<Dimensions>&
AirplaneObstacleSet::getObstacleCoordinates() const noexcept {
  return this->objects.at("obstacles");
}

const Dimensions
AirplaneObstacleSet::NearestObstacle(const Dimensions coordinates, const Dimensions velocity) const {
  int min_index = 0;
  for (int i = 0; i < objects.at("obstacles").size(); i++) {
    if (coordinates.distanceTo(objects.at("obstacles").at(i)) <
        coordinates.distanceTo(objects.at("obstacles")[min_index]))
      min_index = i;
  }

  return objects.at("obstacles").at(min_index);
}

const DimVector
AirplaneObstacleSet::NearestObstacle(const PedestrianSet& PedSet) const {
  const DimVector& coordinatesVector = PedSet.getAllPedCoords();
  DimVector        nearestObstacleVector;
  for (int j = 0; j < coordinatesVector.size(); j++) {
    Dimensions coordinates = coordinatesVector.at(j);
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

const std::vector<Dimensions>&
AirplaneObstacleSet::getObjectsofType(const std::string& type) const noexcept {
  return objects.at(type);
}

const std::vector<std::string>&
AirplaneObstacleSet::getObjectTypes() const noexcept {
  return objectTypes;
}

const Dimensions
AirplaneObstacleSet::getDimensions() const noexcept {
  FLOATING_NUMBER maxX = 0, maxY = 0, maxZ = 0;
  for (auto mapIterator : objects) {
    for (int i = 0; i < mapIterator.second.size(); i++) {
      Dimensions coordinates = mapIterator.second[i];

      if (coordinates.axis[0] > maxX)
        maxX = coordinates.axis[0];
      if (coordinates.axis[1] > maxY)
        maxY = coordinates.axis[1];
      if (coordinates.axis[2] > maxZ)
        maxZ = coordinates.axis[2];
    }
  }
  Dimensions returnDimension(maxX, maxY, maxZ);

  return returnDimension;
}

const FLOATING_NUMBER
AirplaneObstacleSet::rayHit(Dimensions point1, Dimensions point2) const noexcept {
  FLOATING_NUMBER dirRatioL, dirRatioM, dirRatioN;
  dirRatioL = point2.axis[0] - point1.axis[0];
  dirRatioM = point2.axis[1] - point1.axis[1];
  dirRatioN = point2.axis[2] - point1.axis[2];

  for (int i = 0; i < objects.at("obstacles").size(); i++) {
    Dimensions coordinates = objects.at("obstacles")[i];

    FLOATING_NUMBER xRatio = (coordinates.axis[0] - point1.axis[0]) / dirRatioL;
    FLOATING_NUMBER yRatio = (coordinates.axis[1] - point1.axis[1]) / dirRatioM;
    FLOATING_NUMBER zRatio = (coordinates.axis[2] - point1.axis[2]) / dirRatioN;

    if (xRatio == yRatio && yRatio == zRatio) {
      return coordinates.distanceTo(point1);
    }
  }

  return -1;
}