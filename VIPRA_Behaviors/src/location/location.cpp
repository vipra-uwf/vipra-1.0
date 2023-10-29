

#include <definitions/dimensions.hpp>
#include <utility>

#include "distributions/distributions.hpp"
#include "locations/location.hpp"

namespace BHVR {

Location::Location(VIPRA::f3d center, VIPRA::f3d dims, float rot) : _center(center), _dims(dims), _rot(rot) {
  _p1.x = center.x + ((dims.x / 2) * std::cos(rot)) - ((dims.y / 2) * std::sin(rot));
  _p1.y = center.y + ((dims.x / 2) * std::sin(rot)) + ((dims.y / 2) * std::cos(rot));
  _p2.x = center.x - ((dims.x / 2) * std::cos(rot)) - ((dims.y / 2) * std::sin(rot));
  _p2.y = center.y - ((dims.x / 2) * std::sin(rot)) + ((dims.y / 2) * std::cos(rot));
  _p3.x = center.x - ((dims.x / 2) * std::cos(rot)) + ((dims.y / 2) * std::sin(rot));
  _p3.y = center.y - ((dims.x / 2) * std::sin(rot)) - ((dims.y / 2) * std::cos(rot));
  _p4.x = center.x + ((dims.x / 2) * std::cos(rot)) + ((dims.y / 2) * std::sin(rot));
  _p4.y = center.y + ((dims.x / 2) * std::sin(rot)) - ((dims.y / 2) * std::cos(rot));
}

/**
   * @brief Gets the area of a triangle from 3 points
   * 
   * @param point1 : tri point 
   * @param point2 : tri point 
   * @param point3 : tri point 
   * @return constexpr float : triangle area
   */
auto Location::triangle_area(VIPRA::f3d point1, VIPRA::f3d point2, VIPRA::f3d point3) -> float {
  return std::abs((point2.x * point1.y - point1.x * point2.y) + (point3.x * point2.y - point2.x * point3.y) +
                  (point1.x * point3.y - point3.x * point1.y)) /
         2;
}

auto Location::random_point(VIPRA::pRNG_Engine& eng) const -> VIPRA::f3d {
  VIPRA::uniform_distribution<> hDistr{0, _dims.x};
  VIPRA::uniform_distribution<> wDistr{0, _dims.y};

  float      rotSin = std::sin(_rot);
  float      rotCos = std::cos(_rot);
  VIPRA::f3d point{wDistr(eng), hDistr(eng)};

  point.x = (point.x * rotCos - point.y * rotSin) + _center.x;
  point.y = (point.x * rotSin + point.y * rotCos) + _center.y;

  return point;
}

/**
   * @brief Returns if the point is inside the rectangle
   *
   * @param point : point to check
   * @return true : if inside rectangle
   * @return false : if NOT inside rectangle
   */
auto Location::inside(VIPRA::f3d point) const -> bool {
  float areaTri1 = triangle_area(_p1, _p2, point);
  float areaTri2 = triangle_area(_p2, _p3, point);
  float areaTri3 = triangle_area(_p3, _p4, point);
  float areaTri4 = triangle_area(_p4, _p1, point);

  return (areaTri1 += areaTri2 += areaTri3 += areaTri4) <= area() + AREA_ERROR;
}

/**
   * @brief Returns the area of the rectangle
   * 
   * @return constexpr float : area
   */
auto Location::area() const -> float {
  float area1 = triangle_area(_p1, _p2, _p3);
  float area2 = triangle_area(_p1, _p3, _p4);

  return (area1 += area2);
}

}  // namespace BHVR