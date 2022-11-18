#pragma once

#include "../../Base/definitions/type_definitions.hpp"
#include "acutest.h"

[[nodiscard]] bool
TEST_FLOAT(float value, float expected, float error) {
  return (value >= (expected - error) && value <= (expected + error));
}

[[nodiscard]] bool
TEST_DIMENSIONS(const Dimensions& value, const Dimensions& expected, float error) {
  return (TEST_FLOAT(value.axis[0], expected.axis[0], error) &&
          TEST_FLOAT(value.axis[1], expected.axis[1], error) &&
          TEST_FLOAT(value.axis[2], expected.axis[2], error));
}

#define TEST_NO_EXCEPTION(code, check) try { code; } catch (...) { check;}