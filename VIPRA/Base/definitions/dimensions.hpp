#ifndef VIPRA_DIMENSIONS_HPP
#define VIPRA_DIMENSIONS_HPP

#include <cmath>
#include <stdexcept>
#include <vector>

namespace VIPRA {

struct f2d {
  float x, y;

  ~f2d() {}
  constexpr f2d() noexcept : x(0), y(0) {}
  constexpr f2d(float X) noexcept : x(X), y(0) {}
  constexpr f2d(float X, float Y) noexcept : x(X), y(Y) {}
  constexpr f2d(const f2d& other) noexcept : x(other.x), y(other.y) {}
  constexpr f2d(f2d&& other) noexcept : x(other.x), y(other.y) {}
  f2d& operator=(const f2d& other) noexcept {
    x = other.x;
    y = other.y;
    return *this;
  }
  f2d& operator=(f2d&& other) noexcept {
    x = other.x;
    y = other.y;
    return *this;
  }

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  constexpr float& operator[](T index) {
    switch (index) {
      case 0:
        return x;
      case 1:
        return y;
      case 'x':
        return x;
      case 'y':
        return y;
      default:
        throw std::out_of_range("Attempt to access invalid index on VIPRA::f2d");
    }
  }

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  constexpr const float& operator[](T index) const {
    switch (index) {
      case 0:
        return x;
      case 1:
        return y;
      case 'x':
        return x;
      case 'y':
        return y;
      default:
        throw std::out_of_range("Attempt to access invalid index on VIPRA::f2d");
    }
  }
  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  constexpr f2d& operator*=(const T& multiplier) noexcept {
    x *= multiplier;
    y *= multiplier;
    return *this;
  }

  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  constexpr const f2d& operator*(T multiplier) const noexcept {
    return f2d{x, y} *= multiplier;
  }

  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  constexpr const f2d& operator/(T multiplier) noexcept {
    return f2d{x, y} /= multiplier;
  }

  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  constexpr f2d& operator/=(const T& multiplier) noexcept {
    x /= multiplier;
    y /= multiplier;
    return *this;
  }

  f2d operator+(const f2d& other) const noexcept { return f2d{x + other.x, y + other.y}; }

  constexpr f2d& operator+=(const f2d& other) noexcept {
    x += other.x;
    y += other.y;
    return *this;
  }

  constexpr f2d& operator-=(const f2d& other) noexcept {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  constexpr float distanceTo(const f2d& other) const noexcept {
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

  constexpr bool inside(const f2d& other, float sideLength) const noexcept {
    const float half = sideLength / 2;
    return (x >= other.x - half && x <= other.x + half && y <= other.y + half && y >= other.y - half);
  }
};

struct f3d {
  float x;
  float y;
  float z;

  ~f3d() {}
  constexpr f3d() noexcept : x(0), y(0), z(0) {}
  constexpr f3d(float X) noexcept : x(X), y(0), z(0) {}
  constexpr f3d(float X, float Y) noexcept : x(X), y(Y), z(0) {}
  constexpr f3d(float X, float Y, float Z) noexcept : x(X), y(Y), z(Z) {}

  constexpr f3d(const f3d& other) noexcept : x(other.x), y(other.y), z(other.z) {}
  constexpr f3d(f3d&& other) noexcept : x(other.x), y(other.y), z(other.z) {}
  explicit constexpr f3d(const f2d& other) noexcept : x(other.x), y(other.y), z(0) {}
  explicit constexpr f3d(f2d&& other) noexcept : x(other.x), y(other.y), z(0) {}

  f3d& operator=(const f3d& other) noexcept {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }
  f3d& operator=(f3d&& other) noexcept {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }
  f3d& operator=(const f2d& other) noexcept {
    x = other.x;
    y = other.y;
    z = 0;
    return *this;
  }
  f3d& operator=(f2d&& other) noexcept {
    x = other.x;
    y = other.y;
    z = 0;
    return *this;
  }

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  constexpr float& operator[](T index) {
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
      default:
        throw std::out_of_range("Attempt to access invalid index on VIPRA::f3d");
    }
  }

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  constexpr const float& operator[](T index) const {
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
      default:
        throw std::out_of_range("Attempt to access invalid index on VIPRA::f3d");
    }
  }

  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  constexpr f3d& operator*=(const T& multiplier) noexcept {
    x *= multiplier;
    y *= multiplier;
    z *= multiplier;
    return *this;
  }

  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  constexpr f3d& operator/=(const T& multiplier) noexcept {
    x /= multiplier;
    y /= multiplier;
    z /= multiplier;
    return *this;
  }

  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  f3d operator*(T multiplier) const noexcept {
    return f3d{x, y, z} *= multiplier;
  }

  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  f3d operator/(T multiplier) noexcept {
    return f3d{x, y, z} /= multiplier;
  }

  f3d operator+(const f3d& other) const noexcept { return f3d{x + other.x, y + other.y, z + other.z}; }
  f3d operator+(const f2d& other) const noexcept { return f3d{x + other.x, y + other.y, z}; }

  constexpr f3d& operator+=(const f3d& other) noexcept {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  constexpr f3d& operator-=(const f3d& other) noexcept {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  float distanceTo(const f2d& other) const noexcept {
    float dX = other.x - x;
    float dY = other.y - y;
    float dZ = 0 - z;

    dX = dX * dX;
    dY = dY * dY;
    dZ = dZ * dZ;

    return sqrt(dX + dY + dZ);
  }

  float distanceTo(const f3d& other) const noexcept {
    float dX = other.x - x;
    float dY = other.y - y;
    float dZ = other.z - z;

    dX = dX * dX;
    dY = dY * dY;
    dZ = dZ * dZ;

    return sqrt(dX + dY + dZ);
  }

  constexpr bool inside(const f3d& other, float sideLength) const noexcept {
    const float half = sideLength / 2;
    return (x >= other.x - half && x <= other.x + half && y <= other.y + half && y >= other.y - half &&
            z <= other.z + half && z >= other.z - half);
  }
};

typedef std::vector<f2d> f2dVec;
typedef std::vector<f3d> f3dVec;

static f2d __emptyf2d__;
static f3d __emptyf3d__;

}  // namespace VIPRA

#endif