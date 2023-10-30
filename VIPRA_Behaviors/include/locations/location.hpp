#ifndef VIPRA_BEHAVIORS_LOCATION_HPP
#define VIPRA_BEHAVIORS_LOCATION_HPP

#include "definitions/dimensions.hpp"
#include "randomization/random.hpp"
#include "util/class_types.hpp"

namespace BHVR {

/**
   * @brief A Location is an area in the map that is either predefined, such as the bathroom, or defined by a behavior created by the user.
   *     
   */
class Location {
  NON_DEFAULT_CONSTRUCTIBLE(Location)
  COPYABLE(Location)
  MOVEABLE(Location)

 public:
  explicit Location(VIPRA::f3d, VIPRA::f3d, float);

  [[nodiscard]] auto area() const -> float;
  [[nodiscard]] auto center() const -> VIPRA::f3d;

  [[nodiscard]] auto random_point(VIPRA::pRNG_Engine&) const -> VIPRA::f3d;
  [[nodiscard]] auto contains(VIPRA::f3d) const -> bool;

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
};
}  //namespace BHVR
#endif