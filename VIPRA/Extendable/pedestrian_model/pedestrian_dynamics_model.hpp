#ifndef PEDESTRIAN_DYNAMICS_MODEL_HPP
#define PEDESTRIAN_DYNAMICS_MODEL_HPP

#include <memory>
#include <stdexcept>

#include <definitions/config_map.hpp>
#include <definitions/state.hpp>
#include <definitions/type_definitions.hpp>

#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

/**
 * @class PedDynamicsException
 * @brief Custom exception class for handling errors related to PedestrianDynamicsModel.
 *
 * This class is a custom exception class derived from std::runtime_error.
 * It is used to handle errors that may occur in the PedestrianDynamicsModel class.
 */
class PedDynamicsException : public std::runtime_error {
 public:
  /**
   * @brief Constructor for PedDynamicsException.
   *
   * @param message The error message to be associated with the exception.
   */
  explicit PedDynamicsException(const std::string& message)
      : std::runtime_error(message) {}
  /**
   * @brief Static function to throw a PedDynamicsException with the given error message.
   *
   * @param message The error message for the exception.
   */
  static void error(const std::string& message) { throw PedDynamicsException(message); }
};

/**
 * @class PedestrianDynamicsModel
 * @brief Interface for modeling pedestrian dynamics.
 *
 * This class is an interface for modeling pedestrian dynamics.
 */
class PedestrianDynamicsModel {
 public:
  /**
   * @brief Configure the PedestrianDynamicsModel with the given configuration map.
   *
   * @param configMap The configuration map containing settings for the PedestrianDynamicsModel.
   */
  virtual void configure(const VIPRA::CONFIG::Map& configMap) = 0;
  /**
   * @brief Initialize the PedestrianDynamicsModel with the given sets and goals.
   *
   * @param pedSet The PedestrianSet to be used for modeling.
   * @param obsSet The ObstacleSet to be used for modeling.
   * @param goals The Goals to be used for modeling.
   */
  virtual void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) = 0;
  /**
   * @brief Perform a timestep of the pedestrian dynamics model.
   *
   * @param pedSet The PedestrianSet used for the current timestep.
   * @param obsSet The ObstacleSet used for the current timestep.
   * @param goals The Goals used for the current timestep.
   * @param deltaT The time step duration.
   * @param tStep The current simulation time step.
   * @return The updated State after the timestep.
   */
  virtual VIPRA::State& timestep(const PedestrianSet&, const ObstacleSet&, const Goals&,
                                 VIPRA::delta_t, VIPRA::t_step) = 0;

  PedestrianDynamicsModel(const PedestrianDynamicsModel&) = default;
  PedestrianDynamicsModel(PedestrianDynamicsModel&&) = delete;
  PedestrianDynamicsModel& operator=(const PedestrianDynamicsModel&) = default;
  PedestrianDynamicsModel& operator=(PedestrianDynamicsModel&&) = delete;
  PedestrianDynamicsModel() = default;
  virtual ~PedestrianDynamicsModel() = default;
};

#endif
