#ifndef VIPRA_BEHAVIORS_RECTANGLE_HPP
#define VIPRA_BEHAVIORS_RECTANGLE_HPP

#include <definitions/dimensions.hpp>

namespace BHVR {
struct Rectangle {
  VIPRA::f3d bottomLeft;
  VIPRA::f3d topRight;

  [[nodiscard]] bool operator()(VIPRA::f3d point) const {
    return (point.x >= bottomLeft.x && point.x <= topRight.x && point.y >= bottomLeft.y &&
            point.y <= topRight.y);
  }
  // TODO (rolland)
  [[nodiscard]] VIPRA::f3d operator()() const { return VIPRA::f3d{}; }
};
}  // namespace BHVR

#endif