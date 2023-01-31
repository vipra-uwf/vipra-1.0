
#include <gtest/gtest.h>

#include <spdlog/spdlog.h>

spdlog::Logger<spdlog::ConsoleLogger> simLogger{spdlog::error};

int
main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}