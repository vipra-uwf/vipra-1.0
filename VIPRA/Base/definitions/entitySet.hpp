#ifndef VIPRA_ENTITY_SET_HPP
#define VIPRA_ENTITY_SET_HPP

#include <string>
#include <unordered_map>

#include "definitions/dimensions.hpp"

namespace VIPRA {
/**
  * @brief Holds types of objects and their positions
  * 
  */
using EntitySet = std::unordered_map<std::string, f3dVec>;
}  // namespace VIPRA

#endif