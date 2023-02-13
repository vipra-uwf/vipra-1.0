
#include <algorithm>

#include "conditions/condition.hpp"

Condition::Condition(Condition&& other) noexcept
  : operations(std::move(other.operations)), conditions(std::move(other.conditions)) {}

Condition&
Condition::operator=(Condition&& other) noexcept {
  operations = std::move(other.operations);
  conditions = std::move(other.conditions);
  return *this;
}

bool
Condition::evaluate(const PedestrianSet&   pedSet,
                    const ObstacleSet&     obsSet,
                    const Goals&           goals,
                    const BehaviorContext& context,
                    VIPRA::idx             pedIndex,
                    VIPRA::delta_t         dT) const {
  const VIPRA::size condCnt = conditions.size();
  bool              result = (*conditions[0])(pedSet, obsSet, goals, context, pedIndex, dT);

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