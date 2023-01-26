#include <gtest/gtest.h>

#include <filesystem>

#include "MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"

#include "./test_values/test_values.hpp"

namespace fs = std::filesystem;

const auto testValues = fs::current_path().string() + "/modules/obstacle_set/passenger_vehicle_obstacle_set/test_values/";

PointMapLoader mapLoader;

/**
 * @brief ObstacleMap.initialize() should take in a unique_ptr to a MapData and correctly initialize the values for object positions
 */
TEST(Passenger_Vehicle_ObstacleSet, Initialization) {
  PassengerVehicleObstacleSet sut;
  sut.initialize(mapLoader.LoadMap(testValues + "goodmap.omap"));
  EXPECT_EQ(sut.getObjectsofType("obstacle"), goodmap_obstacles);
}

/**
 * @brief ObstacleMap.initialize() should reject any maps that don't have the correct features
 */
TEST(Passenger_Vehicle_ObstacleSet, Handle_Improper_Map) {
  PassengerVehicleObstacleSet sut;
  // TODO switch this to using mock
  // EXPECT_THROW(sut.initialize(mapLoader.LoadMap(testValues + "badmap.omap")), ObstacleSetException);
}

TEST(Passenger_Vehicle_ObstacleSet, Configure) {}

/**
 * @brief ObstacleMap.getMapDimensions() should return a f3d that describes a cube, that starts at {0,0,0} and encloses all objects in the map
 */
TEST(Passenger_Vehicle_ObstacleSet, Get_Map_Dimensions) {
  PassengerVehicleObstacleSet sut;
  sut.initialize(mapLoader.LoadMap(testValues + "goodmap.omap"));
  auto dims = sut.getMapDimensions();
  EXPECT_NEAR(dims['x'], 24.2, 0.001);
  EXPECT_NEAR(dims['y'], 7, 0.001);
}

TEST(Passenger_Vehicle_ObstacleSet, Get_Object_Types) {
  PassengerVehicleObstacleSet sut;
  sut.initialize(mapLoader.LoadMap(testValues + "goodmap.omap"));
  const std::vector<std::string>& types = sut.getObjectTypes();
  for (int i = 0; i < types.size(); ++i) {
    EXPECT_EQ(types.at(i), goodmap_types.at(i));
  }
}

TEST(Passenger_Vehicle_ObstacleSet, Get_Object_OF_Type) {
  PassengerVehicleObstacleSet sut;
  sut.initialize(mapLoader.LoadMap(testValues + "goodmap.omap"));
  const auto& obs = sut.getObjectsofType("obstacle");
  for (int i = 0; i < obs.size(); ++i) {
    EXPECT_EQ(obs.at(i), goodmap_obstacles.at(i));
  }

  const auto& seats = sut.getObjectsofType("seat");
  for (int i = 0; i < seats.size(); ++i) {
    EXPECT_EQ(seats.at(i), goodmap_seats.at(i));
  }
}

TEST(Passenger_Vehicle_ObstacleSet, Nearest_Obstacle_For_Whole_Set) {
  // TODO
}

TEST(Passenger_Vehicle_ObstacleSet, Nearest_Obstacle_For_Individual) {
  PassengerVehicleObstacleSet sut;
  sut.initialize(mapLoader.LoadMap(testValues + "goodmap.omap"));
  const auto nearestObs = sut.nearestObstacle(VIPRA::f3d{0, 1});
  EXPECT_EQ(nearestObs, VIPRA::f3d(0, 0, 0));

  const auto nearestObs2 = sut.nearestObstacle(VIPRA::f3d{10, 7});
  EXPECT_EQ(nearestObs2, VIPRA::f3d(5, 7, 0));
}

TEST(Passenger_Vehicle_ObstacleSet, Nearest_Obstacle_In_Direction_For_Set) {
  // TODO
}

TEST(Passenger_Vehicle_ObstacleSet, Nearest_Obstacle_In_Direction_For_Individual) {
  PassengerVehicleObstacleSet sut;
  sut.initialize(mapLoader.LoadMap(testValues + "goodmap.omap"));
  const auto nearestObs = sut.nearestObstacleInDirection(VIPRA::f3d{0, 1}, VIPRA::f3d{0, -1});
  EXPECT_EQ(nearestObs, VIPRA::f3d(0, 0, 0));

  const auto nearestObs2 = sut.nearestObstacleInDirection(VIPRA::f3d{0, 1}, VIPRA::f3d{0, 1});
  EXPECT_EQ(nearestObs2, VIPRA::f3d(0, 3.46, 0));
}

TEST(Passenger_Vehicle_ObstacleSet, RayHit) {
  PassengerVehicleObstacleSet sut;
  sut.initialize(mapLoader.LoadMap(testValues + "goodmap.omap"));
  sut.configure(configuration);

  const float dist = sut.rayHit(VIPRA::f3d{-1, 0}, VIPRA::f3d{1, 0});
  EXPECT_NEAR(dist, 1, 0.001);

  const float dist1 = sut.rayHit(VIPRA::f3d{0, -1}, VIPRA::f3d{0, 1});
  const float dist2 = sut.rayHit(VIPRA::f3d{0.03, -1}, VIPRA::f3d{0, 1});
  EXPECT_NEAR(dist1, 1, 0.001);
  EXPECT_NEAR(dist2, 1, 0.001);

  const float dist3 = sut.rayHit(VIPRA::f3d{-1, -1}, VIPRA::f3d{1, 1});
  EXPECT_NEAR(dist3, std::sqrt(2), 0.001);
}

TEST(Passenger_Vehicle_ObstacleSet, Collision) {
  PassengerVehicleObstacleSet sut;
  sut.initialize(mapLoader.LoadMap(testValues + "goodmap.omap"));
  sut.configure(configuration);

  EXPECT_TRUE(sut.collision(VIPRA::f3d(0, 0)));
  EXPECT_TRUE(sut.collision(VIPRA::f3d(0, 0.04)));
  EXPECT_TRUE(sut.collision(VIPRA::f3d(0, 3.41)));
  EXPECT_TRUE(sut.collision(VIPRA::f3d(5, 7)));

  EXPECT_FALSE(sut.collision(VIPRA::f3d(-5, -7)));
  EXPECT_FALSE(sut.collision(VIPRA::f3d(1, 1)));
  EXPECT_FALSE(sut.collision(VIPRA::f3d(-3, 1)));
  EXPECT_FALSE(sut.collision(VIPRA::f3d(5, 7.2)));
}