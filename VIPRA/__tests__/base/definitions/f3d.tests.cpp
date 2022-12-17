#include <gtest/gtest.h>

#include "definitions/type_definitions.hpp"

constexpr float error = 0.01;

TEST(TypeTests, Initialization) {
  VIPRA::f3d sutDefault;
  EXPECT_EQ(sutDefault.x, 0);
  EXPECT_EQ(sutDefault.y, 0);
  EXPECT_EQ(sutDefault.z, 0);

  VIPRA::f3d sut_oneD{5};
  EXPECT_EQ(sut_oneD.x, 5);
  EXPECT_EQ(sut_oneD.y, 0);
  EXPECT_EQ(sut_oneD.z, 0);

  VIPRA::f3d sut_twoD{5, 4};
  EXPECT_EQ(sut_twoD.x, 5);
  EXPECT_EQ(sut_twoD.y, 4);
  EXPECT_EQ(sut_twoD.z, 0);

  VIPRA::f3d sut_threeD{5, 4, 3};
  EXPECT_EQ(sut_threeD.x, 5);
  EXPECT_EQ(sut_threeD.y, 4);
  EXPECT_EQ(sut_threeD.z, 3);
}

TEST(TypeTests, DistanceTo) {

  // Testing distance between same dimensions

  VIPRA::f3d sut_oneD{2};
  VIPRA::f3d oneD{4};
  EXPECT_FLOAT_EQ(sut_oneD.distanceTo(oneD), 2);

  VIPRA::f2d sut_twoD{2, 3};
  VIPRA::f2d twoD{3, 4};
  EXPECT_FLOAT_EQ(sut_twoD.distanceTo(twoD), 1.4142135623731);

  VIPRA::f3d sut_threeD{2, 3, 4};
  VIPRA::f3d threeD{3, 4, 5};
  EXPECT_FLOAT_EQ(sut_threeD.distanceTo(threeD), 1.7320508075689);

  // Testing distance between higher/lower dimensions

  EXPECT_FLOAT_EQ(sut_threeD.distanceTo(sut_oneD), 5);
  EXPECT_FLOAT_EQ(sut_oneD.distanceTo(sut_threeD), 5);
  EXPECT_FLOAT_EQ(sut_threeD.distanceTo(sut_twoD), 4);
  EXPECT_FLOAT_EQ(sut_oneD.distanceTo(sut_twoD), 3);
}

TEST(TypeTests, BooleanComparisons) {
  VIPRA::f3d sut_oneD{2};
  VIPRA::f3d oneD_equal{2};
  VIPRA::f3d oneD_not_equal{5};

  EXPECT_EQ(sut_oneD, oneD_equal);
  EXPECT_NE(sut_oneD, oneD_not_equal);

  VIPRA::f3d sut_twoD{2, 3};
  VIPRA::f3d twoD_equal{2, 3};
  VIPRA::f3d twoD_not_equal{5, 6};

  EXPECT_EQ(sut_twoD, twoD_equal);
  EXPECT_NE(sut_twoD, twoD_not_equal);

  VIPRA::f3d sut_threeD{2, 3, 4};
  VIPRA::f3d threeD_equal{2, 3, 4};
  VIPRA::f3d threeD_not_equal{5, 6, 7};

  EXPECT_EQ(sut_threeD, threeD_equal);
  EXPECT_NE(sut_threeD, threeD_not_equal);

  EXPECT_NE(sut_oneD, sut_twoD);
  EXPECT_NE(sut_twoD, sut_threeD);
}