

#include <selectors/subselector.hpp>

namespace Behaviors {

SelectorResult
SubSelector::selectPeds(seed                 s,
                        const VIPRA::idxVec& totalGroup,
                        const VIPRA::idxVec& usableGroup,
                        const PedestrianSet& pedSet,
                        const ObstacleSet&   obsSet,
                        const Goals&         goals) {
  return select(s, totalGroup, usableGroup, pedSet, obsSet, goals);
}

// ------------------- CONSTRUCTORS --------------------------------------------------------------------------

SubSelector::SubSelector(typeUID g, pType t, bool r, SelectorFunc s) : group(g), type(t), required(r), select(s) {}

SubSelector::SubSelector(SubSelector&& other) noexcept
  : group(other.group), type(std::move(other.type)), required(other.required), select(std::move(other.select)) {}

SubSelector::SubSelector(const SubSelector& other) noexcept
  : group(other.group), type(other.type), required(other.required), select(other.select) {}

SubSelector&
SubSelector::operator=(SubSelector&& other) noexcept {
  group = other.group;
  type = other.type;
  required = other.required;
  select = std::move(other.select);
  return *this;
}

SubSelector&
SubSelector::operator=(const SubSelector& other) noexcept {
  group = other.group;
  type = other.type;
  required = other.required;
  select = other.select;
  return *this;
}

}  // namespace Behaviors