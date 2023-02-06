
#include <algorithm>

#include "conditions/condition.hpp"

bool
Condition::evaluate(const ObstacleSet&     obsSet,
                    const PedestrianSet&   pedSet,
                    const Goals&           goals,
                    const BehaviorContext& context,
                    VIPRA::idx             pedIndex) const {
  const VIPRA::size condCnt = conditions.size();
  bool              result = (*conditions[0])(obsSet, pedSet, goals, context, pedIndex);

  if (condCnt == 1) {
    return result;
  }

  for (VIPRA::idx i = 1; i < condCnt; ++i) {
    if (operations[i - 1]) {
      result = result && (*conditions[i])(obsSet, pedSet, goals, context, pedIndex);
    } else {
      result = result || (*conditions[i])(obsSet, pedSet, goals, context, pedIndex);
    }
  }

  return result;
}

void
Condition::addSubCondition(bool operation, std::unique_ptr<SubCondition> cond) {
  operations.emplace_back(operation);
  conditions.emplace_back(std::move(cond));
}