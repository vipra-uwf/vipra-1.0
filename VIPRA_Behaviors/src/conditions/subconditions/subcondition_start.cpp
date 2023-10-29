
#include <conditions/subconditions/subcondition_start.hpp>

namespace BHVR {
/**
   * @brief Always returns true
   * 
   * @return true 
   * @return false 
   */
auto SubConditionStart::operator()(Simpack /*unused*/, VIPRA::idx /*unused*/, Target /*unused*/) const
    -> bool {
  return true;
}
}  // namespace BHVR