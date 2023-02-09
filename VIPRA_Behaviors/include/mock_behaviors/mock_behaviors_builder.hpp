#ifndef VIPRA_MOCK_BEHAVIORS_HPP
#define VIPRA_MOCK_BEHAVIORS_HPP

#include <behavior/human_behavior.hpp>

class MockBehaviorBuilder {
 public:
  HumanBehavior&& buildMockBehavior(const std::string&);
};

#endif