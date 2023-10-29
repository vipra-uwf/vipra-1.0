#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include <selectors/selector.hpp>

namespace BHVR {
/**
  * @brief Selects every pedestrian
  * 
  */
struct SelectorEveryone {
  auto operator()(VIPRA::pRNG_Engine&, const VIPRA::idxVec&, const VIPRA::idxVec&, Simpack) -> SelectorResult;
};

}  // namespace BHVR

#endif