
#include <algorithm>

#include "conditions/condition.hpp"

namespace Behaviors {
Condition::Condition(Condition&& other) noexcept
  : operations(std::move(other.operations)), conditions(std::move(other.conditions)) {}

Condition&
Condition::operator=(Condition&& other) noexcept {
  operations = std::move(other.operations);
  conditions = std::move(other.conditions);
  return *this;
}

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
bool
Condition::evaluate(const PedestrianSet&   pedSet,
                    const ObstacleSet&     obsSet,
                    const Goals&           goals,
                    const BehaviorContext& context,
                    VIPRA::idx             pedIndex,
                    VIPRA::delta_t         dT) const {
  const VIPRA::size condCnt = conditions.size();
  if (condCnt == 0) {
    return false;
  }

  bool result = (*conditions[0])(pedSet, obsSet, goals, context, pedIndex, dT);

  if (condCnt == 1) {
    return result;
  }

  for (VIPRA::idx i = 1; i < condCnt; ++i) {
    if (operations[i - 1]) {
      result = result && (*conditions[i])(pedSet, obsSet, goals, context, pedIndex, dT);
    } else {
      result = result || (*conditions[i])(pedSet, obsSet, goals, context, pedIndex, dT);
    }
  }

  return result;
}

void
Condition::addAndOr(bool andor) {
  operations.push_back(andor);
}
}  // namespace Behaviors