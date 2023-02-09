
#include <spdlog/spdlog.h>

#include <behavior/human_behavior.hpp>
#include <selectors/selector_everyone.hpp>
#include <selectors/selector_exactly_N.hpp>

#include <mock_behaviors/disembark_atom.mock.hpp>
#include <mock_behaviors/luggage_atom.mock.hpp>

#include <mock_behaviors/mock_behaviors_builder.hpp>

HumanBehavior behavior;

void
LuggageBehavior() {
  Action action;

  action.addAtom("mock_luggage", static_cast<float>(10));
  behavior.addAction(std::move(action));
  behavior.addSelector<Selector_Exactly_N>(50, 1234);
}

void
DisembarkBehavior() {
  Action action;

  action.addAtom("mock_disembark");
  behavior.addAction(std::move(action));
  behavior.addSelector<Selector_Everyone>();
}

HumanBehavior&&
MockBehaviorBuilder::buildMockBehavior(const std::string& behaviorName) {
  behavior = HumanBehavior(behaviorName);

  if (behaviorName == "luggage_mock") {
    LuggageBehavior();
  } else if (behaviorName == "disembark_mock") {
    DisembarkBehavior();
  } else {
    spdlog::error("Invalid Mock Behavior: {}", behaviorName);
    exit(1);
  }

  return std::move(behavior);
}
