
#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <definitions/type_definitions.hpp>
#include <util/timed_latch.hpp>

using ::testing::AllOf;
using ::testing::Ge;
using ::testing::Le;

TEST(TimedLatch, LatchCheck) {
  BHVR::TimedLatch sut(2);
  sut.latch(1);

  EXPECT_TRUE(sut.check(1.2));
  EXPECT_TRUE(sut.check(1.4));
  EXPECT_TRUE(sut.check(1.6));
  EXPECT_TRUE(sut.check(1.8));
  EXPECT_FALSE(sut.check(4));
  EXPECT_FALSE(sut.check(4.2));

  sut.latch(5);

  EXPECT_TRUE(sut.check(5.2));
  EXPECT_TRUE(sut.check(5.4));
  EXPECT_TRUE(sut.check(5.6));

  sut.latch(6);

  EXPECT_TRUE(sut.check(5.8));
  EXPECT_FALSE(sut.check(7));
  EXPECT_FALSE(sut.check(7.2));
}

TEST(LatchCollection, LatchCheck) {
  BHVR::LatchCollection sut({1, 5}, 123);
  sut.addLatches(10);

  VIPRA::time_s dur = sut.getDuration(4);
  sut.latch(1, 4);
  EXPECT_TRUE(sut.check(1.2, 4));
  EXPECT_TRUE(sut.check(1.4, 4));
  EXPECT_TRUE(sut.check(1.6, 4));
  EXPECT_TRUE(sut.check(1.8, 4));
  EXPECT_FALSE(sut.check(1 + dur, 4));
  EXPECT_FALSE(sut.check(1.2 + dur, 4));

  VIPRA::time_s dur2 = sut.getDuration(10);
  sut.latch(1, 10);
  EXPECT_TRUE(sut.check(1.2, 10));
  EXPECT_TRUE(sut.check(1.10, 10));
  EXPECT_TRUE(sut.check(1.6, 10));
  EXPECT_TRUE(sut.check(1.8, 10));
  EXPECT_FALSE(sut.check(1 + dur2, 10));
  EXPECT_FALSE(sut.check(1.2 + dur2, 10));
}

TEST(LatchCollection, AddLatches) {
  BHVR::LatchCollection sut({1, 5}, 123);
  sut.addLatches(25);
  EXPECT_EQ(sut.count(), 25);
  for (VIPRA::idx i = 0; i < sut.count(); ++i) {
    VIPRA::time_s dur = sut.getDuration(i);
    EXPECT_THAT(dur, AllOf(Ge(1), Le(5)));
  }

  BHVR::LatchCollection sut2({1, 5}, 3463);
  sut2.addLatches(25);
  EXPECT_EQ(sut2.count(), 25);
  for (VIPRA::idx i = 0; i < sut2.count(); ++i) {
    VIPRA::time_s dur = sut2.getDuration(i);
    EXPECT_THAT(dur, AllOf(Ge(1), Le(5)));
  }
}