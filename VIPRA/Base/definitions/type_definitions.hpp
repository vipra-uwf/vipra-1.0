#ifndef TYPE_DEFINITIONS_HPP
#define TYPE_DEFINITIONS_HPP

#include <limits>
#include <vector>

#include "definitions/dimensions.hpp"

namespace VIPRA {
using idx = uint64_t;
using size = uint64_t;

using t_step = uint64_t;
using delta_t = float;

using idxVec = std::vector<idx>;

static constexpr const idx idx_INVALID = std::numeric_limits<idx>::max();  // NOLINT

}  // namespace VIPRA

#endif