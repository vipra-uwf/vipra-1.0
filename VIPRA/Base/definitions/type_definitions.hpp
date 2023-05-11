#ifndef TYPE_DEFINITIONS_HPP
#define TYPE_DEFINITIONS_HPP

#include <limits>
#include <vector>

#include "definitions/dimensions.hpp"

namespace VIPRA {
typedef uint64_t idx;
typedef uint64_t size;

typedef uint64_t t_step;
typedef float    delta_t;

typedef std::vector<idx> idxVec;

static constexpr const idx idx_INVALID = std::numeric_limits<idx>::max();

}  // namespace VIPRA

#endif