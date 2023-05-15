#ifndef VIPRA_BHVR_SUB_SELECTOR_HPP
#define VIPRA_BHVR_SUB_SELECTOR_HPP

#include <functional>

#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

#include <conditions/sub_condition.hpp>

#include <definitions/behavior_context.hpp>
#include <definitions/pedestrian_types.hpp>
#include <selectors/pedestrian_groups.hpp>

namespace BHVR {

struct SelectorResult {
  bool          starved;
  VIPRA::idxVec group;
};

using SelectorFunc = std::function<SelectorResult(seed, const VIPRA::idxVec&, const VIPRA::idxVec&, const PedestrianSet&,
                                                  const ObstacleSet&, const Goals&)>;

class SubSelector {
 public:
  SubSelector(typeUID, Ptype, bool, SelectorFunc);
  SubSelector() = delete;
  ~SubSelector() = default;
  SubSelector(SubSelector&&) noexcept = default;
  SubSelector(const SubSelector&) = default;
  SubSelector& operator=(SubSelector&&) noexcept = default;
  SubSelector& operator=(const SubSelector&) = default;

  SelectorResult selectPeds(seed, const VIPRA::idxVec&, const VIPRA::idxVec&, const PedestrianSet&, const ObstacleSet&,
                            const Goals&);

  typeUID group;
  Ptype   type;
  bool    required;

 private:
  SelectorFunc                select;
  std::optional<SubCondition> condition;
};

}  // namespace BHVR

#endif