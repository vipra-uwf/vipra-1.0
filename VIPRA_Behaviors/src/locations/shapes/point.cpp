#include <shapes/shape_class_definitions.hpp>

namespace BHVR {

  const VIPRA::f3d Point::getCenterPoint() const {
      return centerPoint;
  }

  Point::Point(VIPRA::f3d pointCenterPoint) 
                      : centerPoint(pointCenterPoint) {}  

} //Namespace BHVR