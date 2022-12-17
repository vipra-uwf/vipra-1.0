
#include <gtest/gtest.h>

#include "definitions/type_definitions.hpp"
#include "inputdataloader/input_json_reader/input_json_reader.hpp"
#include "test_values/expected.hpp"

TEST(Input_Json_Loader, Loads_Proper_EntitySet) {
  InputJSONReader  sut;
  VIPRA::EntitySet entities =
      sut.getInputEntities("./TEST_Values/input_data_loader_VALUES/goodObstacleSet.json");
  EXPECT_NE(entities, InputDataLoader::_emptyset_);
  EXPECT_EQ(entities, goodObstacleSetExpected);
}

TEST(Input_Json_Loader, Error_On_Improper_Input) {
  InputJSONReader sut;
  EXPECT_THROW(sut.getInputEntities("./TEST_Values/input_data_loader_VALUES/badObstacleSet.json"),
               InputDataLoaderException);
  EXPECT_THROW(sut.getInputEntities("./NotAPath.json"), InputDataLoaderException);
}
