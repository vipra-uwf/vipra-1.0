#ifndef VIPRA_DIMENSIONS_HPP
#define VIPRA_DIMENSIONS_HPP

#include <cmath>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace VIPRA {
// NOLINTNEXTLINE
struct f2d {
  float x, y;

  ~f2d() = default;
  constexpr explicit f2d() noexcept : x(0), y(0) {}
  constexpr explicit f2d(float valX) noexcept : x(valX), y(0) {}
  constexpr explicit f2d(float valX, float valY) noexcept : x(valX), y(valY) {}
  constexpr f2d(const f2d& other) noexcept = default;
  constexpr f2d(f2d&& other) noexcept = default;
  constexpr f2d& operator=(const f2d& other) noexcept = default;
  constexpr f2d& operator=(f2d&& other) noexcept {
    x = other.x;
    y = other.y;
    return *this;
  }

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  inline constexpr float& operator[](T index) {
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
  inline constexpr float operator[](T index) const {
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

  template <typename T>
  inline constexpr f2d& operator*=(T&& multiplier) noexcept {
    x *= multiplier;
    y *= multiplier;
    return *this;
  }

  template <typename T>
  inline constexpr f2d operator*(T&& multiplier) const noexcept {
    return f2d{x, y} *= std::forward<T>(multiplier);
  }

  template <typename T>
  inline constexpr f2d operator/(T&& multiplier) const noexcept {
    return f2d{x, y} /= std::forward<T>(multiplier);
  }

  template <typename T>
  inline constexpr f2d& operator/=(T&& multiplier) noexcept {
    x /= multiplier;
    y /= multiplier;
    return *this;
  }

  inline constexpr f2d operator+(const f2d& other) const noexcept {
    return f2d{x + other.x, y + other.y};
  }
  inline constexpr f2d operator-(const f2d& other) const noexcept {
    return f2d{x - other.x, y - other.y};
  }

  inline constexpr f2d& operator+=(const f2d& other) noexcept {
    x += other.x;
    y += other.y;
    return *this;
  }

  inline constexpr f2d& operator-=(const f2d& other) noexcept {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  [[nodiscard]] inline constexpr float distanceTo(const f2d& other) const {
    const float dX = other.x - x;
    const float dY = other.y - y;

    return std::sqrt((dX * dX) + (dY * dY));
  }

  inline constexpr f2d operator-() const noexcept { return f2d{-x, -y}; }

  [[nodiscard]] inline constexpr f2d unit() const {
    const float mag = std::sqrt((x * x) + (y * y));
    return VIPRA::f2d{x, y} /= mag;
  }

  inline constexpr bool operator==(const f2d& other) const noexcept {
    return (x == other.x && y == other.y);
  }
  inline constexpr bool operator==(f2d&& other) const noexcept {
    return (x == other.x && y == other.y);
  }
  inline constexpr bool operator!=(const f2d& other) const noexcept {
    return (x != other.x || y != other.y);
  }
  inline constexpr bool operator!=(f2d&& other) const noexcept {
    return (x != other.x || y != other.y);
  }

  [[nodiscard]] inline constexpr float dot(const f2d& other) const {
    return (x * other.x) + (y * other.y);
  }
};

// NOLINTNEXTLINE (rolland) Keeping f3d from before format changes :  ignore(readability-identifier-naming)
struct f3d {
  float x, y, z;

  ~f3d() = default;
  constexpr explicit f3d() noexcept : x(0), y(0), z(0) {}
  constexpr explicit f3d(float valX) noexcept : x(valX), y(0), z(0) {}
  constexpr explicit f3d(float valX, float valY) noexcept : x(valX), y(valY), z(0) {}
  constexpr explicit f3d(float valX, float valY, float valZ) noexcept
      : x(valX), y(valY), z(valZ) {}
  constexpr f3d(const f3d& other) noexcept = default;
  constexpr f3d(f3d&& other) noexcept = default;
  constexpr f3d& operator=(const f3d& other) noexcept = default;
  constexpr f3d& operator=(f3d&& other) noexcept = default;

  explicit constexpr f3d(const f2d& other) noexcept : x(other.x), y(other.y), z(0) {}
  explicit constexpr f3d(f2d&& other) noexcept : x(other.x), y(other.y), z(0) {}
  constexpr f3d& operator=(const f2d& other) noexcept {
    x = other.x;
    y = other.y;
    z = 0;
    return *this;
  }
  constexpr f3d& operator=(f2d&& other) noexcept {
    x = other.x;
    y = other.y;
    z = 0;
    return *this;
  }

  template <typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
  inline constexpr float& operator[](T index) {
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
  inline constexpr float operator[](T index) const {
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

  template <typename T>
  inline constexpr f3d operator*(T&& multiplier) const noexcept {
    return f3d{x, y, z} *= std::forward<T>(multiplier);
  }
  template <typename T>
  inline constexpr f3d& operator*=(T&& multiplier) noexcept {
    x *= multiplier;
    y *= multiplier;
    z *= multiplier;
    return *this;
  }

  template <typename T>
  inline constexpr f3d operator/(T&& multiplier) const noexcept {
    return f3d{x, y, z} /= std::forward<T>(multiplier);
  }
  template <typename T>
  inline constexpr f3d& operator/=(T&& multiplier) noexcept {
    x /= multiplier;
    y /= multiplier;
    z /= multiplier;
    return *this;
  }

  inline constexpr f3d operator-(const f2d& other) const noexcept {
    return f3d{x - other.x, y - other.y, z};
  }
  inline constexpr f3d operator-(const f3d& other) const noexcept {
    return f3d{x - other.x, y - other.y, z - other.z};
  }
  inline constexpr f3d operator-(f3d&& other) const noexcept {
    return f3d{x - other.x, y - other.y, z - other.z};
  }
  inline constexpr f3d operator+(const f2d& other) const noexcept {
    return f3d{x + other.x, y + other.y, z};
  }
  inline constexpr f3d operator+(const f3d& other) const noexcept {
    return f3d{x + other.x, y + other.y, z + other.z};
  }
  inline constexpr f3d operator+(f3d&& other) const noexcept {
    return f3d{x + other.x, y + other.y, z + other.z};
  }

  inline constexpr f3d& operator+=(const f3d& other) noexcept {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }
  inline constexpr f3d& operator+=(f3d&& other) noexcept {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  inline constexpr f3d& operator-=(const f3d& other) noexcept {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }
  inline constexpr f3d& operator-=(f3d&& other) noexcept {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  [[nodiscard]] inline constexpr float distanceToSquared(
      const f3d& other) const noexcept {
    const float dX = other.x - x;
    const float dY = other.y - y;
    const float dZ = other.z - z;

    return (dX * dX) + (dY * dY) + (dZ * dZ);
  }

  [[nodiscard]] inline constexpr float distanceTo(const f2d& other) const {
    const float dX = other.x - x;
    const float dY = other.y - y;
    const float dZ = 0 - z;

    return std::sqrt((dX * dX) + (dY * dY) + (dZ * dZ));
  }

  [[nodiscard]] inline constexpr float distanceTo(const f3d& other) const {
    const float dX = other.x - x;
    const float dY = other.y - y;
    const float dZ = other.z - z;

    return std::sqrt((dX * dX) + (dY * dY) + (dZ * dZ));
  }

  inline constexpr float distanceTo(f3d&& other) const {
    const float dX = other.x - x;
    const float dY = other.y - y;
    const float dZ = other.z - z;

    return std::sqrt((dX * dX) + (dY * dY) + (dZ * dZ));
  }

  inline constexpr bool operator==(const f3d& other) const noexcept {
    return (x == other.x && y == other.y && z == other.z);
  }
  inline constexpr bool operator==(f3d&& other) const noexcept {
    return (x == other.x && y == other.y && z == other.z);
  }

  inline constexpr bool operator!=(const f3d& other) const noexcept {
    return (x != other.x || y != other.y || z != other.z);
  }
  inline constexpr bool operator!=(f3d&& other) const noexcept {
    return (x != other.x || y != other.y || z != other.z);
  }

  inline constexpr f3d operator-() const noexcept { return f3d{-x, -y, -z}; }

  /**
   * @brief Returns the unit vector in the direction of the f3d
   * 
   * @return constexpr f3d 
   */
  [[nodiscard]] inline constexpr f3d unit() const noexcept {
    if (x == 0 && y == 0 && z == 0) {
      return f3d{0, 0, 0};
    }
    return f3d{x, y, z} / magnitude();
  }

  /**
   * @brief Returns vector magnitude^2
   * 
   * @return constexpr float 
   */
  [[nodiscard]] inline constexpr float magnitudeSquared() const noexcept {
    return (x * x) + (y * y) + (z * z);
  }

  /**
   * @brief Returns the vectors magnitude
   * 
   * @return constexpr float 
   */
  [[nodiscard]] inline constexpr float magnitude() const {
    return std::sqrt((x * x) + (y * y) + (z * z));
  }

  /**
   * @brief Returns the dot product between two f3ds
   * 
   * @param other : 
   * @return constexpr float 
   */
  [[nodiscard]] inline constexpr float dot(const f3d& other) const noexcept {
    return (x * other.x) + (y * other.y) + (z * other.z);
  }
};

template <typename T>
inline constexpr f3d operator*(T&& multiplier, const f3d& other) noexcept {
  return f3d{other.x * multiplier, other.y * multiplier, other.z * multiplier};
}

template <typename T>
inline constexpr f2d operator*(T&& multiplier, const f2d& other) noexcept {
  return f2d{other.x * multiplier, other.y * multiplier};
}

using f2dVec = std::vector<f2d>;
using f3dVec = std::vector<f3d>;

struct F3dHash {
  std::size_t operator()(const f3d& object) const {
    std::size_t seed = 0;

    seed += std::hash<float>{}(object.x);
    seed += std::hash<float>{}(object.y);
    seed += std::hash<float>{}(object.z);

    return seed;
  }
};

inline constexpr const f2d _emptyf2d_ =  // NOLINT
    VIPRA::f2d{std::numeric_limits<float>::max(), std::numeric_limits<float>::max()};
inline constexpr const f3d _emptyf3d_ =  // NOLINT
    VIPRA::f3d{std::numeric_limits<float>::max(), std::numeric_limits<float>::max(),
               std::numeric_limits<float>::max()};

extern const f2dVec emptyf2d_vec;  // NOLINT
extern const f3dVec emptyf3d_vec;  // NOLINT
}  // namespace VIPRA

#endif