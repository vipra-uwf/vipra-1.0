
#include <algorithm>
#include <cmath>
#include <output/output.hpp>
#include <random>
#include <randomization/random.hpp>
#include "definitions/type_definitions.hpp"

#include "selectors/selector_location.hpp"

namespace BHVR {
/**
   * @brief Selects an exact number of pedestrians from a group
   * 
   * @param rngEngine : randomization engine
   * @param group : group to pull from
   * @return SelectorResult 
   */
SelectorResult SelectorLocation::operator()(VIPRA::pRNG_Engine&, const VIPRA::idxVec&,
                                            const VIPRA::idxVec& group,
                                            Simpack              pack) const {
  const auto&   loc = pack.context.locations.at(location);
  size_t        pedCnt = 0;
  VIPRA::idxVec groupPeds;

  for (auto idx : group) {
    if (loc.inside(pack.pedSet.getPedCoords(idx))) {
      VIPRA::Output::pedValue(idx, "group", location);
      groupPeds.push_back(idx);
    }
  }

  spdlog::debug("Selector Exaclty N: Selecting {} Pedestrians", pedCnt);

  return {false, groupPeds};
}
}  // namespace BHVR