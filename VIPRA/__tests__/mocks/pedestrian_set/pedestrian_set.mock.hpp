#ifndef VIPRA_PEDSTRIAN_SET_MOCK_HPP
#define VIPRA_PEDSTRIAN_SET_MOCK_HPP

#include <gmock/gmock.h>

#include "pedestrian_set/pedestrian_set.hpp"

class PedestrianSetMock : public PedestrianSet {
 public:
  PedestrianSetMock() = default;
  MOCK_METHOD(void, configure, (const VIPRA::ConfigMap&), (override));
  MOCK_METHOD(void, initialize, (std::unique_ptr<VIPRA::PedData>), (override));
  MOCK_METHOD(void, updateState, (std::shared_ptr<VIPRA::State>), (override));
  MOCK_METHOD(VIPRA::size, getNumPedestrians, (), (const, override));
  MOCK_METHOD(VIPRA::f3dVec&, getPedestrianCoordinates, (), (const, override));
  MOCK_METHOD(VIPRA::f3dVec&, getVelocities, (), (const, override));
};

#endif