#ifndef VIPRA_BEHAVIORS_LOCATION_HPP
#define VIPRA_BEHAVIORS_LOCATION_HPP

#include <functional>
#include <memory>
#include <string>

#include "definitions/dimensions.hpp"
#include "randomization/random.hpp"

namespace BHVR {

/**
   * @brief A Location is an area in the map that is either predefined, such as the bathroom, or defined by a behavior created by the user.
   *     
   */
class Location {
 public:
  explicit Location(VIPRA::f3d, VIPRA::f3d, float);

  [[nodiscard]] float      area() const;
  [[nodiscard]] VIPRA::f3d center() const;

  [[nodiscard]] VIPRA::f3d randomPoint(VIPRA::pRNG_Engine&) const;
  [[nodiscard]] bool       inside(VIPRA::f3d) const;

 private:
  VIPRA::f3d _p1;
  VIPRA::f3d _p2;
  VIPRA::f3d _p3;
  VIPRA::f3d _p4;
  VIPRA::f3d _center;
  VIPRA::f3d _dims;
  float      _rot{};

  static constexpr float areaError = 0.0001;

  [[nodiscard]] static float triangleArea(VIPRA::f3d, VIPRA::f3d, VIPRA::f3d);

 public:
  ~Location() = default;
  Location(Location&&) noexcept = default;
  Location& operator=(Location&&) noexcept = default;
  Location() = default;
  Location(const Location&) = default;
  Location& operator=(const Location&) noexcept = default;
};
}  //namespace BHVR
#endif