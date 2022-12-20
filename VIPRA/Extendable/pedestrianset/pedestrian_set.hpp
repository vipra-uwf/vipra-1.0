#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <memory>
#include <stdexcept>

#include "definitions/config_map.hpp"
#include "definitions/entitySet.hpp"
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
  virtual void removePedestrian(VIPRA::idx pedestrianIndex) = 0;

  virtual void updateState(std::shared_ptr<VIPRA::State>) = 0;

  virtual VIPRA::size                    getNumPedestrians() const noexcept = 0;
  virtual const VIPRA::f3dVec&           getPedestrianCoordinates() const noexcept = 0;
  virtual const VIPRA::f3dVec&           getVelocities() const noexcept = 0;
  virtual const std::vector<float>&      getSpeeds() const noexcept = 0;
  virtual const std::vector<VIPRA::uid>& getIds() const noexcept = 0;

  virtual void setNumPedestrians(VIPRA::size numPedestrians) = 0;

  virtual void setPedestrianCoordinates(const VIPRA::f3d& coords, VIPRA::idx index) = 0;
  virtual void setPedestrianCoordinates(VIPRA::f3d&& coords, VIPRA::idx index) = 0;
  virtual void setPedestrianCoordinates(VIPRA::f3dVec&& coordinates) noexcept = 0;
  virtual void setPedestrianCoordinates(const VIPRA::f3dVec& coordinates) noexcept = 0;

  virtual void setVelocity(const VIPRA::f3d& velocity, VIPRA::idx index) = 0;
  virtual void setVelocity(VIPRA::f3d&& velocity, VIPRA::idx index) = 0;
  virtual void setVelocities(const VIPRA::f3dVec& velocities) noexcept = 0;
  virtual void setVelocities(VIPRA::f3dVec&& velocities) noexcept = 0;

  virtual void setSpeeds(const std::vector<float>& speedsMetersPerSecond) noexcept = 0;
  virtual void setSpeeds(std::vector<float>&& speedsMetersPerSecond) noexcept = 0;
  virtual void setSpeed(float speed, VIPRA::idx index) = 0;

  virtual void setIds(std::vector<VIPRA::uid> ids) = 0;
};

#endif
