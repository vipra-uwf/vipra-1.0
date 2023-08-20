#ifndef VIPRA_PEDSTRIAN_SET_MOCK_HPP
#define VIPRA_PEDSTRIAN_SET_MOCK_HPP

#include <gmock/gmock.h>

#include "pedestrian_set/pedestrian_set.hpp"

class PedestrianSetMock : public PedestrianSet {
 public:
  PedestrianSetMock() = default;
  MOCK_METHOD(void, configure, (const VIPRA::Config&), (override));
  MOCK_METHOD(void, initialize, (const std::vector<VIPRA::pcoord>&), (override));
  MOCK_METHOD(void, updateState, (VIPRA::State&), (override));
  MOCK_METHOD(VIPRA::size, getNumPedestrians, (), (const, override));
  MOCK_METHOD(VIPRA::f3dVec&, getCoordinates, (), (const, override));
  MOCK_METHOD(VIPRA::f3dVec&, getVelocities, (), (const, override));
  MOCK_METHOD(const VIPRA::f3d&, getPedCoords, (VIPRA::idx), (const, override));
  MOCK_METHOD(const VIPRA::f3d&, getPedVelocity, (VIPRA::idx), (const, override));
  MOCK_METHOD((std::pair<VIPRA::f3d, VIPRA::idx>), getNearestPedestrian,
              (VIPRA::idx, const VIPRA::ObstacleSet&), (const, override));
};

#endif