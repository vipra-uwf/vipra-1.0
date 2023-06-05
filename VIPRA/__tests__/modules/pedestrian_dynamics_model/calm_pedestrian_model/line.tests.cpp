

#include <gtest/gtest.h>

#include <PedestrianDynamicsModel/calm_pedestrian_model/calm_line.hpp>

TEST(CalmLine, doesIntersect) {
  Line sut1_1{VIPRA::f3d{0, 1.52}, VIPRA::f3d{3.1, -1.2}};
  Line sut1_2{VIPRA::f3d{-1.6, -1.3}, VIPRA::f3d{1.6, 1}};
  Line sut1_3{VIPRA::f3d{1.9, 1.52}, VIPRA::f3d{3.1, -1.2}};

  EXPECT_TRUE(sut1_1.doesIntersect(sut1_2));
  EXPECT_TRUE(sut1_2.doesIntersect(sut1_1));
  EXPECT_TRUE(sut1_3.doesIntersect(sut1_1));
  EXPECT_FALSE(sut1_3.doesIntersect(sut1_2));

  Line sut2_1{VIPRA::f3d{0.8, 1.9}, VIPRA::f3d{-2.8, -1.2}};
  Line sut2_2{VIPRA::f3d{3.7, -1.3}, VIPRA::f3d{1.6, 1.8}};

  EXPECT_FALSE(sut2_1.doesIntersect(sut2_2));
  EXPECT_FALSE(sut2_2.doesIntersect(sut2_1));

  //TODO(rolland): add more tests
}

TEST(CalmLine, checkIfOnLineSegment) {
  srand(0);

  Line sut{VIPRA::f3d{1, 2}, VIPRA::f3d{5.2, 9.2}};

  // Make random points along line to test
  for (VIPRA::size i = 0; i < 1000; ++i) {
    float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    auto  test = VIPRA::f3d{(1 - t) * sut.p1.x + t * sut.p2.x, (1 - t) * sut.p1.y + t * sut.p2.y};
    EXPECT_TRUE(sut.isPointOn(test));
  }

  // Make random points along line, add random number
  for (VIPRA::size i = 0; i < 1000; ++i) {
    float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    auto  test = VIPRA::f3d{((1 - t) * sut.p1.x + t * sut.p2.x) + static_cast<float>(rand()),
                           (1 - t) * sut.p1.y + t * sut.p2.y + static_cast<float>(rand())};
    EXPECT_FALSE(sut.isPointOn(test));
  }

  // Make random points along line to test
  for (VIPRA::size i = 0; i < 1000; ++i) {
    float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    auto  test = VIPRA::f3d{(1 - t) * sut.p1.x + t * sut.p2.x, (1 - t) * sut.p1.y + t * sut.p2.y};
    EXPECT_TRUE(Line::checkIfOnLineSegment(sut.p1, sut.p2, test));
  }

  // Make random points along line, add random number
  for (VIPRA::size i = 0; i < 1000; ++i) {
    float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    auto  test = VIPRA::f3d{((1 - t) * sut.p1.x + t * sut.p2.x) + static_cast<float>(rand()),
                           (1 - t) * sut.p1.y + t * sut.p2.y + static_cast<float>(rand())};
    EXPECT_FALSE(Line::checkIfOnLineSegment(sut.p1, sut.p2, test));
  }
}

TEST(CalmLine, orientation) {
  // TODO(rolland): implement tests
}

TEST(CalmLine, ClosesDistanceTo) {
  // TODO(rolland): implement tests
}
