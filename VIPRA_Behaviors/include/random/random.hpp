#ifndef VIPRA_BEHAVIORS_RANDOM_HPP
#define VIPRA_BEHAVIORS_RANDOM_HPP

#include <cstdint>
#include <limits>

#include <definitions/dsl_types.hpp>
#include <definitions/type_definitions.hpp>

#include <randomization/random.hpp>

namespace BHVR {
class DRNG {
 public:
  /**
  * @brief Gets the random float between min and max that is assigned to the pedestrian at pedIdx
  * 
  */
  [[nodiscard]] static inline float pedRandomFloat(BHVR::seed seed, VIPRA::idx pedIdx,
                                                   float min, float max) {
    VIPRA::uniform_distribution<float> distr{min, max};
    return distr(getEngine(seed + (pedIdx * pedMultVal)));
  }

 private:
  static constexpr uint64_t pedMultVal{10037};

  static inline VIPRA::pRNG_Engine& getEngine(BHVR::seed seed) {
    static VIPRA::pRNG_Engine gen{};
    gen.reseed(seed);
    return gen;
  }
};
}  // namespace BHVR

#endif