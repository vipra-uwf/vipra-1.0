#include <locations/location.hpp>

namespace BHVR {

const std::string& Location::getName() const { return name; }

const std::string& Location::getType() const { return type; }

const VIPRA::shape Location::getShape() const { return shape; }

Location::Location(std::string locName, std::string locType, VIPRA::shape locShape)
    : name(std::move(locName)), type(std::move(locType)), shape(locShape) {}

}  //Namespace BHVR