#include <cmath>
#include <iostream>
#include "random_sleep_behavior.hpp"
#include "../definitions/movement_definitions.hpp"
#include "../entity_sets/calm_pedestrian_set.hpp"
#include "../dsl/actions/stop_movement_action.hpp"
#include "../dsl/selectors/id_ratio_selector.hpp"
#include "../dsl/transitions/transition.hpp"
#include "../dsl/conditions/and_condition.hpp"
#include "../dsl/conditions/elapsed_time_condition.hpp"
#include "../dsl/conditions/state_condition.hpp"

static const int AWAKE = 0;
static const int SLEEPING = 1;

RandomSleepBehavior::RandomSleepBehavior()
{
    this->simulationContext.elapsedSeconds = 0.0f;
    this->timeBetweenNapsSeconds = 120;
    this->lengthOfNapSeconds = 120;

    this->simulationContext.states = &(this->states);

    // Simulate states being added programmatically here. These calls will be made as the DSL file is parsed.
    this->addStateDefinition("AWAKE");    // INDEX 0
    this->addStateDefinition("SLEEPING"); // INDEX 1

    // Simulate selector rules being added programmatically here. These will be done by the DSL.
    // e.g., "x% of people are subject to randomly falling asleep"
    // This selector is one of many possibilities that we can add. For example, we can add a 
    // RandomSelector implementation that will select the percentage of the population at random.

    // Initialize the state actions with null pointers to begin with
    this->stateActions.resize(this->getStateDefinitions().size(), nullptr);

    this->addSelector(new IdRatioSelector(&(this->simulationContext), 2.0 / 100.0));

    this->addTransition
    (
        new Transition
        (   
            &(this->simulationContext),
            new AndCondition
            (
                &(this->simulationContext),
                new StateCondition(&(this->simulationContext), AWAKE),
                new ElapsedTimeCondition(&(this->simulationContext), 120.0)
            ),
            SLEEPING
        )
    );

    this->addTransition
    (
        new Transition
        (
            &(this->simulationContext),
            new AndCondition
            (
                &(this->simulationContext),
                new StateCondition(&(this->simulationContext), SLEEPING),
                new ElapsedTimeCondition(&(this->simulationContext), 120.0)
            ),
            AWAKE
        )
    );

    this->addStateAction(1, new StopMovementAction(&(this->simulationContext)));

    // Signify that this HBM should override the fields for a specific pedestrian if they are in a sleeping state.
    this->addDecider(new StateCondition(&(this->simulationContext), SLEEPING));
    
}

void RandomSleepBehavior::initialize(PedestrianSet *pedestrianSet)
{
    int numPedestrians = pedestrianSet->getNumPedestrians();
    this->states.resize(numPedestrians, 0);
    this->simulationContext.transitionPointSeconds.resize(numPedestrians, 0);

    this->simulationContext.pedestrianSet = pedestrianSet;
}

void RandomSleepBehavior::update(FLOATING_NUMBER timestep)
{
    this->simulationContext.elapsedSeconds += timestep;
}

bool RandomSleepBehavior::select(PedestrianSet *pedestrianSet, int pedestrianIndex)
{

    bool selected = false;
    for (auto selector = this->selectors.begin();
         !selected && selector != this->selectors.end();
         selector++)
    {
        selected = (*selector)->select(pedestrianIndex);
    }

    return selected;
}

bool RandomSleepBehavior::decide(PedestrianSet *pedestrianSet, int pedestrianIndex)
{
    bool decided = false;
    for (auto decider = this->deciders.begin();
         !decided && decider != this->deciders.end();
         ++decider)
    {
        decided = (*decider)->evaluate(pedestrianIndex);
    }

    return decided;
}

void RandomSleepBehavior::act(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep)
{
    static const Dimensions STOPPED = Dimensions
    {
        std::vector < FLOATING_NUMBER > {0, 0, 0}
    };

    int pedestrianId = pedestrianSet->getIds()->at(pedestrianIndex);

    // This person is subject to human behaviors for this cycle.
    FLOATING_NUMBER lastTransitionMs = this->simulationContext.elapsedSeconds - this->simulationContext.transitionPointSeconds.at(pedestrianId);

    CalmPedestrianSet *calmPedestrianSet = dynamic_cast<CalmPedestrianSet *>(pedestrianSet);

    // First phase: set the state transition
    bool transitioned = false;
    for (auto transition = this->transitions.begin();
         !transitioned && transition != this->transitions.end();
         ++transition)
    {
        if ((*transition)->evaluateTransition(pedestrianIndex))
        {
            int newState = this->states.at(pedestrianId);
            std::cout 
                << "Person with id " << pedestrianId 
                << " has transitioned to " << this->getStateDefinitions().at(newState)
                << std::endl;
            transitioned = true;
        }
    }

    for (int state = 0; state < stateActions.size(); ++state)
    {
        if (this->states.at(pedestrianId) == state && 
            stateActions.at(state) != nullptr)
        {
            stateActions.at(state)->performAction(pedestrianIndex);
        }
    }
}

void RandomSleepBehavior::addSelector(Selector *selector)
{
    this->selectors.push_back(selector);
}

void RandomSleepBehavior::addTransition(Transition *transition)
{
    this->transitions.push_back(transition);
}

void RandomSleepBehavior::addStateAction(int state, Action *action)
{
    this->stateActions.at(state) = action;
}

void RandomSleepBehavior::addDecider(Condition *decider)
{
    this->deciders.push_back(decider);
}
