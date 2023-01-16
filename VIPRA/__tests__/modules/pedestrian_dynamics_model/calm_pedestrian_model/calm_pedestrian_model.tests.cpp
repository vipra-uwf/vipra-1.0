#include <gtest/gtest.h>

#include "Goals/calm_goals/calm_goals.hpp"
#include "MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"
#include "PedestrianDynamicsModel/calm_pedestrian_model/calm_pedestrian_model.hpp"
#include "definitions/state.hpp"
#include "test_values/calm_model_values.hpp"

TEST(Calm_Ped_Model, Model_Returns_Correct_Distance) {
  // CalmPedestrianSet           pedestrianSet;
  // CalmPedestrianModel         pedestrianModel;
  // CalmGoals                   goals;
  // PassengerVehicleObstacleSet obs;
  // VIPRA::f3dVec               pedestrianCoords = {VIPRA::f3d{8, 5}, VIPRA::f3d{4, 2}, VIPRA::f3d{0, 5}};
  // VIPRA::EntitySet            pedestrians = {{"pedestrians", pedestrianCoords}};

  // pedestrianSet.initialize(pedestrians);
  // pedestrianSet.setPedestrianCoordinates(pedestrianCoords);

  // pedestrianModel.initialize(pedestrianSet, obs, goals);
  // pedestrianModel.calculateDistanceMatrices(pedestrianSet);

  // EXPECT_EQ(pedestrianModel.getPedestrianDistance(pedestrianSet, 0, 1), 5);
  // EXPECT_EQ(pedestrianModel.getPedestrianDistance(pedestrianSet, 0, 2), 8);
  // EXPECT_EQ(pedestrianModel.getPedestrianDistance(pedestrianSet, 1, 0), 5);
  // EXPECT_EQ(pedestrianModel.getPedestrianDistance(pedestrianSet, 1, 2), 5);
  // EXPECT_EQ(pedestrianModel.getPedestrianDistance(pedestrianSet, 2, 0), 8);
  // EXPECT_EQ(pedestrianModel.getPedestrianDistance(pedestrianSet, 2, 1), 5);
}

//First pedestrian's nearest neighbor should be equal to -1 (NOT_FOUND) since they are farthest ahead
//Second pedestrian's nearest neighbor should be equal to 0 (First pedestrian) since they are facing the first
//Third pedestrian's nearest neighbor should be equal to 1 (Second pedestrian) since they are facing both second and first
//And the second pedestrian is closer
TEST(Calm_Ped_Model, Model_Returns_Correct_Nearest_Neighbor) {
  // CalmPedestrianSet           pedestrianSet;
  // CalmPedestrianModel         pedestrianModel;
  // PassengerVehicleObstacleSet obs;
  // CalmGoals                   goals;
  // VIPRA::f3dVec               pedestrianCoords = {VIPRA::f3d{8, 5}, VIPRA::f3d{4, 2}, VIPRA::f3d{0, 5}};
  // VIPRA::f3dVec               velocities = {VIPRA::f3d{3, 4}, VIPRA::f3d{5, 1}, VIPRA::f3d{6, 2}};
  // std::vector<float>          shoulderLengths = {4, 5, 2};
  // VIPRA::EntitySet            pedestrians = {{"pedestrians", pedestrianCoords}};

  // pedestrianSet.initialize(pedestrians);
  // pedestrianSet.setPedestrianCoordinates(pedestrianCoords);

  // pedestrianSet.initialize(pedestrians);
  // pedestrianSet.setPedestrianCoordinates(pedestrianCoords);
  // pedestrianSet.setShoulderLengths(shoulderLengths);
  // pedestrianSet.setVelocities(velocities);

  // pedestrianModel.initialize(pedestrianSet, obs, goals);
  // pedestrianModel.calculateDistanceMatrices(pedestrianSet);
  // pedestrianModel.calculateNeartestNeighbors(pedestrianSet, goals);

  // EXPECT_EQ(pedestrianModel.getNearestNeighbors().at(0), VIPRA::idx_INVALID);
  // EXPECT_EQ(pedestrianModel.getNearestNeighbors().at(1), 0);
  // EXPECT_EQ(pedestrianModel.getNearestNeighbors().at(2), 1);
}

TEST(Calm_Ped_Model, Model_Calculates_Correct_Propulsion) {
  // CalmPedestrianSet           pedSet;
  // CalmPedestrianModel         pedModel;
  // CalmGoals                   goals;
  // PassengerVehicleObstacleSet obs;
  // PointMapLoader              loader;

  // obs.initialize(loader.LoadMap("../../Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.omap"));
  // pedSet.configure(
  //     VIPRA::ConfigMap{{"mass", "1.000000"}, {"reaction_time", "0.400000"}, {"desired_speed", "1.000000"}});
  // pedSet.initialize(CALM_PEDESTRIAN_VIPRA_EntitySet);
  // goals.configure(VIPRA::ConfigMap{
  //     {"endGoalType", "exits"}, {"pathFinding", "Disembark"}, {"diagonalCost", "2.0"}, {"goalRange", "0.05"}});
  // goals.initialize(obs, pedSet);
  // goals.updatePedestrianGoals(obs, pedSet);

  // pedModel.initialize(pedSet, obs, goals);
  // pedModel.timestep(pedSet, obs, goals, 0);

  // for (size_t i = 0; i < pedSet.getNumPedestrians(); i++) {
  //   EXPECT_EQ(pedModel.getPropulsionForces().at(i).x, pedModel.getPropulsionForces().at(i).x);
  //   EXPECT_EQ(pedModel.getPropulsionForces().at(i).y, pedModel.getPropulsionForces().at(i).y);
  // }
}
