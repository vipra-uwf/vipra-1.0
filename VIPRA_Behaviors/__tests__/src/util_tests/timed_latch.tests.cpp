
#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <definitions/type_definitions.hpp>
#include <util/timed_latch.hpp>
#include "values/numeric_value.hpp"

using ::testing::AllOf;
using ::testing::Ge;
using ::testing::Le;

TEST(TimedLatchCollection, LatchCheck) {
  BHVR::TimedLatchCollection sut(BHVR::NumericValue{123, BHVR::RandomFloatValue{1, 5}});
  sut.resize(10);

  VIPRA::time_s dur = sut.getDuration(4);
  sut.latch(1, 4);
  EXPECT_TRUE(sut.check(1.2, 4));
  EXPECT_TRUE(sut.check(1.4, 4));
  EXPECT_TRUE(sut.check(1.6, 4));
  EXPECT_TRUE(sut.check(1.8, 4));
  EXPECT_FALSE(sut.check(1 + dur, 4));
  EXPECT_FALSE(sut.check(1.2 + dur, 4));

  VIPRA::time_s dur2 = sut.getDuration(9);
  sut.latch(1, 9);
  EXPECT_TRUE(sut.check(1.2, 9));
  EXPECT_TRUE(sut.check(1.10, 9));
  EXPECT_TRUE(sut.check(1.6, 9));
  EXPECT_TRUE(sut.check(1.8, 9));
  EXPECT_TRUE(sut.check(1 + dur2, 9));
  EXPECT_FALSE(sut.check(1.2 + dur2, 9));
}