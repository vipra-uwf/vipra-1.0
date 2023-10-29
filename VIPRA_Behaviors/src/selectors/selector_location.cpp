
#include "definitions/type_definitions.hpp"
#include "randomization/random.hpp"

#include "selectors/selector_location.hpp"

namespace BHVR {
/**
   * @brief Selects an exact number of pedestrians from a group
   * 
   * @param rngEngine : randomization engine
   * @param group : group to pull from
   * @return SelectorResult 
   */
auto SelectorLocation::operator()(VIPRA::pRNG_Engine& /*unused*/, const VIPRA::idxVec& /*unused*/,
                                  const VIPRA::idxVec& group, Simpack pack) const -> SelectorResult {
  const auto&   loc = pack.get_context().locations[location];
  size_t        pedCnt = 0;
  VIPRA::idxVec groupPeds;

  for (auto idx : group) {
    if (loc.inside(pack.get_pedset().getPedCoords(idx))) {
      groupPeds.push_back(idx);
    }
  }

  spdlog::debug("Selector Exaclty N: Selecting {} Pedestrians", pedCnt);

  return {false, groupPeds};
}
}  // namespace BHVR