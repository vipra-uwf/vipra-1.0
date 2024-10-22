#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "test_values/test_values.hpp"

#include "MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"

#include "Goals/calm_goals/pathfinding/pathing_graph.hpp"

#include "mocks/pedestrian_set/pedestrian_set.mock.hpp"

using ::testing::Return;
using ::testing::ReturnRef;

TEST(Calm_Goals_Graph, Graph_Building) {
  PointMapLoader              loader;
  PassengerVehicleObstacleSet map;
  CALM_PATH::PathingGraph     sut;

  map.initialize(loader.loadMap(
      "../../Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.omap"));

  sut.build(map, 0.05, 0.25);
  // std::cerr << sut.toString();
}