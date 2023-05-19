
#include <algorithm>
#include <numeric>

#include <selectors/pedestrian_groups.hpp>

namespace {
inline VIPRA::size getTypeCount(BHVR::Ptype allTypes) {
  VIPRA::size typeCnt = 1;
  while (allTypes.fullType != 0) {
    allTypes.fullType = allTypes.fullType & (allTypes.fullType - 1);
    ++typeCnt;
  }
  return typeCnt;
}
}  // namespace

namespace BHVR {

/**
 * @brief Initializes the groups, starting with all pedestrians in group 0
 * 
 * @param allTypes : 
 * @param pedCnt : 
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
 * @param type : 
 * @return const VIPRA::idxVec& 
 */
const VIPRA::idxVec& GroupsContainer::getGroup(typeUID type) const {
  return groups.at(index(type));
}

/**
 * @brief Adds a pedestrians index to the group with type
 * 
 * @param pedIdx : 
 * @param type : 
 */
void GroupsContainer::addPed(VIPRA::idx pedIdx, typeUID type) {
  const VIPRA::size ndx = index(type);
  groups.at(ndx).push_back(pedIdx);
  used.at(ndx).push_back(false);
}

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

const std::vector<bool>& GroupsContainer::getUsed(typeUID type) const {
  return used.at(index(type));
}

void GroupsContainer::cleanUsed() {
  used.clear();
}

/**
 * @brief Removes the pedestrian from the group with type
 * 
 * @param pedIdx : 
 * @param type : 
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

VIPRA::idxVec& GroupsContainer::operator[](VIPRA::idx index) {
  return groups[index];
}

const VIPRA::idxVec& GroupsContainer::at(VIPRA::idx index) const {
  return groups.at(index);
}

/**
 * @brief Returns the number of groups
 * 
 * @return VIPRA::size 
 */
VIPRA::size GroupsContainer::size() const {
  return groups.size();
}
}  // namespace BHVR
