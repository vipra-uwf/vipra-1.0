#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include "../../Base/definitions/type_definitions.hpp"

class ObstacleSet {
 public:
  static const DimVector __empty__;

  virtual ~ObstacleSet() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;

  virtual void addObjects(const std::string& type, const DimVector& locations) = 0;
  virtual void setObstacleCoords(const DimVector& coordinates) = 0;

  virtual int              getNumObstacles() const noexcept = 0;
  virtual const DimVector& getObstacleCoordinates() const noexcept = 0;
  virtual const DimVector& getObjectsofType(const std::string& type) const noexcept = 0;

  virtual const std::vector<std::string>& getObjectTypes() const noexcept = 0;
};

#endif
