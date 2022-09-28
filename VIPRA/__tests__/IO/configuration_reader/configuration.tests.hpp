
#include "../../acutest/acutest.h"

#include "../../../Base/configuration/configuration_reader.hpp"

namespace configuration_reader_TESTS {
void
read_configuration(void) {}
}  // namespace configuration_reader_TESTS

#define configuration_reader_tests                                                       \
  { "Can Read Configurations", configuration_reader_TESTS::read_configuration }