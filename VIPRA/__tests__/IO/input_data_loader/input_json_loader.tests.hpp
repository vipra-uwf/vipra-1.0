#pragma once

#include "./../../acutest/acutest.h"

#include "./../../../Base/definitions/type_definitions.hpp"
#include "./../../../Base/inputdataloader/input_json_reader/input_json_reader.hpp"
#include "./../../TEST_Values/input_data_loader_VALUES/expected.hpp"

namespace Input_Json_Loader_TESTS {

void
LoadProperEntitySet(void) {
  InputJSONReader  sut;
  VIPRA::EntitySet entities =
      sut.getInputEntities("./TEST_Values/input_data_loader_VALUES/goodObstacleSet.json");
  TEST_CHECK(entities != InputDataLoader::_emptyset_);
  TEST_CHECK(entities == goodObstacleSetExpected);
}

void
ErrorOnImproperEntitySet(void) {
  InputJSONReader sut;
  TEST_EXCEPTION(sut.getInputEntities("./TEST_Values/input_data_loader_VALUES/badObstacleSet.json"),
                 InputDataLoaderException);
  TEST_EXCEPTION(sut.getInputEntities("./NotAPath.json"), InputDataLoaderException);
}

}  // namespace Input_Json_Loader_TESTS

#define input_json_loader_tests                                                                              \
  {"INPUT_JSON_LOADER: Properly Loads Entity Sets", Input_Json_Loader_TESTS::LoadProperEntitySet}, {         \
    "INPUT_JSON_LOADER: Fails on Bad Entity Sets", Input_Json_Loader_TESTS::ErrorOnImproperEntitySet         \
  }\
