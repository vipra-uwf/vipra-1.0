#ifndef SHAPE_DESCRIPTOR_HPP
#define SHAPE_DESCRIPTOR_HPP

#include <cmath>
#include <stdexcept>
#include <type_traits>
#include <vector>
namespace VIPRA {


// NOLINTNEXTLINE
struct shape {
  float centerpointx, centerpointy, length, width, radius;

  ~shape() = default;
  constexpr explicit shape() noexcept : centerpointx(0), centerpointy(0), length(0), width(0), radius(0) {}
  constexpr explicit shape(float centerpointx, float centerpointy) noexcept : centerpointx(centerpointx), centerpointy(centerpointy), length(0), width(0), radius(0) {}
  constexpr explicit shape(float centerpointx, float centerpointy, float radius) noexcept : centerpointx(centerpointx), centerpointy(centerpointy), length(0), width(0), radius(radius) {}
  constexpr explicit shape(float centerpointx, float centerpointy, float length, float width) noexcept : centerpointx(centerpointx), centerpointy(centerpointy), length(length), width(width), radius(0) {}
  constexpr explicit shape(float centerpointx, float centerpointy, float length, float width, float radius) noexcept : centerpointx(centerpointx), centerpointy(centerpointy), length(length), width(width), radius(radius) {};
  constexpr shape(const shape& other) noexcept = default;
  constexpr shape(shape&& other) noexcept : centerpointx(other.centerpointx), centerpointy(other.centerpointy), length(other.length), width(other.width), radius(other.radius) {}

  constexpr shape& operator=(const shape& other) noexcept = default;
  constexpr shape& operator=(shape&& other) noexcept = default;

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  inline constexpr float& operator[](T index) {
    switch (index) {
      case 0:
        return centerpointx;
      case 1:
        return centerpointy;
      case 2:
        return length;
      case 3:
        return width;
      case 4:
        return radius;
      case "centerpointx":
        return centerpointx;
      case "centerpointy":
        return centerpointy;
      case "length":
        return length;
      case "width":
        return width;
      case "radius":
        return radius;
      default:
        throw std::out_of_range("Attempt to access invalid index on VIPRA::shape");
    }
  }

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  inline constexpr float operator[](T index) const {
    switch (index) {
      case 0:
        return centerpointx;
      case 1:
        return centerpointy;
      case 2:
        return length;
      case 3:
        return width;
      case 4:
        return radius;
      case "centerpointx":
        return centerpointx;
      case "centerpointy":
        return centerpointy;
      case "length":
        return length;
      case "width":
        return width;
      case "radius":
        return radius;
      default:
        throw std::out_of_range("Attempt to access invalid index on VIPRA::shape");
    }
  }

  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  inline constexpr shape operator*(T multiplier) const noexcept {
    return shape{centerpointx, centerpointy, length, width, radius} *= multiplier;
  }
  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  inline constexpr shape& operator*=(const T& multiplier) noexcept {
    centerpointx *= multiplier;
    centerpointy *= multiplier;
    length *= multiplier;
    width *= multiplier;
    radius *= multiplier;
    return *this;
  }

  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  inline constexpr shape operator/(T multiplier) const noexcept {
    return shape{centerpointx, centerpointy, length, width, radius} /= multiplier;
  }
  template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  inline constexpr shape& operator/=(const T& multiplier) noexcept {
    centerpointx /= multiplier;
    centerpointy /= multiplier;
    length /= multiplier;
    width /= multiplier;
    radius /= multiplier;
    return *this;
  }

  inline constexpr shape operator-(const shape& other) const noexcept { return shape{centerpointx - other.centerpointx, centerpointy - other.centerpointy, length - other.length, width - other.width, radius - other.radius}; }
  inline constexpr shape operator-(shape&& other) const noexcept { return shape{centerpointx - other.centerpointx, centerpointy - other.centerpointy, length - other.length, width - other.width, radius - other.radius}; }

  inline constexpr shape operator+(const shape& other) const noexcept { return shape{centerpointx + other.centerpointx, centerpointy + other.centerpointy, length + other.length, width + other.width, radius + other.radius}; }
  inline constexpr shape operator+(shape&& other) const noexcept { return shape{centerpointx + other.centerpointx, centerpointy + other.centerpointy, length + other.length, width + other.width, radius + other.radius}; }

  inline constexpr shape& operator+=(const shape& other) noexcept {
    centerpointx += other.centerpointx;
    centerpointy += other.centerpointy;
    length += other.length;
    width += other.width;
    radius += other.radius;
    return *this;
  }
  inline constexpr shape& operator+=(shape&& other) noexcept {
    centerpointx += other.centerpointx;
    centerpointy += other.centerpointy;
    length += other.length;
    width += other.width;
    radius += other.radius;
    return *this;
  }

  inline constexpr shape& operator-=(const shape& other) noexcept {
    centerpointx -= other.centerpointx;
    centerpointy -= other.centerpointy;
    length -= other.length;
    width -= other.width;
    radius -= other.radius;
    return *this;
  }
  inline constexpr shape& operator-=(shape&& other) noexcept {
    centerpointx -= other.centerpointx;
    centerpointy -= other.centerpointy;
    length -= other.length;
    width -= other.width;
    radius -= other.radius;
    return *this;
  }

  inline constexpr bool operator==(const shape& other) const noexcept {
    return (centerpointx == other.centerpointx && centerpointy == other.centerpointy && length == other.length && width == other.width && radius == other.radius);
  }
  inline constexpr bool operator==(shape&& other) const noexcept { return (centerpointx == other.centerpointx && centerpointy == other.centerpointy && length == other.length && width == other.width && radius == other.radius); }

  inline constexpr bool operator!=(const shape& other) const noexcept {
    return (centerpointx != other.centerpointx || centerpointy != other.centerpointy || length != other.length || width != other.width || radius != other.radius);
  }
  inline constexpr bool operator!=(shape&& other) const noexcept { return (centerpointx != other.centerpointx || centerpointy != other.centerpointy || length != other.length || width != other.width || radius != other.radius); }

  inline constexpr shape operator-() const noexcept { return shape{-centerpointx, -centerpointy, -length, -width, -radius}; }

};

using shapeVec = std::vector<shape>;

inline constexpr const shape _emptyshape_ =  // NOLINT
    VIPRA::shape{std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max()};

extern const shapeVec emptyshape_vec;  // NOLINT
}  // namespace VIPRA

#endif