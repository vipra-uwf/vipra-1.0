#ifndef VIPRA_DSL_TYPES_HPP
#define VIPRA_DSL_TYPES_HPP

#include <cstdint>
#include <utility>

#include <definitions/type_definitions.hpp>

namespace BHVR {
/**
  * @brief Used for random engine seeds
  * 
  */
using seed = uint64_t;

/**
 * @brief Unique id for a state value
 * 
 */
using stateUID = uint64_t;
}  // namespace BHVR

#endif