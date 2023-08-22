

#include <selectors/subselector.hpp>

namespace BHVR {

/**
 * @brief Runs the select function to select pedestrians
 * 
 * @param rngEngine : randomization engine
 * @param totalGroup : the whole group the selector pulls from
 * @param usableGroup : the actual selectable pedestrians from that group
 * @param pedSet : pedestrian set
 * @param obsSet : obstacle set
 * @param goals : goals module
 * @return SelectorResult 
 */
SelectorResult SubSelector::selectPeds(VIPRA::pRNG_Engine&         rngEngine,
                                       const VIPRA::idxVec&        totalGroup,
                                       const VIPRA::idxVec&        usableGroup,
                                       const VIPRA::PedestrianSet& pedSet,
                                       const VIPRA::ObstacleSet&   obsSet,
                                       const VIPRA::Goals&         goals) {
  return select(rngEngine, totalGroup, usableGroup, pedSet, obsSet, goals);
}

// ------------------- CONSTRUCTORS --------------------------------------------------------------------------

SubSelector::SubSelector(typeUID grp, Ptype typ, bool req, SelectorFunc sel)
    : group(grp), type(typ), required(req), select(std::move(sel)) {}

}  // namespace BHVR