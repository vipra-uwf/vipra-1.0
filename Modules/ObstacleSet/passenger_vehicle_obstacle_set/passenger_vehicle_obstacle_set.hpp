#ifndef AIRPLANE_OBSTACLE_SET
#define AIRPLANE_OBSTACLE_SET

#include <algorithm>
#include <limits>

#include <MapLoader/Point_Map_Loader/point_map_loader.hpp>
#include <definitions/dimensions.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

/**
 * @class PassengerVehicleObstacleSet
 * @brief A class representing the obstacle set for passenger vehicles.
 *
 * This class inherits from ObstacleSet and provides functionality for initializing,
 * configuring, and querying obstacle data for passenger vehicles.
 */
class PassengerVehicleObstacleSet : public ObstacleSet {
 public:
  /**
   * @brief Initializes the PassengerVehicleObstacleSet with the given map data.
   *
   * @param map The map data.
   */
  void initialize(std::unique_ptr<VIPRA::MapData>) override;
  /**
   * @brief Configures the PassengerVehicleObstacleSet with the given configuration map.
   *
   * @param configMap The configuration map.
   */
  void configure(const VIPRA::CONFIG::Map& configMap) override;

  /**
   * @brief Gets the dimensions of the map.
   *
   * @return The map dimensions as a 3D vector.
   */
  [[nodiscard]] VIPRA::f3d getMapDimensions() const override;

  /**
   * @brief Gets the types of objects in the obstacle set.
   *
   * @return A reference to the vector of object types.
   */
  [[nodiscard]] const std::vector<std::string>& getObjectTypes() const override;
  /**
   * @brief Gets the objects of the specified type from the obstacle set.
   *
   * @param type The type of objects.
   * @return A reference to the vector of objects.
   */
  [[nodiscard]] const VIPRA::f3dVec&            getObjectsofType(const std::string& type) const override;

  /**
   * @brief Finds the nearest obstacles for each pedestrian in the PedestrianSet.
   *
   * @param PedSet The PedestrianSet.
   * @return A vector containing the nearest obstacles for each pedestrian.
   */
  [[nodiscard]] VIPRA::f3dVec nearestObstacle(const PedestrianSet&) const override;
  /**
   * @brief Finds the nearest obstacles in the direction of each pedestrian's velocity in the PedestrianSet.
   *
   * @param pedSet The PedestrianSet.
   * @return A vector containing the nearest obstacles in the direction of each pedestrian's velocity.
   */
  [[nodiscard]] VIPRA::f3dVec nearestObstacleInDirection(const PedestrianSet&) const override;
  /**
   * @brief Finds the nearest obstacle to the given coordinates.
   *
   * @param coordinates The coordinates.
   * @return The nearest obstacle.
   */
  [[nodiscard]] VIPRA::f3d    nearestObstacle(VIPRA::f3d) const override;
  /**
   * @brief Finds the nearest obstacle in the direction of the given coordinates and velocity.
   *
   * @param coordinates The coordinates.
   * @param velocity The velocity.
   * @return The nearest obstacle in the given direction.
   */
  [[nodiscard]] VIPRA::f3d    nearestObstacleInDirection(VIPRA::f3d, VIPRA::f3d) const override;

  /**
   * @brief Checks if a collision occurs at the given coordinates.
   *
   * @param coords The coordinates.
   * @return True if a collision occurs, false otherwise.
   */
  [[nodiscard]] bool  collision(VIPRA::f3d) const override;
  /**
   * @brief Performs a ray hit test between two points in the obstacle set.
   *
   * @param point1 The first point.
   * @param point2 The second point.
   * @return The distance of the hit point from point1 if a hit occurs, or -1 if no hit occurs.
   */
  [[nodiscard]] float rayHit(VIPRA::f3d, VIPRA::f3d) const override;

 private:
  VIPRA::EntitySet         objects;
  std::vector<std::string> objectTypes;

  VIPRA::f3d mapDimensions;

  float obstacleCollisionDistance;
  float obstacleCollisionDistanceSqrd;

  /**
   * @brief Checks if the required objects exist in the obstacle map.
   */
  void checkMap() const;

  /**
   * @brief Builds the quadtree data structure.
   */
  void buildQuadTree();
};

#endif