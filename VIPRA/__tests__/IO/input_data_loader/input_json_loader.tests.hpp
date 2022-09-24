#pragma once

#include "./../../acutest/acutest.h"

#include "./../../../Base/definitions/type_definitions.hpp"
#include "./../../../Base/inputdataloader/input_json_reader/input_json_reader.hpp"

namespace Input_Json_Loader_TESTS {

void
LoadProperEntitySet(void) {
  InputJSONReader sut;
  ENTITY_SET      entities =
      sut.getInputEntities("./TEST_Values/input_data_loader_VALUES/goodObstacleSet.json");
  TEST_ASSERT(entities != InputDataLoader::_emptyset_);
}

void
ErrorOnImproperEntitySet(void) {
  InputJSONReader sut;
  TEST_EXCEPTION(
      sut.getInputEntities("./TEST_Values/input_data_loader_VALUES/badObstacleSet.json"),
      std::exception);
}

}  // namespace Input_Json_Loader_TESTS

#define input_json_loader_tests                                                          \
  {"Properly Loads Entity Sets", Input_Json_Loader_TESTS::LoadProperEntitySet}, {        \
    "Fails on Bad Entity Sets", Input_Json_Loader_TESTS::ErrorOnImproperEntitySet        \
  }\
