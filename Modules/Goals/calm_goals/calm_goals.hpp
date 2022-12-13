#ifndef CALM_GOALS
#define CALM_GOALS

#include <algorithm>
#include <limits>
#include <queue>

#include "goals/goals.hpp"
#include "logging/logging.hpp"
#include "pathfinding.hpp"
class CalmGoals : public Goals {

 public:
  void configure(const CONFIG_MAP& configMap) override;
  void initialize(const ObstacleSet&, const PedestrianSet&) override;

  void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&) override;

  [[nodiscard]] const Dimensions& getCurrentGoal(size_t index) const override;
  [[nodiscard]] const Dimensions& getEndGoal(size_t index) const override;

  [[nodiscard]] const DimVector& getAllCurrentGoals() const noexcept override;
  [[nodiscard]] const DimVector& getAllEndGoals() const noexcept override;

  [[nodiscard]] bool isPedestianGoalMet(size_t) const override;
  [[nodiscard]] bool isSimulationGoalMet() const noexcept override;

  void printGraph();
  void printPaths();

 protected:
  FLOATING_NUMBER goalRange;
  FLOATING_NUMBER diagonalCost;
  std::string     endGoalType;
  std::string     pathingType;

  DimVector                           currentGoals;
  DimVector                           endGoals;
  std::vector<bool>                   goalsMet;
  CalmPath::Graph                     graph;
  std::vector<std::queue<Dimensions>> paths;

  void                                 initializePaths(const PedestrianSet&, const ObstacleSet&);
  void                                 findNearestEndGoal(const ObstacleSet&, const PedestrianSet&);
  [[nodiscard]] std::queue<Dimensions> disembarkPath(const Dimensions&,
                                                     const Dimensions&,
                                                     const ObstacleSet&);
  [[nodiscard]] const Dimensions& nearestObjective(const std::string&, const Dimensions&, const ObstacleSet&);
};

#endif