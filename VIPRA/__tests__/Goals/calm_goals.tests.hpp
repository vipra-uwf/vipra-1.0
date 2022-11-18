#ifndef CALM_GOALS_TESTS_HPP
#define CALM_GOALS_TESTS_HPP

#include <algorithm>

#include "../acutest/acutest.h"

#include "../../../Modules/Goals/calm_goals/calm_goals.hpp"
#include "../../../Modules/MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "../../../Modules/ObstacleSet/airplane_obstacle_set/airplane_obstacle_set.hpp"
#include "../MOCKS/obstacle_set/obstacle_set.mock.hpp"
#include "../MOCKS/pedestrian_set/pedestrian_set.mock.hpp"

namespace calm_goals_TESTS {

void
goalsInitialize(void) {
  CalmGoals           goals;
  AirplaneObstacleSet obSet;
  PointMapLoader      loader;
  PedestrianSetMock   pedSet;

  obSet.initialize(loader.LoadMap("../../Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.json"));

  goals.configure(CONFIG_MAP{{"endGoalType", "exits"},
                             {"pathFinding", "Disembark"},
                             {"diagonalCost", "2.0"},
                             {"goalRange", "0.05"}});

  goals.initialize(obSet, pedSet);

  const auto& currents = goals.getAllCurrentGoals();

  TEST_CHECK(std::all_of(currents.begin(), currents.end(), [&](const Dimensions& currGoal) {
    return currGoal != Dimensions{0, 0, 0};
  }));
}

void
testUpdate(const std::string& pathfinding) {

  CalmGoals           goals;
  AirplaneObstacleSet obSet;
  PointMapLoader      loader;
  PedestrianSetMock   pedSet;

  obSet.initialize(loader.LoadMap("../../Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.json"));

  goals.configure(CONFIG_MAP{{"endGoalType", "exits"},
                             {"pathFinding", pathfinding},
                             {"diagonalCost", "2.0"},
                             {"goalRange", "0.05"}});

  goals.initialize(obSet, pedSet);

  const auto& endGoals = goals.getAllEndGoals();
  TEST_CHECK(std::all_of(endGoals.begin(), endGoals.end(), [&](const Dimensions& endGoal) {
    return endGoal != Dimensions{0, 0, 0};
  }));

  // check that a goal is updated properly when the pedestrian reaches current goal
  const Dimensions prevGoal = goals.getCurrentGoal(10);
  pedSet.setPedestrianCoordinates(goals.getCurrentGoal(10), 10);
  goals.updatePedestrianGoals(obSet, pedSet);
  TEST_CHECK(prevGoal != goals.getCurrentGoal(10));

  // check that simulation goal is met when all pedestrians reach their goals
  const size_t pedCnt = pedSet.getNumPedestrians();
  for (size_t i = 0; i < pedCnt; ++i) {
    Dimensions currGoal = goals.getCurrentGoal(i);
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
  testUpdate("Disembark");
  //testUpdate("Astar");
}

}  // namespace calm_goals_TESTS

#define calm_goals_tests                                                                                     \
  {"CALM_GOALS: Goals Initialize Test", calm_goals_TESTS::goalsInitialize}, {                                \
    "CALM_GOALS: Goals Update Test", calm_goals_TESTS::goalsUpdate                                           \
  }

#endif  //CALM_GOALS_TESTS_HPP