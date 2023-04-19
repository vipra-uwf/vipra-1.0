#ifndef VIPRA_BEHAVIORS_PEDESTRIAN_GROUPS_HPP
#define VIPRA_BEHAVIORS_PEDESTRIAN_GROUPS_HPP

#include <vector>

#include <pedestrian_set/pedestrian_set.hpp>

#include <definitions/pedestrian_types.hpp>
#include <definitions/type_definitions.hpp>

namespace Behaviors {
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

  void initialize(pType, VIPRA::size);

  void removePed(VIPRA::idx, typeUID);
  void movePed(VIPRA::idx, typeUID, typeUID);
  void addPed(VIPRA::idx, typeUID);

  [[nodiscard]] VIPRA::size                    size() const;
  [[nodiscard]] const std::vector<VIPRA::idx>& at(VIPRA::idx) const;
  [[nodiscard]] const std::vector<VIPRA::idx>& getGroup(typeUID) const;
  [[nodiscard]] std::vector<VIPRA::idx>&       operator[](VIPRA::idx);

 private:
  std::vector<std::vector<VIPRA::idx>> groups;
};
}  // namespace Behaviors

#endif