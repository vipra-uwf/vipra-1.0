#include <gtest/gtest.h>

#include "definitions/type_definitions.hpp"

const float ERROR = 0.001;

TEST(Dimensions, Default_Constructor_Tests) {
  VIPRA::f3d sutf3d;
  VIPRA::f2d sutf2d;

  EXPECT_EQ(sutf2d.x, 0);
  EXPECT_EQ(sutf2d.y, 0);

  EXPECT_EQ(sutf3d.x, 0);
  EXPECT_EQ(sutf3d.y, 0);
  EXPECT_EQ(sutf3d.z, 0);
}

TEST(Dimensions, Parameterized_Constructor_Tests) {
  VIPRA::f3d sutf3d1{1};
  VIPRA::f2d sutf2d1{1};
  EXPECT_EQ(sutf2d1.x, 1);
  EXPECT_EQ(sutf2d1.y, 0);
  EXPECT_EQ(sutf3d1.x, 1);
  EXPECT_EQ(sutf3d1.y, 0);
  EXPECT_EQ(sutf3d1.z, 0);

  VIPRA::f3d sutf3d2{1, 2};
  VIPRA::f2d sutf2d2{1, 2};
  EXPECT_EQ(sutf2d2.x, 1);
  EXPECT_EQ(sutf2d2.y, 2);
  EXPECT_EQ(sutf3d2.x, 1);
  EXPECT_EQ(sutf3d2.y, 2);
  EXPECT_EQ(sutf3d2.z, 0);

  VIPRA::f3d sutf3d3{1, 2, 3};
  EXPECT_EQ(sutf3d3.x, 1);
  EXPECT_EQ(sutf3d3.y, 2);
  EXPECT_EQ(sutf3d3.z, 3);
}

TEST(Dimensions, CopyMove_Constructor_Tests) {
  VIPRA::f2d sutf2d1{1, 2};
  VIPRA::f3d sutf3d1{1, 2, 3};
  VIPRA::f2d sutf2d2{sutf2d1};
  VIPRA::f3d sutf3d2{sutf3d1};
  EXPECT_EQ(sutf2d2.x, 1);
  EXPECT_EQ(sutf2d2.y, 2);
  EXPECT_EQ(sutf3d2.x, 1);
  EXPECT_EQ(sutf3d2.y, 2);
  EXPECT_EQ(sutf3d2.z, 3);

  VIPRA::f2d sutf2d3{1, 2};
  VIPRA::f3d sutf3d3{1, 2, 3};
  VIPRA::f2d sutf2d4{std::move(sutf2d3)};
  VIPRA::f3d sutf3d4{std::move(sutf3d3)};
  EXPECT_EQ(sutf2d4.x, 1);
  EXPECT_EQ(sutf2d4.y, 2);
  EXPECT_EQ(sutf3d4.x, 1);
  EXPECT_EQ(sutf3d4.y, 2);
  EXPECT_EQ(sutf3d4.z, 3);
}

TEST(Dimensions, CopyMove_Operators_Tests) {
  VIPRA::f2d sutf2d1{1, 2};
  VIPRA::f3d sutf3d1{1, 2, 3};
  VIPRA::f2d sutf2d2;
  VIPRA::f3d sutf3d2;
  sutf2d2 = sutf2d1;
  sutf3d2 = sutf3d1;

  EXPECT_EQ(sutf2d2.x, 1);
  EXPECT_EQ(sutf2d2.y, 2);
  EXPECT_EQ(sutf3d2.x, 1);
  EXPECT_EQ(sutf3d2.y, 2);
  EXPECT_EQ(sutf3d2.z, 3);

  VIPRA::f2d sutf2d3{1, 2};
  VIPRA::f3d sutf3d3{1, 2, 3};
  VIPRA::f2d sutf2d4;
  VIPRA::f3d sutf3d4;
  sutf2d4 = std::move(sutf2d3);
  sutf3d4 = std::move(sutf3d3);
  EXPECT_EQ(sutf2d4.x, 1);
  EXPECT_EQ(sutf2d4.y, 2);
  EXPECT_EQ(sutf3d4.x, 1);
  EXPECT_EQ(sutf3d4.y, 2);
  EXPECT_EQ(sutf3d4.z, 3);
}

TEST(Dimensions, Conversions_Tests) {
  VIPRA::f2d sutf2d1{1, 2};
  VIPRA::f3d sutf3d1{sutf2d1};
  EXPECT_EQ(sutf3d1.x, 1);
  EXPECT_EQ(sutf3d1.y, 2);
  EXPECT_EQ(sutf3d1.z, 0);
}

TEST(Dimensions, Bracket_Operator_Tests) {
  VIPRA::f2d sutf2d1{1, 2};
  EXPECT_EQ(sutf2d1[0], 1);
  EXPECT_EQ(sutf2d1['x'], 1);
  EXPECT_EQ(sutf2d1[1], 2);
  EXPECT_EQ(sutf2d1['y'], 2);
  EXPECT_THROW(sutf2d1[2], std::out_of_range);
  EXPECT_THROW(sutf2d1['z'], std::out_of_range);

  VIPRA::f3d sutf3d1{1, 2, 3};
  EXPECT_EQ(sutf3d1[0], 1);
  EXPECT_EQ(sutf3d1['x'], 1);
  EXPECT_EQ(sutf3d1[1], 2);
  EXPECT_EQ(sutf3d1['y'], 2);
  EXPECT_EQ(sutf3d1[2], 3);
  EXPECT_EQ(sutf3d1['z'], 3);
  EXPECT_THROW(sutf3d1[3], std::out_of_range);
  EXPECT_THROW(sutf3d1['a'], std::out_of_range);
}

TEST(Dimensions, Unit_Vector) {
  VIPRA::f3d sut1{0, 0, 0};
  VIPRA::f3d sut2{1, 0, 0};
  VIPRA::f3d sut3{0, 1, 0};

  EXPECT_EQ(sut1.unit(), VIPRA::f3d(0, 0, 0));
  EXPECT_EQ(sut2.unit(), VIPRA::f3d(1, 0, 0));
  EXPECT_EQ(sut3.unit(), VIPRA::f3d(0, 1, 0));

  VIPRA::f3d sut4 = VIPRA::f3d{1, 1, 0}.unit();
  EXPECT_NEAR(sut4.x, 1 / std::sqrt(2), 0.001);
  EXPECT_NEAR(sut4.y, 1 / std::sqrt(2), 0.001);
}

TEST(Dimensions, Unary_Operators) {
  VIPRA::f3d sut1{0, 0, 0};
  VIPRA::f3d sut2{1, 2, 3};

  EXPECT_EQ(-sut1, VIPRA::f3d(0, 0, 0));
  EXPECT_EQ(-sut2, VIPRA::f3d(-1, -2, -3));
}

TEST(Dimensions, Magnitude) {
  VIPRA::f3d sut1{0, 0, 0};
  VIPRA::f3d sut2{1, 0, 0};
  VIPRA::f3d sut3{0, 1, 0};
  VIPRA::f3d sut4{1, 1, 0};
  EXPECT_NEAR(sut1.magnitude(), 0, 0.01);
  EXPECT_NEAR(sut2.magnitude(), 1, 0.01);
  EXPECT_NEAR(sut3.magnitude(), 1, 0.01);
  EXPECT_NEAR(sut4.magnitude(), std::sqrt(2), 0.01);
}

// TODO test that +, +=, -, -=, *, *=, /, /= operators work

TEST(Dimensions, Binary_Operators_Tests) {
  //operator+
  VIPRA::f3d sut1{1, 2, 3};
  VIPRA::f3d addtest;
  addtest = sut1 + VIPRA::f3d{1, 1, 1};
  EXPECT_EQ(addtest.x, 2);
  EXPECT_EQ(addtest.y, 3);
  EXPECT_EQ(addtest.z, 4);

  //operator+=
  VIPRA::f3d sut2{1, 2, 3};
  sut2 += VIPRA::f3d{1, 1, 1};
  EXPECT_EQ(sut2.x, 2);
  EXPECT_EQ(sut2.y, 3);
  EXPECT_EQ(sut2.z, 4);

  // operator-
  VIPRA::f3d sut3{1, 2, 3};
  VIPRA::f3d subTest;
  subTest = sut3 - VIPRA::f3d{1, 1, 1};
  EXPECT_EQ(subTest.x, 0);
  EXPECT_EQ(subTest.y, 1);
  EXPECT_EQ(subTest.z, 2);

  // operator-=
  VIPRA::f3d sut4{1, 2, 3};
  sut4 -= VIPRA::f3d{1, 1, 1};
  EXPECT_EQ(sut4.x, 0);
  EXPECT_EQ(sut4.y, 1);
  EXPECT_EQ(sut4.z, 2);

  // operator*
  VIPRA::f3d sut5{1, 2, 3};
  VIPRA::f3d multTest;
  multTest = sut5 * 2;
  EXPECT_EQ(multTest.x, 2);
  EXPECT_EQ(multTest.y, 4);
  EXPECT_EQ(multTest.z, 6);

  // operator*=
  VIPRA::f3d sut6{1, 2, 3};
  sut6 *= 2;
  EXPECT_EQ(sut6.x, 2);
  EXPECT_EQ(sut6.y, 4);
  EXPECT_EQ(sut6.z, 6);

  // operator/
  VIPRA::f3d sut7{2, 4, 6};
  VIPRA::f3d divTest;
  divTest = sut7 / 2;
  EXPECT_EQ(divTest.x, 1);
  EXPECT_EQ(divTest.y, 2);
  EXPECT_EQ(divTest.z, 3);

  // operator/=
  VIPRA::f3d sut8{2, 4, 6};
  sut8 /= 2;
  EXPECT_EQ(sut8.x, 1);
  EXPECT_EQ(sut8.y, 2);
  EXPECT_EQ(sut8.z, 3);
}

TEST(Dimensions, Boolean_Operators_Tests) {
  VIPRA::f3d sut1{1, 2, 3};
  VIPRA::f3d sut2{2, 3, 4};
  VIPRA::f3d sut3{1, 2, 3};

  EXPECT_TRUE(sut1 == sut3);
  EXPECT_FALSE(sut1 != sut3);
  EXPECT_FALSE(sut1 == sut2);
  EXPECT_TRUE(sut1 != sut2);
}

TEST(Dimensions, Distance_To_Tests) {
  VIPRA::f3d sut1{1, 2, 3};
  VIPRA::f3d sut2{2, 3, 4};

  EXPECT_NEAR((sut1.distanceTo(sut2)), 1.7320508075689, ERROR);
  EXPECT_NEAR((sut2.distanceTo(sut1)), 1.7320508075689, ERROR);
}

TEST(Dimensions, __Empty__) {
  EXPECT_EQ(VIPRA::__emptyf2d__, VIPRA::f2d(std::numeric_limits<float>::max(), std::numeric_limits<float>::max()));
  EXPECT_EQ(VIPRA::__emptyf3d__,
            VIPRA::f3d(std::numeric_limits<float>::max(),
                       std::numeric_limits<float>::max(),
                       std::numeric_limits<float>::max()));
}

TEST(Dimensions, __Empty_Vec__) {
  EXPECT_EQ(VIPRA::__emptyf2d_Vec__, VIPRA::f2dVec());
  EXPECT_EQ(VIPRA::__emptyf3d_Vec__, VIPRA::f3dVec());
}