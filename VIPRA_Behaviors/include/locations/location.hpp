#ifndef VIPRA_BEHAVIORS_LOCATION_HPP
#define VIPRA_BEHAVIORS_LOCATION_HPP

#include <functional>
#include <memory>
#include <string>

#include "definitions/dimensions.hpp"
#include "definitions/shape_type.hpp"

namespace BHVR {

using InsideFunc = std::function<bool(VIPRA::f3d)>;
using RandomPointFunc = std::function<VIPRA::f3d()>;

/**
   * @brief A Location is an area in the map that is either predefined, such as the bathroom, or defined by a behavior created by the user.
   *     
   */
class Location {
 public:
  explicit Location(std::string, BHVR::Shape, std::shared_ptr<BHVR::Shape>);

  void setType(BHVR::Shape shape) { type = shape; }

  [[nodiscard]] VIPRA::f3d randomPoint() const { return _random(); }
  [[nodiscard]] bool       inside(VIPRA::f3d point) const { return _inside(point); }

  void setRandom(std::function<VIPRA::f3d()>&& randFunc) { _random = randFunc; }
  void setInside(std::function<bool(VIPRA::f3d)>&& inside) { _inside = inside; }

 private:
  BHVR::Shape     type;
  RandomPointFunc _random;
  InsideFunc      _inside;

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