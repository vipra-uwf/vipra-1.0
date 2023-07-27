

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
bool SubConditionSpatial::operator()(Simpack pack, VIPRA::idx pedIdx,
                                     Target target) const {
  const auto& coords = pack.pedSet.getCoordinates();

  return coords.at(pedIdx).distanceTo(coords.at(target.targetIdx)) <=
         within.value(pedIdx);
}

SubConditionSpatial::SubConditionSpatial(NumericValue value) : within(std::move(value)) {}
}  // namespace BHVR