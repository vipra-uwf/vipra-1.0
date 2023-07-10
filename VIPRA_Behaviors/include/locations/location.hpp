#ifndef VIPRA_BEHAVIORS_LOCATION_HPP
#define VIPRA_BEHAVIORS_LOCATION_HPP

#include <functional>
#include <string>
#include <memory>

#include <definitions/shape_type.hpp>
#include <shapes/shape_class_definitions.hpp>


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
  Location& operator=(const Location&) noexcept = default;

  explicit Location(std::string, BHVR::ShapeType, std::shared_ptr<BHVR::Shape>);

  const std::string& getName() const;
  BHVR::ShapeType getType() const;
  std::shared_ptr<BHVR::Shape> getShape();

 private:
  std::string name;
  BHVR::ShapeType type;
  std::shared_ptr<BHVR::Shape> shape;

};
} //namespace BHVR
#endif