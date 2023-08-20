#ifndef GOALS_HPP
#define GOALS_HPP

#include <definitions/dimensions.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include "configuration/config.hpp"
#include "definitions/type_definitions.hpp"

namespace VIPRA {
/**
 * @class GoalsException
 * @brief Custom exception class for handling errors related to Goals.
 *
 * This class is a custom exception class derived from std::runtime_error.
 * It is used to handle errors that may occur during the Goals configuration or initialization.
 */
class GoalsException : public std::runtime_error {
 public:
  /**
   * @brief Constructor for GoalsException.
   *
   * @param message The error message to be associated with the exception.
   */
  explicit GoalsException(const std::string& message) : std::runtime_error(message) {}

  /**
   * @brief Static function to throw a GoalsException with the given error message.
   *
   * @param message The error message for the exception.
   */
  static void error(const std::string& message) { throw GoalsException(message); }
};

/**
 * @class Goals
 * @brief Interface class for defining pedestrian goals in a simulation.
 *
 * This class provides an interface for defining pedestrian goals in a simulation.
 * Specific implementations of this class can define different types of goals for pedestrians,
 * such as reaching a certain destination, avoiding obstacles, etc.
 */
class Goals {
 public:
  /**
   * @brief Configure the goals using configuration parameters.
   *
   * @param configMap A map containing the configuration parameters for the goals.
   */
  virtual void configure(const VIPRA::Config& configMap) = 0;
  /**
   * @brief Initialize the goals using the obstacle and pedestrian information.
   *
   * @param obstacleSet The obstacle set in the simulation.
   * @param pedestrianSet The pedestrian set in the simulation.
   */
  virtual void initialize(const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&) = 0;
  /**
   * @brief Update pedestrian goals based on the obstacle and pedestrian information.
   *
   * @param obstacleSet The obstacle set in the simulation.
   * @param pedestrianSet The pedestrian set in the simulation.
   * @param delta_t The time delta since the last update.
   */
  virtual void updatePedestrianGoals(const VIPRA::ObstacleSet&,
                                     const VIPRA::PedestrianSet&, VIPRA::delta_t) = 0;

  /**
   * @brief Get the current goal position for a specific pedestrian.
   *
   * @param idx The index of the pedestrian.
   * @return The current goal position as a 3D vector (VIPRA::f3d).
   */
  [[nodiscard]] virtual const VIPRA::f3d& getCurrentGoal(VIPRA::idx) const = 0;
  /**
   * @brief Get the end goal position for a specific pedestrian.
   *
   * @param idx The index of the pedestrian.
   * @return The end goal position as a 3D vector (VIPRA::f3d).
   */
  [[nodiscard]] virtual const VIPRA::f3d& getEndGoal(VIPRA::idx) const = 0;

  /**
   * @brief Get all the current goal positions for all pedestrians.
   *
   * @return A vector of 3D vectors (VIPRA::f3d) representing the current goal positions.
   */
  [[nodiscard]] virtual const VIPRA::f3dVec& getAllCurrentGoals() const = 0;
  /**
   * @brief Get all the end goal positions for all pedestrians.
   *
   * @return A vector of 3D vectors (VIPRA::f3d) representing the end goal positions.
   */
  [[nodiscard]] virtual const VIPRA::f3dVec& getAllEndGoals() const = 0;

  /**
   * @brief Get the time elapsed since the last goal update for a specific pedestrian.
   *
   * @param idx The index of the pedestrian.
   * @return The time elapsed since the last goal update (VIPRA::delta_t).
   */
  [[nodiscard]] virtual VIPRA::delta_t timeSinceLastGoal(VIPRA::idx) const = 0;

  /**
   * @brief Check if the goal for a specific pedestrian is met.
   *
   * @param idx The index of the pedestrian.
   * @return True if the goal is met, false otherwise.
   */
  [[nodiscard]] virtual bool isPedestianGoalMet(VIPRA::idx) const = 0;
  /**
   * @brief Check if the simulation goal is met.
   *
   * @return True if the simulation goal is met, false otherwise.
   */
  [[nodiscard]] virtual bool isSimulationGoalMet() const = 0;

  Goals(const VIPRA::Goals&) = default;
  Goals(VIPRA::Goals&&) = delete;
  VIPRA::Goals& operator=(const VIPRA::Goals&) = default;
  VIPRA::Goals& operator=(VIPRA::Goals&&) = delete;
  Goals() = default;
  virtual ~Goals() = default;
};
}  // namespace VIPRA

#endif
