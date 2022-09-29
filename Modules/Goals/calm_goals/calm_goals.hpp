#ifndef CALM_GOALS
#define CALM_GOALS

#include <algorithm>
#include <limits>

#include "../../../VIPRA/Extendable/goals/goals.hpp"
#include "NavLines.hpp"

class CalmGoals : public Goals {

 public:
  void configure(const CONFIG_MAP& configMap) override;
  void initialize(const ObstacleSet&, const PedestrianSet&) override;

  void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&) override;

  [[nodiscard]] const Dimensions getCurrentGoal(size_t index) const override;
  [[nodiscard]] const Dimensions getEndGoal(size_t index) const override;

  [[nodiscard]] const DimVector& getAllCurrentGoals() const noexcept override;
  [[nodiscard]] const DimVector& getAllEndGoals() const noexcept override;

  [[nodiscard]] bool isPedestianGoalMet(size_t) const override;
  [[nodiscard]] bool isSimulationGoalMet() const noexcept override;

 private:
  std::string          endGoalType;
  DimVector            currentGoals;
  DimVector            endGoals;
  std::vector<bool>    goalsMet;
  std::vector<NavLine> rootLines;

  void findNearestEndGoal(const ObstacleSet&, const PedestrianSet&);
  void createNavLines(const ObstacleSet&);
};

#endif