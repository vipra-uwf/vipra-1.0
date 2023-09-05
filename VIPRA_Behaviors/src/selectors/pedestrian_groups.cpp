
#include <algorithm>
#include <numeric>

#include <selectors/pedestrian_groups.hpp>

namespace {
/**
 * @brief Returns the number of individual types in a Ptype
 * 
 * @param allTypes : Ptype to get count of
 * @return VIPRA::size 
 */
inline VIPRA::size getTypeCount(BHVR::Ptype allTypes) {
  VIPRA::size typeCnt = 1;
  while (allTypes.fullType != 0) {
    BHVR::typeUID currType = allTypes.fullType & (allTypes.fullType - 1);
    allTypes.fullType = currType;
    ++typeCnt;
  }
  return typeCnt;
}
}  // namespace

namespace BHVR {

/**
 * @brief Initializes the groups, starting with all pedestrians in group 0
 * 
 * @param allTypes : Ptype with all possible types
 * @param pedCnt : number of pedestrians
 */
void GroupsContainer::initialize(Ptype allTypes, VIPRA::size pedCnt) {
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
 * @param type : type group to get
 * @return const VIPRA::idxVec& 
 */
const VIPRA::idxVec& GroupsContainer::getGroup(typeUID type) const {
  return groups.at(index(type));
}

/**
 * @brief Adds a pedestrians index to the group with type
 * 
 * @param pedIdx : pedestrian index to add to group
 * @param type : group to add to
 */
void GroupsContainer::addPed(VIPRA::idx pedIdx, typeUID type) {
  const VIPRA::size ndx = index(type);
  groups.at(ndx).push_back(pedIdx);
  used.at(ndx).push_back(false);
}

/**
 * @brief Sets a pedestrian as used in a particular group, this pedestrian can then no longer be selected from this group
 * 
 * @param pedIdx : pedestrian index
 * @param type : group pedestrian has been added to
 * @return true 
 * @return false 
 */
bool GroupsContainer::setUsed(VIPRA::idx pedIdx, typeUID type) {
  const VIPRA::size ndx = index(type);
  auto&             group = groups.at(ndx);
  auto&             usedGroup = used.at(ndx);

  for (VIPRA::idx i = 0; i < group.size(); ++i) {
    if (group[i] == pedIdx) {
      usedGroup[i] = true;
      return true;
    }
  }
  return false;
}

/**
 * @brief Returns vector of used pedestrians from a group
 * 
 * @param type : group to get used pedestrians from
 * @return const std::vector<bool>& 
 */
const std::vector<bool>& GroupsContainer::getUsed(typeUID type) const {
  return used.at(index(type));
}

/**
 * @brief Resets used status of all pedestrians
 * 
 */
void GroupsContainer::cleanUsed() { used.clear(); }

/**
 * @brief Removes the pedestrian from the group with type
 * 
 * @param pedIdx : pedestrian index to remove
 * @param type : group to remove the pedestrian from
 */
bool GroupsContainer::removePed(VIPRA::idx pedIdx, typeUID type) {
  auto& group = groups.at(index(type));
  for (auto iter = group.begin(); iter != group.end(); ++iter) {
    if (*iter == pedIdx) {
      group.erase(iter);
      return true;
    }
  }
  return false;
}

/**
 * @brief Gets the group at index
 * 
 * @param index : group index
 * @return VIPRA::idxVec& 
 */
VIPRA::idxVec& GroupsContainer::operator[](VIPRA::idx index) { return groups[index]; }

/**
 * @brief Gets the group at index
 * 
 * @param index : group index
 * @return VIPRA::idxVec& 
 */
const VIPRA::idxVec& GroupsContainer::at(VIPRA::idx index) const {
  return groups.at(index);
}

/**
 * @brief Returns the number of groups
 * 
 * @return VIPRA::size 
 */
VIPRA::size GroupsContainer::size() const { return groups.size(); }
}  // namespace BHVR
