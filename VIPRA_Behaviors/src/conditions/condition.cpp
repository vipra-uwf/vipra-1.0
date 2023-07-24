
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
bool Condition::evaluate(Simpack pack, VIPRA::idx pedIndex, Target target) const {
  const VIPRA::size condCnt = conditions.size();
  if (condCnt == 0) {
    return false;
  }

  bool result = conditions[0](pack, pedIndex, target);

  if (condCnt == 1) {
    return result;
  }

  for (VIPRA::idx i = 1; i < condCnt; ++i) {
    if (operations[i - 1]) {
      result = result && conditions[i](pack, pedIndex, target);
    } else {
      result = result || conditions[i](pack, pedIndex, target);
    }
  }

  return result;
}

/**
 * @brief Adds a new subcondition to the condition
 * 
 * @param condition : 
 */
void Condition::addSubCondition(SubCondition&& condition) {
  conditions.emplace_back(condition);
}

/**
 * @brief Adds a logical and/or operator to the condition
 * 
 * @param andor : 
 */
void Condition::addAndOr(bool andor) { operations.push_back(andor); }
}  // namespace BHVR