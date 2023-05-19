#ifndef CALM_RECT_HPP
#define CALM_RECT_HPP

#include <definitions/dimensions.hpp>
#include <definitions/type_definitions.hpp>

struct Rect {
  VIPRA::f3d p1;
  VIPRA::f3d p2;
  VIPRA::f3d p3;
  VIPRA::f3d p4;

  VIPRA::f3d& operator[](VIPRA::size idx) {
    switch (idx) {
      case 1:
        return p1;
      case 2:
        return p2;
      case 3:
        return p3;
      case 4:
        return p4;
      default:
        throw std::out_of_range("Attempt To Read Out of Bounds on Rect");
    }

    return p1;
  }
};

struct Line {
  Line(VIPRA::f3d P1, VIPRA::f3d P2) : p1(std::move(P1)), p2(std::move(P2)) {}
  bool operator==(const Line& other) const {
    return ((p1 == other.p1) && (p2 == other.p2)) || ((p1 == other.p2) && (p2 == other.p1));
  }
  VIPRA::f3d p1;
  VIPRA::f3d p2;
};

#endif