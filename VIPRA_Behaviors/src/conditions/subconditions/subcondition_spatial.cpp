

#include <conditions/subconditions/subcondition_spatial.hpp>
#include <utility>

namespace BHVR {
bool SubConditionSpatial::operator()(Simpack pack, VIPRA::idx pedIdx, Target target) const {
  const auto& coords = pack.pedSet.getCoordinates();

  return coords.at(pedIdx).distanceTo(coords.at(target.targetIdx)) <= within.value(pedIdx);
}

SubConditionSpatial::SubConditionSpatial(NumericValue value) : within(std::move(value)) {}
}  // namespace BHVR