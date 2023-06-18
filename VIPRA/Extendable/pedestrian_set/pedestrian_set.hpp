#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <functional>
#include <memory>
#include <stdexcept>

#include <definitions/config_map.hpp>
#include <definitions/entitySet.hpp>
#include <definitions/state.hpp>
#include <definitions/type_definitions.hpp>
#include <pedestrian_loader/pedestrian_loader.hpp>

class PedestrianSetException : public std::runtime_error {
 public:
  explicit PedestrianSetException(const std::string& message)
      : std::runtime_error(message) {}
  static void error(const std::string& message) { throw PedestrianSetException(message); }
};

class PedestrianSet {
 public:
  virtual void configure(const VIPRA::CONFIG::Map& configMap) = 0;
  virtual void initialize(const std::vector<VIPRA::pcoord>&) = 0;
  virtual void updateState(VIPRA::State&) = 0;

  [[nodiscard]] virtual VIPRA::size          getNumPedestrians() const = 0;
  [[nodiscard]] virtual const VIPRA::f3dVec& getCoordinates() const = 0;
  [[nodiscard]] virtual const VIPRA::f3dVec& getVelocities() const = 0;
  [[nodiscard]] virtual VIPRA::pcoord        getPedCoords(VIPRA::idx) const = 0;
  [[nodiscard]] virtual VIPRA::veloc         getPedVelocity(VIPRA::idx) const = 0;

  virtual ~PedestrianSet() = default;
  PedestrianSet() = default;
  PedestrianSet(const PedestrianSet&) = default;
  PedestrianSet(PedestrianSet&&) = default;
  PedestrianSet& operator=(const PedestrianSet&) = default;
  PedestrianSet& operator=(PedestrianSet&&) = default;
};

#endif
