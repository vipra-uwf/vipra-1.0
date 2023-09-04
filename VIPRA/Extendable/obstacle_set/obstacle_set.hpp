#ifndef VIPRA_OBSTACLE_SET_HPP
#define VIPRA_OBSTACLE_SET_HPP

#include "configuration/config.hpp"
#include "definitions/type_definitions.hpp"
#include "map_loader/map_loader.hpp"

namespace VIPRA {
class PedestrianSet;

/**
 * @class ObstacleSetException
 * @brief Custom exception class for handling errors related to ObstacleSet.
 *
 * This class is a custom exception class derived from std::runtime_error.
 * It is used to handle errors that may occur in the ObstacleSet class.
 */
class ObstacleSetException : public std::runtime_error {
 public:
  explicit ObstacleSetException(const std::string& message)
      : std::runtime_error(message) {}
  /**
   * @brief Static function to throw an ObstacleSetException with the given error message.
   *
   * @param message The error message for the exception.
   */
  static void error(const std::string& message) { throw ObstacleSetException(message); }
};

/**
 * @class ObstacleSet
 * @brief Interface for handling obstacles in a map.
 *
 * This class is an interface for handling obstacles in a map.
 */
class ObstacleSet {
 public:
  virtual void initialize(std::unique_ptr<VIPRA::MapData>) = 0;
  virtual void configure(const VIPRA::Config& configMap) = 0;

  [[nodiscard]] virtual std::pair<VIPRA::f3d, VIPRA::f3d> getMapDimensions() const = 0;
  [[nodiscard]] virtual const std::vector<std::string>&   getObjectTypes() const = 0;
  [[nodiscard]] virtual const VIPRA::f3dVec&              getObjectsofType(
                   const std::string& type) const = 0;
  [[nodiscard]] virtual VIPRA::f3dVec nearestObstacle(
      const VIPRA::PedestrianSet&) const = 0;
  [[nodiscard]] virtual VIPRA::f3dVec nearestObstacleInDirection(
      const VIPRA::PedestrianSet&) const = 0;

  [[nodiscard]] virtual VIPRA::f3d nearestObstacle(VIPRA::f3d) const = 0;
  [[nodiscard]] virtual VIPRA::f3d nearestObstacleInDirection(VIPRA::f3d,
                                                              VIPRA::f3d) const = 0;
  [[nodiscard]] virtual bool       collision(VIPRA::f3d) const = 0;
  [[nodiscard]] virtual float      rayHit(VIPRA::f3d, VIPRA::f3d) const = 0;

  ObstacleSet(const VIPRA::ObstacleSet&) = default;
  ObstacleSet(VIPRA::ObstacleSet&&) = delete;
  VIPRA::ObstacleSet& operator=(const VIPRA::ObstacleSet&) = default;
  VIPRA::ObstacleSet& operator=(VIPRA::ObstacleSet&&) = delete;
  ObstacleSet() = default;
  virtual ~ObstacleSet() = default;
};
}  // namespace VIPRA

#endif
