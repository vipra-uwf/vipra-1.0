
#ifndef VIPRA_OBSTACLE_SET_MOCK_HPP
#define VIPRA_OBSTACLE_SET_MOCK_HPP

#include <gmock/gmock.h>

#include "obstacleset/obstacle_set.hpp"

class ObstacleSetMock : public ObstacleSet {
 public:
  MOCK_METHOD(void, configure, (const VIPRA::ConfigMap& configMap), (override));
  MOCK_METHOD(void, initialize, (const std::unique_ptr<MapType>), (override));
  MOCK_METHOD(const VIPRA::f3dVec, NearestObstacle, (const PedestrianSet& PedSet), (const, override));
  MOCK_METHOD(const VIPRA::f3d,
              NearestObstacle,
              (const VIPRA::f3d coordinates, const VIPRA::f3d velocity),
              (const, override));
  MOCK_METHOD(void, addObjects, (const std::string& type, const VIPRA::f3dVec& locations), (override));
  MOCK_METHOD(void, setObstacleCoords, (const VIPRA::f3dVec& coordinates), (override));
  MOCK_METHOD(int, getNumObstacles, (), (const noexcept override));
  MOCK_METHOD(const VIPRA::f3dVec&, getObstacleCoordinates, (), (const noexcept override));
  MOCK_METHOD(const VIPRA::f3dVec&, getObjectsofType, (const std::string& type), (const noexcept override));
  MOCK_METHOD(const std::vector<std::string>&, getObjectTypes, (), (const noexcept override));
  MOCK_METHOD(const VIPRA::f3d, getDimensions, (), (const, override));
  MOCK_METHOD(float, rayHit, (VIPRA::f3d, VIPRA::f3d), (const, override));
};

#endif