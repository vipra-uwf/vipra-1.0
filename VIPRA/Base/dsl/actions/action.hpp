#ifndef ACTION_HPP
#define ACTION_HPP

#include "../simulation_context.hpp"
#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"

/**
 * An action is something the pedestrian does, such as stopping movement.
 */
class Action {
 public:
  Action(SimulationContext* simulationContext, std::string actionName);
  virtual ~Action() = default;

  virtual void       performAction(int                  pedestrianIndex,
                                   const PedestrianSet& pedestrianSet,
                                   const ObstacleSet&   obstacleSet,
                                   const Goals&         goals) = 0;
  const std::string& getActionName() const;
  virtual void       initialize(const PedestrianSet& pedestrianSet);

 protected:
  virtual bool       actionApplied(int pedestrianIndex);
  SimulationContext* getSimulationContext();
  std::string        actionName;

 private:
  SimulationContext* simulationContext;
};

#endif