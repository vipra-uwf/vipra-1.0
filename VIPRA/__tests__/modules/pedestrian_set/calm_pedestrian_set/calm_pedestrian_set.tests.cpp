
#include <gtest/gtest.h>

#include "PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"
#include "definitions/type_definitions.hpp"

TEST(Calm_Ped_Set, LoadProperValuesInPedestrianSet) {
  CalmPedestrianSet pedestrianSet;
  size_t            numPedestrians = 3;

  VIPRA::f3dVec    pedestrianCoords = {{8, 5}, {4, 2}, {0, 5}};
  VIPRA::EntitySet pedestrians = {{"pedestrians", pedestrianCoords}};

  pedestrianSet.initialize(pedestrians);

  EXPECT_EQ(pedestrianSet.getIds().size(), numPedestrians);
  EXPECT_EQ(pedestrianSet.getVelocities().size(), numPedestrians);
  EXPECT_EQ(pedestrianSet.getSpeeds().size(), numPedestrians);
  EXPECT_EQ(pedestrianSet.getMasses().size(), numPedestrians);
  EXPECT_EQ(pedestrianSet.getReactionTimes().size(), numPedestrians);
  EXPECT_EQ(pedestrianSet.getDesiredSpeeds().size(), numPedestrians);
  EXPECT_EQ(pedestrianSet.getShoulderLengths().size(), numPedestrians);
}
