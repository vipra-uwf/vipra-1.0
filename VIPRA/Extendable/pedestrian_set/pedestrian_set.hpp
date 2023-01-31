#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <memory>
#include <stdexcept>

#include "definitions/config_map.hpp"
#include "definitions/entitySet.hpp"
#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"
#include "pedestrian_loader/pedestrian_loader.hpp"

class PedestrianSetException : public std::runtime_error {
 public:
  PedestrianSetException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw PedestrianSetException(message); }
};

class PedestrianSet {
 public:
  virtual ~PedestrianSet() = default;

  virtual void configure(const VIPRA::Config::Map& configMap) = 0;
  virtual void initialize(std::unique_ptr<VIPRA::PedData>) = 0;

  virtual void updateState(std::shared_ptr<VIPRA::State>) = 0;

  virtual VIPRA::size          getNumPedestrians() const = 0;
  virtual const VIPRA::f3dVec& getPedestrianCoordinates() const = 0;
  virtual const VIPRA::f3dVec& getVelocities() const = 0;

  virtual VIPRA::f3d getPedCoords(VIPRA::idx) const = 0;
  virtual VIPRA::f3d getPedVelocity(VIPRA::idx) const = 0;
};

#endif
