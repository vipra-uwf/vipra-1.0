#ifndef TYPE_DEFINITIONS_HPP
#define TYPE_DEFINITIONS_HPP

#include <limits>

#include "definitions/dimensions.hpp"

namespace VIPRA {
typedef int64_t  uid;
typedef uint64_t idx;
typedef uint64_t size;

typedef uint64_t t_step;
typedef float    delta_t;

constexpr const idx idx_INVALID = std::numeric_limits<idx>::max();
}  // namespace VIPRA

#endif