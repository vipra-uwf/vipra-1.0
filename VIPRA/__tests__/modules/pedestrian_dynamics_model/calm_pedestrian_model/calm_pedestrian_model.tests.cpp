#include <gtest/gtest.h>

#include "Goals/calm_goals/calm_goals.hpp"
#include "MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"
#include "PedestrianDynamicsModel/calm_pedestrian_model/calm_pedestrian_model.hpp"
#include "definitions/state.hpp"
#include "test_values/calm_model_values.hpp"

class CalmTester : private CalmPedestrianModel {
 public:
  CalmTester() : CalmPedestrianModel() {}

  bool Test_objectDirectionTest(const VIPRA::f3d& pedCoords, const VIPRA::f3d& pedVelocity, const VIPRA::f3d& objCoords) {
    return objectDirectionTest(pedCoords, pedVelocity, objCoords);
  }

  bool Test_objectSpatialTest(const VIPRA::f3d& pedCoords,
                              const VIPRA::f3d& pedVelocity,
                              float             pedShoulderLength,
                              const VIPRA::f3d& objLeft,
                              const VIPRA::f3d& objRight) {
    return objectSpatialTest(pedCoords, pedVelocity, pedShoulderLength, objLeft, objRight);
  }

  float Test_checkBlockedPath(const VIPRA::f3d&  coords,
                              const VIPRA::f3d&  velocity,
                              float              shoulderWidth,
                              float              checkDistance,
                              const ObstacleSet& obsSet) {
    return checkBlockedPath(coords, velocity, shoulderWidth, checkDistance, obsSet);
  }

  bool Test_lineIntersect(const VIPRA::f3d& start1,
                          const VIPRA::f3d& end1,
                          const VIPRA::f3d& linep1,
                          const VIPRA::f3d& linep2) noexcept {
    return lineIntersect(start1, end1, linep1, linep2);
  }
  Line Test_getShoulderPoints(const VIPRA::f3d& coords, const VIPRA::f3d& velocity, float shoulderWidth) {
    return getShoulderPoints(coords, velocity, shoulderWidth);
  }

  bool Test_isPointInRect(const Rect& rect, const VIPRA::f3d& p1) noexcept { return isPointInRect(rect, p1); }
};

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

TEST(Calm_Ped_Model, Beta) {}

TEST(Calm_Ped_Model, Object_Spatial_Test) {
  CalmTester test;

  VIPRA::f3d ped1{0, 0, 0};
  VIPRA::f3d vel1{1, 0, 0};
  float      shoulder1 = .32;

  VIPRA::f3d ped2Shoulder1{1, .32, 0};
  VIPRA::f3d ped2Shoulder2{1, -.32, 0};

  VIPRA::f3d ped3Shoulder1{1, 1.32, 0};
  VIPRA::f3d ped3Shoulder2{1, .4, 0};

  VIPRA::f3d ped4Shoulder1{-1, .32, 0};
  VIPRA::f3d ped4Shoulder2{-1, -.32, 0};

  EXPECT_TRUE(test.Test_objectSpatialTest(ped1, vel1, shoulder1, ped2Shoulder1, ped2Shoulder2));
  EXPECT_TRUE(test.Test_objectSpatialTest(ped1, vel1, shoulder1, ped2Shoulder2, ped2Shoulder1));

  EXPECT_FALSE(test.Test_objectSpatialTest(ped1, vel1, shoulder1, ped3Shoulder1, ped3Shoulder2));
  EXPECT_FALSE(test.Test_objectSpatialTest(ped1, vel1, shoulder1, ped3Shoulder2, ped3Shoulder1));

  EXPECT_FALSE(test.Test_objectSpatialTest(ped1, vel1, shoulder1, ped4Shoulder1, ped4Shoulder2));
  EXPECT_FALSE(test.Test_objectSpatialTest(ped1, vel1, shoulder1, ped4Shoulder2, ped4Shoulder1));
}

/* bool lineIntersect(const VIPRA::f3d& start1,
                     const VIPRA::f3d& end1,
                     const VIPRA::f3d& linep1,
                     const VIPRA::f3d& linep2) noexcept; */
TEST(Calm_Ped_Model, Line_Intersect) {
  CalmTester test;
  VIPRA::f3d vert1p1 = VIPRA::f3d{1, 2, 0};
  VIPRA::f3d vert1p2 = VIPRA::f3d{1, 0, 0};
  VIPRA::f3d vert2p1 = VIPRA::f3d{0, 1, 0};
  VIPRA::f3d vert2p2 = VIPRA::f3d{0, 0, 0};

  EXPECT_FALSE(test.Test_lineIntersect(vert1p1, vert1p2, vert2p1, vert2p2));
  EXPECT_FALSE(test.Test_lineIntersect(vert1p2, vert1p1, vert2p1, vert2p2));
  EXPECT_FALSE(test.Test_lineIntersect(vert1p1, vert1p2, vert2p2, vert2p1));
  EXPECT_FALSE(test.Test_lineIntersect(vert1p2, vert1p1, vert2p2, vert2p1));

  VIPRA::f3d horz1p1 = VIPRA::f3d{0, 1, 0};
  VIPRA::f3d horz1p2 = VIPRA::f3d{2, 1, 0};

  EXPECT_TRUE(test.Test_lineIntersect(vert1p1, vert1p2, horz1p1, horz1p2));
  EXPECT_TRUE(test.Test_lineIntersect(horz1p1, horz1p2, vert1p1, vert1p2));
  EXPECT_FALSE(test.Test_lineIntersect(horz1p1, horz1p2, vert2p1, vert2p2));
  EXPECT_FALSE(test.Test_lineIntersect(vert2p1, vert2p2, horz1p1, horz1p2));

  VIPRA::f3d diag1p1 = VIPRA::f3d{1, 2, 0};
  VIPRA::f3d diag1p2 = VIPRA::f3d{3, 4, 0};
  VIPRA::f3d diag2p1 = VIPRA::f3d{2, 1, 0};
  VIPRA::f3d diag2p2 = VIPRA::f3d{-1, 3, 0};

  // Touching lines should intersect
  EXPECT_FALSE(test.Test_lineIntersect(vert1p1, vert1p2, diag1p1, diag1p2));
  EXPECT_FALSE(test.Test_lineIntersect(diag1p1, diag1p2, vert1p1, vert1p2));
  EXPECT_FALSE(test.Test_lineIntersect(diag1p1, diag1p2, diag2p1, diag2p2));
  EXPECT_FALSE(test.Test_lineIntersect(diag2p1, diag2p2, diag1p1, diag1p2));

  VIPRA::f3d ped4Shoulder1{-1, .32, 0};
  VIPRA::f3d ped4Shoulder2{-1, -.32, 0};
  VIPRA::f3d p1{0, .32, 0};
  VIPRA::f3d p2{5, .32, 0};
  VIPRA::f3d p3{5, -.32, 0};
  VIPRA::f3d p4{0, -.32, 0};

  EXPECT_FALSE(test.Test_lineIntersect(p1, ped4Shoulder1, p2, p3));
  EXPECT_FALSE(test.Test_lineIntersect(p1, ped4Shoulder1, p3, p4));
  EXPECT_FALSE(test.Test_lineIntersect(p3, ped4Shoulder1, p1, p2));
  EXPECT_FALSE(test.Test_lineIntersect(p3, ped4Shoulder1, p3, p1));

  EXPECT_FALSE(test.Test_lineIntersect(p1, ped4Shoulder2, p2, p3));
  EXPECT_FALSE(test.Test_lineIntersect(p1, ped4Shoulder2, p3, p4));
  EXPECT_FALSE(test.Test_lineIntersect(p3, ped4Shoulder2, p1, p2));
  EXPECT_FALSE(test.Test_lineIntersect(p3, ped4Shoulder2, p3, p1));
}

/*
Line getShoulderPoints(const VIPRA::f3d& coords, const VIPRA::f3d& velocity, float shoulderWidth);
*/
TEST(Calm_Ped_Model, Get_Shoulder_Points) {
  CalmTester test;

  VIPRA::f3d ped1 = VIPRA::f3d{0, 0, 0};
  VIPRA::f3d ped2 = VIPRA::f3d{3.2, 1.5, 0};

  VIPRA::f3d vel1 = VIPRA::f3d{0, 0, 0};
  VIPRA::f3d vel2 = VIPRA::f3d{1, 0, 0};
  VIPRA::f3d vel3 = VIPRA::f3d{0, 1, 0};
  VIPRA::f3d vel4 = VIPRA::f3d{1, 1, 0};
  VIPRA::f3d vel5 = VIPRA::f3d{.5, 1.8, 0};
  float      shoulder1 = 1.0f;
  float      shoulder2 = 0.32f;

  EXPECT_EQ(test.Test_getShoulderPoints(ped1, vel1, shoulder1), Line(VIPRA::f3d(0, 1, 0), VIPRA::f3d(0, -1, 0)));
  EXPECT_EQ(test.Test_getShoulderPoints(ped1, vel2, shoulder1), Line(VIPRA::f3d(0, 1, 0), VIPRA::f3d(0, -1, 0)));
  EXPECT_EQ(test.Test_getShoulderPoints(ped1, vel3, shoulder1), Line(VIPRA::f3d(-1, 0, 0), VIPRA::f3d(1, 0, 0)));

  auto result1 = test.Test_getShoulderPoints(ped1, vel4, shoulder1);
  EXPECT_NEAR(result1.p1.x, 1 / -std::sqrt(2), 0.01);
  EXPECT_NEAR(result1.p1.y, 1 / std::sqrt(2), 0.01);
  EXPECT_NEAR(result1.p2.x, 1 / std::sqrt(2), 0.01);
  EXPECT_NEAR(result1.p2.y, 1 / -std::sqrt(2), 0.01);

  auto result2 = test.Test_getShoulderPoints(ped1, vel4, shoulder2);
  EXPECT_NEAR(result2.p1.x, 0.32 / -std::sqrt(2), 0.01);
  EXPECT_NEAR(result2.p1.y, 0.32 / std::sqrt(2), 0.01);
  EXPECT_NEAR(result2.p2.x, 0.32 / std::sqrt(2), 0.01);
  EXPECT_NEAR(result2.p2.y, 0.32 / -std::sqrt(2), 0.01);

  auto result3 = test.Test_getShoulderPoints(ped2, vel4, shoulder2);
  EXPECT_NEAR(result3.p1.x, 3.2 + (0.32 / -std::sqrt(2)), 0.01);
  EXPECT_NEAR(result3.p1.y, 1.5 + (0.32 / std::sqrt(2)), 0.01);
  EXPECT_NEAR(result3.p2.x, 3.2 + (0.32 / std::sqrt(2)), 0.01);
  EXPECT_NEAR(result3.p2.y, 1.5 + (0.32 / -std::sqrt(2)), 0.01);
}

/*
bool isPointInRect(const Rect& rect, const VIPRA::f3d& p1) noexcept;
*/
TEST(Calm_Ped_Model, Is_Point_In_Rect) {
  CalmTester test;
  VIPRA::f3d p1 = VIPRA::f3d{0, 0, 0};
  VIPRA::f3d p2 = VIPRA::f3d{0, 1, 0};
  VIPRA::f3d p3 = VIPRA::f3d{1, 1, 0};
  VIPRA::f3d p4 = VIPRA::f3d{1, 0, 0};
  Rect       r1 = {p1, p2, p3, p4};

  EXPECT_TRUE(test.Test_isPointInRect(r1, VIPRA::f3d{0.5, 0.5}));
  EXPECT_TRUE(test.Test_isPointInRect(r1, VIPRA::f3d{1, 1}));
  EXPECT_FALSE(test.Test_isPointInRect(r1, VIPRA::f3d{1.2, 0.5}));
  EXPECT_FALSE(test.Test_isPointInRect(r1, VIPRA::f3d{-0.5, 0.5}));

  VIPRA::f3d p5 = VIPRA::f3d{1, 1, 0};
  VIPRA::f3d p6 = VIPRA::f3d{2, 2, 0};
  VIPRA::f3d p7 = VIPRA::f3d{3, 1, 0};
  VIPRA::f3d p8 = VIPRA::f3d{2, 0, 0};
  Rect       r2 = {p5, p6, p7, p8};

  EXPECT_FALSE(test.Test_isPointInRect(r2, VIPRA::f3d{0.5, 0.5}));
  EXPECT_TRUE(test.Test_isPointInRect(r2, VIPRA::f3d{2.0, 1.0}));
  EXPECT_TRUE(test.Test_isPointInRect(r2, VIPRA::f3d{2.63, 1.2}));
  EXPECT_TRUE(test.Test_isPointInRect(r2, VIPRA::f3d{1.0, 1.0}));
  EXPECT_FALSE(test.Test_isPointInRect(r2, VIPRA::f3d{1.2, 0.5}));
  EXPECT_FALSE(test.Test_isPointInRect(r2, VIPRA::f3d{-0.5, 0.5}));
  EXPECT_FALSE(test.Test_isPointInRect(r2, VIPRA::f3d{3, 2}));
}
