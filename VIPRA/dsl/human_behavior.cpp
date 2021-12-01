#include "human_behavior.hpp"
#include <iostream>

// Provide default definitions for methods to make extending much easier

HumanBehavior::HumanBehavior()
    : initialState(0)
{
    this->simulationContext.elapsedSeconds = 0.0f;
    this->simulationContext.states = &(this->states);

}

void HumanBehavior::initialize(PedestrianSet *pedestrianSet)
{
    // At this point the states have been set up in the constructor, so 
    // initialize the state actions with null pointers to begin with
    // this->stateActions.resize(this->getStateDefinitions().size(), nullptr);

    int numPedestrians = pedestrianSet->getNumPedestrians();
    this->states.resize(numPedestrians, this->initialState);
    this->simulationContext.transitionPointSeconds.resize(numPedestrians, 0);

    this->simulationContext.pedestrianSet = pedestrianSet;

    // Initialize the selectors. These get their pedestrian set from the simulation context.
    for (auto selector: this->selectors) {
        selector->initialize();
    }
}

void HumanBehavior::update(FLOATING_NUMBER timestep)
{
    this->simulationContext.elapsedSeconds += timestep;
}

bool HumanBehavior::select(PedestrianSet *pedestrianSet, int pedestrianIndex)
{
    bool selected = false;
    for (auto selector = this->getSelectors().begin();
         !selected && selector != this->getSelectors().end();
         selector++)
    {
        selected = (*selector)->select(pedestrianIndex);
    }

    return selected;
}

bool HumanBehavior::decide(PedestrianSet *pedestrianSet, int pedestrianIndex)
{
    bool decided = false;
    for (auto decider = this->getDeciders().begin();
         !decided && decider != this->getDeciders().end();
         ++decider)
    {
        decided = (*decider)->evaluate(pedestrianIndex);
    }

    return decided;
}

void HumanBehavior::act(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep)
{

    int pedestrianId = pedestrianSet->getIds()->at(pedestrianIndex);

    // First phase: set the state transition
    bool transitioned = false;
    for (auto transition = this->getTransitions().begin();
         !transitioned && transition != this->getTransitions().end();
         ++transition)
    {
        int oldState = this->getStates().at(pedestrianId);
        if ((*transition)->evaluateTransition(pedestrianIndex))
        {
            int newState = this->getStates().at(pedestrianId);
            std::cout 
                << "Person with id " << pedestrianId
                << " has transitioned from " << this->getStateDefinitions().at(oldState)
                << " to " << this->getStateDefinitions().at(newState)
                << std::endl;
            transitioned = true;
        }
    }

    for (size_t state = 0; state < this->getStateActions().size(); ++state)
    {
        if (this->getStates().at(pedestrianId) == state && 
            this->getStateActions().at(state) != nullptr)
        {
            this->getStateActions().at(state)->performAction(pedestrianIndex);
        }
    }
}

void HumanBehavior::addStateDefinition(std::string const &stateDefinition)
{
    this->stateDefinitions.push_back(stateDefinition);
    this->stateActions.push_back(nullptr);
}

std::vector<std::string> HumanBehavior::getStateDefinitions() 
{
    return this->stateDefinitions;
}

SimulationContext *HumanBehavior::getSimulationContext()
{
    return &(this->simulationContext);
}

std::vector<Selector *> &HumanBehavior::getSelectors()
{
    return this->selectors;
}

std::vector<Transition *> &HumanBehavior::getTransitions()
{
    return this->transitions;
}

std::vector<Action *> &HumanBehavior::getStateActions()
{
    return this->stateActions;
}

std::vector<Condition *> &HumanBehavior::getDeciders()
{
    return this->deciders;
}

std::vector<int> &HumanBehavior::getStates()
{
    return this->states;
}

void HumanBehavior::addSelector(Selector *selector)
{
    this->selectors.push_back(selector);
}

void HumanBehavior::addTransition(Transition *transition)
{
    this->transitions.push_back(transition);
}

void HumanBehavior::addStateAction(int state, Action *action)
{
    this->stateActions.at(state) = action;
}

void HumanBehavior::addDecider(Condition *decider)
{
    this->deciders.push_back(decider);
}

void HumanBehavior::setInitialState(int state)
{
    this->initialState = state;
}
