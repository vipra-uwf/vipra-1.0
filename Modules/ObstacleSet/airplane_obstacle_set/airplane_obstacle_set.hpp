#ifndef AIRPLANE_OBSTACLE_SET
#define AIRPLANE_OBSTACLE_SET

#include "../../MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class AirplaneObstacleSet : public ObstacleSet {

 private:
  VIPRA::f3dVec            obstacleCoordinates;
  VIPRA::ConfigMap         configurationMap;
  std::vector<std::string> objectTypes;
  VIPRA::EntitySet         objects;

 public:
  void configure(const VIPRA::ConfigMap& configMap) override;

  void addObjects(const std::string& type, const VIPRA::f3dVec& locations) override;

  void setObstacleCoords(const VIPRA::f3dVec& coordinates) override;
  int  getNumObstacles() const noexcept override;

  const VIPRA::f3dVec& getObstacleCoordinates() const noexcept override;

  const VIPRA::f3dVec& getObjectsofType(const std::string& type) const noexcept override;

  const std::vector<std::string>& getObjectTypes() const noexcept override;

  void                initialize(const std::unique_ptr<MapType>) override;
  const VIPRA::f3dVec NearestObstacle(const PedestrianSet& PedSet) const override;
  const VIPRA::f3d    NearestObstacle(const VIPRA::f3d coordinates, const VIPRA::f3d velocity) const override;

  const VIPRA::f3d getDimensions() const noexcept override;
  const float      rayHit(VIPRA::f3d, VIPRA::f3d) const noexcept override;
};

#endif