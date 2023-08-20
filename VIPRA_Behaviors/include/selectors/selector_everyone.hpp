#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include <selectors/selector.hpp>

namespace BHVR {
/**
  * @brief Selects every pedestrian
  * 
  */
struct SelectorEveryone {
  SelectorResult operator()(VIPRA::pRNG_Engine&, const VIPRA::idxVec&,
                            const VIPRA::idxVec&, const VIPRA::PedestrianSet&,
                            const VIPRA::ObstacleSet&, const VIPRA::Goals&);
};

}  // namespace BHVR

#endif