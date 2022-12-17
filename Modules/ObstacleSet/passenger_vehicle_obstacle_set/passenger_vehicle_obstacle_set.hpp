#ifndef AIRPLANE_OBSTACLE_SET
#define AIRPLANE_OBSTACLE_SET

#include "MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "definitions/dimensions.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"


class PassengerVehicleObstacleSet : public ObstacleSet {

 private:
  VIPRA::EntitySet         objects;
  std::vector<std::string> objectTypes;

  VIPRA::f3d mapDimensions;

 public:
  void initialize(const std::unique_ptr<MapType>) override;
  void configure(const VIPRA::ConfigMap& configMap) override;

  VIPRA::f3d getMapDimensions() const noexcept override;

  const VIPRA::f3dVec&            getObjectsofType(const std::string& type) const noexcept override;
  const std::vector<std::string>& getObjectTypes() const noexcept override;

  VIPRA::f3dVec nearestObstacle(const PedestrianSet& PedSet) const override;
  VIPRA::f3dVec nearestObstacleInDirection(const PedestrianSet&) const override;

  VIPRA::f3d nearestObstacle(const VIPRA::f3d coordinates) const override;
  VIPRA::f3d nearestObstacleInDirection(const VIPRA::f3d coordinates,
                                        const VIPRA::f3d velocity) const override;

  float rayHit(VIPRA::f3d, VIPRA::f3d) const noexcept override;

 private:
  void checkMap() const;
};

#endif