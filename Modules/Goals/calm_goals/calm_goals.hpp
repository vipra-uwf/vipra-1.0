#ifndef CALM_GOALS
#define CALM_GOALS

#include <algorithm>
#include <limits>
#include <queue>

#include "../../../VIPRA/Extendable/goals/goals.hpp"

#include "adjacencyGraph.hpp"
#include "pathfinding.hpp"

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
  static constexpr FLOATING_NUMBER GOAL_RANGE = 0.05;
  std::string                      endGoalType;

  DimVector                           currentGoals;
  DimVector                           endGoals;
  std::vector<bool>                   goalsMet;
  CalmPath::Graph                     graph;
  std::vector<std::queue<Dimensions>> paths;

  void initializePaths(const PedestrianSet&);
  void findNearestEndGoal(const ObstacleSet&, const PedestrianSet&);
};

#endif