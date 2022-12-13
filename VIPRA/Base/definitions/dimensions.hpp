#ifndef VIPRA_DIMENSIONS_HPP
#define VIPRA_DIMENSIONS_HPP

#include <cmath>
#include <stdexcept>
#include <vector>

namespace VIPRA {

struct f2d {
  float x, y;

  f2d() : x(0), y(0) {}
  f2d(float X) : x(X), y(0) {}
  f2d(float X, float Y) : x(X), y(Y) {}
  f2d(float X, float Y, float Z) : x(X), y(Y) {}
  f2d(const f2d& other) : x(other.x), y(other.y) {}
  f2d(f2d&& other) : x(other.x), y(other.y) {}
  f2d& operator=(const f2d& other) {
    x = other.x;
    y = other.y;
    return *this;
  }
  f2d& operator=(f2d&& other) {
    x = other.x;
    y = other.y;
    return *this;
  }

  float distanceTo(const f2d& other) const {
    float dX = other.x - x;
    float dY = other.y - y;

    if (dX != 0) {
      dX = dX * dX;
    }
    if (dY != 0) {
      dY = dY * dY;
    }

    return sqrt(dX + dY);
  }

  bool inside(const f2d& other, float sideLength) const {
    const float half = sideLength / 2;
    return (x >= other.x - half && x <= other.x + half && y <= other.y + half && y >= other.y - half);
  }

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  float& operator[](T index) {
    switch (index) {
      case 0:
        return x;
      case 1:
        return y;
      case 'x':
        return x;
      case 'y':
        return y;
    }
    throw std::out_of_range("Attempt to access invalid index on VIPRA::f2d");
  }
};

struct f3d {
  float x, y, z;

  f3d() : x(0), y(0), z(0) {}
  f3d(float X) : x(X), y(0), z(0) {}
  f3d(float X, float Y) : x(X), y(Y), z(0) {}
  f3d(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
  f3d(const f3d& other) : x(other.x), y(other.y), z(other.z) {}
  f3d(f3d&& other) : x(other.x), y(other.y), z(other.z) {}

  explicit f3d(const f2d& other) : x(other.x), y(other.y), z(0) {}
  explicit f3d(f2d&& other) : x(other.x), y(other.y), z(0) {}

  f3d& operator=(const f3d& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }
  f3d& operator=(f3d&& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }
  f3d& operator=(const f2d& other) {
    x = other.x;
    y = other.y;
    z = 0;
    return *this;
  }
  f3d& operator=(f2d&& other) {
    x = other.x;
    y = other.y;
    z = 0;
    return *this;
  }

  float distanceTo(const f2d& other) const {
    float dX = other.x - x;
    float dY = other.y - y;
    float dZ = 0 - z;

    dX = dX * dX;
    dY = dY * dY;
    dZ = dZ * dZ;

    return sqrt(dX + dY + dZ);
  }

  float distanceTo(const f3d& other) const {
    float dX = other.x - x;
    float dY = other.y - y;
    float dZ = other.z - z;

    dX = dX * dX;
    dY = dY * dY;
    dZ = dZ * dZ;

    return sqrt(dX + dY + dZ);
  }

  bool inside(const f3d& other, float sideLength) const {
    const float half = sideLength / 2;
    return (x >= other.x - half && x <= other.x + half && y <= other.y + half && y >= other.y - half &&
            z <= other.z + half && z >= other.z - half);
  }

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  float& operator[](T index) {
    switch (index) {
      case 0:
        return x;
      case 1:
        return y;
      case 2:
        return z;
      case 'x':
        return x;
      case 'y':
        return y;
      case 'z':
        return z;
    }
    throw std::out_of_range("Attempt to access invalid index on VIPRA::f3d");
  }
};

typedef std::vector<f2d> f2dVec;
typedef std::vector<f3d> f3dVec;

static f2d __emptyf2d__;
static f3d __emptyf3d__;

}  // namespace VIPRA

#endif