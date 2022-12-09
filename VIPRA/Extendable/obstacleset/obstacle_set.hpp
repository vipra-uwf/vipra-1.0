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
  static const DimVector __empty__;

  virtual ~ObstacleSet() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;

  /**/
  virtual void             initialize(const std::unique_ptr<MapType>) = 0;
  virtual const DimVector  NearestObstacle(const PedestrianSet& PedSet) const = 0;
  virtual const Dimensions NearestObstacle(const Dimensions coordinates, const Dimensions velocity) const = 0;
  /**/

  virtual void addObjects(const std::string& type, const DimVector& locations) = 0;
  virtual void setObstacleCoords(const DimVector& coordinates) = 0;

  virtual int              getNumObstacles() const noexcept = 0;
  virtual const DimVector& getObstacleCoordinates() const noexcept = 0;
  virtual const DimVector& getObjectsofType(const std::string& type) const noexcept = 0;

  virtual const std::vector<std::string>& getObjectTypes() const noexcept = 0;

  virtual const Dimensions      getDimensions() const = 0;
  virtual const FLOATING_NUMBER rayHit(Dimensions, Dimensions) const = 0;
};

#endif
