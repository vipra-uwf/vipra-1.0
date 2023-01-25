
#ifndef VIPRA_OBSTACLE_SET_MOCK_HPP
#define VIPRA_OBSTACLE_SET_MOCK_HPP

#include <functional>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

class ObstacleSetMock : public ObstacleSet {
 public:
  ~ObstacleSetMock() override {}
  MOCK_METHOD(void, initialize, (std::unique_ptr<VIPRA::MapData>), (override));
  MOCK_METHOD(void, configure, (const VIPRA::ConfigMap& configMap), (override));
  MOCK_METHOD(VIPRA::f3d, getMapDimensions, (), (const, override));
  MOCK_METHOD(const std::vector<std::string>&, getObjectTypes, (), (const, override));
  MOCK_METHOD(const VIPRA::f3dVec&, getObjectsofType, (const std::string& type), (const, override));
  MOCK_METHOD(VIPRA::f3dVec, nearestObstacle, (const PedestrianSet&), (const, override));
  MOCK_METHOD(VIPRA::f3dVec, nearestObstacleInDirection, (const PedestrianSet&), (const, override));
  MOCK_METHOD(VIPRA::f3d, nearestObstacle, (VIPRA::f3d), (const, override));
  MOCK_METHOD(VIPRA::f3d, nearestObstacleInDirection, (VIPRA::f3d, VIPRA::f3d), (const, override));
  MOCK_METHOD(bool, collision, (VIPRA::f3d), (const, override));
  MOCK_METHOD(float, rayHit, (VIPRA::f3d, VIPRA::f3d), (const, override));
};

#endif