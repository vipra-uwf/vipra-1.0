#pragma once

#include "../_pch/pch.hpp"

typedef float FLOATING_NUMBER;

struct Dimensions {
  Dimensions() : axis{0, 0, 0} {}
  Dimensions(FLOATING_NUMBER x) : axis{x, 0, 0} {}
  Dimensions(FLOATING_NUMBER x, FLOATING_NUMBER y) : axis{x, y, 0} {}
  Dimensions(FLOATING_NUMBER x, FLOATING_NUMBER y, FLOATING_NUMBER z)
      : axis{x, y, z} {}

  FLOATING_NUMBER axis[3];

  bool operator==(const Dimensions& other) const {
    return (axis[0] == other.axis[0] && axis[1] == other.axis[1] &&
            axis[2] == other.axis[2]);
  }
  bool operator!=(const Dimensions& other) const {
    return (axis[0] != other.axis[0] || axis[1] != other.axis[1] ||
            axis[2] != other.axis[2]);
  }
};

typedef std::vector<Dimensions> DimVector;

typedef std::unordered_map<std::string, std::string> CONFIG_MAP;

typedef std::unordered_map<std::string, DimVector> ENTITY_SET;
