
#include <filesystem>

#include <gtest/gtest.h>

#include "configuration/configuration_reader.hpp"

namespace fs = std::filesystem;

const auto testValues = fs::current_path().string() + "/base/configuration/test_values/";

TEST(Configuration_Reader, Get_Configuration) {
  VIPRA::ConfigurationReader sut;

  auto result = sut.getConfiguration(testValues + "module_params.json");

  EXPECT_EQ(result["human_behavior_model"]["seed"], "testseed");
}