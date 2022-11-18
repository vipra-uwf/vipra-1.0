#pragma once

#include "../acutest/acutest.h"
#include "../acutest/extraTests.hpp"

#include "../../Base/definitions/type_definitions.hpp"

namespace dimensions_TESTS {

constexpr FLOATING_NUMBER error = 0.01;

void
proper_initialization(void) {
  Dimensions sutDefault;
  TEST_ASSERT(sutDefault.axis[0] == 0);
  TEST_ASSERT(sutDefault.axis[1] == 0);
  TEST_ASSERT(sutDefault.axis[2] == 0);

  Dimensions sut_oneD{5};
  TEST_ASSERT(sut_oneD.axis[0] == 5);
  TEST_ASSERT(sut_oneD.axis[1] == 0);
  TEST_ASSERT(sut_oneD.axis[2] == 0);

  Dimensions sut_twoD{5, 4};
  TEST_ASSERT(sut_twoD.axis[0] == 5);
  TEST_ASSERT(sut_twoD.axis[1] == 4);
  TEST_ASSERT(sut_twoD.axis[2] == 0);

  Dimensions sut_threeD{5, 4, 3};
  TEST_ASSERT(sut_threeD.axis[0] == 5);
  TEST_ASSERT(sut_threeD.axis[1] == 4);
  TEST_ASSERT(sut_threeD.axis[2] == 3);
}

void
distance_to(void) {

  // Testing distance between same dimensions

  Dimensions sut_oneD{2};
  Dimensions oneD{4};
  TEST_CHECK(TEST_FLOAT(sut_oneD.distanceTo(oneD), 2, error));

  Dimensions sut_twoD{2, 3};
  Dimensions twoD{3, 4};
  TEST_CHECK(TEST_FLOAT(sut_twoD.distanceTo(twoD), 1.4142135623731, error));

  Dimensions sut_threeD{2, 3, 4};
  Dimensions threeD{3, 4, 5};
  TEST_CHECK(TEST_FLOAT(sut_threeD.distanceTo(threeD), 1.7320508075689, error));

  // Testing distance between higher/lower dimensions

  TEST_CHECK(TEST_FLOAT(sut_threeD.distanceTo(sut_oneD), 5, error));
  TEST_CHECK(TEST_FLOAT(sut_oneD.distanceTo(sut_threeD), 5, error));
  TEST_CHECK(TEST_FLOAT(sut_threeD.distanceTo(sut_twoD), 4, error));
  TEST_CHECK(TEST_FLOAT(sut_twoD.distanceTo(sut_threeD), 4, error));
  TEST_CHECK(TEST_FLOAT(sut_twoD.distanceTo(sut_oneD), 3, error));
  TEST_CHECK(TEST_FLOAT(sut_oneD.distanceTo(sut_twoD), 3, error));
}

void
boolean_comparisons(void) {
  Dimensions sut_oneD{2};
  Dimensions oneD_equal{2};
  Dimensions oneD_not_equal{5};

  TEST_CHECK(sut_oneD == oneD_equal);
  TEST_CHECK(sut_oneD != oneD_not_equal);

  Dimensions sut_twoD{2, 3};
  Dimensions twoD_equal{2, 3};
  Dimensions twoD_not_equal{5, 6};

  TEST_CHECK(sut_twoD == twoD_equal);
  TEST_CHECK(sut_twoD != twoD_not_equal);

  Dimensions sut_threeD{2, 3, 4};
  Dimensions threeD_equal{2, 3, 4};
  Dimensions threeD_not_equal{5, 6, 7};

  TEST_CHECK(sut_threeD == threeD_equal);
  TEST_CHECK(sut_threeD != threeD_not_equal);

  TEST_CHECK(sut_oneD != sut_twoD);
  TEST_CHECK(sut_twoD != sut_threeD);

  TEST_CHECK(!(sut_oneD == sut_twoD));
  TEST_CHECK(!(sut_twoD == sut_threeD));
}

}  // namespace dimensions_TESTS

#define dimensions_tests                                                                                     \
  {"DIMENSIONS: Dimension Initializes Properly", dimensions_TESTS::proper_initialization},                   \
      {"DIMENSIONS: distanceTo Gets Proper Result", dimensions_TESTS::distance_to}, {                        \
    "DIMENSIONS: Equality between Dimensions can be checked", dimensions_TESTS::boolean_comparisons          \
  }