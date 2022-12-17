#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include "definitions/type_definitions.hpp"
#include "maploader/map_loader.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class ObstacleSetException : public std::runtime_error {
 public:
  ObstacleSetException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw ObstacleSetException(message); }
};

class ObstacleSet {
 public:
  static const VIPRA::f3dVec __empty__;

  virtual ~ObstacleSet() = default;

  virtual void configure(const VIPRA::ConfigMap& configMap) = 0;

  /**/
  virtual void                initialize(const std::unique_ptr<MapType>) = 0;
  virtual const VIPRA::f3dVec NearestObstacle(const PedestrianSet& PedSet) const = 0;
  virtual const VIPRA::f3d NearestObstacle(const VIPRA::f3d coordinates, const VIPRA::f3d velocity) const = 0;
  /**/

  virtual void addObjects(const std::string& type, const VIPRA::f3dVec& locations) = 0;
  virtual void setObstacleCoords(const VIPRA::f3dVec& coordinates) = 0;

  virtual int                  getNumObstacles() const noexcept = 0;
  virtual const VIPRA::f3dVec& getObstacleCoordinates() const noexcept = 0;
  virtual const VIPRA::f3dVec& getObjectsofType(const std::string& type) const noexcept = 0;

  virtual const std::vector<std::string>& getObjectTypes() const noexcept = 0;

  virtual const VIPRA::f3d getDimensions() const = 0;
  virtual float            rayHit(VIPRA::f3d, VIPRA::f3d) const = 0;
};

#endif
