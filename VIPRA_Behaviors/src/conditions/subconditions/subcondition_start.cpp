
#include <conditions/subconditions/subcondition_start.hpp>

namespace BHVR {
/**
   * @brief Always returns true
   * 
   * @return true 
   * @return false 
   */
bool SubConditionStart::operator()(Simpack, VIPRA::idx, Target) const { return true; }
}  // namespace BHVR