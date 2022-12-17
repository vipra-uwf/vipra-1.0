#ifndef CALM_GOALS
#define CALM_GOALS

#include <algorithm>
#include <limits>
#include <queue>

#include "definitions/dimensions.hpp"
#include "goals/goals.hpp"
#include "logging/logging.hpp"
#include "pathfinding.hpp"
class CalmGoals : public Goals {

 public:
  void configure(const VIPRA::ConfigMap& configMap) override;
  void initialize(const ObstacleSet&, const PedestrianSet&) override;

  void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&) override;

  [[nodiscard]] const VIPRA::f3d& getCurrentGoal(size_t index) const override;
  [[nodiscard]] const VIPRA::f3d& getEndGoal(size_t index) const override;

  [[nodiscard]] const VIPRA::f3dVec& getAllCurrentGoals() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec& getAllEndGoals() const noexcept override;

  [[nodiscard]] bool isPedestianGoalMet(size_t) const override;
  [[nodiscard]] bool isSimulationGoalMet() const noexcept override;

 protected:
  float       goalRange;
  float       diagonalCost;
  std::string endGoalType;
  std::string pathingType;

  VIPRA::f3dVec                       currentGoals;
  VIPRA::f3dVec                       endGoals;
  std::vector<bool>                   goalsMet;
  CalmPath::Graph                     graph;
  std::vector<std::queue<VIPRA::f3d>> paths;

  void                                 initializePaths(const PedestrianSet&, const ObstacleSet&);
  void                                 findNearestEndGoal(const ObstacleSet&, const PedestrianSet&);
  [[nodiscard]] std::queue<VIPRA::f3d> disembarkPath(const VIPRA::f3d&,
                                                     const VIPRA::f3d&,
                                                     const ObstacleSet&);
  [[nodiscard]] const VIPRA::f3d& nearestObjective(const std::string&, const VIPRA::f3d&, const ObstacleSet&);
};

#endif