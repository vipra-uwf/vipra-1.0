#ifndef TYPE_DEFINITIONS_HPP
#define TYPE_DEFINITIONS_HPP

#include <cstdint>
#include <limits>
#include <vector>

#include <definitions/dimensions.hpp>

namespace VIPRA {

/**
 * @brief used for goal points
 */
using goal = VIPRA::f3d;

/**
 * @brief used for pedestrian coordinates
 */
using pcoord = VIPRA::f3d;

/**
 * @brief used for velocities
 * 
 */
using veloc = VIPRA::f3d;

/**
 * @brief used for distance
 */
using dist = float;

/**
 * @brief used for indexes into containers
 */
using idx = uint64_t;
/**
 * @brief used for a count of container elements
 */
using size = uint64_t;

/**
 * @brief used for counting
 */
using cnt = uint64_t;

/**
 * @brief used for time step count
 */
using t_step = uint64_t;
/**
 * @brief used for a change in time, in seconds
 */
using delta_t = float;
/**
 * @brief used for a time value, in seconds
 */
using time_s = float;
/**
 * @brief used for a time value, in milliseconds
 */
using time_ms = float;

/**
 * @brief used for a range of time, in seconds
 */
using time_range_s = std::pair<VIPRA::time_s, VIPRA::time_s>;

/**
 * @brief used for a range of time, in milliseconds
 */
using time_range_ms = std::pair<VIPRA::time_ms, VIPRA::time_ms>;

/**
 * @brief used for a vector of indexes
 */
using idxVec = std::vector<idx>;

/**
 * @brief used for an invalid index, where an exception is the wrong option
 */
static constexpr const idx idx_INVALID = std::numeric_limits<idx>::max();  // NOLINT

}  // namespace VIPRA

#endif