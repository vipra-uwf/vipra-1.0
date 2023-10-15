#ifndef CALM_GOALS
#define CALM_GOALS

#include <algorithm>
#include <limits>
#include <queue>

#include <spdlog/spdlog.h>

#include "goals/goals.hpp"
#include "pathfinding/pathfinding.hpp"

class CalmGoals : public VIPRA::Goals {
 public:
  void configure(const VIPRA::Config& configMap) override;
  void initialize(const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&) override;

  void updatePedestrianGoals(const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&,
                             VIPRA::delta_t) override;

  void changeEndGoal(VIPRA::idx, VIPRA::f3d, VIPRA::f3d) override;

  [[nodiscard]] const VIPRA::f3d& getCurrentGoal(VIPRA::idx) const override;
  [[nodiscard]] const VIPRA::f3d& getEndGoal(VIPRA::idx) const override;

  [[nodiscard]] const VIPRA::f3dVec& getAllCurrentGoals() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec& getAllEndGoals() const noexcept override;

  [[nodiscard]] bool isPedestianGoalMet(VIPRA::idx) const override;
  [[nodiscard]] bool isSimulationGoalMet() const noexcept override;

  [[nodiscard]] VIPRA::delta_t timeSinceLastGoal(VIPRA::idx) const override;

 private:
  float goalRange;
  float gridSize;
  float closestObs;

  std::string endGoalType;
  std::string pathingType;

  VIPRA::f3dVec currentGoals;
  VIPRA::f3dVec endGoals;

  std::vector<VIPRA::delta_t>         lastGoalTimes;
  std::vector<bool>                   goalsMet;
  CALM_PATH::PathingGraph             graph;
  std::vector<std::queue<VIPRA::f3d>> paths;

  void initializePaths(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&);
  void findNearestEndGoal(const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&);
  [[nodiscard]] static const VIPRA::f3d& nearestObjective(const std::string&,
                                                          const VIPRA::f3d&,
                                                          const VIPRA::ObstacleSet&);
};

#endif