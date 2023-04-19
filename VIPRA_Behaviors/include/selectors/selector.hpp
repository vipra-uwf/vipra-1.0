#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include <spdlog/spdlog.h>

#include <actions/action.hpp>
#include <definitions/behavior_context.hpp>
#include <definitions/pedestrian_types.hpp>

#include <selectors/pedestrian_groups.hpp>
#include <selectors/subselector.hpp>

namespace Behaviors {

class Selector {
 public:
  ~Selector() = default;

  Selector(const Selector&) = delete;
  Selector& operator=(const Selector&) = delete;

  Selector();
  Selector(Selector&&) noexcept;
  Selector& operator=(Selector&&) noexcept;

  Selector(SelectorFunc&&);

  void initialize(const std::string&,
                  Behaviors::seed,
                  BehaviorContext&,
                  const PedestrianSet&,
                  const ObstacleSet&,
                  const Goals&);

  void setAllTypes(pType);
  void addSubSelector(SubSelector&&);

  const GroupsContainer& getGroups() const;

  [[nodiscard]] VIPRA::size SelectorCount() const;

 private:
  pType                    allTypes;
  std::vector<SubSelector> subSelectors;
  GroupsContainer          pedGroups;

  std::vector<VIPRA::idx> selectPedsFromGroup(SubSelector&,
                                              Behaviors::seed,
                                              const PedestrianSet&,
                                              const ObstacleSet&,
                                              const Goals&,
                                              const std::string&);

  void updatePedGroups(const std::vector<VIPRA::idx>&, SubSelector&, BehaviorContext&, const std::string&);

  void sortGroups();
};
}  // namespace Behaviors

#endif