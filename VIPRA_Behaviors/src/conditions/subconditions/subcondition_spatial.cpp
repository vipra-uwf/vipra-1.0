

#include <conditions/subconditions/subcondition_spatial.hpp>
#include <utility>

namespace BHVR {
/**
  * @brief Returns true if the target is within the condition distance
  * 
  * @param pack : simulation pack
  * @param pedIdx : current pedestrians index
  * @param target : condition target
  * @return true 
  * @return false 
  */
auto SubConditionSpatial::operator()(Simpack pack, VIPRA::idx pedIdx, Target target) const -> bool {
  const auto& coords = pack.get_pedset().getCoordinates();

  return coords[pedIdx].distanceTo(coords[target.targetIdx]) <= _within.value(pedIdx);
}

SubConditionSpatial::SubConditionSpatial(NumericValue value) : _within(std::move(value)) {}
}  // namespace BHVR