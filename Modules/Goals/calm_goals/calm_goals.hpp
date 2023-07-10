#ifndef CALM_GOALS
#define CALM_GOALS

#include <algorithm>
#include <limits>
#include <queue>

#include <spdlog/spdlog.h>

#include "goals/goals.hpp"
#include "pathfinding/pathfinding.hpp"

class CalmGoals : public Goals {
 public:
  void configure(const VIPRA::CONFIG::Map& configMap) override;
  void initialize(const ObstacleSet&, const PedestrianSet&) override;

  void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&,
                             VIPRA::delta_t) override;

  [[nodiscard]] VIPRA::f3d getCurrentGoal(VIPRA::idx) const override;
  [[nodiscard]] VIPRA::f3d getEndGoal(VIPRA::idx) const override;

  [[nodiscard]] const VIPRA::f3dVec& getAllCurrentGoals() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec& getAllEndGoals() const noexcept override;

  [[nodiscard]] bool isPedestianGoalMet(VIPRA::idx) const override;
  [[nodiscard]] bool isSimulationGoalMet() const noexcept override;

  [[nodiscard]] VIPRA::delta_t timeSinceLastGoal(VIPRA::idx) const override;

 private:
  float goalRange;
  float quadSize;
  float closestObs;

  std::string endGoalType;
  std::string pathingType;

  VIPRA::f3dVec currentGoals;
  VIPRA::f3dVec endGoals;

  std::vector<VIPRA::delta_t>         lastGoalTimes;
  std::vector<bool>                   goalsMet;
  CalmPath::PathingGraph              graph;
  std::vector<std::queue<VIPRA::f3d>> paths;

  void initializePaths(const PedestrianSet&, const ObstacleSet&);
  void findNearestEndGoal(const ObstacleSet&, const PedestrianSet&);
  [[nodiscard]] static std::queue<VIPRA::f3d> disembarkPath(const VIPRA::f3d&,
                                                            const ObstacleSet&);
  [[nodiscard]] static const VIPRA::f3d&      nearestObjective(const std::string&,
                                                               const VIPRA::f3d&,
                                                               const ObstacleSet&);
};

#endif