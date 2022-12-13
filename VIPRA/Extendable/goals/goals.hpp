#ifndef GOALS_HPP
#define GOALS_HPP

#include "definitions/dimensions.hpp"

#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class GoalsException : public std::runtime_error {
 public:
  GoalsException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw GoalsException(message); }
};

class Goals {
 public:
  virtual ~Goals() = default;

  virtual void configure(const VIPRA::ConfigMap& configMap) = 0;
  virtual void initialize(const ObstacleSet&, const PedestrianSet&) = 0;

  virtual void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&) = 0;

  virtual const VIPRA::f3d& getCurrentGoal(size_t index) const = 0;
  virtual const VIPRA::f3d& getEndGoal(size_t index) const = 0;

  virtual const VIPRA::f3dVec& getAllCurrentGoals() const noexcept = 0;
  virtual const VIPRA::f3dVec& getAllEndGoals() const noexcept = 0;

  virtual bool isPedestianGoalMet(size_t) const = 0;
  virtual bool isSimulationGoalMet() const noexcept = 0;
};

#endif
