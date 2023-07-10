#include <shapes/shape_class_definitions.hpp>

namespace BHVR {

  const VIPRA::f3d Rectangle::getCenterPoint() const {
      return centerPoint;
  }

  float Rectangle::getLength(){
      return length;
  }

  float Rectangle::getWidth(){
      return width;
  }

  Rectangle::Rectangle(VIPRA::f3d rectCenterPoint, float rectLength, float rectWidth) 
                      : centerPoint(rectCenterPoint), length(rectLength), width(rectWidth) {}  

} //Namespace BHVR