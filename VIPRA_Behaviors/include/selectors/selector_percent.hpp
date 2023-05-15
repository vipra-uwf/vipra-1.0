#ifndef ID_RATIO_SELECTOR_HPP
#define ID_RATIO_SELECTOR_HPP

#include <definitions/type_definitions.hpp>
#include <selectors/selector.hpp>

namespace BHVR {
struct SelectorPercent {
  float          percentage;
  SelectorResult operator()(BHVR::seed, const std::vector<VIPRA::idx>&, const std::vector<VIPRA::idx>&, const PedestrianSet&,
                            const ObstacleSet&, const Goals&) const;
};

}  // namespace BHVR

#endif