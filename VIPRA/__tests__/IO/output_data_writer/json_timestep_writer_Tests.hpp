#pragma once

#include "./../../acutest/acutest.h"
#include "./../../acutest/fileTesting.hpp"

#include "./../../../Base/outputdatawriter/json_timestep_writer/json_timestep_writer.hpp"
#include "./../../TEST_Values/output_data_loader_VALUES/json_timestep_writer/expected.hpp"

namespace Json_Timestep_Writer_TESTS {

void
add_float_values(void) {

  const size_t       NUMTIMESTEPS = 2;
  const size_t       NUMPEDS = 2;
  JSONTimestepWriter sut;
  sut.initializeOutputFile("./temp/jsontimestepwriter.json");

  for (size_t i = 0; i < NUMTIMESTEPS; ++i) {
    for (size_t j = 0; j < NUMPEDS; ++j) {
      sut.addFloatValue("x", j);
      sut.addFloatValue("y", j);
    }
    sut.addFloatValue("NEW_TIMESTEP", 0);
  }
  Json::Value expected;
  getExpectedTimeSteps(expected);
  TEST_CHECK(sut.getDocument().compare(expected) == 0);
}

void
write_to_document(void) {
  const size_t       NUMTIMESTEPS = 2;
  const size_t       NUMPEDS = 2;
  JSONTimestepWriter sut;
  sut.initializeOutputFile("./temp/jsontimestepwriter.json");

  for (size_t i = 0; i < NUMTIMESTEPS; ++i) {
    for (size_t j = 0; j < NUMPEDS; ++j) {
      sut.addFloatValue("x", j);
      sut.addFloatValue("y", j);
    }
    sut.addFloatValue("NEW_TIMESTEP", 0);
  }

  sut.writeToDocument();

  TEST_FILE_CONTENT("./temp/jsontimestepwriter.json", expectedTimeSteps, true);
}

}  // namespace Json_Timestep_Writer_TESTS

#define json_timestep_writer_tests                                                       \
  {"Can Add Float Values", Json_Timestep_Writer_TESTS::add_float_values}, {              \
    "Can Write To Document", Json_Timestep_Writer_TESTS::write_to_document               \
  }