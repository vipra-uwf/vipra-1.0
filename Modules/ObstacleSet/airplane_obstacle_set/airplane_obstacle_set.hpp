#ifndef AIRPLANE_OBSTACLE_SET
#define AIRPLANE_OBSTACLE_SET

#include "../../../VIPRA/Extendable/obstacleset/obstacle_set.hpp"

class AirplaneObstacleSet : public ObstacleSet {
 public:
  void configure(const CONFIG_MAP& configMap) override;

  void addObjects(const std::string&             type,
                  const std::vector<Dimensions>& locations) override;

  void setObstacleCoords(const std::vector<Dimensions>& coordinates) override;
  int  getNumObstacles() const noexcept override;

  const std::vector<Dimensions>& getObstacleCoordinates() const noexcept override;

  const std::vector<Dimensions>& getObjectsofType(
      const std::string& type) const noexcept override;

  const std::vector<std::string>& getObjectTypes() const noexcept override;

 private:
};

#endif