#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include <definitions/type_definitions.hpp>
#include <selectors/selector.hpp>

namespace BHVR {
struct SelectorEveryone {
  SelectorResult operator()(BHVR::seed, const VIPRA::idxVec&, const VIPRA::idxVec&, const PedestrianSet&, const ObstacleSet&,
                            const Goals&);
};

}  // namespace BHVR

#endif