
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
  groups[0] = std::vector<VIPRA::idx>(pedCnt);
  std::iota(groups[0].begin(), groups[0].end(), 0);
}

/**
 * @brief Returns the group with a given type
 * 
 * @param type : 
 * @return const std::vector<VIPRA::idx>& 
 */
const std::vector<VIPRA::idx>&
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
  groups.at(Index(type)).push_back(pedIdx);
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

std::vector<VIPRA::idx>&
GroupsContainer::operator[](VIPRA::idx index) {
  return groups[index];
}

const std::vector<VIPRA::idx>&
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

GroupsContainer::GroupsContainer() : groups() {}

}  // namespace Behaviors
