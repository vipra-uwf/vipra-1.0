

#include <selectors/subselector.hpp>
#include <utility>

namespace BHVR {

SelectorResult SubSelector::selectPeds(seed bSeed, const VIPRA::idxVec& totalGroup, const VIPRA::idxVec& usableGroup,
                                       const PedestrianSet& pedSet, const ObstacleSet& obsSet, const Goals& goals) {
  return select(bSeed, totalGroup, usableGroup, pedSet, obsSet, goals);
}

// ------------------- CONSTRUCTORS --------------------------------------------------------------------------

SubSelector::SubSelector(typeUID grp, Ptype typ, bool req, SelectorFunc sel)
    : group(grp), type(typ), required(req), select(std::move(sel)) {}

}  // namespace BHVR