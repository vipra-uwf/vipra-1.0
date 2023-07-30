

#include <gtest/gtest.h>

#include <PedestrianDynamicsModel/calm_pedestrian_model/calm_rect.hpp>

TEST(CalmRect, IsPointInRect) {
  Rect sut{VIPRA::f3d{0, 0, 0}, VIPRA::f3d{0, 1, 0}, VIPRA::f3d{1, 1, 0},
           VIPRA::f3d{1, 0, 0}};

  EXPECT_FALSE(sut.isPointInRect(VIPRA::f3d{2, 0, 0}));
  EXPECT_FALSE(sut.isPointInRect(VIPRA::f3d{1.1, 0, 0}));
  EXPECT_FALSE(sut.isPointInRect(VIPRA::f3d{-0.5, -0.5, 0}));
  EXPECT_FALSE(sut.isPointInRect(VIPRA::f3d{4, 1, 0}));
  EXPECT_FALSE(sut.isPointInRect(VIPRA::f3d{7, -3, 0}));
  EXPECT_FALSE(sut.isPointInRect(VIPRA::f3d{-1, -2, 0}));

  EXPECT_TRUE(sut.isPointInRect(VIPRA::f3d{0.5, 0, 0}));
  EXPECT_TRUE(sut.isPointInRect(VIPRA::f3d{0.1, 0.236, 0}));
  EXPECT_TRUE(sut.isPointInRect(VIPRA::f3d{1, 1, 0}));
  EXPECT_TRUE(sut.isPointInRect(VIPRA::f3d{.2, .7, 0}));

  Rect sut1{VIPRA::f3d{-1, -1, 0}, VIPRA::f3d{-1, 1, 0}, VIPRA::f3d{1, 1, 0},
            VIPRA::f3d{1, -1, 0}};

  EXPECT_FALSE(sut1.isPointInRect(VIPRA::f3d{2, 0, 0}));
  EXPECT_FALSE(sut1.isPointInRect(VIPRA::f3d{1.1, 0, 0}));
  EXPECT_FALSE(sut1.isPointInRect(VIPRA::f3d{4, 1, 0}));
  EXPECT_FALSE(sut1.isPointInRect(VIPRA::f3d{7, -3, 0}));
  EXPECT_FALSE(sut1.isPointInRect(VIPRA::f3d{-1, -2, 0}));

  EXPECT_TRUE(sut1.isPointInRect(VIPRA::f3d{-0.5, -0.5, 0}));
  EXPECT_TRUE(sut1.isPointInRect(VIPRA::f3d{0.5, 0, 0}));
  EXPECT_TRUE(sut1.isPointInRect(VIPRA::f3d{0.1, 0.236, 0}));
  EXPECT_TRUE(sut1.isPointInRect(VIPRA::f3d{1, 1, 0}));
  EXPECT_TRUE(sut1.isPointInRect(VIPRA::f3d{.2, .7, 0}));
}

TEST(CalmRect, InPointInRectROTATED) {
  Rect sut{VIPRA::f3d{-0.076, 1.411, 0}, VIPRA::f3d{3.111, 2.576, 0},
           VIPRA::f3d{4.276, -0.611, 0}, VIPRA::f3d{1.089, -1.776, 0}};

  EXPECT_TRUE(sut.isPointInRect(VIPRA::f3d{.2, .7, 0}));
  EXPECT_TRUE(sut.isPointInRect(VIPRA::f3d{2.69, 1.23, 0}));
  EXPECT_TRUE(sut.isPointInRect(VIPRA::f3d{4.07, -0.56, 0}));

  EXPECT_FALSE(sut.isPointInRect(VIPRA::f3d{1.03, 1.92, 0}));
  EXPECT_FALSE(sut.isPointInRect(VIPRA::f3d{2.9, -2.18, 0}));
  EXPECT_FALSE(sut.isPointInRect(VIPRA::f3d{-1.16, 1.37, 0}));

  Rect sut1{VIPRA::f3d{6.016, 4.092, 0}, VIPRA::f3d{3.892, 0.584, 0},
            VIPRA::f3d{0.384, 2.708, 0}, VIPRA::f3d{2.508, 6.216, 0}};

  EXPECT_TRUE(sut1.isPointInRect(VIPRA::f3d{5.54, 3.99, 0}));
  EXPECT_TRUE(sut1.isPointInRect(VIPRA::f3d{1.2, 2.8, 0}));
  EXPECT_TRUE(sut1.isPointInRect(VIPRA::f3d{2.52, 6.18, 0}));

  EXPECT_FALSE(sut1.isPointInRect(VIPRA::f3d{3.52, 0.59, 0}));
  EXPECT_FALSE(sut1.isPointInRect(VIPRA::f3d{3.52, 0.59, 0}));
  EXPECT_FALSE(sut1.isPointInRect(VIPRA::f3d{2.65, 6.66, 0}));
}

TEST(CalmRect, DoRectIntersect) {
  Rect sut1_1{
      VIPRA::f3d{-2.908, 3.119},
      VIPRA::f3d{-0.461, 4.228},
      VIPRA::f3d{0.648, 1.781},
      VIPRA::f3d{-1.799, 0.672},
  };
  Rect sut1_2{
      VIPRA::f3d{0.651, -0.268},
      VIPRA::f3d{-0.458, 2.179},
      VIPRA::f3d{1.989, 3.288},
      VIPRA::f3d{3.098, 0.841},
  };

  Rect sut2{
      VIPRA::f3d{},
      VIPRA::f3d{0, 1},
      VIPRA::f3d{1, 1},
      VIPRA::f3d{1, 0},
  };

  Rect sut3{
      VIPRA::f3d{-2, -2},
      VIPRA::f3d{-2, -3},
      VIPRA::f3d{-5, -3},
      VIPRA::f3d{-5, -2},
  };

  EXPECT_TRUE(sut1_1.doesIntersect(sut1_2));
  EXPECT_TRUE(sut1_2.doesIntersect(sut1_1));
  EXPECT_FALSE(sut1_1.doesIntersect(sut2));
  EXPECT_TRUE(sut1_2.doesIntersect(sut2));

  EXPECT_FALSE(sut1_1.doesIntersect(sut3));
  EXPECT_FALSE(sut1_2.doesIntersect(sut3));
  EXPECT_FALSE(sut2.doesIntersect(sut3));
  EXPECT_FALSE(sut3.doesIntersect(sut1_1));
  EXPECT_FALSE(sut3.doesIntersect(sut1_2));
  EXPECT_FALSE(sut3.doesIntersect(sut2));

  // TODO(rolland): these shapes, very close to each other are considered touching when they should not be
  Rect sut5_1{
      VIPRA::f3d{2.8, -1.29},
      VIPRA::f3d{5.05, -2.76},
      VIPRA::f3d{3.58, -5.01},
      VIPRA::f3d{1.33, -3.54},
  };
  Rect sut5_2{
      VIPRA::f3d{5.05, -2.76},
      VIPRA::f3d{3.58, -5.01},
      VIPRA::f3d{1.33, -3.54},
      VIPRA::f3d{2.8, -1.29},
  };
  Rect sut5_3{
      VIPRA::f3d{3.58, -5.01},
      VIPRA::f3d{1.33, -3.54},
      VIPRA::f3d{2.8, -1.29},
      VIPRA::f3d{5.05, -2.76},
  };
  Rect sut5_4{
      VIPRA::f3d{1.33, -3.54},
      VIPRA::f3d{2.8, -1.29},
      VIPRA::f3d{5.05, -2.76},
      VIPRA::f3d{3.58, -5.01},
  };
  Rect sut6{
      VIPRA::f3d{0.48, 0.16},
      VIPRA::f3d{2.73, -1.31},
      VIPRA::f3d{1.26, -3.56},
      VIPRA::f3d{-0.99, -2.09},
  };

  //   EXPECT_FALSE(sut5_1.doesIntersect(sut6));
  //   EXPECT_FALSE(sut6.doesIntersect(sut5_1));

  //   EXPECT_FALSE(sut5_2.doesIntersect(sut6));
  //   EXPECT_FALSE(sut6.doesIntersect(sut5_2));

  //   EXPECT_FALSE(sut5_3.doesIntersect(sut6));
  //   EXPECT_FALSE(sut6.doesIntersect(sut5_3));

  //   EXPECT_FALSE(sut5_4.doesIntersect(sut6));
  //   EXPECT_FALSE(sut6.doesIntersect(sut5_4));

  //   EXPECT_TRUE(sut5_2.doesIntersect(sut2));
  //   EXPECT_TRUE(sut2.doesIntersect(sut5_2));

  Rect sut7{
      VIPRA::f3d{2.93, -0.78},
      VIPRA::f3d{5.18, -2.25},
      VIPRA::f3d{3.71, -4.5},
      VIPRA::f3d{1.46, -3.03},
  };

  EXPECT_TRUE(sut6.doesIntersect(sut7));
}