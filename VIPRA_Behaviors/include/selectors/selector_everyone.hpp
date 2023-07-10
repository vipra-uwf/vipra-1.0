#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include <selectors/selector.hpp>

namespace BHVR {
struct SelectorEveryone {
  SelectorResult operator()(VIPRA::pRNG_Engine&, const VIPRA::idxVec&,
                            const VIPRA::idxVec&, const PedestrianSet&,
                            const ObstacleSet&, const Goals&);
};

}  // namespace BHVR

#endif