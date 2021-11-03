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
    this->timeBetweenNapsSeconds = 120;
    this->lengthOfNapSeconds = 120;

    // Simulate states being added programmatically here. These calls will be made as the DSL file is parsed.
    this->addStateDefinition("AWAKE");    // INDEX 0
    this->addStateDefinition("SLEEPING"); // INDEX 1

    SimulationContext *simulationContext = this->getSimulationContext();

    // Simulate selector rules being added programmatically here. These will be done by the DSL.
    // e.g., "x% of people are subject to randomly falling asleep"
    // This selector is one of many possibilities that we can add. For example, we can add a 
    // RandomSelector implementation that will select the percentage of the population at random.
    this->addSelector(new IdRatioSelector(simulationContext, 2.0 / 100.0));

    this->addTransition
    (
        new Transition
        (   
            simulationContext,
            new AndCondition
            (
                simulationContext,
                new StateCondition(simulationContext, AWAKE),
                new ElapsedTimeCondition(simulationContext, 120.0)
            ),
            SLEEPING
        )
    );

    this->addTransition
    (
        new Transition
        (
            simulationContext,
            new AndCondition
            (
                simulationContext,
                new StateCondition(simulationContext, SLEEPING),
                new ElapsedTimeCondition(simulationContext, 120.0)
            ),
            AWAKE
        )
    );

    // this->addStateAction(AWAKE, nullptr);
    this->addStateAction(SLEEPING, new StopMovementAction(simulationContext));

    // Signify that this HBM should override the fields for a specific pedestrian if they are in a sleeping state.
    this->addDecider(new StateCondition(simulationContext, SLEEPING));

}

