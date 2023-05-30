#ifndef VIPRA_BHVR_PEDESTRIAN_TYPES_HPP
#define VIPRA_BHVR_PEDESTRIAN_TYPES_HPP

#include <cstdint>
#include <functional>

#include <definitions/type_definitions.hpp>

namespace BHVR {

/**
 * @brief typeUID is used to identify a single pedestrian type, should only be powers of 2
 * 
 */
using typeUID = uint64_t;

/**
 * @brief Pedestrian Type, used as a composite of typeUIDs
 * 
 */
class Ptype {
 public:
  typeUID fullType = 0;

  explicit constexpr Ptype(typeUID id) noexcept : fullType(id) {}

  /**
   * @brief Returns the number of different types, excluding the base type (0)
   * 
   * @return constexpr VIPRA::size 
   */
  [[nodiscard]] inline constexpr VIPRA::size typeCount() const {
    VIPRA::size count = 0;
    typeUID     check = 1;
    while ((check & fullType) != 0U) {
      check = check << 1U;
      ++count;
    }

    return count;
  }


  /**
   * @brief Loops through each individual type, starting from 1. example(1, 2, 4, 8)
   * 
   * @param func : 
   */
  void forEachType(const std::function<void(typeUID)>& func) const {
    typeUID type = fullType;
    typeUID check = 1;
    while (check <= type) {
      if ((type & check) != 0U) {
        func(check);
      }
      check = check << 1U;
    }
  }


  /**
   * @brief Checks if the Ptype has the given type
   * 
   * @param type : type to check for
   */
  [[nodiscard]] inline constexpr bool isType(typeUID type) const noexcept {
    return ((type & fullType) != 0U) && ((~type & fullType) == 0);
  }


  /**
   * @brief Checks if the Ptype has the given type
   * 
   * @param type : type to check for
   */
  [[nodiscard]] inline constexpr bool hasType(typeUID type) const noexcept { return (type & fullType) != 0U; }

  inline constexpr Ptype  operator+(typeUID type) const noexcept { return Ptype{fullType | type}; }
  inline constexpr Ptype& operator+=(typeUID type) noexcept {
    fullType = (fullType | type);
    return *this;
  }
  inline constexpr Ptype  operator+(Ptype type) const noexcept { return Ptype{fullType | type.fullType}; }
  inline constexpr Ptype& operator+=(Ptype type) noexcept {
    fullType = (fullType | type.fullType);
    return *this;
  }

  inline constexpr Ptype  operator-(typeUID type) const noexcept { return Ptype{fullType & ~type}; }
  inline constexpr Ptype& operator-=(typeUID type) noexcept {
    fullType = (fullType & ~type);
    return *this;
  }

  inline constexpr Ptype  operator-(Ptype type) const noexcept { return Ptype{fullType & ~type.fullType}; }
  inline constexpr Ptype& operator-=(Ptype type) noexcept {
    fullType = (fullType & ~type.fullType);
    return *this;
  }

  inline constexpr bool operator==(Ptype type) const noexcept { return fullType == type.fullType; }
  inline constexpr bool operator!=(Ptype type) const noexcept { return fullType != type.fullType; }

  ~Ptype() = default;
  constexpr Ptype() noexcept = default;
  constexpr Ptype(const Ptype& other) = default;
  constexpr Ptype& operator=(const Ptype& other) = default;
  constexpr Ptype(Ptype&& other) noexcept = default;
  constexpr Ptype& operator=(Ptype&& other) noexcept = default;
};
}  // namespace BHVR

#endif
