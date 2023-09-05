#ifndef VIPRA_GOALS_MOCK_HPP
#define VIPRA_GOALS_MOCK_HPP

#include <gmock/gmock.h>

#include <definitions/dimensions.hpp>
#include <goals/goals.hpp>
#include "configuration/config.hpp"

class GoalsMock : public VIPRA::Goals {
 public:
  MOCK_METHOD(void, configure, (const VIPRA::Config& configMap), (override));
  MOCK_METHOD(void, initialize, (const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&),
              (override));
  MOCK_METHOD(void, updatePedestrianGoals,
              (const VIPRA::ObstacleSet&, const VIPRA::PedestrianSet&, VIPRA::delta_t),
              (override));
  MOCK_METHOD(bool, isPedestianGoalMet, (VIPRA::idx), (const, override));
  MOCK_METHOD(bool, isSimulationGoalMet, (), (const, override));
  MOCK_METHOD(const VIPRA::f3d&, getCurrentGoal, (VIPRA::idx), (const, override));
  MOCK_METHOD(const VIPRA::f3d&, getEndGoal, (VIPRA::idx), (const, override));
  MOCK_METHOD(VIPRA::f3dVec&, getAllCurrentGoals, (), (const, override));
  MOCK_METHOD(VIPRA::f3dVec&, getAllEndGoals, (), (const, override));
  MOCK_METHOD(VIPRA::delta_t, timeSinceLastGoal, (VIPRA::idx), (const, override));
};

#endif