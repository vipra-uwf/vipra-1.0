#ifndef GOALS_HPP
#define GOALS_HPP

#include <definitions/config_map.hpp>
#include <definitions/dimensions.hpp>
#include <definitions/type_definitions.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

class GoalsException : public std::runtime_error {
 public:
  explicit GoalsException(const std::string& message) : std::runtime_error(message) {}
  static void error(const std::string& message) { throw GoalsException(message); }
};

class Goals {
 public:
  virtual void configure(const VIPRA::CONFIG::Map& configMap) = 0;
  virtual void initialize(const ObstacleSet&, const PedestrianSet&) = 0;
  virtual void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&,
                                     VIPRA::delta_t) = 0;

  [[nodiscard]] virtual const VIPRA::f3d& getCurrentGoal(VIPRA::idx) const = 0;
  [[nodiscard]] virtual const VIPRA::f3d& getEndGoal(VIPRA::idx) const = 0;

  [[nodiscard]] virtual const VIPRA::f3dVec& getAllCurrentGoals() const = 0;
  [[nodiscard]] virtual const VIPRA::f3dVec& getAllEndGoals() const = 0;

  [[nodiscard]] virtual VIPRA::delta_t timeSinceLastGoal(VIPRA::idx) const = 0;

  [[nodiscard]] virtual bool isPedestianGoalMet(VIPRA::idx) const = 0;
  [[nodiscard]] virtual bool isSimulationGoalMet() const = 0;

  Goals(const Goals&) = default;
  Goals(Goals&&) = delete;
  Goals& operator=(const Goals&) = default;
  Goals& operator=(Goals&&) = delete;
  Goals() = default;
  virtual ~Goals() = default;
};

#endif
