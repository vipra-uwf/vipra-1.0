#ifndef VIPRA_GOALS_HPP
#define VIPRA_GOALS_HPP

#include "configuration/config.hpp"
#include "definitions/dimensions.hpp"
#include "definitions/type_definitions.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

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
  explicit GoalsException(const std::string& message) : std::runtime_error(message) {}

  /**
   * @brief Throws a GoalsException with the given error message.
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
  virtual void configure(const VIPRA::Config& configMap) = 0;
  virtual void initialize(const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&) = 0;

  virtual void updatePedestrianGoals(const VIPRA::ObstacleSet&,
                                     const VIPRA::PedestrianSet&, VIPRA::delta_t) = 0;

  virtual void changeEndGoal(VIPRA::idx, VIPRA::f3d, VIPRA::f3d) = 0;

  [[nodiscard]] virtual const VIPRA::f3d&    getCurrentGoal(VIPRA::idx) const = 0;
  [[nodiscard]] virtual const VIPRA::f3d&    getEndGoal(VIPRA::idx) const = 0;
  [[nodiscard]] virtual const VIPRA::f3dVec& getAllCurrentGoals() const = 0;
  [[nodiscard]] virtual const VIPRA::f3dVec& getAllEndGoals() const = 0;
  [[nodiscard]] virtual VIPRA::delta_t       timeSinceLastGoal(VIPRA::idx) const = 0;
  [[nodiscard]] virtual bool                 isPedestianGoalMet(VIPRA::idx) const = 0;
  [[nodiscard]] virtual bool                 isSimulationGoalMet() const = 0;

  Goals(const VIPRA::Goals&) = default;
  Goals(VIPRA::Goals&&) = delete;
  VIPRA::Goals& operator=(const VIPRA::Goals&) = default;
  VIPRA::Goals& operator=(VIPRA::Goals&&) = delete;
  Goals() = default;
  virtual ~Goals() = default;
};
}  // namespace VIPRA

#endif
