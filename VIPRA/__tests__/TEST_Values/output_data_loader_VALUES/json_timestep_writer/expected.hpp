#pragma once

#include "./../../../../Base/jsoncpp/json/json.h"

const std::string expectedTimeSteps =
    R"({"timesteps":{"0":[{"x":0.0,"y":0.0},{"x":1.0,"y":1.0}],"1":[{"x":0.0,"y":0.0},{"x":1.0,"y":1.0}]}})";

void
getExpectedTimeSteps(Json::Value& value) {
  Json::CharReaderBuilder builder;
  Json::CharReader*       reader = builder.newCharReader();
  reader->parse(expectedTimeSteps.c_str(),
                expectedTimeSteps.c_str() + expectedTimeSteps.size(),
                &value,
                nullptr);
  delete reader;
}
