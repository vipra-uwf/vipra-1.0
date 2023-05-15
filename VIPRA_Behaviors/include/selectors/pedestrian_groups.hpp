#ifndef VIPRA_BHVR_PEDESTRIAN_GROUPS_HPP
#define VIPRA_BHVR_PEDESTRIAN_GROUPS_HPP

#include <vector>

#include <pedestrian_set/pedestrian_set.hpp>

#include <definitions/pedestrian_types.hpp>
#include <definitions/type_definitions.hpp>

namespace BHVR {

/**
 * @brief Holds the indexes for pedestrians in each type group
 * 
 */
class GroupsContainer {
 public:
  /**
  * @brief Gets the index into the container for a given type
  * 
  * @param type : 
  * @return constexpr VIPRA::idx 
  */
  static constexpr VIPRA::idx index(typeUID type) {
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

  GroupsContainer() = default;
  ~GroupsContainer() = default;
  GroupsContainer(const GroupsContainer&) = default;
  GroupsContainer& operator=(const GroupsContainer&) = default;
  GroupsContainer(GroupsContainer&&) noexcept = default;
  GroupsContainer& operator=(GroupsContainer&&) noexcept = default;

  void initialize(Ptype, VIPRA::size);
  void cleanUsed();

  [[nodiscard]] VIPRA::size size() const;

  [[nodiscard]] const VIPRA::idxVec& at(VIPRA::idx) const;
  [[nodiscard]] VIPRA::idxVec&       operator[](VIPRA::idx);

  [[nodiscard]] const VIPRA::idxVec& getGroup(typeUID) const;

  void addPed(VIPRA::idx, typeUID);
  void movePed(VIPRA::idx, typeUID, typeUID);
  bool removePed(VIPRA::idx, typeUID);

  bool                                   setUsed(VIPRA::idx, typeUID);
  [[nodiscard]] const std::vector<bool>& getUsed(typeUID) const;
  [[nodiscard]] bool                     isUsed(VIPRA::idx, typeUID) const;

 private:
  std::vector<VIPRA::idxVec>     groups;
  std::vector<std::vector<bool>> used;
};
}  // namespace BHVR

#endif