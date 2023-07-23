
#include "pathing_graph.hpp"

#include <spdlog/spdlog.h>

#include <cmath>

namespace CalmPath {

static constexpr float floatError = 0.0001;

/**
 * @brief determins if two vectors are equal in contents.
 *
 * @param first First vector to compare.
 * @param second Second vector to compare.
 * @return true
 * @return false
 */
bool GridPoint::vectorEq(const std::vector<GridPoint*>& first,
                         const std::vector<GridPoint*>& second) {
  if (first.size() != second.size()) {
    return false;
  }
  return std::equal(first.begin(), first.end(), second.begin());
}

/**
 * @brief determines if a point is inside a distance surrounding a center point.
 *
 * @param point Point to compare.
 * @param center Center point.
 * @param size Distance surrounding the center. 
 * @return true
 * @return false
 */
inline bool inside(VIPRA::f3d point, VIPRA::f3d center, float size) {
  VIPRA::f3d tl{center.x - size / 2, center.y + size / 2};
  VIPRA::f3d br{center.x + size / 2, center.y - size / 2};
  return (point.x >= tl.x && point.x <= br.x && point.y <= tl.y && point.y >= br.y);
}

/**
 * @brief determines if two float values are equivalent.
 *
 * @param first First float for comparison.
 * @param second Second float for comparison.
 * @return true
 * @return false
 */
inline bool floatEq(float first, float second) {
  return std::fabs(first - second) < floatError;
}

/**
 * @brief returns an index of a x, y pair.
 *
 * @param x X-coordinate.
 * @param y Y-coordinate.
 * @param xCnt
 * @return VIPRA::idx
 */
VIPRA::idx PathingGraph::getIndex(VIPRA::size gridX, VIPRA::size gridY,
                                  VIPRA::size xCnt) {
  return gridX + (gridY * xCnt);
}

/**
 * @brief starts processes to build the points and adjacencies for the obstacle set.
 *
 * @param obsSet Obstacle set for the simulation.
 * @param gridSz Size of the grid being built.
 * @param obsBufferDist
 */
void PathingGraph::build(const ObstacleSet& obsSet, float gridSz, float obsBufferDist) {
  gridSize = gridSz;
  constructPoints(obsSet, obsBufferDist);
  buildAdjacencies();
}

/**
 * @brief creates the set of GridPoints used on the map.
 *
 * @param obsSet Obstacle set for the simulation.
 * @param obsBufferDist 
 */
void PathingGraph::constructPoints(const ObstacleSet& obsSet, float obsBufferDist) {
  dimensions = obsSet.getMapDimensions();
  setGridCounts();

  VIPRA::f3d center{dimensions.first};
  center.x += gridSize / 2;
  center.y += gridSize / 2;

  for (VIPRA::size gridY = 0; gridY < yCnt; ++gridY) {
    for (VIPRA::size gridX = 0; gridX < xCnt; ++gridX) {
      const auto nearest = obsSet.nearestObstacle(center);
      const auto dist = nearest.distanceTo(center);
      if (dist > obsBufferDist) {
        points.emplace_back(center, true, false);
      } else {
        points.emplace_back(center, false, !inside(nearest, center, gridSize));
      }

      center.x += gridSize;
    }
    center.y += gridSize;
    center.x = dimensions.first.x;
  }
}

/**
 * @brief builds a vector of adjacent GridPoints for each GridPoint.
 * 
 */
void PathingGraph::buildAdjacencies() {
  const std::array<std::pair<int, int>, 8> checkPoints{std::pair<int, int>{-1, 0},
                                                       {1, 0},
                                                       {0, 1},
                                                       {0, -1},
                                                       {1, 1},
                                                       {-1, 1},
                                                       {-1, -1},
                                                       {1, -1}};

  for (VIPRA::size gridY = 0; gridY < yCnt; ++gridY) {
    for (VIPRA::size gridX = 0; gridX < xCnt; ++gridX) {
      VIPRA::idx index = getIndex(gridX, gridY, xCnt);
      auto&      point = points[index];

      if (!point.traversable) continue;

      for (auto dif : checkPoints) {
        int tempX = static_cast<int>(gridX) + dif.first;
        int tempY = static_cast<int>(gridY) + dif.second;

        if (tempX < 0 || tempY < 0 || tempX >= static_cast<int>(xCnt) ||
            tempY >= static_cast<int>(yCnt))
          continue;

        auto checkIdx = getIndex(tempX, tempY, xCnt);

        auto& adjacentGrid = points[static_cast<VIPRA::idx>(checkIdx)];

        if (adjacentGrid.traversable) {
          points[index].adj.push_back(&adjacentGrid);
        }
      }
    }
  }
}

/**
 * @brief adds adjacent coordinates to a string value for representation of the GridPoints.
 *
 * @param node Parent GridPoint to record adjacent grid points.
 * @param str Holds the node's adjacent coordinates.
 */
void PathingGraph::addAdjToString(const GridPoint& node, std::string& str) {
  for (auto* const adj : node.adj) {
    str += fmt::format(R"({{"x": {}, "y": {}}},)", adj->center.x, adj->center.y);
  }
  if (!node.adj.empty()) {
    str.pop_back();
  }
}

/**
 * @brief Creates and returns a string representation of the pathing graph.
 *
 * @return std::string
 */
std::string PathingGraph::toString() const {
  std::string treeStr = "{ \"GridPoints\":[";

  for (VIPRA::size gridY = 0; gridY < yCnt; ++gridY) {
    for (VIPRA::size gridX = 0; gridX < xCnt; ++gridX) {
      VIPRA::idx  index = getIndex(gridX, gridY, xCnt);
      const auto& node = points[index];

      treeStr +=
          fmt::format(R"({{"x":{} , "y":{}, "trav": {}, "buffer": {}, "adj":[)",
                      node.center.x, node.center.y, (node.traversable ? "true" : "false"),
                      (node.buffer ? "true" : "false"));
      addAdjToString(node, treeStr);
      treeStr += "]},";
    }
  }
  treeStr.pop_back();
  treeStr += "]}";
  return treeStr;
}

/**
 * @brief searches the graph for a desired point.
 *
 * @param pos Desired position to see if it is in the graph.
 * @return GridPoint*
 */
GridPoint* PathingGraph::search(VIPRA::f3d pos) {
  const auto& [minDim, maxDim] = dimensions;

  auto gridX = static_cast<VIPRA::idx>(std::floor((pos.x - minDim.x) / gridSize));
  auto gridY = static_cast<VIPRA::idx>(std::floor((pos.y - minDim.y) / gridSize));

  VIPRA::idx idx = getIndex(gridX, gridY, xCnt);

  if (idx >= points.size()) {
    throw std::out_of_range("Pathing Graph Search: Index out of range: X: " +
                            std::to_string(gridX) + ", Y: " + std::to_string(gridY));
  }

  return &points[idx];
}

void PathingGraph::setGridCounts() {
  auto [minDim, maxDim] = dimensions;
  auto dif = maxDim - minDim;
  xCnt = static_cast<VIPRA::size>(std::ceil(dif.x / gridSize) + 1);
  yCnt = static_cast<VIPRA::size>(std::ceil(dif.y / gridSize) + 1);
}
}  // namespace CalmPath