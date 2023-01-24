
#include <algorithm>

#include <gtest/gtest.h>

#include "test_values/test_values.hpp"

#include "mocks/obstacle_set/obstacle_set.mock.hpp"
#include "mocks/pedestrian_set/pedestrian_set.mock.hpp"

#include "Goals/calm_goals/calm_goals.hpp"
#include "ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"

using ::testing::Return;
using ::testing::ReturnRef;

class CalmGoalsTester : public CalmGoals {
 public:
  const VIPRA::f3d& testNearestObjective(const std::string& type, const VIPRA::f3d& point, const ObstacleSet& obsSet) {
    return nearestObjective(type, point, obsSet);
  }

  void testFindNearesetEndGoal(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
    return findNearestEndGoal(obsSet, pedSet);
  }

  void setup(size_t pedCnt) {
    currentGoals = VIPRA::f3dVec(pedCnt);
    endGoals = VIPRA::f3dVec(pedCnt);
    goalsMet = std::vector<bool>(pedCnt);
  }
};

// TODO test that initialize properly sets the pedestrian paths
TEST(Calm_Goals, Initialize_Disembark) {
  CalmGoalsTester         test;
  const ObstacleSetMock   obsSet;
  const PedestrianSetMock pedSet;

  test.configure(VIPRA::ConfigMap{
      {"goalRange", "0.35"}, {"endGoalType", "exit"}, {"pathFinding", "Disembark"}, {"diagonalCost", "2.0"}});

  EXPECT_CALL(obsSet, getObjectTypes()).WillRepeatedly(ReturnRef(goodmap_types));
  EXPECT_CALL(obsSet, getObjectsofType("obstacle")).WillRepeatedly(ReturnRef(goodmap_obstacles));
  EXPECT_CALL(obsSet, getObjectsofType("endOfAisle")).WillRepeatedly(ReturnRef(goodmap_seats));
  EXPECT_CALL(obsSet, getObjectsofType("exit")).WillRepeatedly(ReturnRef(goodmap_exits));
  EXPECT_CALL(obsSet, getObjectsofType("aisle")).WillRepeatedly(ReturnRef(goodmap_aisle));

  EXPECT_CALL(pedSet, getNumPedestrians()).WillRepeatedly(Return(4));
  EXPECT_CALL(pedSet, getPedestrianCoordinates()).WillRepeatedly(ReturnRef(goodmap_pedestrians));

  test.initialize(obsSet, pedSet);

  for (const auto endGoal : test.getAllEndGoals()) {
    EXPECT_EQ(endGoal, VIPRA::f3d(24.2, 3.5));
  }
}

// TODO test that bad maps are handled properly
TEST(Calm_Goals, Initialize_Bad_Map) {}

// TODO test that update pedestrian goals, properly updates to next goal
TEST(Calm_Goals, Update_Pedestrian_Goals) {}

// TODO test that update pedestrian goals, properly updates if the pedestrian has met their end goal
TEST(Calm_Goals, Update_Pedestrian_Goals_Meets_End_Goal) {}
// TODO test that is simulation goal returns the proper value
TEST(Calm_Goals, Simulation_Goal) {}

// TODO test that getters return the proper goals

// TODO test that nearest objective returns the correct value
TEST(Calm_Goals, Nearest_Objective) {}
// TODO test that nearest end goal returns the correct value
TEST(Calm_Goals, Nearest_End_Goal) {}
