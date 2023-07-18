#ifndef VIPRA_BEHAVIORS_SHAPE_DEFINITIONS_HPP
#define VIPRA_BEHAVIORS_SHAPE_DEFINITIONS_HPP

#include <functional>

#include <definitions/dimensions.hpp>
#include <definitions/shape_type.hpp>


namespace BHVR {
/**
   * @brief A Shape is an area in the map that is either predefined in the config file, or defined by a behavior created by the user.
   *     
   */

/**
 * TODO: Add location config file and load them into behavior.
*/

class Shape {
 public:
  ~Shape() = default;
  Shape(Shape&&) noexcept = default;
  Shape& operator=(Shape&&) noexcept = default;
  Shape() = default;
  Shape(const Shape&) = default;
  Shape& operator=(const Shape&) = default;

  virtual const VIPRA::f3d getCenterPoint() const = 0;

 private:
  VIPRA::f3d centerpoint;

};


class Rectangle : public Shape {
 public:
  ~Rectangle() = default;
  Rectangle(Rectangle&&) noexcept = default;
  Rectangle& operator=(Rectangle&&) noexcept = default;
  Rectangle() = default;
  Rectangle(const Rectangle&) = default;
  Rectangle& operator=(const Rectangle&) = default;

  explicit Rectangle(VIPRA::f3d, float, float);

  const VIPRA::f3d getCenterPoint() const override;
  float getLength();
  float getWidth();

 private:
  VIPRA::f3d centerPoint;
  float length;
  float width;

};


class Circle : public Shape {
 public:
  ~Circle() = default;
  Circle(Circle&&) noexcept = default;
  Circle& operator=(Circle&&) noexcept = default;
  Circle() = default;
  Circle(const Circle&) = default;
  Circle& operator=(const Circle&) = default;

  explicit Circle(VIPRA::f3d, float);

  const VIPRA::f3d getCenterPoint() const override;
  float getRadius();

 private:
  VIPRA::f3d centerPoint;
  float radius;

};


class Point : public Shape {
 public:
  ~Point() = default;
  Point(Point&&) noexcept = default;
  Point& operator=(Point&&) noexcept = default;
  Point() = default;
  Point(const Point&) = default;
  Point& operator=(const Point&) = default;

  explicit Point(VIPRA::f3d);

  const VIPRA::f3d getCenterPoint() const override;


 private:
  VIPRA::f3d centerPoint;

};



} //namespace BHVR
#endif