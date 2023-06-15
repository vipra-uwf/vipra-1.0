#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include <spdlog/spdlog.h>

#include <actions/action.hpp>
#include <definitions/behavior_context.hpp>
#include <definitions/pedestrian_types.hpp>

#include <randomization/random.hpp>
#include <selectors/pedestrian_groups.hpp>
#include <selectors/subselector.hpp>

namespace BHVR {

class Selector {
 public:
  Selector() = default;
  ~Selector() = default;
  Selector(const Selector&) = default;
  Selector& operator=(const Selector&) = default;
  Selector(Selector&&) noexcept = default;
  Selector& operator=(Selector&&) noexcept = default;

  void initialize(const std::string&, VIPRA::pRNG_Engine&, BehaviorContext&,
                  const PedestrianSet&, const ObstacleSet&, const Goals&);

  void setAllTypes(Ptype);
  void addSubSelector(const SubSelector&);

  [[nodiscard]] const GroupsContainer& getGroups() const;

  [[nodiscard]] VIPRA::size selectorCount() const;

 private:
  Ptype                    allTypes;
  std::vector<SubSelector> subSelectors;
  GroupsContainer          pedGroups;

  [[nodiscard]] VIPRA::idxVec selectPedsFromGroup(SubSelector&, VIPRA::pRNG_Engine&,
                                                  const PedestrianSet&,
                                                  const ObstacleSet&, const Goals&,
                                                  const std::string&);

  [[nodiscard]] VIPRA::idxVec        orderSelectors();
  [[nodiscard]] static VIPRA::idxVec filterUsedPeds(const VIPRA::idxVec&,
                                                    const std::vector<bool>&);

  void runSelectors(const VIPRA::idxVec&, const std::string&, VIPRA::pRNG_Engine&,
                    BehaviorContext&, const PedestrianSet&, const ObstacleSet&,
                    const Goals&);
  void updateUsedPeds(const VIPRA::idxVec&, std::vector<bool>&);
  void updatePedGroups(const VIPRA::idxVec&, SubSelector&, BehaviorContext&,
                       const std::string&);
  void sortGroups();
};
}  // namespace BHVR

#endif