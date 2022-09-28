#ifndef CALM_GOALS
#define CALM_GOALS

#include "../../../VIPRA/Extendable/goals/goals.hpp"

class CalmGoals : public Goals {
 public:
  void configure(const CONFIG_MAP& configMap) override;
  void initialize(const ObstacleSet&, const PedestrianSet&) override;

  void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&) override;

  const Dimensions getCurrentGoal(size_t index) const override;
  const Dimensions getEndGoal(size_t index) const override;

  const DimVector& getAllCurrentGoals() const noexcept override;
  const DimVector& getAllEndGoals() const noexcept override;

  bool isPedestianGoalMet(size_t) const override;
  bool isSimulationGoalMet() const noexcept override;

 private:
};

#endif