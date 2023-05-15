

#include <selectors/subselector.hpp>
#include <utility>

namespace BHVR {

SelectorResult SubSelector::selectPeds(seed s, const VIPRA::idxVec& totalGroup, const VIPRA::idxVec& usableGroup,
                                       const PedestrianSet& pedSet, const ObstacleSet& obsSet, const Goals& goals) {
  return select(s, totalGroup, usableGroup, pedSet, obsSet, goals);
}

// ------------------- CONSTRUCTORS --------------------------------------------------------------------------

SubSelector::SubSelector(typeUID g, Ptype t, bool r, SelectorFunc s)
    : group(g), type(t), required(r), select(std::move(s)) {}

}  // namespace BHVR