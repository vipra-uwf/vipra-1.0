

#include <gtest/gtest.h>

#include <cstdint>
#include <limits>
#include <randomization/random.hpp>
#include <values/numeric_value.hpp>
#include <vector>
#include "values/values.hpp"

TEST(NumericValue, RandomSame) {
  BHVR::NumericValue sut(123, BHVR::RandomNumberValue{1, 300});

  std::vector<float> values(100);
  for (int i = 0; i < 100; ++i) {
    values.at(i) = sut.value(i);
  }

  for (int i = 0; i < 100; ++i) {
    EXPECT_EQ(values.at(i), sut.value(i));
  }
  for (int i = 0; i < 100; ++i) {
    EXPECT_EQ(values.at(i), sut.value(i));
  }

  BHVR::NumericValue sut2(346346, BHVR::RandomNumberValue{500, 1234});

  std::vector<float> values2(100);
  for (int i = 0; i < 100; ++i) {
    values2.at(i) = sut2.value(i);
  }

  for (int i = 0; i < 100; ++i) {
    EXPECT_EQ(values2.at(i), sut2.value(i));
  }
  for (int i = 0; i < 100; ++i) {
    EXPECT_EQ(values2.at(i), sut2.value(i));
  }
}

TEST(NumericValue, ExactValue) {
  BHVR::NumericValue sut(123, BHVR::ExactValue{10.5});
  BHVR::NumericValue sut2(34536, BHVR::ExactValue{10.5});

  for (int i = 0; i < 100; ++i) {
    EXPECT_EQ(sut.value(i), 10.5);
    EXPECT_EQ(sut2.value(i), 10.5);
  }
}