#ifndef VIPRA_PEDSTRIAN_SET_MOCK_HPP
#define VIPRA_PEDSTRIAN_SET_MOCK_HPP

#include <gmock/gmock.h>

#include "definitions/dimensions.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class PedestrianSetMock : public PedestrianSet {
 public:
  MOCK_METHOD(void, configure, (const VIPRA::ConfigMap& configMap), (override));
  MOCK_METHOD(void, initialize, (VIPRA::EntitySet pedestrianCount), (override));
  MOCK_METHOD(void, removePedestrian, (size_t pedestrianIndex), (override));
  MOCK_METHOD(void, updateState, (std::shared_ptr<VIPRA::State>), (override));
  MOCK_METHOD(int, getNumPedestrians, (), (const noexcept override));

  MOCK_METHOD(const VIPRA::f3dVec&, getPedestrianCoordinates, (), (const noexcept override));
  MOCK_METHOD(const VIPRA::f3dVec&, getVelocities, (), (const noexcept override));
  MOCK_METHOD(const std::vector<float>&, getSpeeds, (), (const noexcept override));
  MOCK_METHOD(const std::vector<int>&, getIds, (), (const noexcept override));

  MOCK_METHOD(void, setNumPedestrians, (int numPedestrians), (override));

  MOCK_METHOD(void, setPedestrianCoordinates, (const VIPRA::f3d& coords, size_t index), (override));
  MOCK_METHOD(void, setPedestrianCoordinates, (VIPRA::f3d && coords, size_t index), (override));
  MOCK_METHOD(void, setPedestrianCoordinates, (VIPRA::f3dVec && coordinates), (noexcept override));
  MOCK_METHOD(void, setPedestrianCoordinates, (const VIPRA::f3dVec& coordinates), (noexcept override));

  MOCK_METHOD(void, setVelocity, (const VIPRA::f3d& velocity, size_t index), (override));
  MOCK_METHOD(void, setVelocity, (VIPRA::f3d && velocity, size_t index), (override));
  MOCK_METHOD(void, setVelocities, (const VIPRA::f3dVec& velocities), (noexcept override));
  MOCK_METHOD(void, setVelocities, (VIPRA::f3dVec && velocities), (noexcept override));
  MOCK_METHOD(void, setSpeeds, (const std::vector<float>& speedsMetersPerSecond), (noexcept override));
  MOCK_METHOD(void, setSpeeds, (std::vector<float> && speedsMetersPerSecond), (noexcept override));
  MOCK_METHOD(void, setSpeed, (float speed, size_t index), (override));
  MOCK_METHOD(void, setIds, (std::vector<int> ids), (override));
};

#endif