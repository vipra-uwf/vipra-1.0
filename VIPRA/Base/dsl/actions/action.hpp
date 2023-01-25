#ifndef ACTION_HPP
#define ACTION_HPP

#include "../simulation_context.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

/**
 * An action is something the pedestrian does, such as stopping movement.
 */
class Action {
 public:
  Action(SimulationContext* simulationContext, std::string actionName);
  virtual ~Action() = default;

  virtual void performAction(const ObstacleSet&   obstacleSet,
                             const PedestrianSet& pedestrianSet,
                             const Goals&         goals,
                             VIPRA::idx           pedestrianIndex,
                             VIPRA::delta_t,
                             std::shared_ptr<VIPRA::State>) = 0;

  const std::string& getActionName() const;
  virtual void       initialize(const PedestrianSet& pedestrianSet);

 protected:
  virtual bool       actionApplied(VIPRA::idx pedestrianIndex);
  SimulationContext* getSimulationContext();
  std::string        actionName;

 private:
  SimulationContext* simulationContext;
};

#endif