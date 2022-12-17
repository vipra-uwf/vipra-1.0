#ifndef PATH_FINDING_TESTS_HPP
#define PATH_FINDING_TESTS_HPP

#include "Goals/calm_goals/calm_goals.hpp"
#include "MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "ObstacleSet/airplane_obstacle_set/airplane_obstacle_set.hpp"

namespace path_finding_TESTS {

void
testPathfinding(void) {
  PedestrianSetMock   pedSet;
  AirplaneObstacleSet obs;
  CalmGoals           goals;
  PointMapLoader      loader;

  goals.configure(VIPRA::ConfigMap{
      {"endGoalType", "exits"}, {"pathFinding", "Astar"}, {"diagonalCost", "2.0"}, {"goalRange", "0.05"}});

  obs.initialize(loader.LoadMap("../../Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.json"));

  goals.initialize(obs, pedSet);

  goals.printGraph();
  goals.printPaths();
}

}  // namespace path_finding_TESTS

#define path_finding_tests                                                                                   \
  { "PATH_FINDING: Pathfinding", path_finding_TESTS::testPathfinding }

#endif