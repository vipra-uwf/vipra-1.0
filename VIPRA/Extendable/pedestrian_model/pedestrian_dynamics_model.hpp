#ifndef PEDESTRIAN_DYNAMICS_MODEL_HPP
#define PEDESTRIAN_DYNAMICS_MODEL_HPP

#include <memory>
#include <stdexcept>

#include "configuration/config.hpp"
#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"

#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

namespace VIPRA {
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
  virtual void configure(const VIPRA::Config& configMap) = 0;
  virtual void initialize(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&,
                          const VIPRA::Goals&) = 0;
  virtual void timestep(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&,
                        const VIPRA::Goals&, VIPRA::State&, VIPRA::delta_t,
                        VIPRA::t_step) = 0;

  PedestrianDynamicsModel(const PedestrianDynamicsModel&) = default;
  PedestrianDynamicsModel(PedestrianDynamicsModel&&) = delete;
  PedestrianDynamicsModel& operator=(const PedestrianDynamicsModel&) = default;
  PedestrianDynamicsModel& operator=(PedestrianDynamicsModel&&) = delete;
  PedestrianDynamicsModel() = default;
  virtual ~PedestrianDynamicsModel() = default;
};
}  // namespace VIPRA

#endif
