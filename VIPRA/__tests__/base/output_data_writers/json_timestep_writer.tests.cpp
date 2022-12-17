
#include <gtest/gtest.h>

#include "outputdatawriter/json_timestep_writer/json_timestep_writer.hpp"
#include "test_values/expected.hpp"
TEST(Json_Timestep_Writer, Add_Float_Values) {
  const size_t       NUMTIMESTEPS = 2;
  const size_t       NUMPEDS = 2;
  JSONTimestepWriter sut;
  sut.initializeOutputFile("./temp/jsontimestepwriter.json");

  for (size_t i = 0; i < NUMTIMESTEPS; ++i) {
    sut.addFloatValue("NEW_TIMESTEP", i);
    for (size_t j = 0; j < NUMPEDS; ++j) {
      sut.addFloatValue("x", j);
      sut.addFloatValue("y", j);
    }
  }
  Json::Value expected;
  getExpectedTimeSteps(expected);

  EXPECT_EQ(sut.getDocument().compare(expected), 0);
}

void
write_to_document(void) {
  const size_t       NUMTIMESTEPS = 2;
  const size_t       NUMPEDS = 2;
  JSONTimestepWriter sut;
  sut.initializeOutputFile("./temp/jsontimestepwriter.json");

  for (size_t i = 0; i < NUMTIMESTEPS; ++i) {
    sut.addFloatValue("NEW_TIMESTEP", i);
    for (size_t j = 0; j < NUMPEDS; ++j) {
      sut.addFloatValue("x", j);
      sut.addFloatValue("y", j);
    }
  }

  sut.writeToDocument();

  // EXPECT_EQ(TEST_FILE_CONTENT("./temp/jsontimestepwriter.json", expectedTimeSteps, true));
}