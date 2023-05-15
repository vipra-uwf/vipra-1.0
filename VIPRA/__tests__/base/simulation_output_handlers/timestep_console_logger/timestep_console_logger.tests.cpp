
#include <gtest/gtest.h>

#include "mocks/goals/goals.mock.hpp"
#include "mocks/obstacle_set/obstacle_set.mock.hpp"
#include "mocks/pedestrian_set/pedestrian_set.mock.hpp"

#include "simulation_output_handler/timestep_console_logger/timestep_console_logger.hpp"

// check that isOutputCriterionMet returns the correct value
TEST(Timestep_Console_Logger, Is_Output_Criterion_Met) {
  TimestepConsoleLogger test;
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
TEST(TimeStep_Console_Logger, Write_Output) {}