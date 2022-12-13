#pragma once

#include "acutest.h"
#include "definitions/type_definitions.hpp"

[[nodiscard]] bool
TEST_FLOAT(float value, float expected, float error) {
  return (value >= (expected - error) && value <= (expected + error));
}

[[nodiscard]] bool
TEST_DIMENSIONS(const VIPRA::f3d& value, const VIPRA::f3d& expected, float error) {
  return (TEST_FLOAT(value.x, expected.x, error) && TEST_FLOAT(value.y, expected.y, error) &&
          TEST_FLOAT(value.z, expected.z, error));
}

#define TEST_NO_EXCEPTION(code, check)                                                                       \
  try {                                                                                                      \
    code;                                                                                                    \
  } catch (...) {                                                                                            \
    check;                                                                                                   \
  }