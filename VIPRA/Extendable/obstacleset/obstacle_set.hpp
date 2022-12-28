#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP
#include "definitions/config_map.hpp"
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

  virtual void initialize(std::unique_ptr<MapType>) = 0;
  virtual void configure(const VIPRA::ConfigMap& configMap) = 0;

  virtual VIPRA::f3d getMapDimensions() const noexcept = 0;

  virtual const std::vector<std::string>& getObjectTypes() const noexcept = 0;
  virtual const VIPRA::f3dVec&            getObjectsofType(const std::string& type) const noexcept = 0;

  virtual VIPRA::f3dVec nearestObstacle(const PedestrianSet&) const = 0;
  virtual VIPRA::f3dVec nearestObstacleInDirection(const PedestrianSet&) const = 0;

  virtual VIPRA::f3d nearestObstacle(VIPRA::f3d) const = 0;
  virtual VIPRA::f3d nearestObstacleInDirection(const VIPRA::f3d, const VIPRA::f3d) const = 0;

  virtual bool  collision(VIPRA::f3d) const = 0;
  virtual float rayHit(VIPRA::f3d, VIPRA::f3d) const = 0;
};

#endif
