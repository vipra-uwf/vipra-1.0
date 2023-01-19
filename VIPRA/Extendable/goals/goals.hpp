#ifndef GOALS_HPP
#define GOALS_HPP

#include "definitions/config_map.hpp"
#include "definitions/dimensions.hpp"
#include "definitions/type_definitions.hpp"
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

  virtual void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&, VIPRA::delta_t) = 0;

  virtual const VIPRA::f3d& getCurrentGoal(VIPRA::idx) const = 0;
  virtual const VIPRA::f3d& getEndGoal(VIPRA::idx) const = 0;

  virtual const VIPRA::f3dVec& getAllCurrentGoals() const = 0;
  virtual const VIPRA::f3dVec& getAllEndGoals() const = 0;

  virtual VIPRA::delta_t timeSinceLastGoal(VIPRA::idx) const = 0;

  virtual bool isPedestianGoalMet(VIPRA::idx) const = 0;
  virtual bool isSimulationGoalMet() const = 0;
};

#endif
