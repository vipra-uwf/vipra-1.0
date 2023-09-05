#ifndef VIPRA_PEDESTRIAN_SET_HPP
#define VIPRA_PEDESTRIAN_SET_HPP

#include <stdexcept>

#include "configuration/config.hpp"
#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"
#include "obstacle_set/obstacle_set.hpp"

namespace VIPRA {
class ObstacleSet;

/**
 * @class PedestrianSetException
 * @brief Custom exception class for handling errors related to PedestrianSet.
 *
 * This class is a custom exception class derived from std::runtime_error.
 * It is used to handle errors that may occur in the PedestrianSet class.
 */
class PedestrianSetException : public std::runtime_error {
 public:
  /**
   * @brief Constructor for PedestrianSetException.
   *
   * @param message The error message to be associated with the exception.
   */
  explicit PedestrianSetException(const std::string& message)
      : std::runtime_error(message) {}
  /**
   * @brief Static function to throw a PedestrianSetException with the given error message.
   *
   * @param message The error message for the exception.
   */
  static void error(const std::string& message) { throw PedestrianSetException(message); }
};

/**
 * @class PedestrianSet
 * @brief Interface for managing pedestrian information in a simulation.
 *
 * This class is an interface for managing pedestrian information in a simulation.
 */
class PedestrianSet {
 public:
  virtual void configure(const VIPRA::Config& configMap) = 0;
  virtual void initialize(const std::vector<VIPRA::pcoord>&) = 0;

  virtual void updateState(VIPRA::State&) = 0;

  [[nodiscard]] virtual VIPRA::size          getNumPedestrians() const = 0;
  [[nodiscard]] virtual const VIPRA::f3dVec& getCoordinates() const = 0;
  [[nodiscard]] virtual const VIPRA::f3dVec& getVelocities() const = 0;
  [[nodiscard]] virtual const VIPRA::pcoord& getPedCoords(VIPRA::idx) const = 0;
  [[nodiscard]] virtual const VIPRA::veloc&  getPedVelocity(VIPRA::idx) const = 0;
  [[nodiscard]] virtual std::pair<VIPRA::f3d, VIPRA::idx> getNearestPedestrian(
      VIPRA::idx, const VIPRA::ObstacleSet&) const = 0;

  virtual ~PedestrianSet() = default;
  PedestrianSet() = default;
  PedestrianSet(const VIPRA::PedestrianSet&) = default;
  PedestrianSet(VIPRA::PedestrianSet&&) = default;
  VIPRA::PedestrianSet& operator=(const VIPRA::PedestrianSet&) = default;
  VIPRA::PedestrianSet& operator=(VIPRA::PedestrianSet&&) = default;
};
}  // namespace VIPRA

#endif
