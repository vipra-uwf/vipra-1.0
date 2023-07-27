#ifndef VIPRA_DSL_TYPES_HPP
#define VIPRA_DSL_TYPES_HPP

#include <cstdint>
#include <utility>

#include <definitions/type_definitions.hpp>

namespace BHVR {
/**
  * @brief Seed for randomization
  * 
  */
using seed = uint64_t;

/**
 * @brief Unique identifier for a pedestrian/environment state
 * 
 */
using stateUID = uint64_t;
}  // namespace BHVR

#endif