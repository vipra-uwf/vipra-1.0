#ifndef PATH_FINDING_TESTS_HPP
#define PATH_FINDING_TESTS_HPP

#include "../acutest/acutest.h"

#include "../../../Modules/Goals/calm_goals/calm_goals.hpp"
#include "../../../Modules/MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "../../../Modules/ObstacleSet/airplane_obstacle_set/airplane_obstacle_set.hpp"
#include "../../../VIPRA/Base/inputdataloader/input_json_reader/input_json_reader.hpp"
#include "../MOCKS/pedestrian_set/pedestrian_set.mock.hpp"

namespace path_finding_TESTS {

void
testPathfinding(void) {
  PedestrianSetMock   pedSet;
  InputJSONReader     reader;
  AirplaneObstacleSet obs;
  CalmGoals           goals;
  PointMapLoader      loader;

  goals.configure(CONFIG_MAP{{"endGoalType", "exits"}, {"pathFinding", "Deplane"}, {"diagonalCost", "2.0"}});

  obs.initialize(loader.LoadMap("../../Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.json"));

  goals.initialize(obs, pedSet);

  goals.printGraph();
  goals.printPaths();
}

}  // namespace path_finding_TESTS

#define path_finding_tests                                                                                   \
  { "PATH_FINDING: Pathfinding", path_finding_TESTS::testPathfinding }

#endif