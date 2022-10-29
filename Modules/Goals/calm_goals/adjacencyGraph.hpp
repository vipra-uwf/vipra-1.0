#ifndef ADJACENCYGRAPH_HPP
#define ADJACENCYGRAPH_HPP

#include "../../../VIPRA/Base/definitions/type_definitions.hpp"
#include "../../../VIPRA/Extendable/obstacleset/obstacle_set.hpp"

namespace CalmPath {
struct Quad {
  Dimensions         center;
  float              size;
  bool               traversable;
  Quad*              tl;
  Quad*              tr;
  Quad*              bl;
  Quad*              br;
  std::vector<Quad*> adj;
  Quad(Dimensions center, float size, bool traversable, Quad* tl, Quad* tr, Quad* bl, Quad* br)
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
    const Dimensions mapRes = obSet.getDimensions();
    printf("Constructing Quad Tree\n");
    root = construct({mapRes.axis[0] / 2, mapRes.axis[1] / 2}, mapRes.axis[0]);

    printf("Building Adjacencies\n");
    buildAdjacencies(root);
  }

  Quad* getRoot() const { return root; }

  [[nodiscard]] Quad* search(const Dimensions& coords) const {
    Quad* curr = nullptr;
    Quad* next = root;
    while (next != nullptr) {
      curr = next;
      if (coords.axis[0] < curr->center.axis[0]) {
        if (coords.axis[1] < curr->center.axis[1]) {
          next = curr->bl;
        } else {
          next = curr->tl;
        }
      } else {
        if (coords.axis[1] < curr->center.axis[1]) {
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

  int n = 0;

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
    Dimensions point;
    Dimensions direction;
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
      ++n;
      Dimensions checkPoint = from->center;
      float      d = (from->center.distanceTo(to->center) / 0.01);
      float      dx = (to->center.axis[0] - from->center.axis[0]) / d;
      float      dy = (to->center.axis[1] - from->center.axis[1]) / d;
      Dimensions move{dx, dy};
      Quad*      curr = from;
      while (curr != nullptr && curr != to) {
        checkPoint = {checkPoint.axis[0] + move.axis[0], checkPoint.axis[1] + move.axis[1]};
        curr = search(checkPoint);
        if (!curr->traversable) {
          return;
        }
        if (curr == to || checkPoint.inside(to->center, 0.01)) {
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
      // Dimensions checkPoint;
      // while (curr != nullptr && curr->traversable) {
      //   auto intersect = quadEdgeIntersect(curr, from->center, to->center);
      //   if (intersect.has_value()) {
      //     checkPoint.axis[0] =
      //         intersect.value().point.axis[0] + (0.0001 * intersect.value().direction.axis[0]);
      //     checkPoint.axis[1] =
      //         intersect.value().point.axis[1] + (0.0001 * intersect.value().direction.axis[1]);
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

  inline std::optional<Dimensions> checkTop(float             quadX,
                                            float             quadY,
                                            float             halfSide,
                                            const Dimensions& start,
                                            const Dimensions& end) const {
    return lineIntersect(
        {quadX - halfSide, quadY + halfSide}, {quadX + halfSide, quadY + halfSide}, start, end);
  }
  inline std::optional<Dimensions> checkBottom(float             quadX,
                                               float             quadY,
                                               float             halfSide,
                                               const Dimensions& start,
                                               const Dimensions& end) const {
    return lineIntersect(
        {quadX - halfSide, quadY - halfSide}, {quadX + halfSide, quadY - halfSide}, start, end);
  }
  inline std::optional<Dimensions> checkRight(float             quadX,
                                              float             quadY,
                                              float             halfSide,
                                              const Dimensions& start,
                                              const Dimensions& end) const {
    return lineIntersect(
        {quadX + halfSide, quadY + halfSide}, {quadX + halfSide, quadY - halfSide}, start, end);
  }
  inline std::optional<Dimensions> checkLeft(float             quadX,
                                             float             quadY,
                                             float             halfSide,
                                             const Dimensions& start,
                                             const Dimensions& end) const {
    return lineIntersect(
        {quadX - halfSide, quadY + halfSide}, {quadX - halfSide, quadY - halfSide}, start, end);
  }

  std::optional<IntersectPoint> quadEdgeIntersect(Quad*             quad,
                                                  const Dimensions& start,
                                                  const Dimensions& end) const {
    float halfSide = quad->size / 2;
    float quadX = quad->center.axis[0];
    float quadY = quad->center.axis[1];

    if (end.axis[0] >= (quadX - halfSide) && end.axis[0] <= (quadX + halfSide)) {
      // directly above or below
      if (end.axis[1] > quadY) {
        // above
        auto inter = checkTop(quadX, quadY, halfSide, start, end);
        if (inter.has_value()) {
          return {{inter.value(), Dimensions{0, 1}}};
        }
      } else {
        // below
        auto inter = checkBottom(quadX, quadY, halfSide, start, end);
        if (inter.has_value()) {
          return {{inter.value(), Dimensions{0, -1}}};
        }
      }
    }

    if (end.axis[0] >= (quadX - halfSide) && end.axis[0] <= (quadX + halfSide)) {
      // directly left or right
      if (end.axis[0] > quadX) {
        // right
        auto inter = checkRight(quadX, quadY, halfSide, start, end);
        if (inter.has_value()) {
          return {{inter.value(), Dimensions{1, 0}}};
        }
      } else {
        // left
        auto inter = checkLeft(quadX, quadY, halfSide, start, end);
        if (inter.has_value()) {
          return {{inter.value(), Dimensions{-1, 0}}};
        }
      }
    }

    if (end.axis[0] > quadX) {
      // to the right, maybe above or below
      if (end.axis[1] > quadY) {
        // to the right above
        auto inter = checkTop(quadX, quadY, halfSide, start, end);
        if (inter.has_value()) {
          return {{inter.value(), Dimensions{0, 1}}};
        } else {
          inter = checkRight(quadX, quadY, halfSide, start, end);
          if (inter.has_value()) {
            return {{inter.value(), Dimensions{1, 0}}};
          }
        }
      } else {
        // to the right below
        auto inter = checkBottom(quadX, quadY, halfSide, start, end);
        if (inter.has_value()) {
          return {{inter.value(), Dimensions{0, -1}}};
        } else {
          inter = checkRight(quadX, quadY, halfSide, start, end);
          if (inter.has_value()) {
            return {{inter.value(), Dimensions{1, 0}}};
          }
        }
      }
    } else {
      // to the left, maybe above or below
      if (end.axis[1] > quadY) {
        // to the left above
        auto inter = checkTop(quadX, quadY, halfSide, start, end);
        if (inter.has_value()) {
          return {{inter.value(), Dimensions{0, 1}}};
        } else {
          inter = checkLeft(quadX, quadY, halfSide, start, end);
          if (inter.has_value()) {
            return {{inter.value(), Dimensions{-1, 0}}};
          }
        }
      } else {
        // to the left below
        auto inter = checkBottom(quadX, quadY, halfSide, start, end);
        if (inter.has_value()) {
          return {{inter.value(), Dimensions{0, -1}}};
        } else {
          inter = checkLeft(quadX, quadY, halfSide, start, end);
          if (inter.has_value()) {
            return {{inter.value(), Dimensions{-1, 0}}};
          }
        }
      }
    }

    return {};
  }

  std::optional<Dimensions> lineIntersect(const Dimensions& start1,
                                          const Dimensions& end1,
                                          const Dimensions& start2,
                                          const Dimensions& end2) const {
    float x1 = start1.axis[0];
    float y1 = start1.axis[1];
    float x2 = end1.axis[0];
    float y2 = end1.axis[1];

    float x3 = start2.axis[0];
    float y3 = start2.axis[1];
    float x4 = end2.axis[0];
    float y4 = end2.axis[1];

    float uA =
        ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    float uB =
        ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
      float intersectX = x1 + (uA * (x2 - x1));
      float intersectY = y1 + (uA * (y2 - y1));
      return std::optional<Dimensions>{Dimensions{intersectX, intersectY}};
    } else {
      return std::optional<Dimensions>{};
    }
  }

  Quad* construct(Dimensions center, float size) {
    if (size <= gridUnit) {
      return nullptr;
    }

    Quad* tl = nullptr;
    Quad* tr = nullptr;
    Quad* bl = nullptr;
    Quad* br = nullptr;

    float x = center.axis[0];
    float y = center.axis[1];
    if (inside(obs->NearestObstacle(center, Dimensions{0, 0}), center, size)) {
      tl = construct({x - size / 4, y + size / 4}, size / 2);
      tr = construct({x + size / 4, y + size / 4}, size / 2);
      bl = construct({x - size / 4, y - size / 4}, size / 2);
      br = construct({x + size / 4, y - size / 4}, size / 2);
      if (tl != nullptr || tr != nullptr || bl != nullptr || br != nullptr) {
        return new Quad(center, size, true, tl, tr, bl, br);
      } else {
        return new Quad(center, size, false, tl, tr, bl, br);
      }
    }
    return new Quad(center, size, true, tl, tr, bl, br);
  }

  bool inside(Dimensions point, Dimensions center, float size) {
    Dimensions tl = {center.axis[0] - size / 2, center.axis[1] + size / 2};
    Dimensions br = {center.axis[0] + size / 2, center.axis[1] - size / 2};
    bool i = (point.axis[0] >= tl.axis[0] && point.axis[0] <= br.axis[0] && point.axis[1] <= tl.axis[1] &&
              point.axis[1] >= br.axis[1]);
    return i;
  }
};
}  // namespace CalmPath
#endif