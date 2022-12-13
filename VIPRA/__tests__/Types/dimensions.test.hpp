#pragma once

#include "../acutest/acutest.h"
#include "../acutest/extraTests.hpp"

#include "../../Base/definitions/type_definitions.hpp"

namespace dimensions_TESTS {

constexpr float error = 0.01;

void
proper_initialization(void) {
  VIPRA::f3d sutDefault;
  TEST_ASSERT(sutDefault.x == 0);
  TEST_ASSERT(sutDefault.y == 0);
  TEST_ASSERT(sutDefault.z == 0);

  VIPRA::f3d sut_oneD{5};
  TEST_ASSERT(sut_oneD.x == 5);
  TEST_ASSERT(sut_oneD.y == 0);
  TEST_ASSERT(sut_oneD.z == 0);

  VIPRA::f3d sut_twoD{5, 4};
  TEST_ASSERT(sut_twoD.x == 5);
  TEST_ASSERT(sut_twoD.y == 4);
  TEST_ASSERT(sut_twoD.z == 0);

  VIPRA::f3d sut_threeD{5, 4, 3};
  TEST_ASSERT(sut_threeD.x == 5);
  TEST_ASSERT(sut_threeD.y == 4);
  TEST_ASSERT(sut_threeD.z == 3);
}

void
distance_to(void) {

  // Testing distance between same dimensions

  VIPRA::f3d sut_oneD{2};
  VIPRA::f3d oneD{4};
  TEST_CHECK(TEST_FLOAT(sut_oneD.distanceTo(oneD), 2, error));

  VIPRA::f3d sut_twoD{2, 3};
  VIPRA::f3d twoD{3, 4};
  TEST_CHECK(TEST_FLOAT(sut_twoD.distanceTo(twoD), 1.4142135623731, error));

  VIPRA::f3d sut_threeD{2, 3, 4};
  VIPRA::f3d threeD{3, 4, 5};
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
  VIPRA::f3d sut_oneD{2};
  VIPRA::f3d oneD_equal{2};
  VIPRA::f3d oneD_not_equal{5};

  TEST_CHECK(sut_oneD == oneD_equal);
  TEST_CHECK(sut_oneD != oneD_not_equal);

  VIPRA::f3d sut_twoD{2, 3};
  VIPRA::f3d twoD_equal{2, 3};
  VIPRA::f3d twoD_not_equal{5, 6};

  TEST_CHECK(sut_twoD == twoD_equal);
  TEST_CHECK(sut_twoD != twoD_not_equal);

  VIPRA::f3d sut_threeD{2, 3, 4};
  VIPRA::f3d threeD_equal{2, 3, 4};
  VIPRA::f3d threeD_not_equal{5, 6, 7};

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
    "DIMENSIONS: Equality between VIPRA::f3d can be checked", dimensions_TESTS::boolean_comparisons          \
  }