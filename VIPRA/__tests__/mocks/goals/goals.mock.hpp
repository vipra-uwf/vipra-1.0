#ifndef VIPRA_GOALS_MOCK_HPP
#define VIPRA_GOALS_MOCK_HPP

#include <gmock/gmock.h>

#include "definitions/config_map.hpp"
#include "definitions/dimensions.hpp"
#include "goals/goals.hpp"

class GoalsMock : public Goals {
 public:
  MOCK_METHOD(void, configure, (const VIPRA::Config::Map& configMap), (override));
  MOCK_METHOD(void, initialize, (const ObstacleSet&, const PedestrianSet&), (override));
  MOCK_METHOD(void, updatePedestrianGoals, (const ObstacleSet&, const PedestrianSet&, VIPRA::delta_t), (override));
  MOCK_METHOD(bool, isPedestianGoalMet, (VIPRA::idx), (const, override));
  MOCK_METHOD(bool, isSimulationGoalMet, (), (const, override));
  MOCK_METHOD(VIPRA::f3d, getCurrentGoal, (VIPRA::idx), (const, override));
  MOCK_METHOD(VIPRA::f3d, getEndGoal, (VIPRA::idx), (const, override));
  MOCK_METHOD(VIPRA::f3dVec&, getAllCurrentGoals, (), (const, override));
  MOCK_METHOD(VIPRA::f3dVec&, getAllEndGoals, (), (const, override));
  MOCK_METHOD(VIPRA::delta_t, timeSinceLastGoal, (VIPRA::idx), (const, override));
};

#endif