#ifndef GRAPH_BUILD_TESTS_HPP
#define GRAPH_BUILD_TESTS_HPP

#include "../../../Modules/Goals/calm_goals/adjacencyGraph.hpp"
#include "../acutest/acutest.h"
#include "../acutest/extraTests.hpp"

namespace graph_build_TESTS {

class testGraph : public CalmPath::Graph {
 public:
  std::optional<Dimensions> testLineIntersect(const Dimensions& start1,
                                              const Dimensions& end1,
                                              const Dimensions& start2,
                                              const Dimensions& end2) const {
    return this->lineIntersect(start1, end1, start2, end2);
  }

  std::optional<IntersectPoint> testQuadEdgeIntersect(CalmPath::Quad*   quad,
                                                      const Dimensions& start,
                                                      const Dimensions& end) const {
    return this->quadEdgeIntersect(quad, start, end);
  }
};

void
testLineIntersect(void) {
  testGraph graph;

  // intersecting lines
  const auto test1 = graph.testLineIntersect({2, 3}, {-6, -13}, {-4, -10}, {2, 8});
  const auto test2 = graph.testLineIntersect({-4, -10}, {2, 8}, {2, 3}, {-6, -13});
  TEST_ASSERT(test1.has_value() && test2.has_value());
  TEST_ASSERT(test1.value() == test2.value());
  TEST_ASSERT((test1.value() == Dimensions{-3, -7}));

  // paralell lines
  const auto test3 = graph.testLineIntersect({0, 2}, {-2, -4}, {2, 5}, {0, -1});
  const auto test4 = graph.testLineIntersect({2, 5}, {0, -1}, {0, 2}, {-2, -4});
  TEST_ASSERT(!(test3.has_value() || test4.has_value()));

  // lines that would intersect if they were infinite
  const auto test5 = graph.testLineIntersect({0, 0}, {6, 6}, {6, 2}, {10, 2});
  const auto test6 = graph.testLineIntersect({6, 2}, {10, 2}, {0, 0}, {6, 6});
  TEST_ASSERT(!(test5.has_value() || test6.has_value()));

  // lines touch at point
  const auto test7 = graph.testLineIntersect({0, 0}, {6, 6}, {6, 6}, {10, 6});
  const auto test8 = graph.testLineIntersect({6, 6}, {10, 6}, {0, 0}, {6, 6});
  TEST_ASSERT(test7.has_value() && test8.has_value());
  TEST_ASSERT(test7.value() == test8.value());
  TEST_ASSERT((test7.value() == Dimensions{6, 6}));
}

void
testQuadIntersect(void) {
  testGraph      graph;
  CalmPath::Quad quad1{{0, 0}, 2, true, nullptr, nullptr, nullptr, nullptr};
  const auto     test1 = graph.testQuadEdgeIntersect(&quad1, {2, 5}, {-2, -7});

  TEST_ASSERT(test1.has_value());
  TEST_ASSERT(TEST_DIMENSIONS(test1.value().point, Dimensions{0, -1}, 0.001));
  TEST_ASSERT((test1.value().direction == Dimensions{0, -1}));

  const auto test2 = graph.testQuadEdgeIntersect(&quad1, {-2, -7}, {2, 5});
  TEST_ASSERT(test2.has_value());
  TEST_ASSERT(TEST_DIMENSIONS(test2.value().point, Dimensions{(2.0 / 3.0), 1}, 0.001));
  TEST_ASSERT(TEST_DIMENSIONS(test2.value().direction, Dimensions{0, 1}, 0.001));
}

}  // namespace graph_build_TESTS

#define graph_build_tests                                                                                    \
  {"GRAPH BUILDING: Test Line Intersect", graph_build_TESTS::testLineIntersect}, {                           \
    "GRAPH BUILDING: Test Quad Intersect", graph_build_TESTS::testQuadIntersect                              \
  }

#endif