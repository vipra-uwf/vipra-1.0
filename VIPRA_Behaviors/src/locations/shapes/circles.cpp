#include <shapes/shape_class_definitions.hpp>

namespace BHVR {

  const VIPRA::f3d Circle::getCenterPoint() const {
      return centerPoint;
  }

  const float Circle::getRadius(){
      return radius;
  }

  Circle::Circle(VIPRA::f3d circleCenterPoint, float circleRadius) 
                      : centerPoint(circleCenterPoint), radius(circleRadius) {}  

} //Namespace BHVR