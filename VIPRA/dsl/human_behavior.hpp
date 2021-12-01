#ifndef VIPRA_HUMAN_BEHAVIOR_HPP
#define VIPRA_HUMAN_BEHAVIOR_HPP

#include "actions/action.hpp"
#include "transitions/transition.hpp"
#include "conditions/condition.hpp"
#include "selectors/selector.hpp"
#include "simulation_context.hpp"
#include "../definitions/type_definitions.hpp"
#include "../entity_sets/pedestrian_set.hpp"

/**
 * Describes a specific human behavior. Implementations can either define the behavior directly in C++ or use a DSL.
 */
class HumanBehavior
{
    public:
        HumanBehavior();
        virtual ~HumanBehavior() = default;

        // The pattern across the board is to have actual handles to the data that are provided on object creation.
        // But the data lives on the model itself. Therefore we should have the behavior take in the PedestrianSet as an argument.

        virtual void initialize(PedestrianSet *pedestrianSet);

        // Track any internal state if it exists
        virtual void update(FLOATING_NUMBER timestep);

        // Select a specific pedestrian for this behavior
        virtual bool select(PedestrianSet *pedestrianSet, int pedestrianIndex);

        // Tell the simulation whether or not this behavior will decide their speed (or anything else for that matter).
        virtual bool decide(PedestrianSet *pedestrianSet, int pedestrianIndex);

        // Perform the action associated with this behavior
        virtual void act(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep);

        // Add a state definition
        void addStateDefinition(std::string const &state);

        // Get the state definitions
        std::vector<std::string> getStateDefinitions();
    
    protected:
        void addSelector(Selector *selector);
        void addTransition(Transition *transition);
        void addStateAction(int state, Action *action);
        void addDecider(Condition *decider);

        void setInitialState(int state);

        std::vector<Selector *> &getSelectors();
        std::vector<Transition *> &getTransitions();
        std::vector<Action *> &getStateActions();
        std::vector<Condition *> &getDeciders();
        std::vector<int> &getStates();

        SimulationContext *getSimulationContext();
    
    private:
        // The definitions of the states as read in by the behavior file.
        std::vector<std::string> stateDefinitions;

        // These states are defined by the this behavior. Currently they are a hard-coded enumeration but future 
        // iterations will have these defined directly in the DSL.
        std::vector<int> states;
        int initialState;

        std::vector<Selector *> selectors;
        std::vector<Transition *> transitions;
        std::vector<Action *> stateActions;
        std::vector<Condition *> deciders;

        // Track the simulation context for use with the behavior
        // TODO move this to the HBM?
        SimulationContext simulationContext;
};

#endif
