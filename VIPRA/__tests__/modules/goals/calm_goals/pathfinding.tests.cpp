#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "test_values/test_values.hpp"

#include "Goals/calm_goals/pathfinding/pathfinding.hpp"
#include "MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"

#include "mocks/pedestrian_set/pedestrian_set.mock.hpp"

using ::testing::Return;
using ::testing::ReturnRef;

TEST(Calm_Goals_Pathfinding, Pathfinding) {
  PointMapLoader              loader;
  PassengerVehicleObstacleSet map;
  CalmPath::PathingGraph      test;
  map.initialize(
      loader.loadMap("/mnt/c/Users/gabeb/Research-Vipra/vipra/Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.omap"));

  test.build(map, 0.1, 0.2);
  spdlog::info("Done Building");

  std::cerr << "{ \"Paths\": [";
  for (const auto& coords : all_peds) {
    auto t = CalmPath::pathFind(coords, goodmap_exits[0], test);
    std::cerr << "{ \"points\": [";
    while (!t.empty()) {
      auto coord = t.front();
      t.pop();
      std::cerr << fmt::format("{{\"x\": {}, \"y\": {} }}", coord.x, coord.y);
      if (!t.empty()) {
        std::cerr << ",";
      }
    }
    std::cerr << "]},";
  }
  std::cerr << "]}";
}