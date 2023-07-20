#ifndef ID_RATIO_SELECTOR_HPP
#define ID_RATIO_SELECTOR_HPP

#include <selectors/selector.hpp>

namespace BHVR {
/**
 * @brief Selects a percentage of a group to be a type
 * 
 */
struct SelectorPercent {
  float          percentage;
  SelectorResult operator()(VIPRA::pRNG_Engine&, const std::vector<VIPRA::idx>&,
                            const std::vector<VIPRA::idx>&, const PedestrianSet&,
                            const ObstacleSet&, const Goals&) const;
};

}  // namespace BHVR

#endif