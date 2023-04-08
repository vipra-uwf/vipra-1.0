

# VIPRA Behaviors

# Sections

### B. Behaviors
### S. Selectors
### A. Actions
### C. Conditions
### E. Events
### BB. Behavior Builder
### N. Needs

---

# B. Behaviors

A `Behavior` describes `Actions` that pedestrians take given certain `Conditions`

A `Behavior` is comprised of:
- a `Selector`
- `Events`
- `Actions`
- `Behavior Context`

### Example Behavior:
This behavior describes an important announcement, while the announcement is occurring all pedestrians will walk at 50% speed.
```
Consider an announcement_listener.

// Selector Statement
Everyone is an announcement_listener.

// Event Definition
An !announcement event will occur after 5 seconds from !start and end after 10 seconds from !announcement.

// Action Statement
An announcement_listener will @walk 50% slower while an !announcement event is occurring.
```

### Important Notes on Behaviors

1. Each Behavior is self-contained, Behaviors know nothing of and can not interact with each other.

---


# S. Selectors

`Selectors` Decide which pedestrians "possess" a `Behavior`.

`Behaviors` can have multiple selectors.

---
## S.1. Creating A Selector

1. Add To Grammar
2. Create Selector Definition
3. Add To BehaviorBuilder
4. Add Source To CMakeLists.txt
5. Add Tests
6. Add To Documentation

### S.1.1. Add To Grammar

`Selectors` are added to the grammar in `/VIPRA_Behaviors/grammar/selector.g4`

After defining a new `Selector` grammar rule run `make` in `/VIPRA_Behaviors/grammar/` to update the generated files.

example:
```
selector_Example:
	'An example Selector with a ' NUMBER '.'
	;
```

### S.1.2. Create Selector Function Definition

Add a header file in `/VIPRA_Behaviors/include/selectors/` and a matching source file in `/VIPRA_Behaviors/src/selectors/`


The only rule that `Selector Functions` need to conform to is that they implement
```C++
std::vector<VIPRA::idx> selector_percent::operator()(Behaviors::seed, const PedestrianSet& pedSet, const ObstacleSet&, const Goals&)
```
example:
```C++
// selector_example.hpp
struct Selector_Example {
  float _f;
  std::vector<VIPRA::idx> operator()(Behaviors::seed, const PedestrianSet&, const ObstacleSet&, const Goals&);
};

// selector_example.cpp
std::vector<VIPRA::idx> operator()(Behaviors::seed, const PedestrianSet&, const ObstacleSet&, const Goals&) {
	// ... return the selected pedestrians
}

```

### S.1.3. Add To BehaviorBuilder

```C++
Selector
BehaviorBuilder::buildSelector(BehaviorParser::Ped_SelectorContext* ctx) {
  std::string typeStr = ctx->ID()->toString();
  typeUID     type = getType(typeStr);

  // ... other selectors ...  

  // Check if the current rule context matches our example selector
  if (ctx->selector_Example()) {
    float floatParam = std::stof(ctx->selector_Percent()->NUMBER()->toString());
    spdlog::debug("Behavior \"{}\": Adding Selector: \"Percent\" For Ped Type: {}", currentBehavior.getName(), typeStr);
    return Selector(type, selector_percent{floatParam});
  }
  
  // ... other selectors ...
}
```



### S.1.4. Add Source To CMakeLists.txt

Add the `Selector` source file to `/VIPRA_Behaviors/src/CMakeLists.txt`

example:
- for our Example `Selector`:
`${SRC_DIR}/selectors/selector_example.cpp`

### S.1.5. Add Tests

Add any tests in `/VIPRA_Behaviors/__tests__/selector_tests/`

### S.1.6. Add To Documentation

Add any documentation

---


# A. Actions

`Actions` are what affect a Pedestrian's position, velocity, state, etc.
`Actions` are comprised of `Atoms` and, optionally, a `Condition`.

# A.1. Unconditional Actions

An `Unconditional Action` will ALWAYS take effect.

`Unconditional Actions` are described with the following rule:
`A(n) {TYPE} will always {ATOM_LIST}.`
- Type being the name given to pedestrians with the behavior
- see **§A.3.1** for an explanation of Atom Lists

---
# A.2. Conditional Actions

A `Conditional Action` will only take effect if its `Condition` is satisfied.

`Conditional Actions` are described with the following rule:
`A(n) {TYPE} will {ATOM_LIST} {CONDITION}.`
- Type being the name given to pedestrians with the behavior
- see **§A.3.1** for an explanation of Atom Lists
- see **§C.** for an explanation of Conditions

---
# A.3 Atoms

`Atoms` are the part of an `Action` that actually affects a pedestrian. A group of `Atoms` (`Atom List`) comprise an `Action`.

`Atoms` can be one or multiple words long and are always preceded by an `@`

Examples:
- `@stop`
- `@walk 10% slower`
- `@run in circles`

`Atoms` derive from `/VIPRA_Behaviors/include/actions/action_atom.hpp :: Atom`
- `Atoms` can have one constructor, that may take any number of parameters
- `Atoms` must override `performAction`

---
## A.3.1 Atom List
An `Atom List` is the collection of `Atoms` that make up an `Action`.
`Atom Lists` are comprised of one or more `Atoms`.

`Atom Lists` are described with the following rule:
`{ATOM} (then {ATOM_LIST})`

Examples:
- `@stop`
- `@stop then @listen`
- `@stop then @listen then @run in circles`

**Important Note:** `Atom` effects are applied in the order they are listed
- e.g The `Atom List` `@run in circles then @stop` might result in the pedestrian simply stopping *(dependent on the definition of @run in circles and @stop)*

---
## A.3.2. Making An Atom
1. Add To Grammar
2. Create Atom Definition
3. Add To BehaviorBuilder
4. Add Source To CMakeLists.txt
5. Add Tests
6. Add Documentation

### A.3.2.1. Add To Grammar

`Atoms` are added to the grammar in `/VIPRA_Behaviors/grammar/action.g4`

After creating the `Atom` grammar rule run `make` in `/VIPRA_Behaviors/grammar/` to update the generated files.

example:
```
// Don't forget to add the new rule to the action_atom rule
action_atom:
	ACTION |
	action_Example
	;

// Defining the example atom rule
action_Example:
	'@example do something with ' ID AND NUMBER;
```

### A.3.2.2. Create Atom Definition

Create a header file in `/VIPRA_Behaviors/include/actions/atoms/` and a matching source file in `/VIPRA_Behaviors/src/actions/atoms/`

The only rule that `Atoms` need to conform to is that they implement
```c++
void operator()(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx, VIPRA::delta_t, std::shared_ptr<VIPRA::State>);
```
example:
```C++
// atom_example.hpp
struct Atom_Example {
  float _x;
  std::string _str;
  
  void operator()(PedestrianSet&,
                     ObstacleSet&,
                     Goals&,
                     BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>);

};

//atom_example.cpp
  Atom_Example::Atom_Example(float x, std::string str) : _x(x), _str(str) {}
  void Atom_Example::operator()(PedestrianSet&,
                     ObstacleSet&,
                     Goals&,
                     BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>) {
  // ... code that writes changes to state
}

```

### A.3.2.3. Add To BehaviorBuilder

Add the `Atom` to the `addAtomToAction` method in `/VIPRA_Behaviors/src/behavior/behavior_builder.cpp`

example:
- for our Example `Atom`:
```C++
void BehaviorBuilder::addAtomToAction(Action&  action, BehaviorParser::Action_atomContext*  atom) {
	// ... other atoms ...

	// Check if the current rule context matches our example atom
	if (atom->action_Example()) {
		spdlog::debug("Behavior \"{}\": Adding Action Atom: \"Example\"", currentBehavior.getName());
		// getting parameters from grammar rule
		float x = std::stof(atom->action_Example()->NUMBER()->toString());
		std::string str = atom->action_Example()->ID()->toString();
		
		// add a newly constructed atom with the provided parameters
		action.addAtom(Atom_Example{x, str});
		return;
	}

	// ... other atoms ...
}
```
- The function `ctx->action_Example()` comes from the name we gave the rule in the grammar

### A.3.2.4. Add Source To CMakeLists.txt

Add the `Atom` source file to `/VIPRA_Behaviors/src/CMakeLists.txt`

example:
- for our Example `Atom`:
`${SRC_DIR}/actions/atoms/atom_example.cpp`

### A.3.2.5. Add Tests

Add any tests in `/VIPRA_Behaviors/__tests__/atom_tests/`

### A.3.2.6. Add To Documentation

Add any documentation

---


# Conditions

A `Condition` is what decides if a `Conditional Action` or `Event` occurs. 
`Conditions` are comprised of one or more `Sub Conditions` and the boolean operations between them (and/or).

Conditions are described by the rule:
`{Sub Condition} (and|or {Sub Condition})*`

---
# C.1. Sub Conditions

A `Sub Condition` defines a single condition of the state of the simulation in which it returns true.

Each `Sub Condition` is described with its own grammar rule, check `/VIPRA_Behaviors/grammar/condition.g4` for them

---
## C.1.1. Combining Sub Conditions

! currently boolean logic is only applied in the order the sub conditions are added !
! there is no grouping subconditions  e.g. (A & !B & C) vs (A & !(B & C)) !

When building `Conditions`, `Sub Conditions` are combined with either `and` or `or`

---
## C.1.2. Making A Sub Condition

1. Add To Grammar
2. Create Sub Condition Definition
3. Add To BehaviorBuilder
4. Add Source To CMakeLists.txt
5. Add Tests
6. Add Documentation

### C.1.2.1 Add To Grammar

`Sub Conditions` are added to the grammar in `/VIPRA_Behaviors/grammar/condition.g4`

After creating the `SubCondition` grammar rule run `make` in `/VIPRA_Behaviors/grammar/` to update the generated files.

example:
```
// don't forget to add to the sub condition rule
sub_condition:
	condition_Example |
	*other conditions*
	;

// create new rule for the condition
condition_Example:
	'this is and example condition'
	;
```

### C.1.2.2. Create Sub Condition Definition

Create a header file in `/VIPRA_Behaviors/include/conditions/subconditions/` and a matching source file in `/VIPRA_Behaviors/src/conditions/`

The only rule that `SubConditions` need to conform to is that they implement
```C++
bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx, VIPRA::delta_t);
```


```C++
// subcondition_example.hpp
struct SubCondition_Example {
  Behaviors::stateUID _s;
  bool _b;
  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx, VIPRA::delta_t);
};

// subcondtion_example.cpp
bool
SubCondition_Example::operator()(const PedestrianSet&,
                               const ObstacleSet&,
                               const Goals&,
                               const BehaviorContext&,
                               VIPRA::idx,
                               VIPRA::delta_t) {
	// ... code to check if condition is met
}
```

### C.1.2.3. Add To BehaviorBuilder

Add the `SubCondition` to the `addSubCondToCondtion` method in `/VIPRA_Behaviors/src/behavior/behavior_builder.cpp`

example:
- for our Example `SubCondition`:

```C++
void
BehaviorBuilder::addSubCondToCondtion(Condition& condition, BehaviorParser::Sub_conditionContext* subcond) {
	// ... other subconditions ...

	// Check if the current rule context matches our example subcondition
  if (subcond->condition_Example()) {
    spdlog::debug("Behavior \"{}\": Adding SubCondition: Example", currentBehavior.getName());
	// ... get parameters
    condition.addSubCondition(SubCondition{stateParam, boolParam});
    return;
  }
  
	// ... other subconditions ...
}


```

### C.1.2.4. Add Source To CMakeLists.txt

Add the `SubCondition` source file to `/VIPRA_Behaviors/src/CMakeLists.txt`

example:
- for our Example `SubCondition`:
`${SRC_DIR}/conditions/subconditions/subcondition_example.cpp`

### C.1.2.5. Add Tests

Add any tests in `/VIPRA_Behaviors/__tests__/subcondition_tests/`

### C.1.2.6. Add To Documentation

Add any documentation

---
## C.1.3 Current Sub Conditions

### C.1.3.1 Elapsed Time:

**Parameters:**
- VIPRA::delta_t : the desired elapsed time
- Event* : pointer to event to listen to

**Evaluates to True, Given:** An `Event` has started and The elapsed time between the start and the current time step is greater or equal to the desired elapsed time

### C.1.3.2 Event Occurring:

**Parameters:**
- Event* : pointer to event to listen to

**Evaluates to True, Given:** The event has started and The event has not ended


### C.1.3.3. Event One Time:

**Parameters:**
- bool : true if fire on event start, false if fire on event end
- Event* : pointer to event to listen to

**Evaluates to True, Given:** The event has triggered the listener and the current simulation time is the same as when the listener was triggered

### C.1.3.4. Event:

**Parameters:**
- Event* : pointer to the event to listen to

**Evaluates to True, Given:** The event has started

### C.1.3.5. Start:

**Parameters:** none

**Evaluates to True, Given:** Always


### C.1.3.6 State:

**Parameters:**
- Behaviors::stateUID : the state to wait for
- bool : true if the condition relies on a pedestrian's state, false if the condition relies on a the environment state

**Evaluates to True, Given:** The pedestrian or environments state is the same as the conditions required state

---


# E. Events

An `Event` is something that occurs during a simulation, for example an announcement or fire.

There are two kinds of events: `Single Fire` and `Lasting`

`Events` have a start `Condition` and, optional, end `Condition`
When either the start `Condition` or end `Condition` its respective `Event Handlers` are called.

An `Event` can only be described once, if a `Behavior` file tries to redefine an `Event` of the same name a `Behavior Error` is thrown.

Events are always preceded by a `!` in the grammar
ex. `!announcement`

---
# E.1 Single Fire Events

`Single Fire Events` only have a start `Condition`

When a `Single Fire Event` occurs, it calls its start `Event Handlers` and end `Event Handlers` in the same time step.

Single Fire `Events` are described by the rule:
`A(n) !{NAME} 'event will occur' {CONDITION}  '.';`
- Name being the name of the `Event` and can be anything

---
# E.2 Lasting Events

`Lasting Events` have a start `Condition` and end `Condition`

When a `Lasting Event` occurs, it calls its start `Event Handlers`.
A `Lasting Event` only calls its end `Event Handlers` when its end `Condition` returns true.

`Lasting Events` are described by the rule:
`A(n) !{NAME} 'event will occur' {CONDITION} 'and end' {CONDITION} '.';`
- Name being the name of the `Event` and can be anything

---
# E.3 Event Handlers

`Event Handlers` are the methods called when an `Event` either starts or ends.

Currently `Event Handlers` are simply typedef'd 
```c++
typedef  std::function<void(float)>  EventHandler;
```

## E.3.1 Subscribing Handlers

To subscribe an `Event Handler` to an `Event` use:
```C++
Event event("example");

// for an event start handler
event.onStart(startHandler);

// for an event end handler
event.onEnd(endHandler);
```

---
# E.4 Special Events

Currently there is only one special event: the `!start` event

The `!start` event is in every `Behavior` and fires at the start of a simulation.

---

# BB. Behavior Builder

The `Behavior Builder` is what constructs `Behavior` objects from .behavior files.

---



# N. Needs/Wants/Issues

## N.1. Needs


### N.1.1. Add Checks
We may need to add checks that the what behaviors do is reasonable.

For example: Collisions detection, currently the change speed atom can cause pedestrians to fly through walls / go past their goals (only really an issue if they set the speed up to an unreasonable value)

### N.1.2. Pedestrian Attributes
We need a way to access pedestrian attributes, such as: state, speed, goal, etc.

example
```
// conditional action based on the pedestrians state
a pedestrian will @stop given their *state is #waiting.
```

### N.1.3. Run Time Parameters
We need a way to provide behaviors parameters at run time (taken from module params).

This is needed to allow for parameter sweeps

example
```
// Parameter declaration
PARAMETERS: $event_start, $event_length

// Parameter use
The !announcement event will
	start after $event_start seconds from !start
	and end after $event_length seconds from !announcement.
```

### N.1.4 Allow Behaviors To Change Goals
We need a way for behaviors to change pedestrian goals.

This would require updating the Goals module to add a update pathfinding method

example
```
a !fire will occur after 5 seconds from !start.

// the @head atom would change their goal and require a re-calc of pathfinding
a pedestrian will @head towards the +exit nearest to them.
```

### N.1.5 Personal Events
We need a way for events to happen to individuals, as opposed to the overall environment.

for example: a pedestrian hurts themselves and now walks slower

### N.1.6 Exclusive Selectors

Currently there is no way to make selectors exclusive.

example
```
exactly one pedestrian is an example.
exactly one pedestrian is another_example.

// It is possible these choose the same pedestrian
// There needs to be a way to choose if a selector is exclusive
```


### N.1.7. Behavior Priorities
We need a way to say which behaviors take precedence over others.

todo

### N.1.8 Conditional Selectors
We need a way to select pedestrians based on conditions.

For example: choosing a pedestrians type based on their end goal

## N.2. Wants

### N.2.1. Sub Condition grouping / Operation Order
We may need a way to group sub conditions with the equivalent of parenthesis, to provide more expressive conditions. Currently sub conditions are evaluated in the order they were added

example: 
`A && (B || C)`
vs
`(A && B) || C`

### N.2.2. Custom Action/Condition Definitions
We may need a way for end users to specify `Atoms` and `Sub Conditions` in the `Behavior`

example:
```
// Action definition
The @wait action means:
	@be #waiting

// Atom in use
A pedestrian will always @wait.
```

### N.2.3. Behaviors Affect The Environment Physically
We may need to add the ability for behaviors to add to the environment.

For example: a fire even can "place" fires around the map, then pedestrians can avoid these

Currently behaviors can only change the state of the environment

### N.2.4. Make Everything Case Insensitive
We may want to make the grammar completely case insensitive

At the least we should make it consistent.

Currently parts are sensitive and others aren't

## N.3 Issues

---