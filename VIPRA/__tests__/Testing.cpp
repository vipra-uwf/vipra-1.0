
#include <gtest/gtest.h>

#include "logging/logging.hpp"

LJ::Logger<LJ::ConsoleLogger> simLogger{LJ::ERROR};

int
main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}