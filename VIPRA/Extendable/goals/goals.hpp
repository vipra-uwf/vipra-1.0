#ifndef GOALS_HPP
#define GOALS_HPP

#include "../../Base/definitions/type_definitions.hpp"

#include "../obstacleset/obstacle_set.hpp"
#include "../pedestrianset/pedestrian_set.hpp"

class Goals {
 public:
  static const Dimensions __empty__;

  virtual ~Goals() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;
  virtual void initialize(const ObstacleSet&, const PedestrianSet&) = 0;

  virtual void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&) = 0;

  virtual const Dimensions& getCurrentGoal(size_t index) const = 0;
  virtual const Dimensions& getEndGoal(size_t index) const = 0;

  virtual const DimVector& getAllCurrentGoals() const noexcept = 0;
  virtual const DimVector& getAllEndGoals() const noexcept = 0;

  virtual bool isPedestianGoalMet(size_t) const = 0;
  virtual bool isSimulationGoalMet() const noexcept = 0;
};

#endif
