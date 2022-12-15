#include "human_behavior.hpp"

// Provide default definitions for methods to make extending much easier

HumanBehavior::HumanBehavior() : initialState(0), initialEnvironmentState(0) {
  this->simulationContext.elapsedSeconds = 0.0f;
}

void
HumanBehavior::initialize(const ObstacleSet&   obstacleSet,
                          const PedestrianSet& pedestrianSet,
                          const Goals&         goals) {
  // At this point the states have been set up in the constructor, so
  // initialize the state actions with null pointers to begin with
  // this->stateActions.resize(this->getStateDefinitions().size(), nullptr);

  int numPedestrians = pedestrianSet.getNumPedestrians();
  this->simulationContext.states.resize(numPedestrians, this->initialState);
  this->simulationContext.transitionPointSeconds.resize(numPedestrians, 0);

  this->simulationContext.environmentState = this->initialEnvironmentState;
  this->simulationContext.environmentTransitionPointSeconds = 0;

  // Initialize the selectors. These get their pedestrian set from the simulation context.
  for (auto selector : this->selectors) {
    selector->initialize(obstacleSet, pedestrianSet, goals);
  }

  for (auto action : this->stateActions) {
    if (action != nullptr) {
      action->initialize(pedestrianSet);
    }
  }
}

void
HumanBehavior::update(const PedestrianSet& pedestrianSet,
                      float                timestep,
                      const ObstacleSet&   obstacleSet,
                      const Goals&         goals) {
  this->simulationContext.elapsedSeconds += timestep;

  for (auto environmentTransition : this->environmentTransitions) {
    int oldState = this->simulationContext.environmentState;
    if (environmentTransition->evaluateTransition(obstacleSet, pedestrianSet, goals, 0)) {
      LJ::Debug(simLogger,
                "Environment has transitioned from {} to {}",
                this->getEnvironmentStateDefinitions().at(oldState),
                this->getEnvironmentStateDefinitions().at(this->simulationContext.environmentState));
    }
  }
}

bool
HumanBehavior::select(const PedestrianSet& pedestrianSet,
                      const ObstacleSet&   obstacleSet,
                      const Goals&         goals,
                      int                  pedestrianIndex) {
  bool selected = false;
  for (auto selector = this->getSelectors().begin(); !selected && selector != this->getSelectors().end();
       selector++) {
    selected = (*selector)->select(pedestrianIndex, obstacleSet, goals, pedestrianSet);
  }

  return selected;
}

bool
HumanBehavior::decide(const PedestrianSet& pedestrianSet,
                      const ObstacleSet&   obstacleSet,
                      const Goals&         goals,
                      int                  pedestrianIndex) {
  bool decided = false;
  for (auto decider = this->getDeciders().begin(); !decided && decider != this->getDeciders().end();
       ++decider) {
    decided = (*decider)->evaluate(obstacleSet, pedestrianSet, goals, pedestrianIndex);
  }

  return decided;
}

void
HumanBehavior::act(const PedestrianSet& pedestrianSet,
                   int                  pedestrianIndex,
                   float                timestep,
                   const ObstacleSet&   obstacleSet,
                   const Goals&         goals) {

  int pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);

  // First phase: set the state transition
  bool transitioned = false;
  for (auto transition = this->getTransitions().begin();
       !transitioned && transition != this->getTransitions().end();
       ++transition) {
    int oldState = this->simulationContext.states.at(pedestrianId);
    if ((*transition)->evaluateTransition(obstacleSet, pedestrianSet, goals, pedestrianIndex)) {
      int newState = this->simulationContext.states.at(pedestrianId);
      LJ::Debug(simLogger,
                "Person with id {} has transitioned from {} to {}",
                pedestrianId,
                this->getStateDefinitions().at(oldState),
                this->getStateDefinitions().at(newState));
      transitioned = true;
    }
  }

  for (size_t state = 0; state < this->getStateActions().size(); ++state) {
    if (this->simulationContext.states.at(pedestrianId) == state &&
        this->getStateActions().at(state) != nullptr) {
      this->getStateActions().at(state)->performAction(pedestrianIndex, pedestrianSet, obstacleSet, goals);
    }
  }
}

void
HumanBehavior::addStateDefinition(std::string const& stateDefinition) {
  this->stateDefinitions.push_back(stateDefinition);
  this->stateActions.push_back(nullptr);
}

void
HumanBehavior::addEnvironmentStateDefinition(const std::string& stateDefinition) {
  this->environmentStateDefinitions.push_back(stateDefinition);
}

std::vector<std::string>
HumanBehavior::getStateDefinitions() {
  return this->stateDefinitions;
}

SimulationContext*
HumanBehavior::getSimulationContext() {
  return &(this->simulationContext);
}

std::vector<Selector*>&
HumanBehavior::getSelectors() {
  return this->selectors;
}

std::vector<PedestrianTransition*>&
HumanBehavior::getTransitions() {
  return this->transitions;
}

std::vector<Action*>&
HumanBehavior::getStateActions() {
  return this->stateActions;
}

std::vector<Condition*>&
HumanBehavior::getDeciders() {
  return this->deciders;
}

void
HumanBehavior::addSelector(Selector* selector) {
  this->selectors.push_back(selector);
}

void
HumanBehavior::addTransition(PedestrianTransition* transition) {
  this->transitions.push_back(transition);
}

void
HumanBehavior::addStateAction(int state, Action* action) {
  this->stateActions.at(state) = action;
}

void
HumanBehavior::addDecider(Condition* decider) {
  this->deciders.push_back(decider);
}

void
HumanBehavior::setInitialState(int state) {
  this->initialState = state;
}

void
HumanBehavior::setInitialEnvironmentState(int state) {
  this->initialEnvironmentState = state;
}

const std::vector<std::string>&
HumanBehavior::getEnvironmentStateDefinitions() const {
  return environmentStateDefinitions;
}

void
HumanBehavior::addEnvironmentTransition(EnvironmentTransition* environmentTransition) {
  this->environmentTransitions.push_back(environmentTransition);
}
