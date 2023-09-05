#ifndef VIPRA_BHVR_PEDESTRIAN_TYPES_HPP
#define VIPRA_BHVR_PEDESTRIAN_TYPES_HPP

#include <cstdint>
#include <functional>

#include "definitions/type_definitions.hpp"

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
   * @brief Loops through each individual type, starting from 1, calling func with the type. example(1, 2, 4, 8)
   * 
   * @param func : function to apply to each type
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
  [[nodiscard]] inline constexpr bool hasType(typeUID type) const noexcept {
    return (type & fullType) != 0U;
  }

  /**
   * @brief Returns they union of the ptype and the type provided
   * 
   * @param type : type to union with
   * @return constexpr Ptype 
   */
  inline constexpr Ptype operator+(typeUID type) const noexcept {
    return Ptype{fullType | type};
  }

  /**
   * @brief Adds a type to the ptype
   * 
   * @param type : type to add
   * @return constexpr Ptype& 
   */
  inline constexpr Ptype& operator+=(typeUID type) noexcept {
    fullType = (fullType | type);
    return *this;
  }

  /**
   * @brief Returns the union of the two ptypes
   * 
   * @param type : ptype to union
   * @return constexpr Ptype 
   */
  inline constexpr Ptype operator+(Ptype type) const noexcept {
    return Ptype{fullType | type.fullType};
  }

  /**
   * @brief Adds the given ptype
   * 
   * @param type : ptype to add
   * @return constexpr Ptype& 
   */
  inline constexpr Ptype& operator+=(Ptype type) noexcept {
    fullType = (fullType | type.fullType);
    return *this;
  }

  /**
   * @brief Returns a ptype without the given type
   * 
   * @param type : type to remove
   * @return constexpr Ptype 
   */
  inline constexpr Ptype operator-(typeUID type) const noexcept {
    return Ptype{fullType & ~type};
  }

  /**
   * @brief Removes the type from the ptype
   * 
   * @param type : type to remove
   * @return constexpr Ptype& 
   */
  inline constexpr Ptype& operator-=(typeUID type) noexcept {
    fullType = (fullType & ~type);
    return *this;
  }

  /**
   * @brief Returns the difference of the two ptypes
   * 
   * @param type : ptype to compare
   * @return constexpr Ptype 
   */
  inline constexpr Ptype operator-(Ptype type) const noexcept {
    return Ptype{fullType & ~type.fullType};
  }

  /**
   * @brief Sets the ptype as the difference of the two types
   * 
   * @param type : type to compare
   * @return constexpr Ptype& 
   */
  inline constexpr Ptype& operator-=(Ptype type) noexcept {
    fullType = (fullType & ~type.fullType);
    return *this;
  }

  /**
   * @brief Checks if two ptypes are the same
   * 
   * @param type : ptype to compare
   * @return true 
   * @return false 
   */
  inline constexpr bool operator==(Ptype type) const noexcept {
    return fullType == type.fullType;
  }

  /**
   * @brief Checks if two ptypes are different
   * 
   * @param type : 
   * @return true 
   * @return false 
   */
  inline constexpr bool operator!=(Ptype type) const noexcept {
    return fullType != type.fullType;
  }

  ~Ptype() = default;
  constexpr Ptype() noexcept = default;
  constexpr Ptype(const Ptype& other) = default;
  constexpr Ptype& operator=(const Ptype& other) = default;
  constexpr Ptype(Ptype&& other) noexcept = default;
  constexpr Ptype& operator=(Ptype&& other) noexcept = default;
};
}  // namespace BHVR

#endif
