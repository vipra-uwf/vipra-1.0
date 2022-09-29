#pragma once

#include "acutest.h"

[[nodiscard]] bool
TEST_FLOAT(float value, float expected, float error) {
  return (value >= (expected - error) && value <= (expected + error));
}