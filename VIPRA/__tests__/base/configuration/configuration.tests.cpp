
#include <filesystem>

#include <gtest/gtest.h>

#include "configuration/configuration_reader.hpp"

namespace fs = std::filesystem;

const auto testValues = fs::current_path().string() + "/base/configuration/test_values/";

// Json::Value getConfiguration(const std::string& filePath);
// void        configure(const VIPRA::ConfigMap& config);

// TODO test that getConfiguration loads the file correctly
TEST(Configuration_Reader, Read_Configuration_Files) {
  ConfigurationReader test;

  const std::string simConfigPath = testValues + "sim.config";
  const auto        result = test.getConfiguration(simConfigPath);
  EXPECT_TRUE(result.isMember("id"));
  EXPECT_TRUE(result.isMember("name"));
  EXPECT_TRUE(result.isMember("description"));
  EXPECT_TRUE(result.isMember("modules"));
  EXPECT_TRUE(result["modules"].isMember("input_data_loader"));
  EXPECT_TRUE(result["modules"].isMember("human_behavior_model"));
  EXPECT_TRUE(result["modules"].isMember("output_data_writer"));
  EXPECT_TRUE(result["modules"].isMember("simulation_output_handler"));
  EXPECT_TRUE(result["modules"].isMember("pedestrian_set"));
  EXPECT_TRUE(result["modules"].isMember("obstacle_set"));
  EXPECT_TRUE(result["modules"].isMember("entity_set_factory"));
  EXPECT_TRUE(result["modules"].isMember("goals"));
  EXPECT_TRUE(result["modules"].isMember("pedestrian_dynamics_model"));
  EXPECT_TRUE(result["modules"].isMember("configuration_reader"));
  EXPECT_TRUE(result["modules"].isMember("clock"));
  EXPECT_TRUE(result["modules"].isMember("data"));
  EXPECT_TRUE(result["modules"].isMember("simulation"));
  EXPECT_TRUE(result["modules"].isMember("map_loader"));
  EXPECT_TRUE(result["modules"].isMember("pedestrian_loader"));
  EXPECT_TRUE(result["modules"].isMember("policy_model"));
}

// TODO test that getConfiguration handles incorrect files / nonexistant files correctly
TEST(Configuration_Reader, Handle_Bad_Files) {
  ConfigurationReader test;

  const std::string nonexistantPath = testValues + "non_existant";
  EXPECT_THROW(test.getConfiguration(nonexistantPath), ConfigurationReaderException);

  const std::string badConfigPath = testValues + "bad.config";
  EXPECT_THROW(test.getConfiguration(badConfigPath), ConfigurationReaderException);
}

/*
"id"
"name"
"description"
"modules"
"input_data_loader"
"human_behavior_model"
"output_data_writer"
"simulation_output_handler"
"pedestrian_set"
"obstacle_set"
"entity_set_factory"
"goals"
"pedestrian_dynamics_model"
"configuration_reader"
"clock"
"data"
"simulation"
"map_loader"
"pedestrian_loader"
"policy_model"
*/