#include <locations/location.hpp>

namespace BHVR {

const std::string& Location::getName() const {
   return name;
}

const BHVR::ShapeType Location::getType() const {
   return type;
}

std::shared_ptr<BHVR::Shape> Location::getShape() {
   return shape;
}

Location::Location(std::string locName, BHVR::ShapeType locType, std::shared_ptr<Shape> locShape) : name(std::move(locName)), type(std::move(locType)), shape(locShape){}

} //Namespace BHVR