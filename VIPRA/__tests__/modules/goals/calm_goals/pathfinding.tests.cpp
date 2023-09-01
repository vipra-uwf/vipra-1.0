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

// TEST(Calm_Goals_Pathfinding, Pathfinding) {
//   PointMapLoader              loader;
//   PassengerVehicleObstacleSet map;
//   CALM_PATH::PathingGraph     test;
//   map.initialize(
//       loader.loadMap("../../Maps/obstacle_maps/"
//                      "757_200_182_obstacles/757_200_182_obstacles.omap"));

//   test.build(map, 0.05, 0.20);
//   spdlog::info("Done Building");

//   std::cerr << "{ \"Paths\": [";
//   for (const auto& coords : allPeds2) {
//     auto t = CALM_PATH::pathFind(coords, VIPRA::f3d{30.7, 1.75}, test);
//     std::cerr << "{ \"points\": [";
//     while (!t.empty()) {
//       auto coord = t.front();
//       t.pop();
//       std::cerr << fmt::format("{{\"x\": {}, \"y\": {} }}", coord.x, coord.y);
//       if (!t.empty()) {
//         std::cerr << ",";
//       }
//     }
//     std::cerr << "]},";
//   }
//   std::cerr << "]}";
// }