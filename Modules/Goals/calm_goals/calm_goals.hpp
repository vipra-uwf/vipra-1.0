#ifndef CALM_GOALS
#define CALM_GOALS

#include <algorithm>
#include <limits>
#include <queue>

#include "goals/goals.hpp"
#include "pathfinding.hpp"
#include <spdlog/spdlog.h>

class CalmGoals : public Goals {

 public:
  void configure(const VIPRA::Config::Map& configMap) override;
  void initialize(const ObstacleSet&, const PedestrianSet&) override;

  void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&, VIPRA::delta_t) override;

  [[nodiscard]] const VIPRA::f3d& getCurrentGoal(VIPRA::idx) const override;
  [[nodiscard]] const VIPRA::f3d& getEndGoal(VIPRA::idx) const override;

  [[nodiscard]] const VIPRA::f3dVec& getAllCurrentGoals() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec& getAllEndGoals() const noexcept override;

  [[nodiscard]] bool isPedestianGoalMet(VIPRA::idx) const override;
  [[nodiscard]] bool isSimulationGoalMet() const noexcept override;

  [[nodiscard]] VIPRA::delta_t timeSinceLastGoal(VIPRA::idx) const override;

 protected:
  float       goalRange;
  float       diagonalCost;
  std::string endGoalType;
  std::string pathingType;

  VIPRA::f3dVec currentGoals;
  VIPRA::f3dVec endGoals;

  std::vector<VIPRA::delta_t>         lastGoalTimes;
  std::vector<bool>                   goalsMet;
  CalmPath::Graph                     graph;
  std::vector<std::queue<VIPRA::f3d>> paths;

  void                                 initializePaths(const PedestrianSet&, const ObstacleSet&);
  void                                 findNearestEndGoal(const ObstacleSet&, const PedestrianSet&);
  [[nodiscard]] std::queue<VIPRA::f3d> disembarkPath(const VIPRA::f3d&, const ObstacleSet&);
  [[nodiscard]] const VIPRA::f3d&      nearestObjective(const std::string&, const VIPRA::f3d&, const ObstacleSet&);
};

#endif