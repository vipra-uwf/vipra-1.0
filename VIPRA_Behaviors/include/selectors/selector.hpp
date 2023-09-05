#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include <spdlog/spdlog.h>

#include <actions/action.hpp>
#include <definitions/behavior_context.hpp>
#include <definitions/pedestrian_types.hpp>

#include <randomization/random.hpp>
#include <selectors/pedestrian_groups.hpp>
#include <selectors/subselector.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {

/**
 * @brief Combines/Organizes SubSelectors to select pedestrians for types
 * 
 */
class Selector {
 public:
  Selector() = default;
  ~Selector() = default;
  Selector(const Selector&) = default;
  Selector& operator=(const Selector&) = default;
  Selector(Selector&&) noexcept = default;
  Selector& operator=(Selector&&) noexcept = default;

  void initialize(const std::string&, VIPRA::pRNG_Engine&, Simpack);

  void setAllTypes(Ptype);
  void addSubSelector(const SubSelector&);

  [[nodiscard]] const GroupsContainer& getGroups() const;

  [[nodiscard]] VIPRA::size selectorCount() const;

 private:
  Ptype                    allTypes;
  std::vector<SubSelector> subSelectors;
  GroupsContainer          pedGroups;

  [[nodiscard]] VIPRA::idxVec selectPedsFromGroup(SubSelector&, VIPRA::pRNG_Engine&,
                                                  const VIPRA::PedestrianSet&,
                                                  const VIPRA::ObstacleSet&,
                                                  const VIPRA::Goals&,
                                                  const std::string&);

  [[nodiscard]] VIPRA::idxVec        orderSelectors();
  [[nodiscard]] static VIPRA::idxVec filterUsedPeds(const VIPRA::idxVec&,
                                                    const std::vector<bool>&);

  void runSelectors(const VIPRA::idxVec&, const std::string&, VIPRA::pRNG_Engine&,
                    Simpack);
  void updateUsedPeds(const VIPRA::idxVec&, std::vector<bool>&);
  void updatePedGroups(const VIPRA::idxVec&, SubSelector&, BehaviorContext&,
                       const std::string&);
  void sortGroups();
};
}  // namespace BHVR

#endif