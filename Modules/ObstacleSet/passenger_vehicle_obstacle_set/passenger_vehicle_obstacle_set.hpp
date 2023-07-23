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
  void initialize(std::unique_ptr<VIPRA::MapData>) override;
  void configure(const VIPRA::CONFIG::Map& configMap) override;

  [[nodiscard]] std::pair<VIPRA::f3d, VIPRA::f3d> getMapDimensions() const override;

  [[nodiscard]] const std::vector<std::string>& getObjectTypes() const override;
  [[nodiscard]] const VIPRA::f3dVec&            getObjectsofType(
                 const std::string& type) const override;

  [[nodiscard]] VIPRA::f3dVec nearestObstacle(const PedestrianSet&) const override;
  [[nodiscard]] VIPRA::f3dVec nearestObstacleInDirection(
      const PedestrianSet&) const override;

  [[nodiscard]] VIPRA::f3d nearestObstacle(VIPRA::f3d) const override;
  [[nodiscard]] VIPRA::f3d nearestObstacleInDirection(VIPRA::f3d,
                                                      VIPRA::f3d) const override;

  [[nodiscard]] bool  collision(VIPRA::f3d) const override;
  [[nodiscard]] float rayHit(VIPRA::f3d, VIPRA::f3d) const override;

 private:
  VIPRA::EntitySet         objects;
  std::vector<std::string> objectTypes;

  std::pair<VIPRA::f3d, VIPRA::f3d> mapDimensions;

  float obstacleCollisionDistance;
  float obstacleCollisionDistanceSqrd;

  void buildQuadTree();
};

#endif