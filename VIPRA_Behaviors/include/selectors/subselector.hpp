#ifndef VIPRA_BEHAVIORS_SUB_SELECTOR_HPP
#define VIPRA_BEHAVIORS_SUB_SELECTOR_HPP

#include <functional>

#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

#include <conditions/sub_condition.hpp>

#include <definitions/behavior_context.hpp>
#include <definitions/pedestrian_types.hpp>
#include <selectors/pedestrian_groups.hpp>

namespace Behaviors {

struct SelectorResult {
  bool          starved;
  VIPRA::idxVec group;
};

using SelectorFunc = std::function<SelectorResult(seed,
                                                  const VIPRA::idxVec&,
                                                  const VIPRA::idxVec&,
                                                  const PedestrianSet&,
                                                  const ObstacleSet&,
                                                  const Goals&)>;

class SubSelector {
 public:
  SubSelector() = delete;
  ~SubSelector() = default;

  SubSelector(typeUID, pType, bool, SelectorFunc);

  SubSelector(SubSelector&&) noexcept;
  SubSelector(const SubSelector&) noexcept;
  SubSelector& operator=(SubSelector&&) noexcept;
  SubSelector& operator=(const SubSelector&) noexcept;

  SelectorResult selectPeds(seed,
                            const VIPRA::idxVec&,
                            const VIPRA::idxVec&,
                            const PedestrianSet&,
                            const ObstacleSet&,
                            const Goals&);

  typeUID group;
  pType   type;
  bool    required;

 private:
  SelectorFunc                select;
  std::optional<SubCondition> condition;
};

}  // namespace Behaviors

#endif