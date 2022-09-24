#pragma once

#include "./../../acutest/acutest.h"

namespace Json_Timestep_Writer_TESTS {
void
example(void) {
  // do whatever
  TEST_CHECK(true == true);
}
}  // namespace Json_Timestep_Writer_TESTS

#define json_timestep_writer_tests                                                       \
  { "Example", Json_Timestep_Writer_TESTS::example }