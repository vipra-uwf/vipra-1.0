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
  /**
   * @brief Configure the PedestrianSet with the given configuration map.
   *
   * @param configMap The configuration map containing settings for the PedestrianSet.
   */
  virtual void configure(const VIPRA::CONFIG::Map& configMap) = 0;
  /**
   * @brief Initialize the PedestrianSet with the given pedestrian coordinates.
   *
   * @param pedCoords The vector of pedestrian coordinates.
   */
  virtual void initialize(const std::vector<VIPRA::pcoord>&) = 0;
  /**
   * @brief Update the state of the pedestrian set.
   *
   * @param state The current simulation state.
   */
  virtual void updateState(VIPRA::State&) = 0;

  /**
   * @brief Get the number of pedestrians in the set.
   *
   * @return The number of pedestrians in the set.
   */
  [[nodiscard]] virtual VIPRA::size          getNumPedestrians() const = 0;
  /**
   * @brief Get the vector of pedestrian coordinates.
   *
   * @return The vector of pedestrian coordinates.
   */
  [[nodiscard]] virtual const VIPRA::f3dVec& getCoordinates() const = 0;
  /**
   * @brief Get the vector of pedestrian velocities.
   *
   * @return The vector of pedestrian velocities.
   */
  [[nodiscard]] virtual const VIPRA::f3dVec& getVelocities() const = 0;
  /**
   * @brief Get the coordinates of a specific pedestrian.
   *
   * @param index The index of the pedestrian.
   * @return The coordinates of the pedestrian at the specified index.
   */
  [[nodiscard]] virtual const VIPRA::pcoord& getPedCoords(VIPRA::idx) const = 0;
  /**
   * @brief Get the velocity of a specific pedestrian.
   *
   * @param index The index of the pedestrian.
   * @return The velocity of the pedestrian at the specified index.
   */
  [[nodiscard]] virtual const VIPRA::veloc&  getPedVelocity(VIPRA::idx) const = 0;

  /**
   * @brief Get the nearest pedestrian to the pedestrian at the specified index.
   *
   * @param pedIdx The index of the pedestrian.
   * @return A pair containing the coordinates and index of the nearest pedestrian.
   */
  [[nodiscard]] virtual std::pair<VIPRA::f3d, VIPRA::idx> getNearestPedestrian(
      VIPRA::idx) const = 0;

  virtual ~PedestrianSet() = default;
  PedestrianSet() = default;
  PedestrianSet(const PedestrianSet&) = default;
  PedestrianSet(PedestrianSet&&) = default;
  PedestrianSet& operator=(const PedestrianSet&) = default;
  PedestrianSet& operator=(PedestrianSet&&) = default;
};

#endif
