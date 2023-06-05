#ifndef VIPRA_BEHAVIORS_LOCATION_HPP
#define VIPRA_BEHAVIORS_LOCATION_HPP

#include <functional>

#include <definitions/shape_descriptor.hpp>


namespace BHVR {
/**
   * @brief A Location is an area in the map that is either predefined, such as the bathroom, or defined by a behavior created by the user.
   *     
   */
class Location {
 public:
  ~Location() = default;
  Location(Location&&) noexcept = default;
  Location& operator=(Location&&) noexcept = default;
  Location() = default;
  Location(const Location&) = default;
  Location& operator=(const Location&) = default;

  explicit Location(std::string, std::string locType, VIPRA::shape locShape);

  const std::string& getName() const;
  const std::string& getType() const;
  const VIPRA::shape getShape() const;

 private:
  std::string name;
  std::string type;
  VIPRA::shape shape;

};
} //namespace BHVR
#endif