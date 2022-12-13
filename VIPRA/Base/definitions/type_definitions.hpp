#ifndef TYPE_DEFINITIONS_HPP
#define TYPE_DEFINITIONS_HPP

#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

#include "definitions/dimensions.hpp"

namespace VIPRA {
typedef std::unordered_map<std::string, std::string> ConfigMap;
typedef std::unordered_map<std::string, f3dVec>      EntitySet;
}  // namespace VIPRA

#endif