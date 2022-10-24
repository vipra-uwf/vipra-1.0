#ifndef AIRPLANE_OBSTACLE_SET
#define AIRPLANE_OBSTACLE_SET

#include "../../../VIPRA/Extendable/obstacleset/obstacle_set.hpp"

class AirplaneObstacleSet : public ObstacleSet {

 private:
  DimVector  obstacleCoordinates;
  CONFIG_MAP configurationMap;
  std::vector<std::string> objectTypes;

 public:
  void configure(const CONFIG_MAP& configMap) override;

  void addObjects(const std::string& type, const DimVector& locations) override;

  void setObstacleCoords(const DimVector& coordinates) override;
  int  getNumObstacles() const noexcept override;

  const DimVector& getObstacleCoordinates() const noexcept override;

  const DimVector& getObjectsofType(const std::string& type) const noexcept override;

  const std::vector<std::string>& getObjectTypes() const noexcept override;

  void             initialize(const ENTITY_SET& MapType) noexcept override;
  const DimVector  NearestObstacle(const PedestrianSet& PedSet) const override;
  const Dimensions NearestObstacle(const Dimensions coordinates, const Dimensions velocity) const override;

  const Dimensions      getDimensions() const noexcept override;
  const FLOATING_NUMBER rayHit(Dimensions, Dimensions) const noexcept override;
};

#endif