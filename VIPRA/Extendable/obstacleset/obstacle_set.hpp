#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include "../../Base/definitions/type_definitions.hpp"
#include "../pedestrianset/pedestrian_set.hpp"

class ObstacleSet {
 public:
  static const DimVector __empty__;

  ENTITY_SET objects;
  virtual ~ObstacleSet() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;

  /**/
  virtual void initialize(const ENTITY_SET& MapType) = 0;
  virtual const DimVector& NearestObstacle(PedestrianSet PedSet) = 0;
  virtual const DimVector& NearestObstacle(const Dimensions coordinates, const Dimensions velocity) = 0;
  /**/

  virtual void addObjects(const std::string& type, const DimVector& locations) = 0;
  virtual void setObstacleCoords(const DimVector& coordinates) = 0;

  virtual int              getNumObstacles() const noexcept = 0;
  virtual const DimVector& getObstacleCoordinates() const noexcept = 0;
  virtual const DimVector& getObjectsofType(const std::string& type) const noexcept = 0;

  virtual const std::vector<std::string>& getObjectTypes() const noexcept = 0;
  
  virtual const Dimensions getDimensions() = 0;
  virtual const FLOATING_NUMBER rayHit(Dimensions, Dimensions) = 0; 

};

#endif
