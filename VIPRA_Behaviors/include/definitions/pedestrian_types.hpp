#ifndef VIPRA_BEHAVIORS_PEDESTRIAN_TYPES_HPP
#define VIPRA_BEHAVIORS_PEDESTRIAN_TYPES_HPP

#include <functional>
#include <stdint.h>

namespace Behaviors {

/**
 * @brief typeUID is used to identify a single pedestrian type, should only be powers of 2
 * 
 */
typedef uint64_t typeUID;

/**
 * @brief Pedestrian Type, used as a composite of typeUIDs
 * 
 */
struct pType {
  typeUID fullType = 0;

  ~pType() = default;
  constexpr pType() noexcept : fullType(0) {}

  explicit constexpr pType(typeUID id) noexcept : fullType(id) {}

  constexpr pType(const pType& other) noexcept : fullType(other.fullType) {}
  constexpr pType(pType&& other) noexcept : fullType(other.fullType) {}
  constexpr pType& operator=(const pType& other) noexcept {
    fullType = other.fullType;
    return *this;
  }
  constexpr pType& operator=(pType&& other) noexcept {
    fullType = other.fullType;
    return *this;
  }

  inline constexpr bool isType(typeUID type) const noexcept { return (type & fullType) && ((~type & fullType) == 0); }
  inline constexpr bool hasType(typeUID type) const noexcept { return type & fullType; }

  inline constexpr pType  operator+(typeUID type) const noexcept { return pType{fullType | type}; }
  inline constexpr pType& operator+=(typeUID type) noexcept {
    fullType = (fullType | type);
    return *this;
  }
  inline constexpr pType  operator+(pType type) const noexcept { return pType{fullType | type.fullType}; }
  inline constexpr pType& operator+=(pType type) noexcept {
    fullType = (fullType | type.fullType);
    return *this;
  }

  inline constexpr pType  operator-(typeUID type) const noexcept { return pType{fullType & ~type}; }
  inline constexpr pType& operator-=(typeUID type) noexcept {
    fullType = (fullType & ~type);
    return *this;
  }

  inline constexpr pType  operator-(pType type) const noexcept { return pType{fullType & ~type.fullType}; }
  inline constexpr pType& operator-=(pType type) noexcept {
    fullType = (fullType & ~type.fullType);
    return *this;
  }

  inline constexpr bool operator==(pType type) const noexcept { return fullType == type.fullType; }
  inline constexpr bool operator!=(pType type) const noexcept { return fullType != type.fullType; }

  void forEachType(std::function<void(typeUID)> func) {
    typeUID type = fullType;
    typeUID check = 1;
    while (check <= type) {
      if (type & check) {
        func(check);
      }
      check = check << 1;
    }
  }
};
}  // namespace Behaviors

#endif
