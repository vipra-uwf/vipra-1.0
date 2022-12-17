#ifndef ADJACENCYGRAPH_HPP
#define ADJACENCYGRAPH_HPP

#include "definitions/type_definitions.hpp"
#include "obstacleset/obstacle_set.hpp"
#include <optional>

constexpr bool
inside(const VIPRA::f3d& point, const VIPRA::f3d& center, float sideLength) noexcept {
  const float half = sideLength / 2;
  return (point.x >= center.x - half && point.x <= center.x + half && point.y <= center.y + half &&
          point.y >= center.y - half && point.z <= center.z + half && point.z >= center.z - half);
}

namespace CalmPath {
struct Quad {
  VIPRA::f3d         center;
  float              size;
  bool               traversable;
  Quad*              tl;
  Quad*              tr;
  Quad*              bl;
  Quad*              br;
  std::vector<Quad*> adj;
  Quad(VIPRA::f3d center, float size, bool traversable, Quad* tl, Quad* tr, Quad* bl, Quad* br)
    : center(center), size(size), traversable(traversable), tl(tl), tr(tr), bl(bl), br(br) {}
};

class Graph {
 public:
  ~Graph() {
    if (root != nullptr) {
      cleanQuad(root);
    }
  }

  void buildGraph(const ObstacleSet& obSet) {
    obs = &obSet;
    const VIPRA::f3d mapRes = obSet.getMapDimensions();
    root = construct(VIPRA::f3d{mapRes.x / 2, mapRes.y / 2}, mapRes.x);
    buildAdjacencies(root);
  }

  Quad* getRoot() const { return root; }

  [[nodiscard]] Quad* search(const VIPRA::f3d& coords) const {
    Quad* curr = nullptr;
    Quad* next = root;
    while (next != nullptr) {
      curr = next;
      if (coords.x < curr->center.x) {
        if (coords.y < curr->center.y) {
          next = curr->bl;
        } else {
          next = curr->tl;
        }
      } else {
        if (coords.y < curr->center.y) {
          next = curr->br;
        } else {
          next = curr->tr;
        }
      }
    }
    return curr;
  }

 private:
  static constexpr float gridUnit = .1;
  const ObstacleSet*     obs;
  Quad*                  root = nullptr;

 protected:
  void cleanQuad(Quad* node) {
    if (node != nullptr) {
      cleanQuad(node->bl);
      cleanQuad(node->tl);
      cleanQuad(node->br);
      cleanQuad(node->tr);
      delete node;
    }
  }

  void buildAdjacencies(Quad* curr) {
    if (curr == nullptr)
      return;

    buildAdjacencies(curr->tl);
    buildAdjacencies(curr->tr);
    buildAdjacencies(curr->bl);
    buildAdjacencies(curr->br);

    getAdjacencies(curr, root);
  }

  struct IntersectPoint {
    VIPRA::f3d point;
    VIPRA::f3d direction;
  };

  void getAdjacencies(Quad* from, Quad* to) {
    if (to == nullptr || !from->traversable)
      return;

    getAdjacencies(from, to->tl);
    getAdjacencies(from, to->tr);
    getAdjacencies(from, to->bl);
    getAdjacencies(from, to->br);

    // travel along line between nodes
    // check if grid at point is traversable
    if (to->traversable && from != to) {
      VIPRA::f3d checkPoint = from->center;
      float      d = (from->center.distanceTo(to->center) / 0.01);
      float      dx = (to->center.x - from->center.x) / d;
      float      dy = (to->center.y - from->center.y) / d;
      VIPRA::f3d move{dx, dy};
      Quad*      curr = from;
      while (curr != nullptr && curr != to) {
        checkPoint = VIPRA::f3d{checkPoint.x + move.x, checkPoint.y + move.y};
        curr = search(checkPoint);
        if (!curr->traversable) {
          return;
        }
        if (curr == to || inside(checkPoint, to->center, 0.01)) {
          from->adj.push_back(to);
          return;
        }
      }

      /**
       * start from start quad
       * find where line intersects edge of quad
       * check the quad just past there
       * if new quad is traversable
       * repeat till at end quad
       */
      // std::cout << "Getting Adjacencies for " << std::to_string(n) << "\n";
      // ++n;
      // Quad*      curr = from;
      // VIPRA::f3d checkPoint;
      // while (curr != nullptr && curr->traversable) {
      //   auto intersect = quadEdgeIntersect(curr, from->center, to->center);
      //   if (intersect.has_value()) {
      //     checkPoint.x =
      //         intersect.value().point.x + (0.0001 * intersect.value().direction.x);
      //     checkPoint.y =
      //         intersect.value().point.y + (0.0001 * intersect.value().direction.y);
      //     curr = search(checkPoint);
      //     if (curr->parent != nullptr) {
      //       if (curr->parent->center == to->center) {
      //         from->adj.push_back(to);
      //         break;
      //       }
      //     }
      //     if (curr == to) {
      //       from->adj.push_back(to);
      //       break;
      //     }
      //   }
      // }
    }
  }

  Quad* construct(VIPRA::f3d center, float size) {
    if (size <= gridUnit) {
      return nullptr;
    }

    Quad* tl = nullptr;
    Quad* tr = nullptr;
    Quad* bl = nullptr;
    Quad* br = nullptr;

    float x = center.x;
    float y = center.y;
    if (inside(obs->nearestObstacle(center), center, size)) {
      tl = construct(VIPRA::f3d{x - size / 4, y + size / 4}, size / 2);
      tr = construct(VIPRA::f3d{x + size / 4, y + size / 4}, size / 2);
      bl = construct(VIPRA::f3d{x - size / 4, y - size / 4}, size / 2);
      br = construct(VIPRA::f3d{x + size / 4, y - size / 4}, size / 2);
      if (tl != nullptr || tr != nullptr || bl != nullptr || br != nullptr) {
        return new Quad(center, size, true, tl, tr, bl, br);
      } else {
        return new Quad(center, size, false, tl, tr, bl, br);
      }
    }
    return new Quad(center, size, true, tl, tr, bl, br);
  }

  bool inside(VIPRA::f3d point, VIPRA::f3d center, float size) {
    VIPRA::f3d tl{center.x - size / 2, center.y + size / 2};
    VIPRA::f3d br{center.x + size / 2, center.y - size / 2};
    bool       i = (point.x >= tl.x && point.x <= br.x && point.y <= tl.y && point.y >= br.y);
    return i;
  }

  // inline std::optional<VIPRA::f3d> checkTop(float             quadX,
  //                                           float             quadY,
  //                                           float             halfSide,
  //                                           const VIPRA::f3d& start,
  //                                           const VIPRA::f3d& end) const {
  //   return lineIntersect(
  //       {quadX - halfSide, quadY + halfSide}, {quadX + halfSide, quadY + halfSide}, start, end);
  // }
  // inline std::optional<VIPRA::f3d> checkBottom(float             quadX,
  //                                              float             quadY,
  //                                              float             halfSide,
  //                                              const VIPRA::f3d& start,
  //                                              const VIPRA::f3d& end) const {
  //   return lineIntersect(
  //       {quadX - halfSide, quadY - halfSide}, {quadX + halfSide, quadY - halfSide}, start, end);
  // }
  // inline std::optional<VIPRA::f3d> checkRight(float             quadX,
  //                                             float             quadY,
  //                                             float             halfSide,
  //                                             const VIPRA::f3d& start,
  //                                             const VIPRA::f3d& end) const {
  //   return lineIntersect(
  //       {quadX + halfSide, quadY + halfSide}, {quadX + halfSide, quadY - halfSide}, start, end);
  // }
  // inline std::optional<VIPRA::f3d> checkLeft(float             quadX,
  //                                            float             quadY,
  //                                            float             halfSide,
  //                                            const VIPRA::f3d& start,
  //                                            const VIPRA::f3d& end) const {
  //   return lineIntersect(
  //       {quadX - halfSide, quadY + halfSide}, {quadX - halfSide, quadY - halfSide}, start, end);
  // }

  // std::optional<IntersectPoint> quadEdgeIntersect(Quad*             quad,
  //                                                 const VIPRA::f3d& start,
  //                                                 const VIPRA::f3d& end) const {
  //   float halfSide = quad->size / 2;
  //   float quadX = quad->center.x;
  //   float quadY = quad->center.y;

  //   if (end.x >= (quadX - halfSide) && end.x <= (quadX + halfSide)) {
  //     // directly above or below
  //     if (end.y > quadY) {
  //       // above
  //       auto inter = checkTop(quadX, quadY, halfSide, start, end);
  //       if (inter.has_value()) {
  //         return {{inter.value(), VIPRA::f3d{0, 1}}};
  //       }
  //     } else {
  //       // below
  //       auto inter = checkBottom(quadX, quadY, halfSide, start, end);
  //       if (inter.has_value()) {
  //         return {{inter.value(), VIPRA::f3d{0, -1}}};
  //       }
  //     }
  //   }

  //   if (end.x >= (quadX - halfSide) && end.x <= (quadX + halfSide)) {
  //     // directly left or right
  //     if (end.x > quadX) {
  //       // right
  //       auto inter = checkRight(quadX, quadY, halfSide, start, end);
  //       if (inter.has_value()) {
  //         return {{inter.value(), VIPRA::f3d{1, 0}}};
  //       }
  //     } else {
  //       // left
  //       auto inter = checkLeft(quadX, quadY, halfSide, start, end);
  //       if (inter.has_value()) {
  //         return {{inter.value(), VIPRA::f3d{-1, 0}}};
  //       }
  //     }
  //   }

  //   if (end.x > quadX) {
  //     // to the right, maybe above or below
  //     if (end.y > quadY) {
  //       // to the right above
  //       auto inter = checkTop(quadX, quadY, halfSide, start, end);
  //       if (inter.has_value()) {
  //         return {{inter.value(), VIPRA::f3d{0, 1}}};
  //       } else {
  //         inter = checkRight(quadX, quadY, halfSide, start, end);
  //         if (inter.has_value()) {
  //           return {{inter.value(), VIPRA::f3d{1, 0}}};
  //         }
  //       }
  //     } else {
  //       // to the right below
  //       auto inter = checkBottom(quadX, quadY, halfSide, start, end);
  //       if (inter.has_value()) {
  //         return {{inter.value(), VIPRA::f3d{0, -1}}};
  //       } else {
  //         inter = checkRight(quadX, quadY, halfSide, start, end);
  //         if (inter.has_value()) {
  //           return {{inter.value(), VIPRA::f3d{1, 0}}};
  //         }
  //       }
  //     }
  //   } else {
  //     // to the left, maybe above or below
  //     if (end.y > quadY) {
  //       // to the left above
  //       auto inter = checkTop(quadX, quadY, halfSide, start, end);
  //       if (inter.has_value()) {
  //         return {{inter.value(), VIPRA::f3d{0, 1}}};
  //       } else {
  //         inter = checkLeft(quadX, quadY, halfSide, start, end);
  //         if (inter.has_value()) {
  //           return {{inter.value(), VIPRA::f3d{-1, 0}}};
  //         }
  //       }
  //     } else {
  //       // to the left below
  //       auto inter = checkBottom(quadX, quadY, halfSide, start, end);
  //       if (inter.has_value()) {
  //         return {{inter.value(), VIPRA::f3d{0, -1}}};
  //       } else {
  //         inter = checkLeft(quadX, quadY, halfSide, start, end);
  //         if (inter.has_value()) {
  //           return {{inter.value(), VIPRA::f3d{-1, 0}}};
  //         }
  //       }
  //     }
  //   }

  //   return {};
  // }

  // std::optional<VIPRA::f3d> lineIntersect(const VIPRA::f3d& start1,
  //                                         const VIPRA::f3d& end1,
  //                                         const VIPRA::f3d& start2,
  //                                         const VIPRA::f3d& end2) const {
  //   float x1 = start1.x;
  //   float y1 = start1.y;
  //   float x2 = end1.x;
  //   float y2 = end1.y;

  //   float x3 = start2.x;
  //   float y3 = start2.y;
  //   float x4 = end2.x;
  //   float y4 = end2.y;

  //   float uA =
  //       ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
  //   float uB =
  //       ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

  //   if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
  //     float intersectX = x1 + (uA * (x2 - x1));
  //     float intersectY = y1 + (uA * (y2 - y1));
  //     return std::optional<VIPRA::f3d>{VIPRA::f3d{intersectX, intersectY}};
  //   } else {
  //     return std::optional<VIPRA::f3d>{};
  //   }
  // }
};
}  // namespace CalmPath
#endif