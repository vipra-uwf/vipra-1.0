#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <definitions/config_map.hpp>
#include <definitions/type_definitions.hpp>
#include <map_loader/map_loader.hpp>

class PedestrianSet;

class ObstacleSetException : public std::runtime_error {
 public:
  explicit ObstacleSetException(const std::string& message)
      : std::runtime_error(message) {}
  static void error(const std::string& message) { throw ObstacleSetException(message); }
};

class ObstacleSet {
 public:
  virtual void initialize(std::unique_ptr<VIPRA::MapData>) = 0;
  virtual void configure(const VIPRA::CONFIG::Map& configMap) = 0;

  [[nodiscard]] virtual std::pair<VIPRA::f3d, VIPRA::f3d> getMapDimensions() const = 0;

  [[nodiscard]] virtual const std::vector<std::string>& getObjectTypes() const = 0;
  [[nodiscard]] virtual const VIPRA::f3dVec&            getObjectsofType(
                 const std::string& type) const = 0;

  [[nodiscard]] virtual VIPRA::f3dVec nearestObstacle(const PedestrianSet&) const = 0;
  [[nodiscard]] virtual VIPRA::f3dVec nearestObstacleInDirection(
      const PedestrianSet&) const = 0;

  [[nodiscard]] virtual VIPRA::f3d nearestObstacle(VIPRA::f3d) const = 0;
  [[nodiscard]] virtual VIPRA::f3d nearestObstacleInDirection(VIPRA::f3d,
                                                              VIPRA::f3d) const = 0;

  [[nodiscard]] virtual bool  collision(VIPRA::f3d) const = 0;
  [[nodiscard]] virtual float rayHit(VIPRA::f3d, VIPRA::f3d) const = 0;

  ObstacleSet(const ObstacleSet&) = default;
  ObstacleSet(ObstacleSet&&) = delete;
  ObstacleSet& operator=(const ObstacleSet&) = default;
  ObstacleSet& operator=(ObstacleSet&&) = delete;
  ObstacleSet() = default;
  virtual ~ObstacleSet() = default;
};

#endif
