

#include <selectors/subselector.hpp>

namespace BHVR {

SelectorResult SubSelector::selectPeds(VIPRA::pRNG_Engine&  rngEngine,
                                       const VIPRA::idxVec& totalGroup,
                                       const VIPRA::idxVec& usableGroup,
                                       const PedestrianSet& pedSet,
                                       const ObstacleSet& obsSet, const Goals& goals) {
  return select(rngEngine, totalGroup, usableGroup, pedSet, obsSet, goals);
}

// ------------------- CONSTRUCTORS --------------------------------------------------------------------------

SubSelector::SubSelector(typeUID grp, Ptype typ, bool req, SelectorFunc sel)
    : group(grp), type(typ), required(req), select(std::move(sel)) {}

}  // namespace BHVR