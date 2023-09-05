#ifndef CALM_RECT_HPP
#define CALM_RECT_HPP

#include <array>
#include <definitions/dimensions.hpp>
#include "definitions/type_definitions.hpp"

#include "calm_line.hpp"

struct Rect {
  VIPRA::f3d p1;
  VIPRA::f3d p2;
  VIPRA::f3d p3;
  VIPRA::f3d p4;

  [[nodiscard]] inline constexpr VIPRA::f3d& operator[](VIPRA::size idx) {
    switch (idx) {
      case 0:
        return p1;
      case 1:
        return p2;
      case 2:
        return p3;
      case 3:
        return p4;
      default:
        throw std::out_of_range("Attempt To Read Out of Bounds on Rect");
    }

    return p1;
  }

  [[nodiscard]] inline constexpr const VIPRA::f3d& at(VIPRA::size idx) const {
    switch (idx) {
      case 0:
        return p1;
      case 1:
        return p2;
      case 2:
        return p3;
      case 3:
        return p4;
      default:
        throw std::out_of_range("Attempt To Read Out of Bounds on Rect");
    }

    return p1;
  }

  /**
   * @brief Returns the area of the rectangle
   * 
   * @return constexpr float : area
   */
  [[nodiscard]] inline constexpr float area() const {
    float area1 = triangleArea(p1, p2, p3);

    float area2 = triangleArea(p1, p3, p4);

    return (area1 += area2);
  }

  /**
   * @brief Returns if the point is inside the rectangle
   *
   * @param point : point to check
   * @return true : if inside rectangle
   * @return false : if NOT inside rectangle
   */
  [[nodiscard]] inline constexpr bool isPointInRect(VIPRA::f3d point) const noexcept {
    float areaTri1 = triangleArea(p1, p2, point);

    float areaTri2 = triangleArea(p2, p3, point);

    float areaTri3 = triangleArea(p3, p4, point);

    float areaTri4 = triangleArea(p4, p1, point);

    return (areaTri1 += areaTri2 += areaTri3 += areaTri4) <= area() + areaError;
  }

  // /**
  //  * @brief Returns if the point is inside the rectangle
  //  *
  //  * @param point :
  //  * @return true
  //  * @return false
  //  */
  // [[nodiscard]] inline bool isPointInRect(VIPRA::f3d point) const noexcept {
  //   std::array<VIPRA::f3d, 4> rectPoints{p1, p2, p3, p4};
  //   float                     maxX = p1.x;
  //   for (auto& rectPoint : rectPoints) {
  //     maxX = std::max(maxX, rectPoint.x);
  //   }
  //   VIPRA::f3d ptInf(2 * maxX, point.y);

  //   int cnt = 0;
  //   for (size_t i = 0; i < rectPoints.size(); i++) {
  //     auto pt1 = rectPoints.at(i);
  //     auto pt2 = rectPoints.at((i + 1) % rectPoints.size());
  //     if (Line::checkIfOnLineSegment(pt1, pt2, point) &&
  //         Line::orientation(pt1, point, pt2) == 0)
  //       return true;

  //     Line segment(pt1, pt2);
  //     Line ptToInf(point, ptInf);
  //     if (segment.doesIntersect(ptToInf)) cnt++;
  //   }
  //   return (cnt % 2 == 1);
  // }

  // /**
  //  * @brief Returns if the point is inside the rectangle
  //  *
  //  * @param point :
  //  * @return true
  //  * @return false
  //  */
  // [[nodiscard]] inline bool isPointInRect(VIPRA::f3d point) const noexcept {
  //   std::array<VIPRA::f3d, 4> rectPoints{p1, p2, p3, p4};
  //   float                     maxX = p1.x;
  //   for (auto& rectPoint : rectPoints) {
  //     maxX = std::max(maxX, rectPoint.x);
  //   }
  //   VIPRA::f3d ptInf(2 * maxX, point.y);

  //   int cnt = 0;
  //   for (size_t i = 0; i < rectPoints.size(); i++) {
  //     auto pt1 = rectPoints.at(i);
  //     auto pt2 = rectPoints.at((i + 1) % rectPoints.size());
  //     if (Line::checkIfOnLineSegment(pt1, pt2, point) &&
  //         Line::orientation(pt1, point, pt2) == 0)
  //       return true;

  //     Line segment(pt1, pt2);
  //     Line ptToInf(point, ptInf);
  //     if (segment.doesIntersect(ptToInf)) cnt++;
  //   }
  //   return (cnt % 2 == 1);
  // }

  // /**
  //  * @brief Returns if the rectangle intersects another
  //  *
  //  * @param other :
  //  * @return true
  //  * @return false
  //  */
  // [[nodiscard]] constexpr bool doesIntersect(const Rect& other) const {
  //   for (VIPRA::idx i1 = 0; i1 < 4; ++i1) {
  //     const VIPRA::idx i2 = (i1 + 1) % 4;

  //     float normalx = (*this).at(i2).y - (*this).at(i1).y;
  //     float normaly = (*this).at(i2).x - (*this).at(i1).x;

  //     auto [minA, maxA] = getProjectedMinMax(*this, normalx, normaly);
  //     auto [minB, maxB] = getProjectedMinMax(other, normalx, normaly);

  //     if (maxA < minB || maxB < minA) return false;

  //     normalx = other.at(i2).y - other.at(i1).y;
  //     normaly = other.at(i2).x - other.at(i1).x;

  //     auto [minA2, maxA2] = getProjectedMinMax(*this, normalx, normaly);
  //     auto [minB2, maxB2] = getProjectedMinMax(other, normalx, normaly);

  //     if (maxA2 < minB2 || maxB2 < minA2) return false;
  //   }

  //   return true;
  // }

  /**
   * @brief Returns if the rectangles intersect one another
   * 
   * @param r1, r2 : 
   * @return true 
   * @return false 
   */
  [[nodiscard]] static bool doRectanglesIntersect(Rect& r1, Rect& r2) {
    std::array<Line, 4> s1{
        Line{r1.p1, r1.p2}, {r1.p2, r1.p3}, {r1.p3, r1.p4}, {r1.p4, r1.p1}};
    std::array<Line, 4> s2{
        Line{r2.p1, r2.p2}, {r2.p2, r2.p3}, {r2.p3, r2.p4}, {r2.p4, r2.p1}};

    for (size_t i = 0; i < 4; i++) {
      for (size_t j = 0; j < 4; j++) {
        if (s1.at(i).doesIntersect(s2.at(j))) return true;
      }
    }

    return false;
  }

  /**
   * @brief Returns if the rectangle intersects another
   * 
   * @param other : 
   * @return true 
   * @return false 
   */
  [[nodiscard]] bool doesIntersect(Rect& other) {
    std::array<Line, 4> s1{Line{p1, p2}, {p2, p3}, {p3, p4}, {p4, p1}};
    std::array<Line, 4> s2{Line{other.p1, other.p2},
                           {other.p2, other.p3},
                           {other.p3, other.p4},
                           {other.p4, other.p1}};

    for (size_t i = 0; i < 4; i++) {
      for (size_t j = 0; j < 4; j++) {
        if (s1.at(i).doesIntersect(s2.at(j))) return true;
      }
    }

    return false;
  }

 private:
  static constexpr float two = 2.0F;

  [[nodiscard]] static inline constexpr std::pair<float, float> getProjectedMinMax(
      const Rect& rect, float normalx, float normaly) {
    std::pair<float, float> minMax{std::numeric_limits<float>::max(),
                                   std::numeric_limits<float>::min()};

    for (int ai = 0; ai < 4; ++ai) {
      const float projected = normalx * rect.at(ai).x + normaly * rect.at(ai).y;
      if (projected < minMax.first) minMax.first = projected;
      if (projected > minMax.second) minMax.second = projected;
    }

    return minMax;
  }

  static constexpr float areaError = 0.0001;

  /**
   * @brief Gets the area of a triangle from 3 points
   * 
   * @param point1 : tri point 
   * @param point2 : tri point 
   * @param point3 : tri point 
   * @return constexpr float : triangle area
   */
  [[nodiscard]] static inline constexpr float triangleArea(VIPRA::f3d point1,
                                                           VIPRA::f3d point2,
                                                           VIPRA::f3d point3) {
    return std::abs((point2.x * point1.y - point1.x * point2.y) +
                    (point3.x * point2.y - point2.x * point3.y) +
                    (point1.x * point3.y - point3.x * point1.y)) /
           2;
  }
};

#endif