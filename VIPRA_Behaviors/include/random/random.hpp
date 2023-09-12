#ifndef VIPRA_BEHAVIORS_RANDOM_HPP
#define VIPRA_BEHAVIORS_RANDOM_HPP

#include <cstdint>
#include <limits>

#include <definitions/dsl_types.hpp>
#include "definitions/type_definitions.hpp"

#include <distributions/distributions.hpp>
#include <randomization/random.hpp>

namespace BHVR {
class DRNG {
 public:
  /**
  * @brief Gets the random float between min and max that is assigned to the pedestrian at pedIdx
  * 
  */
  [[nodiscard]] static inline auto ped_random_float(BHVR::seed seed, VIPRA::idx pedIdx, float min, float max)
      -> float {
    VIPRA::uniform_distribution<float> distr{min, max};
    return distr(get_engine(seed + (pedIdx * PED_MULT_VAL)));
  }

 private:
  static constexpr uint64_t PED_MULT_VAL{10037};

  static inline auto get_engine(BHVR::seed seed) -> VIPRA::pRNG_Engine& {
    static VIPRA::pRNG_Engine gen{};
    gen.reseed(seed);
    return gen;
  }
};
}  // namespace BHVR

#endif