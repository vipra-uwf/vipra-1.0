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

  [[nodiscard]] auto area() const -> float;
  [[nodiscard]] auto center() const -> VIPRA::f3d;

  [[nodiscard]] auto random_point(VIPRA::pRNG_Engine&) const -> VIPRA::f3d;
  [[nodiscard]] auto inside(VIPRA::f3d) const -> bool;

 private:
  VIPRA::f3d _p1;
  VIPRA::f3d _p2;
  VIPRA::f3d _p3;
  VIPRA::f3d _p4;
  VIPRA::f3d _center;
  VIPRA::f3d _dims;
  float      _rot{};

  static constexpr float AREA_ERROR = 0.0001;

  [[nodiscard]] static auto triangle_area(VIPRA::f3d, VIPRA::f3d, VIPRA::f3d) -> float;

 public:
  ~Location() = default;
  Location(Location&&) noexcept = default;
  auto operator=(Location&&) noexcept -> Location& = default;
  Location() = default;
  Location(const Location&) = default;
  auto operator=(const Location&) noexcept -> Location& = default;
};
}  //namespace BHVR
#endif