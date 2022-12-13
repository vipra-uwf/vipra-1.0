#ifndef CALM_GOALS_TESTS_HPP
#define CALM_GOALS_TESTS_HPP

#include <algorithm>

#include "../acutest/acutest.h"

#include "../../../Modules/Goals/calm_goals/calm_goals.hpp"
#include "../../../Modules/ObstacleSet/airplane_obstacle_set/airplane_obstacle_set.hpp"
#include "../MOCKS/obstacle_set/obstacle_set.mock.hpp"
#include "../MOCKS/pedestrian_set/pedestrian_set.mock.hpp"

namespace calm_goals_TESTS {

class CalmGoalsTester : public CalmGoals {
 public:
  const VIPRA::f3d& testNearestObjective(const std::string& type,
                                         const VIPRA::f3d&  point,
                                         const ObstacleSet& obsSet) {
    return nearestObjective(type, point, obsSet);
  }

  void testFindNearesetEndGoal(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
    return findNearestEndGoal(obsSet, pedSet);
  }

  void setup(size_t pedCnt) {
    currentGoals = VIPRA::f3dVec(pedCnt);
    endGoals = VIPRA::f3dVec(pedCnt);
    goalsMet = std::vector<bool>(pedCnt);
  }
};

void
testInitialize(const std::string& pathfinding) {
  CalmGoalsTester   goals;
  ObstacleSetMock   obSet;
  PedestrianSetMock pedSet;

  goals.configure(VIPRA::ConfigMap{{"endGoalType", "exits"},
                                   {"pathFinding", pathfinding},
                                   {"diagonalCost", "2.0"},
                                   {"goalRange", "0.05"}});

  goals.initialize(obSet, pedSet);

  const auto& currents = goals.getAllCurrentGoals();

  TEST_CHECK(std::all_of(
      currents.begin(), currents.end(), [&](const VIPRA::f3d& currGoal) { return currGoal.initialized; }));
}

void
goalsInitialize(void) {
  return;
  testInitialize("Astar");
  testInitialize("Disembark");
}

void
testUpdate(const std::string& pathfinding) {
  CalmGoalsTester   goals;
  ObstacleSetMock   obSet;
  PedestrianSetMock pedSet;

  goals.configure(VIPRA::ConfigMap{{"endGoalType", "exits"},
                                   {"pathFinding", pathfinding},
                                   {"diagonalCost", "2.0"},
                                   {"goalRange", "0.05"}});

  goals.initialize(obSet, pedSet);

  const auto& endGoals = goals.getAllEndGoals();
  TEST_CHECK(std::all_of(endGoals.begin(), endGoals.end(), [&](const VIPRA::f3d& endGoal) {
    return endGoal != VIPRA::f3d{0, 0, 0};
  }));

  // check that a goal is updated properly when the pedestrian reaches current goal
  const VIPRA::f3d prevGoal = goals.getCurrentGoal(10);
  pedSet.setPedestrianCoordinates(goals.getCurrentGoal(10), 10);
  goals.updatePedestrianGoals(obSet, pedSet);
  TEST_CHECK(prevGoal != goals.getCurrentGoal(10));

  // check that simulation goal is met when all pedestrians reach their goals
  const size_t pedCnt = pedSet.getNumPedestrians();
  for (size_t i = 0; i < pedCnt; ++i) {
    VIPRA::f3d currGoal = goals.getCurrentGoal(i);
    while (currGoal.initialized) {
      pedSet.setPedestrianCoordinates(currGoal, i);
      goals.updatePedestrianGoals(obSet, pedSet);
      currGoal = goals.getCurrentGoal(i);
    }
  }

  TEST_CHECK(goals.isSimulationGoalMet());
}

void
goalsUpdate(void) {
  return;
  testUpdate("Disembark");
  testUpdate("Astar");
}

void
nearestObjective(void) {
  CalmGoalsTester goals;
  ObstacleSetMock obSet;
  obSet.clear();
  obSet.addObjects("exits", {{5, 5}, {10, 10}, {1, 1}});

  TEST_CHECK((goals.testNearestObjective("exits", {1.5, 1.5}, obSet) == VIPRA::f3d{1, 1}));
  TEST_CHECK((goals.testNearestObjective("exits", {4, 3}, obSet) == VIPRA::f3d{5, 5}));
  TEST_CHECK((goals.testNearestObjective("exits", {20, 15}, obSet) == VIPRA::f3d{10, 10}));
  TEST_CHECK((goals.testNearestObjective("exits", {-3, 3}, obSet) == VIPRA::f3d{1, 1}));
}

void
findNearestEndGoal(void) {
  CalmGoalsTester   goals;
  ObstacleSetMock   obSet;
  PedestrianSetMock pedSet;
  goals.setup(3);
  goals.configure({{"endGoalType", "exits"},
                   {"pathFinding", "Disembark"},
                   {"diagonalCost", "2.0"},
                   {"goalRange", "0.05"}});
  obSet.clear();
  obSet.addObjects("exits", {{5, 5}, {10, 10}, {1, 1}});
  pedSet.clear();
  pedSet.setPedestrianCoordinates({{1.5, 1.5}, {20, 15}, {3.75, 4}});
  goals.testFindNearesetEndGoal(obSet, pedSet);

  TEST_CHECK((goals.getAllEndGoals() == VIPRA::f3dVec{{1, 1}, {10, 10}, {5, 5}}));
}

}  // namespace calm_goals_TESTS

#define calm_goals_tests                                                                                     \
  {"CALM_GOALS: Find Nearest End Goal Test", calm_goals_TESTS::findNearestEndGoal},                          \
      {"CALM_GOALS: Nearest Objective Test", calm_goals_TESTS::nearestObjective},                            \
      {"CALM_GOALS: Goals Initialize Test", calm_goals_TESTS::goalsInitialize}, {                            \
    "CALM_GOALS: Goals Update Test", calm_goals_TESTS::goalsUpdate                                           \
  }

#endif  //CALM_GOALS_TESTS_HPP