#pragma once

#include "./../../acutest/acutest.h"

#include "./../../../Base/definitions/type_definitions.hpp"

namespace Input_Xml_Loader_TESTS {
void
LoadEntitySet(void) {
  TEST_CHECK(true == true);
}
}  // namespace Input_Xml_Loader_TESTS

#define input_xml_loader_tests                                                           \
  { "Properly Loads Entity Set", Input_Xml_Loader_TESTS::LoadEntitySet }