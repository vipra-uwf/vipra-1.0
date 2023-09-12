#ifndef VIPRA_BEHAVIORS_STIMULUS_SOURCE_HPP
#define VIPRA_BEHAVIORS_STIMULUS_SOURCE_HPP

#include <definitions/dimensions.hpp>
#include <optional>

namespace BHVR {
struct Source {
  inline void set_location(std::optional<VIPRA::f3d> location) { _location = location; }

  inline auto get_location(VIPRA::f3d from) -> VIPRA::f3d {
    if (_location) return _location.value();
    return from;
  }

 private:
  std::optional<VIPRA::f3d> _location;
};
}  // namespace BHVR

#endif