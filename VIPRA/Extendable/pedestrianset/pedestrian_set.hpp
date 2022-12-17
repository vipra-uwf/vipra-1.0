#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <memory>
#include <stdexcept>

#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"

class PedestrianSetException : public std::runtime_error {
 public:
  PedestrianSetException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw PedestrianSetException(message); }
};

class PedestrianSet {
 public:
  virtual ~PedestrianSet() = default;

  virtual void configure(const VIPRA::ConfigMap& configMap) = 0;
  virtual void initialize(VIPRA::EntitySet pedestrianCount) = 0;
  virtual void removePedestrian(size_t pedestrianIndex) = 0;

  virtual void updateState(std::shared_ptr<VIPRA::State>) = 0;

  virtual size_t                    getNumPedestrians() const noexcept = 0;
  virtual const VIPRA::f3dVec&      getPedestrianCoordinates() const noexcept = 0;
  virtual const VIPRA::f3dVec&      getVelocities() const noexcept = 0;
  virtual const std::vector<float>& getSpeeds() const noexcept = 0;
  virtual const std::vector<int>&   getIds() const noexcept = 0;

  virtual void setNumPedestrians(int numPedestrians) = 0;

  virtual void setPedestrianCoordinates(const VIPRA::f3d& coords, size_t index) = 0;
  virtual void setPedestrianCoordinates(VIPRA::f3d&& coords, size_t index) = 0;
  virtual void setPedestrianCoordinates(VIPRA::f3dVec&& coordinates) noexcept = 0;
  virtual void setPedestrianCoordinates(const VIPRA::f3dVec& coordinates) noexcept = 0;

  virtual void setVelocity(const VIPRA::f3d& velocity, size_t index) = 0;
  virtual void setVelocity(VIPRA::f3d&& velocity, size_t index) = 0;
  virtual void setVelocities(const VIPRA::f3dVec& velocities) noexcept = 0;
  virtual void setVelocities(VIPRA::f3dVec&& velocities) noexcept = 0;

  virtual void setSpeeds(const std::vector<float>& speedsMetersPerSecond) noexcept = 0;
  virtual void setSpeeds(std::vector<float>&& speedsMetersPerSecond) noexcept = 0;
  virtual void setSpeed(float speed, size_t index) = 0;

  virtual void setIds(std::vector<int> ids) = 0;
};

#endif
