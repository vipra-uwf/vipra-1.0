
#include <algorithm>
#include <numeric>

#include <selectors/pedestrian_groups.hpp>

namespace {
inline VIPRA::size
getTypeCount(Behaviors::pType allTypes) {
  VIPRA::size typeCnt = 1;
  while (allTypes.fullType != 0) {
    allTypes.fullType = allTypes.fullType & (allTypes.fullType - 1);
    ++typeCnt;
  }
  return typeCnt;
}
}  // namespace

namespace Behaviors {

/**
 * @brief Initializes the groups, starting with all pedestrians in group 0
 * 
 * @param allTypes : 
 * @param pedCnt : 
 */
void
GroupsContainer::initialize(pType allTypes, VIPRA::size pedCnt) {
  VIPRA::size typeCnt = getTypeCount(allTypes);
  groups.resize(typeCnt);
  groups[0] = VIPRA::idxVec(pedCnt);
  std::iota(groups[0].begin(), groups[0].end(), 0);

  used.resize(typeCnt);
  used[0] = std::vector<bool>(pedCnt, false);
}

/**
 * @brief Returns the group with a given type
 * 
 * @param type : 
 * @return const VIPRA::idxVec& 
 */
const VIPRA::idxVec&
GroupsContainer::getGroup(typeUID type) const {
  return groups.at(Index(type));
}

/**
 * @brief Adds a pedestrians index to the group with type
 * 
 * @param pedIdx : 
 * @param type : 
 */
void
GroupsContainer::addPed(VIPRA::idx pedIdx, typeUID type) {
  const VIPRA::size index = Index(type);
  groups.at(index).push_back(pedIdx);
  used.at(index).push_back(false);
}

void
GroupsContainer::setUsed(VIPRA::idx pedIdx, typeUID type) {
  const VIPRA::size index = Index(type);
  auto&             group = groups.at(index);
  auto&             used_group = used.at(index);

  for (VIPRA::idx i = 0; i < group.size(); ++i) {
    if (group[i] == pedIdx) {
      used_group[i] = true;
    }
  }
}

const std::vector<bool>&
GroupsContainer::getUsed(typeUID type) const {
  return used.at(Index(type));
}

void
GroupsContainer::cleanUsed() {
  used.clear();
}

/**
 * @brief Removes the pedestrian from the group with type
 * 
 * @param pedIdx : 
 * @param type : 
 */
void
GroupsContainer::removePed(VIPRA::idx pedIdx, typeUID type) {
  auto& group = groups.at(Index(type));
  for (auto iter = group.begin(); iter != group.end(); ++iter) {
    if (*iter == pedIdx) {
      group.erase(iter);
      return;
    }
  }
}

VIPRA::idxVec&
GroupsContainer::operator[](VIPRA::idx index) {
  return groups[index];
}

const VIPRA::idxVec&
GroupsContainer::at(VIPRA::idx index) const {
  return groups.at(index);
}

/**
 * @brief Returns the number of groups
 * 
 * @return VIPRA::size 
 */
VIPRA::size
GroupsContainer::size() const {
  return groups.size();
}

// ---------- CONSTRUCTORS ---------------------------

GroupsContainer::GroupsContainer() : groups(), used() {}

GroupsContainer::GroupsContainer(GroupsContainer&& other) noexcept
  : groups(std::move(other.groups)), used(std::move(other.used)) {}

GroupsContainer::GroupsContainer(const GroupsContainer& other) noexcept : groups(other.groups), used(other.used) {}

GroupsContainer&
GroupsContainer::operator=(GroupsContainer&& other) noexcept {
  groups = std::move(other.groups);
  used = std::move(other.used);
  return *this;
}

GroupsContainer&
GroupsContainer::operator=(const GroupsContainer& other) noexcept {
  groups = other.groups;
  used = other.used;
  return *this;
}

}  // namespace Behaviors
