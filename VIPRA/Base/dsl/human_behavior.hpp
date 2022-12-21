#ifndef VIPRA_HUMAN_BEHAVIOR_HPP
#define VIPRA_HUMAN_BEHAVIOR_HPP

#include "actions/action.hpp"
#include "conditions/condition.hpp"
#include "definitions/type_definitions.hpp"
#include "goals/goals.hpp"
#include "logging/logging.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"
#include "selectors/selector.hpp"
#include "simulation_context.hpp"
#include "transitions/environment_transition.hpp"
#include "transitions/pedestrian_transition.hpp"

#include "dsl/definitions/dsl_types.hpp"

/**
 * Describes a specific human behavior. Implementations can either define the behavior directly in C++ or use a DSL.
 */
class HumanBehavior {
 public:
  HumanBehavior();
  virtual ~HumanBehavior() = default;

  // The pattern across the board is to have actual handles to the data that are provided on object creation.
  // But the data lives on the model itself. Therefore we should have the behavior take in the PedestrianSet as an argument.

  virtual void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&);

  // Track any internal state if it exists
  virtual void update(const PedestrianSet&, const ObstacleSet&, const Goals&, VIPRA::delta_t);

  // Select a specific pedestrian for this behavior
  virtual bool select(const PedestrianSet&, const ObstacleSet&, const Goals&, VIPRA::idx);

  // Tell the simulation whether or not this behavior will decide their speed (or anything else for that matter).
  virtual bool decide(const PedestrianSet&, const ObstacleSet&, const Goals&, VIPRA::idx);

  // Perform the action associated with this behavior
  virtual void act(const PedestrianSet&,
                   const ObstacleSet&,
                   const Goals&,
                   std::shared_ptr<VIPRA::State>,
                   VIPRA::idx,
                   VIPRA::delta_t);

  // Get the state definitions
  std::vector<std::string> getStateDefinitions();

  // Get the environment state definitions
  const std::vector<std::string>& getEnvironmentStateDefinitions() const;

 protected:
  void addSelector(Selector* selector);
  void addTransition(PedestrianTransition* transition);
  void addEnvironmentTransition(EnvironmentTransition* environmentTransition);
  void addStateAction(VIPRA::stateUID state, Action* action);
  void addDecider(Condition* decider);

  void addStateDefinition(std::string const& state);
  void addEnvironmentStateDefinition(std::string const& state);

  void setInitialState(VIPRA::stateUID state);
  void setInitialEnvironmentState(VIPRA::stateUID state);

  std::vector<Selector*>&             getSelectors();
  std::vector<PedestrianTransition*>& getTransitions();
  std::vector<Action*>&               getStateActions();
  std::vector<Condition*>&            getDeciders();

  SimulationContext* getSimulationContext();

 private:
  // The definitions of the states as read in by the behavior file.
  std::vector<std::string> stateDefinitions;
  std::vector<std::string> environmentStateDefinitions;

  VIPRA::stateUID initialState;
  VIPRA::stateUID initialEnvironmentState;

  std::vector<Selector*>              selectors;
  std::vector<PedestrianTransition*>  transitions;
  std::vector<EnvironmentTransition*> environmentTransitions;
  std::vector<Action*>                stateActions;
  std::vector<Condition*>             deciders;

  SimulationContext simulationContext;
};

#endif
