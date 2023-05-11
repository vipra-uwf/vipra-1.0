#ifndef VIPRA_BEHAVIORS_PEDESTRIAN_GROUPS_HPP
#define VIPRA_BEHAVIORS_PEDESTRIAN_GROUPS_HPP

#include <vector>

#include <pedestrian_set/pedestrian_set.hpp>

#include <definitions/pedestrian_types.hpp>
#include <definitions/type_definitions.hpp>

namespace Behaviors {

/**
 * @brief Holds the indexes for pedestrians in each type group
 * 
 */
class GroupsContainer {
 public:
  static constexpr VIPRA::idx Index(typeUID type) {
    if (type == 0)
      return 0;

    VIPRA::idx check = 1;
    VIPRA::idx index = 1;
    while (!(check & type)) {
      check = check << 1;
      ++index;
    }

    return index;
  }

  GroupsContainer();
  ~GroupsContainer() = default;

  GroupsContainer(GroupsContainer&&) noexcept;
  GroupsContainer(const GroupsContainer&) noexcept;
  GroupsContainer& operator=(GroupsContainer&&) noexcept;
  GroupsContainer& operator=(const GroupsContainer&) noexcept;

  void initialize(pType, VIPRA::size);
  void cleanUsed();

  [[nodiscard]] VIPRA::size size() const;

  [[nodiscard]] const VIPRA::idxVec& at(VIPRA::idx) const;
  [[nodiscard]] VIPRA::idxVec&       operator[](VIPRA::idx);

  [[nodiscard]] const VIPRA::idxVec& getGroup(typeUID) const;

  void addPed(VIPRA::idx, typeUID);
  void movePed(VIPRA::idx, typeUID, typeUID);
  void removePed(VIPRA::idx, typeUID);

  void                                   setUsed(VIPRA::idx, typeUID);
  [[nodiscard]] const std::vector<bool>& getUsed(typeUID) const;
  [[nodiscard]] bool                     isUsed(VIPRA::idx, typeUID) const;

 private:
  std::vector<VIPRA::idxVec>     groups;
  std::vector<std::vector<bool>> used;
};
}  // namespace Behaviors

#endif