#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include <spdlog/spdlog.h>

#include "actions/action.hpp"
#include "definitions/behavior_context.hpp"
#include "definitions/pedestrian_types.hpp"

#include "definitions/sim_pack.hpp"
#include "randomization/random.hpp"
#include "selectors/pedestrian_groups.hpp"
#include "selectors/subselector.hpp"

namespace BHVR {

/**
 * @brief Combines/Organizes SubSelectors to select pedestrians for types
 * 
 */
class Selector {
  DEFAULT_CONSTRUCTIBLE(Selector)
  COPYABLE(Selector)
  MOVEABLE(Selector)

 public:
  void initialize(const std::string&, VIPRA::pRNG_Engine&, Simpack);

  void set_all_types(Ptype);
  void add_sub_selector(const SubSelector&);

  [[nodiscard]] auto get_groups() const -> const GroupsContainer&;

  [[nodiscard]] auto selector_count() const -> VIPRA::size;

 private:
  Ptype                    _allTypes;
  std::vector<SubSelector> _subSelectors;
  GroupsContainer          _pedGroups;

  [[nodiscard]] auto select_peds_from_group(SubSelector&, VIPRA::pRNG_Engine&, Simpack, const std::string&)
      -> VIPRA::idxVec;

  [[nodiscard]] auto        order_selectors() -> VIPRA::idxVec;
  [[nodiscard]] static auto filter_used_peds(const VIPRA::idxVec&, const std::vector<bool>&) -> VIPRA::idxVec;

  void run_selectors(const VIPRA::idxVec&, const std::string&, VIPRA::pRNG_Engine&, Simpack);
  void update_used_peds(const VIPRA::idxVec&, std::vector<bool>&);
  void update_ped_groups(const VIPRA::idxVec&, SubSelector&, BehaviorContext&, const std::string&);
  void sort_groups();
};
}  // namespace BHVR

#endif