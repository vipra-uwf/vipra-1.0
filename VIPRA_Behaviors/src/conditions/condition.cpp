
#include <algorithm>

#include "conditions/condition.hpp"

namespace BHVR {

/**
 * @brief Tests whether a condition is met, by running through each sub condition sequentially
 * 
 * @param pedSet : pedestrian set object
 * @param obsSet : obstacle set object
 * @param goals : goals object
 * @param context : behavior context
 * @param pedIndex : index of current pedestrian
 * @param dT : simulation timestep size
 * @return true 
 * @return false
 */
auto Condition::evaluate(Simpack pack, VIPRA::idx pedIndex, Target target) const -> bool {
  const VIPRA::size condCnt = _conditions.size();
  if (condCnt == 0) {
    return false;
  }

  bool result = _conditions[0](pack, pedIndex, target);

  if (condCnt == 1) {
    return result;
  }

  for (VIPRA::idx i = 1; i < condCnt; ++i) {
    if (_operations[i - 1]) {
      result = result && _conditions[i](pack, pedIndex, target);
    } else {
      result = result || _conditions[i](pack, pedIndex, target);
    }
  }

  return result;
}

/**
 * @brief Adds a new subcondition to the condition
 * 
 * @param condition : 
 */
void Condition::add_sub_condition(SubCondition&& condition) { _conditions.emplace_back(condition); }

/**
 * @brief Adds a logical and/or operator to the condition
 * 
 * @param andor : 
 */
void Condition::add_and_or(bool andor) { _operations.push_back(andor); }
}  // namespace BHVR