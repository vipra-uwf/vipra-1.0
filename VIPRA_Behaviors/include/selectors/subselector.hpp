#ifndef VIPRA_BHVR_SUB_SELECTOR_HPP
#define VIPRA_BHVR_SUB_SELECTOR_HPP

#include <functional>
#include <optional>

#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

#include <conditions/sub_condition.hpp>

#include <definitions/behavior_context.hpp>
#include <definitions/pedestrian_types.hpp>
#include <randomization/random.hpp>
#include <selectors/pedestrian_groups.hpp>

namespace BHVR {

/**
 * @brief Result of a call to a subselector
 * 
 */
struct SelectorResult {
  bool          starved;
  VIPRA::idxVec group;
};

/**
 * @brief Functor type for sub selectors
 * 
 */
using SelectorFunc = std::function<SelectorResult(
    VIPRA::pRNG_Engine&, const VIPRA::idxVec&, const VIPRA::idxVec&, const PedestrianSet&,
    const ObstacleSet&, const Goals&)>;

/**
 * @brief Subselectors are combined in a Selector to group pedestrians by type
 * 
 */
class SubSelector {
 public:
  SubSelector(typeUID, Ptype, bool, SelectorFunc);

  SelectorResult selectPeds(VIPRA::pRNG_Engine&, const VIPRA::idxVec&,
                            const VIPRA::idxVec&, const PedestrianSet&,
                            const ObstacleSet&, const Goals&);

  // NOLINTBEGIN - (rolland) Having these public increases readability   : ignoring (cppcoreguidelines-non-private-member-variables-in-classes)
  typeUID group;
  Ptype   type;
  bool    required;
  // NOLINTEND

 private:
  SelectorFunc                select;
  std::optional<SubCondition> condition;

 public:
  SubSelector() = delete;
  ~SubSelector() = default;
  SubSelector(SubSelector&&) noexcept = default;
  SubSelector(const SubSelector&) = default;
  SubSelector& operator=(SubSelector&&) noexcept = default;
  SubSelector& operator=(const SubSelector&) = default;
};

}  // namespace BHVR

#endif