#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <definitions/config_map.hpp>
#include <definitions/type_definitions.hpp>
#include <map_loader/map_loader.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

/**
 * @class ObstacleSetException
 * @brief Custom exception class for handling errors related to ObstacleSet.
 *
 * This class is a custom exception class derived from std::runtime_error.
 * It is used to handle errors that may occur in the ObstacleSet class.
 */
class ObstacleSetException : public std::runtime_error {
 public:
  /**
   * @brief Constructor for ObstacleSetException.
   *
   * @param message The error message to be associated with the exception.
   */
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
  /**
   * @brief Initialize the ObstacleSet with the given map data.
   *
   * @param map A unique pointer to MapData representing the map data.
   */
  virtual void initialize(std::unique_ptr<VIPRA::MapData>) = 0;
  /**
   * @brief Configure the ObstacleSet with the given configuration map.
   *
   * @param configMap The configuration map containing settings for the ObstacleSet.
   */
  virtual void configure(const VIPRA::CONFIG::Map& configMap) = 0;

  /**
   * @brief Get the dimensions of the map.
   *
   * @return The dimensions of the map as a 3D vector.
   */
  [[nodiscard]] virtual VIPRA::f3d getMapDimensions() const = 0;

  /**
   * @brief Get the types of objects in the obstacle set.
   *
   * @return A vector of strings representing the types of objects in the obstacle set.
   */
  [[nodiscard]] virtual const std::vector<std::string>& getObjectTypes() const = 0;
  /**
   * @brief Get the objects of the specified type in the obstacle set.
   *
   * @param type The type of objects to retrieve.
   * @return A vector of 3D vectors for coordinates of the objects of the specified type in the obstacle set.
   */
  [[nodiscard]] virtual const VIPRA::f3dVec&            getObjectsofType(
                 const std::string& type) const = 0;

  /**
   * @brief Get the nearest obstacles to each pedestrian.
   *
   * @param pedSet The PedestrianSet containing pedestrian information.
   * @return A vector of 3D vectors for coordinates of the nearest obstacles to each pedestrian.
   */
  [[nodiscard]] virtual VIPRA::f3dVec nearestObstacle(const PedestrianSet&) const = 0;
  /**
   * @brief Get the nearest obstacles in the specified direction to each pedestrian.
   *
   * @param pedSet The PedestrianSet containing pedestrian information.
   * @return A vector of 3D vectors for coordinates of the nearest obstacles in the specified direction to each pedestrian.
   */
  [[nodiscard]] virtual VIPRA::f3dVec nearestObstacleInDirection(
      const PedestrianSet&) const = 0;

  /**
   * @brief Get the nearest obstacle to the specified point.
   *
   * @param point The 3D vector representing the point to find the nearest obstacle to.
   * @return A 3D vector with coordinates of the nearest obstacle to the specified point.
   */
  [[nodiscard]] virtual VIPRA::f3d nearestObstacle(VIPRA::f3d) const = 0;
  /**
   * @brief Get the nearest obstacle in the specified direction to the specified point.
   *
   * @param point The 3D vector representing the starting point.
   * @param direction The 3D vector representing the direction.
   * @return A 3D vector of coordinates of the nearest obstacle in the specified direction to the specified point.
   */
  [[nodiscard]] virtual VIPRA::f3d nearestObstacleInDirection(VIPRA::f3d,
                                                              VIPRA::f3d) const = 0;

  /**
   * @brief Check if there is a collision at the specified point.
   *
   * @param point The 3D vector representing the point to check for collision.
   * @return True if there is a collision at the specified point, false otherwise.
   */
  [[nodiscard]] virtual bool  collision(VIPRA::f3d) const = 0;
  /**
   * @brief Compute the distance to the nearest obstacle along the specified ray.
   *
   * @param origin The origin point of the ray.
   * @param direction The direction of the ray.
   * @return The distance to the nearest obstacle along the ray.
   */
  [[nodiscard]] virtual float rayHit(VIPRA::f3d, VIPRA::f3d) const = 0;

  ObstacleSet(const ObstacleSet&) = default;
  ObstacleSet(ObstacleSet&&) = delete;
  ObstacleSet& operator=(const ObstacleSet&) = default;
  ObstacleSet& operator=(ObstacleSet&&) = delete;
  ObstacleSet() = default;
  virtual ~ObstacleSet() = default;
};

#endif
