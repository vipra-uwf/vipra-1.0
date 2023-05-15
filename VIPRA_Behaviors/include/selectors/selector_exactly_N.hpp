
#ifndef VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
#define VIPRA_EXACTLY_N_RANDOM_SELECTOR_H

#include <selectors/selector.hpp>

namespace BHVR {
struct SelectorExactlyN {
  size_t         selectCount;
  SelectorResult operator()(BHVR::seed, const VIPRA::idxVec&, const VIPRA::idxVec&, const PedestrianSet&, const ObstacleSet&,
                            const Goals&);
};
}  // namespace BHVR

#endif  //VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
