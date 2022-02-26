# Human Behaviors

Human behaviors are modeled with the Human Behavioral Model. This shares the same lifecycle of the Pedestrian Dynamics 
Model, but intends to alter the velocity of individual pedestrians.

Each iteration of the simulation, the human behavior model is updated. It will modify certain aspects of the pedestrian
set (e.g., velocity, propulsion) before the pedestrian dynamics model is run.

Individual behaviors can have state (such as defining groups of travelers) that exist directly on the HumanBehavior 
class. The human behavior model (HBM) runs a list of these states in the order they were defined in `sim_config.json`.

## Changes to Existing Code

To support the human behaviors, we had to change a bit of how Pedestrian Dynamics Model worked. The original design 
involved (in the update() method) the entirety of the positions, velocities, speeds, and propulsions to be computed,
and subsequently set by value as the new list. In order to have the HBM influence these values, we had to modify their 
values directly. This also had the effect of reducing the amount of data copied from the stack to the heap, which 
theoretically should improve performance.

Essentially, the human behavior makes influencing changes to the pedestrian set's velocities, speeds, and propulsions,
but otherwise lets the pedestrian dynamics model to actually move the pedestrians.

We also set the movement state to HUMAN, which was already there, but not yet used. In the function 
`updateMovementState()` on the Pedestrian Dynamics Model we check for this state to avoid resetting it to STOPPED or 
PED_DYNAM. The goal here was to avoid unnecessary changes to the PDM and keep most of the new logic in the HBM.

## Anatomy of a Human Behavior

This project defines "building blocks" that allow researchers to describe aspects of human behavior. These building 
blocks compose to form many possible complex behaviors with relatively simple code. It also allows researchers who run
the simulation to describe human behaviors in structured English, rather than a programming language.

When researchers encounter a behavior that cannot be described using existing building blocks, the software developers
have the option of enhancing existing blocks or defining new ones. The idea is that over time that the VIPRA human 
behavioral model can be rich enough to meet most of the needs of researchers describing human behavior.

### Consideration

This is a formal declaration of the name of the behavior. It's used for logging output and to help describe the behavior
in a distinctive manner. This can be any word or hyphenated word. 

Example:

```
Consider a sleeper.
```

### Selector

When the simulation starts, the human behavior model (HBM) selects a subset of the pedestrians in the simulation. Those
people are selected just to be tracked by the behavior. The selector doesn't influence exactly what the behavior is,
or what state the person is. It just indicates that this individual was selected for that behavior.

Example:

```
A random 1 out of every 50 pedestrians is a sleeper.
```

### States

Human behaviors can be described using states. For example, a person can be listening to an announcement.

Example:

```
A sleeper can be SLEEPING.
A sleeper can be AWAKE.
```

### Transition

The transition is composed of a before-state, an after-state, and a condition. Several conditions exist as options.
See the "conditions" directory for examples.

Example:

```
A sleeper who is SLEEPING will be AWAKE after 120 seconds.
A sleeper who is AWAKE will be SLEEPING after 300 seconds.
```

### State-Action

Each iteration of the simulation, if the selected person is in the specified state, perform that action (for example,
slow down or speed up). The actions are defined in the "actions" directory.

Example:

```
A sleeper who is SLEEPING is STOPPED.
A sleeper who is AWAKE will behave normally.
```

Note: there is no code defined for the "will behave normally" action. The HBM will effectively ignore behaviors that 
have no visitors defined.

### Decider

This tells the simulation that the movement states are being tracked by the human behavior model, and not the pedestrian 
dynamics model. For example, if a person is stopped because of the human behavior model, we don't want the pedestrian
dynamics model to overwrite its state and have it move again, so its decider will return true. But if a person is slowed
down by the human behavior model, we want the pedestrian dynamics model to continue to guide that person to its goal, so
its decider will return false.

NOTE: This was a part of the original design, but it turned out that deciders were un-necessary. Each action is 
associated with a state, and it turned out that the simplest way to model the behavior was to simply apply the action
on a selected person if they are in the specified state, and ignore the decider.

## The Human Behavior Environment

Some behaviors operate on changes to the environment. These can be described very similarly to pedestrian states, in 
that states are defined and state transitions can be expressed. There are no actions associated with the environment 
state, however. The actions are defined only on the pedestrian, and those actions are tied to the pedestrian states.

### Environment State

The environment can be in a specified state, like "ANNOUNCING." Typically, we recommend these to be in all-caps to 
help improve readability, but it can be lower-case as well.

Example:

```
The environment can be ANNOUNCING.
```

### Environment State Transition

This describes under what scenarios the environment can be transitioned. These can use the same types of conditions 
that we have defined for pedestrian state transitions.

```
The environment that is ANNOUNCING will be POST_ANNOUNCING after 30 seconds.
```

# Domain-Specific Language (DSL)

Each behavior is described in a ".behavior" file in the root of the VIPRA directory. Several examples are provided:

* random_sleep.behavior - describes a random person that will fall asleep and stop movement for a pre-defined amount of time.
* important_announcement.behavior - describes an environmental change when an announcement is happening. Everyone will
  stop in reaction to this announcement.
* injured_person.behavior - describes an individual that is injured and walks slowly.

You can specify these in the `input_data/sim_config.json` file under the "behaviors" section.

The DSL is developed with [ANTLR4](https://www.antlr.org/), so in order to run the application you will need the ANTLR4
runtime. To compile the application, you will also need the ANTLR4 development files provided by your Linux distribution.
If you want to add new capabilities to the DSL, you will also need the ANTLR4 tool installed. See the Makefile for 
instructions for individual distributions.

## New Behaviors

If a new behavior can be described using the same selectors, state transitions, and actions, no new code needs to be
written. You can just write the new ".behavior" file and reference it in `input_data/sim_config.json` and the system
should pick it up.

If you need new selectors, the best approach is to write the ".behavior" file and work your way backwards. These files
support C++-style comments, so you can comment out portions of the file that are not yet implemented. Then modify
the grammar file "Behaviors.g4" to tell ANTLR how to parse the file. See ANTLR documentation for details. 

NOTE: The [official book](https://pragprog.com/titles/tpantlr2/the-definitive-antlr-4-reference/) is a very good 
reference for this. In my opinion it is well worth the cost to avoid the frustration of learning without it.

Once the grammar file has been updated you need to re-generate the DSL code. This command is in the Makefile, so all you
need to do is run `make grammar`. This command assumes you have `antlr4` defined in your shell.

Finally, use the visitor pattern (as described by the ANTLR4 documentation) to override a visitor for the new statement
you defined. You can reference the existing visitors as examples.

When you re-compile the application, you can run it against your new behavior and monitor the result.

### Testing

You can use ANTLR4's "grun" utility to graphically test your grammar and behavior. Unfortunately this only works in 
Java. To test the parsing logic of your grammar:

```shell
antlr4 Behaviors.g4
javac *.java
alias grun='java org.antlr.v4.gui.TestRig'
grun Behaviors program -gui random_sleep.behavior
```

This should print a nice GUI to show how the generated ANTLR4 code would parse your file. When you subsequently run 
`make grammar` it will re-generate these files in C++ and behave identically to its java counterpart.