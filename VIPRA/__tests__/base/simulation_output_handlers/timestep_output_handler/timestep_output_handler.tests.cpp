
#include <gtest/gtest.h>

#include "mocks/goals/goals.mock.hpp"
#include "mocks/obstacle_set/obstacle_set.mock.hpp"
#include "mocks/pedestrian_set/pedestrian_set.mock.hpp"

#include "simulation_output_handler/timestep_output_handler/timestep_output_handler.hpp"

// check that isOutputCriterionMet returns the correct value
TEST(Timestep_Output_Handler, Is_Output_Criterion_Met) {
  TimestepOutputHandler test;
  GoalsMock             gm;
  PedestrianSetMock     pm;
  ObstacleSetMock       om;

  test.configure(VIPRA::CONFIG::Map{{"outputFrequency", "100"}});

  EXPECT_TRUE(test.isOutputCriterionMet(pm, om, gm, 0));
  EXPECT_TRUE(test.isOutputCriterionMet(pm, om, gm, 100));
  EXPECT_TRUE(test.isOutputCriterionMet(pm, om, gm, 300));
  EXPECT_FALSE(test.isOutputCriterionMet(pm, om, gm, 15));
  EXPECT_FALSE(test.isOutputCriterionMet(pm, om, gm, 94));
  EXPECT_FALSE(test.isOutputCriterionMet(pm, om, gm, 2934));

  test.configure(VIPRA::CONFIG::Map{{"outputFrequency", "6"}});

  EXPECT_TRUE(test.isOutputCriterionMet(pm, om, gm, 0));
  EXPECT_TRUE(test.isOutputCriterionMet(pm, om, gm, 36));
  EXPECT_TRUE(test.isOutputCriterionMet(pm, om, gm, 138));
  EXPECT_FALSE(test.isOutputCriterionMet(pm, om, gm, 15));
  EXPECT_FALSE(test.isOutputCriterionMet(pm, om, gm, 94));
  EXPECT_FALSE(test.isOutputCriterionMet(pm, om, gm, 2935));
}

// TODO check that writeToDocument is correct
TEST(Timestep_Output_Handler, Write_Output) {}