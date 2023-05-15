
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

// test that initialize properly sets the pedestrian paths
TEST(Calm_Goals, Initialize_Disembark) {
  CalmGoalsTester         test;
  const ObstacleSetMock   obsSet;
  const PedestrianSetMock pedSet;

  const VIPRA::CONFIG::Map config{std::string("\" goalRange \": \" 0.35 \", \" endGoalType \": \" exit \", \" "
                                              "pathFinding \": \" Disembark\", \" diagonalCost \": \" 2.0 \"")};
  test.configure(config);

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

  for (VIPRA::idx i = 0; i < goodmap_pedestrians.size(); ++i) {
    EXPECT_EQ(test.getCurrentGoal(i), goodmap_aisle.at(i));
  }
}

// test that update pedestrian goals, properly updates to next goal
TEST(Calm_Goals, Update_Pedestrian_Goals) {
  CalmGoalsTester          test;
  const ObstacleSetMock    obsSet;
  const PedestrianSetMock  pedSet;
  const VIPRA::CONFIG::Map config{std::string("\" goalRange \": \" 0.35 \", \" endGoalType \": \" exit \", \" "
                                              "pathFinding \": \" Disembark\", \" diagonalCost \": \" 2.0 \"")};
  test.configure(config);

  EXPECT_CALL(obsSet, getObjectTypes()).WillRepeatedly(ReturnRef(goodmap_types));
  EXPECT_CALL(obsSet, getObjectsofType("obstacle")).WillRepeatedly(ReturnRef(goodmap_obstacles));
  EXPECT_CALL(obsSet, getObjectsofType("endOfAisle")).WillRepeatedly(ReturnRef(goodmap_endOfAisle));
  EXPECT_CALL(obsSet, getObjectsofType("exit")).WillRepeatedly(ReturnRef(goodmap_exits));
  EXPECT_CALL(obsSet, getObjectsofType("aisle")).WillRepeatedly(ReturnRef(goodmap_aisle));

  EXPECT_CALL(pedSet, getNumPedestrians()).WillRepeatedly(Return(4));
  VIPRA::f3dVec updatedCoords = goodmap_pedestrians;
  EXPECT_CALL(pedSet, getPedestrianCoordinates()).WillRepeatedly(ReturnRef(updatedCoords));

  test.initialize(obsSet, pedSet);

  // Move peds to aisle, check that goals update
  updatedCoords = goodmap_aisle;
  test.updatePedestrianGoals(obsSet, pedSet, 0.05);
  for (const auto currGoal : test.getAllCurrentGoals()) {
    EXPECT_EQ(currGoal, VIPRA::f3d(24.1, 1.7));
  }

  // Move peds to end of aisle, check that goals update
  for (VIPRA::idx i = 0; i < updatedCoords.size(); ++i) {
    updatedCoords[i] = goodmap_endOfAisle[0];
  }
  test.updatePedestrianGoals(obsSet, pedSet, 0.05);
  for (const auto currGoal : test.getAllCurrentGoals()) {
    EXPECT_EQ(currGoal, VIPRA::f3d(24.2, 3.5));
  }

  // move peds to exit, check that current goals, goal met, and simulation goal update properly
  for (VIPRA::idx i = 0; i < updatedCoords.size(); ++i) {
    updatedCoords[i] = goodmap_exits[0];
  }
  test.updatePedestrianGoals(obsSet, pedSet, 0.05);
  for (const auto currGoal : test.getAllCurrentGoals()) {
    EXPECT_EQ(currGoal, VIPRA::_emptyf3d_);
  }

  // check that all ped goals are met
  for (VIPRA::idx i = 0; i < updatedCoords.size(); ++i) {
    EXPECT_TRUE(test.isPedestianGoalMet(i));
  }

  // check that simulation goal is met
  EXPECT_TRUE(test.isSimulationGoalMet());
}
