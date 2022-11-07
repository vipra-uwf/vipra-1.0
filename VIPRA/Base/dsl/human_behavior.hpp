#ifndef VIPRA_HUMAN_BEHAVIOR_HPP
#define VIPRA_HUMAN_BEHAVIOR_HPP

#include "../../Extendable/goals/goals.hpp"
#include "../../Extendable/obstacleset/obstacle_set.hpp"
#include "../../Extendable/pedestrianset/pedestrian_set.hpp"
#include "../_pch/pch.hpp"
#include "../definitions/type_definitions.hpp"
#include "actions/action.hpp"
#include "conditions/condition.hpp"
#include "selectors/selector.hpp"
#include "simulation_context.hpp"
#include "transitions/environment_transition.hpp"
#include "transitions/pedestrian_transition.hpp"

/**
 * Describes a specific human behavior. Implementations can either define the behavior directly in C++ or use a DSL.
 */
class HumanBehavior {
 public:
  HumanBehavior();
  virtual ~HumanBehavior() = default;

  // The pattern across the board is to have actual handles to the data that are provided on object creation.
  // But the data lives on the model itself. Therefore we should have the behavior take in the PedestrianSet as an argument.

  virtual void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&);

  // Track any internal state if it exists
  virtual void update(FLOATING_NUMBER timestep);

  // Select a specific pedestrian for this behavior
  virtual bool select(const PedestrianSet& pedestrianSet, int pedestrianIndex);

  // Tell the simulation whether or not this behavior will decide their speed (or anything else for that matter).
  virtual bool decide(const PedestrianSet& pedestrianSet, int pedestrianIndex);

  // Perform the action associated with this behavior
  virtual void act(const PedestrianSet& pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep);

  // Get the state definitions
  std::vector<std::string> getStateDefinitions();

  // Get the environment state definitions
  const std::vector<std::string>& getEnvironmentStateDefinitions() const;

 protected:
  void addSelector(Selector* selector);
  void addTransition(PedestrianTransition* transition);
  void addEnvironmentTransition(EnvironmentTransition* environmentTransition);
  void addStateAction(int state, Action* action);
  void addDecider(Condition* decider);

  void addStateDefinition(std::string const& state);
  void addEnvironmentStateDefinition(std::string const& state);

  void setInitialState(int state);
  void setInitialEnvironmentState(int state);

  std::vector<Selector*>&             getSelectors();
  std::vector<PedestrianTransition*>& getTransitions();
  std::vector<Action*>&               getStateActions();
  std::vector<Condition*>&            getDeciders();

  SimulationContext* getSimulationContext();

 private:
  // The definitions of the states as read in by the behavior file.
  std::vector<std::string> stateDefinitions;
  std::vector<std::string> environmentStateDefinitions;

  int initialState;
  int initialEnvironmentState;

  std::vector<Selector*>              selectors;
  std::vector<PedestrianTransition*>  transitions;
  std::vector<EnvironmentTransition*> environmentTransitions;
  std::vector<Action*>                stateActions;
  std::vector<Condition*>             deciders;

  SimulationContext simulationContext;
};

#endif
