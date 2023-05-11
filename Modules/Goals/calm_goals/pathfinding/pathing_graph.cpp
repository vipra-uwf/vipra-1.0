
#include "pathing_graph.hpp"

#include <spdlog/spdlog.h>

namespace CalmPath {

inline bool
inside(VIPRA::f3d point, VIPRA::f3d center, float size) {
  VIPRA::f3d tl{center.x - size / 2, center.y + size / 2};
  VIPRA::f3d br{center.x + size / 2, center.y - size / 2};
  return (point.x >= tl.x && point.x <= br.x && point.y <= tl.y && point.y >= br.y);
}

inline bool
floatEq(float first, float second) {
  return fabs(first - second) < 0.0001;
}

inline VIPRA::idx
getIndex(VIPRA::size x, VIPRA::size y, VIPRA::size xCnt) {
  return x + (y * xCnt);
}

void
PathingGraph::build(const ObstacleSet& obsSet, float gridSz, float obsBufferDist) {
  this->gridSize = gridSz;
  constructPoints(obsSet, obsBufferDist);
  buildAdjacencies();
}

void
PathingGraph::constructPoints(const ObstacleSet& obsSet, float obsBufferDist) {
  dimensions = obsSet.getMapDimensions();
  xCnt = static_cast<VIPRA::size>(std::ceil(dimensions.x / gridSize) + 1);
  yCnt = static_cast<VIPRA::size>(std::ceil(dimensions.y / gridSize) + 1);
  VIPRA::f3d center;

  for (VIPRA::size y = 0; y < yCnt; ++y) {
    for (VIPRA::size x = 0; x < xCnt; ++x) {
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
    center.x = 0;
  }
}

void
PathingGraph::buildAdjacencies() {
  int                      cnt = static_cast<int>(xCnt);
  const std::array<int, 8> checkPoints{-1, 1, cnt, (-cnt), cnt + 1, cnt - 1, (-cnt) + 1, (-cnt) - 1};

  for (VIPRA::size y = 0; y < yCnt; ++y) {
    for (VIPRA::size x = 0; x < xCnt; ++x) {
      VIPRA::idx index = getIndex(x, y, xCnt);
      auto&      point = points[index];

      if (!point.traversable)
        continue;

      for (auto dif : checkPoints) {
        int checkIdx = static_cast<int>(index) + dif;
        int pointCnt = static_cast<int>(points.size());

        if (checkIdx < 0 && checkIdx >= pointCnt)
          continue;

        auto& adjacentGrid = points[static_cast<VIPRA::idx>(checkIdx)];

        if (adjacentGrid.traversable) {
          points[index].adj.push_back(&adjacentGrid);
        }
      }
    }
  }
}

void
PathingGraph::addAdjToString(const GridPoint& node, std::string& str) const {
  for (const auto adj : node.adj) {
    str += fmt::format("{{\"x\": {}, \"y\": {}}},", adj->center.x, adj->center.y);
  }
  if (node.adj.size() > 0) {
    str.pop_back();
  }
}

std::string
PathingGraph::toString() const {
  std::string treeStr = "{ \"GridPoints\":[";

  for (VIPRA::size y = 0; y < yCnt; ++y) {
    for (VIPRA::size x = 0; x < xCnt; ++x) {
      VIPRA::idx index = getIndex(x, y, xCnt);
      auto&      node = points[index];

      treeStr += fmt::format("{{\"x\":{} , \"y\":{}, \"trav\": {}, \"buffer\": {}, \"adj\":[",
                             node.center.x,
                             node.center.y,
                             (node.traversable ? "true" : "false"),
                             (node.buffer ? "true" : "false"));
      addAdjToString(node, treeStr);
      treeStr += "]},";
    }
  }
  treeStr.pop_back();
  treeStr += "]}";
  return treeStr;
}

GridPoint*
PathingGraph::search(VIPRA::f3d pos) {
  VIPRA::idx x = static_cast<VIPRA::idx>(std::floor(pos.x / gridSize));
  VIPRA::idx y = static_cast<VIPRA::idx>(std::floor(pos.y / gridSize));

  VIPRA::idx idx = getIndex(x, y, xCnt);

  if (idx >= points.size()) {
    throw std::out_of_range("Pathing Graph Search: Index out of range: X: " + std::to_string(x) +
                            ", Y: " + std::to_string(y));
  }

  return &points[idx];
}

}  // namespace CalmPath
