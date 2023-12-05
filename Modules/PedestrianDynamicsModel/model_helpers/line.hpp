#ifndef LINE_HPP
#define LINE_HPP

#include "definitions/type_definitions.hpp"

struct Line {
  VIPRA::f3d p1{};
  VIPRA::f3d p2{};

  Line() = default;
  Line(VIPRA::f3d P1, VIPRA::f3d P2) : p1(P1), p2(P2) {}

  [[nodiscard]] inline constexpr bool operator==(const Line& other) const {
    return ((p1 == other.p1) && (p2 == other.p2)) ||
           ((p1 == other.p2) && (p2 == other.p1));
  }

  /**
   * @brief Check if the line segment intersects with another line segment
   * 
   * @param other 
   * @return true 
   * @return false 
   */
  [[nodiscard]] inline constexpr bool doesIntersect(const Line& other) const {
    if (p1 == other.p1 || p1 == other.p2 || p2 == other.p1 || p2 == other.p2) return true;

    int o1 = orientation(p1, p2, other.p1);
    int o2 = orientation(p1, p2, other.p2);
    int o3 = orientation(other.p1, other.p2, p1);
    int o4 = orientation(other.p1, other.p2, p2);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && checkIfOnLineSegment(p1, p2, other.p1)) return true;
    if (o2 == 0 && checkIfOnLineSegment(p1, p2, other.p2)) return true;
    if (o3 == 0 && checkIfOnLineSegment(other.p1, other.p2, p1)) return true;
    if (o4 == 0 && checkIfOnLineSegment(other.p1, other.p2, p2)) return true;

    return false;
  }

  [[nodiscard]] inline constexpr bool isPointOn(VIPRA::f3d point) const {
    return point.x <= std::max(p1.x, p2.x) && point.y <= std::max(p1.y, p2.y) &&
           point.x >= std::min(p1.x, p2.x) && point.y >= std::min(p1.y, p2.y);
  }

  /**
   * @brief Checks if pt is on the line segment, provided the orientation between the 3 points is known to be 0
   * 
   * @param lineStart 
   * @param lineEnd 
   * @param pt 
   * @return true 
   * @return false 
   */
  [[nodiscard]] static inline constexpr bool checkIfOnLineSegment(VIPRA::f3d lineStart,
                                                                  VIPRA::f3d lineEnd,
                                                                  VIPRA::f3d pt) {
    return pt.x <= std::max(lineStart.x, lineEnd.x) &&
           pt.y <= std::max(lineStart.y, lineEnd.y) &&
           pt.x >= std::min(lineStart.x, lineEnd.x) &&
           pt.y >= std::min(lineStart.y, lineEnd.y);
  }

  /**
   * @brief Calculates the orientation of point1, point2, point 3.
   * 
   * @param point1 
   * @param point2 
   * @param point3 
   * @return The function returns following values: 0 --> p, q and r are collinear; 1 --> Clockwise; 2 --> Counterclockwise
   */
  [[nodiscard]] static constexpr int orientation(VIPRA::f3d point1, VIPRA::f3d point2,
                                                 VIPRA::f3d point3) {
    float val = (point2.y - point1.y) * (point3.x - point2.x) -
                (point2.x - point1.x) * (point3.y - point2.y);

    if (val > 0) return 1;

    if (val < 0) return 2;

    return 0;
  }

  /**
   * @brief Calculate the shortest distance from the line to a point
   * 
   * @param point 
   * @return float 
   */
  [[nodiscard]] float shortestDistanceTo(VIPRA::f3d point) const {
    float dotProd = (p2.x - p1.x) * (point.x - p1.x) + (p2.y - p1.y) * (point.y - p1.y);

    float segLenSq = p1.distanceToSquared(p2);

    if (segLenSq == 0) return point.distanceTo(p1);

    float distRat = dotProd / segLenSq;
    if (distRat >= 1) {
      if (point.distanceTo(p1) < point.distanceTo(p2)) return point.distanceTo(p1);

      return point.distanceTo(p2);
    }

    float bX = p1.x + distRat * (p2.x - p1.x);
    float bY = p1.y + distRat * (p2.y - p1.y);
    return std::sqrt((point.x - bX) * (point.x - bX) + (point.y - bY) * (point.y - bY));
  }
};

#endif