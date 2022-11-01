#ifndef TYPE_DEFINITIONS_HPP
#define TYPE_DEFINITIONS_HPP

#include "../_pch/pch.hpp"

typedef float FLOATING_NUMBER;

struct Dimensions {
  Dimensions() : axis{0, 0, 0} {}
  Dimensions(FLOATING_NUMBER x) : axis{x, 0, 0} {}
  Dimensions(FLOATING_NUMBER x, FLOATING_NUMBER y) : axis{x, y, 0} {}
  Dimensions(FLOATING_NUMBER x, FLOATING_NUMBER y, FLOATING_NUMBER z) : axis{x, y, z} {}

  FLOATING_NUMBER axis[3];

  bool operator==(const Dimensions& other) const {
    return (axis[0] == other.axis[0] && axis[1] == other.axis[1] && axis[2] == other.axis[2]);
  }
  bool operator!=(const Dimensions& other) const {
    return (axis[0] != other.axis[0] || axis[1] != other.axis[1] || axis[2] != other.axis[2]);
  }

  inline Dimensions operator+(const Dimensions& other) const {
    return Dimensions{axis[0] + other.axis[0], axis[1] + other.axis[1], axis[2] + other.axis[2]};
  }

  inline Dimensions operator-(const Dimensions& other) const {
    return Dimensions{axis[0] - other.axis[0], axis[1] - other.axis[1], axis[2] - other.axis[2]};
  }

  inline Dimensions operator/(FLOATING_NUMBER divisor) const {
    return Dimensions{axis[0] / divisor, axis[1] / divisor, axis[2] / divisor};
  }

  inline Dimensions operator*(FLOATING_NUMBER multiplier) const {
    return Dimensions{axis[0] * multiplier, axis[1] * multiplier, axis[2] * multiplier};
  }

  FLOATING_NUMBER distanceTo(const Dimensions& other) const {
    FLOATING_NUMBER dX = other.axis[0] - axis[0];
    FLOATING_NUMBER dY = other.axis[1] - axis[1];
    FLOATING_NUMBER dZ = other.axis[2] - axis[2];

    if (dX != 0) {
      dX = dX * dX;
    }
    if (dY != 0) {
      dY = dY * dY;
    }
    if (dZ != 0) {
      dZ = dZ * dZ;
    }

    return sqrt(dX + dY + dZ);
  }

  bool inside(const Dimensions& other, FLOATING_NUMBER sideLength) const {
    const FLOATING_NUMBER half = sideLength / 2;
    return (axis[0] >= other.axis[0] - half && axis[0] <= other.axis[0] + half &&
            axis[1] <= other.axis[1] + half && axis[1] >= other.axis[1] - half);
  }
};

typedef std::vector<Dimensions> DimVector;

typedef std::unordered_map<std::string, std::string> CONFIG_MAP;

typedef std::unordered_map<std::string, DimVector> ENTITY_SET;

#endif