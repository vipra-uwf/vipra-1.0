

#include "behavior/behavior_builder.hpp"

#include <filesystem>
#include <gtest/gtest.h>

#include <iostream>

const std::filesystem::path test_values = std::filesystem::current_path() / "test_values";

TEST(Behavior_Parsing, Parse_Test) {
  BehaviorBuilder builder;
  HumanBehavior   test = builder.build(test_values / "test_behavior.behavior", 0);
}