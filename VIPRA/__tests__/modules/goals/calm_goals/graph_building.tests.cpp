#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "test_values/test_values.hpp"

#include "Goals/calm_goals/pathfinding/quadTree.hpp"
#include "MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"

#include "mocks/pedestrian_set/pedestrian_set.mock.hpp"

using ::testing::Return;
using ::testing::ReturnRef;

TEST(Calm_Goals_Graph, Graph_Building) {
  PointMapLoader              loader;
  PassengerVehicleObstacleSet map;
  CalmPath::QuadTree          test;
  map.initialize(
      loader.LoadMap("/home/rolland/Documents/VIPRA/vipra/Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.omap"));

  test.build(map, 0.05);
  std::cerr << test.toString();
}