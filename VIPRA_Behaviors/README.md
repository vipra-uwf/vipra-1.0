# VIPRA Behaviors

# Sections

## B. Behaviors
## S. Selectors
## A. Actions
## C. Conditions
## E. Events


---
# B. Behaviors

A `Behavior` describes `Actions` (§A.) that pedestrian takes given certain `Conditions` (§C.)

A `Behavior` is comprised of:
- a `Selector` (§S.)
- `Events` (§E.)
- `Actions` (§A.)

### Example Behavior:
This behavior describes an important announcement, while the announcement is occurring all pedestrian will walk at 50% speed
```
Consider an announcement_listener.

// Selector Statement
Everyone is an announcement_listener.

// Event Definition
An !announcement event will occur after 5 seconds from !start and end after 10 seconds.

// Action Statement
An announcement_listener will @walk 50% slower while an !announcement event is occurring.
```


---


# Selectors

Selectors Decide which pedestrians "possess" a Behavior.
- Behaviors are only allowed 1 selector.

## Creating A Selector

### Add To Grammar
### Create Selector Definition
### Add To BehaviorBuilder
### Add Source To CMakeLists.txt
### Add Tests
### Add To Documentation

---




# A. Actions

`Actions` are what affect a Pedestrian's position, velocity, state, etc.
`Actions` are comprised of `Atoms` (§A.3) and, optionally, a `Condition` (§C.).

# A.1. Unconditional Actions

An `Unconditional Action` will ALWAYS take effect.

`Unconditional Actions` are described with the following grammar:
`A(n) {TYPE} will always {ATOM_LIST}.`
- Type being the name given to pedestrians with the behavior
- see **§A.3.1** for an explanation of Atom Lists


# A.2. Conditional Actions

A `Conditional Action` will only take effect if its `Condition` is satisfied.

`Conditional Actions` are described with the following grammar:
`A(n) {TYPE} will {ATOM_LIST} {CONDITION}.`
- Type being the name given to pedestrians with the behavior
- see **§A.3.1** for an explanation of Atom Lists
- see **§C.** for an explanation of Conditions


# A.3 Atoms

`Atoms` are the part of an `Action` that actually affects a pedestrian. A group of `Atoms` (`Atom List` (§A.3.1)) comprise an `Action`.

`Atoms` can be one or multiple words long and are always preceded by an `@`

Examples:
- `@stop`
- `@walk 10% slower`
- `@run in circles`

`Atoms` derive from `/VIPRA_Behaviors/include/actions/action_atom.hpp :: Atom`
- `Atoms` can have one constructor, that may take any number of parameters
- `Atoms` must override `performAction`


## A.3.1 Atom List
An `Atom List` is the collection of `Atoms` that make up an `Action`.
`Atom Lists` are comprised of one or more `Atoms`.

`Atom Lists` are described with the following grammar:
`{ATOM} (then {ATOM_LIST})`

Examples:
- `@stop`
- `@stop then @listen`
- `@stop then @listen then @run in circles`

**Important Note:** `Atom` effects are applied in the order they are listed
- e.g The `Atom List` `@run in circles then @stop` might result in the pedestrian simply stopping *(dependent on the definition of @run in circles and @stop)*

## A.3.2. Making an Atom
1. Add To Grammar
2. Create Atom Definition
3. Add To Atom Map
4. Add To BehaviorBuilder
5. Add Source To CMakeLists.txt
6. Add Tests
7. Add Documentation

### A.3.2.1. Add To Grammar

`Atoms` are added to the grammar in `/VIPRA_Behaviors/grammar/action.g4`

Run `make` in `/VIPRA_Behaviors/grammar/`

example:
```
// Don't forget to add the new rule to the action_atom rule
action_atom:
	ACTION |
	action_Example
	;

// Defining the example atom rule
action_Example:
	'@example do something';
```

### A.3.2.2. Create Atom Definition

Create a header file in `/VIPRA_Behaviors/include/actions/atoms/` and a matching source file in `/VIPRA_Behaviors/src/actions/atoms/`

The `Atom` should derive from `Atom` in `/VIPRA_Behaviors/include/actions/action_atom.hpp`

Define a constructor (it can take any parameters) and implement the `performAction` method

example:
```C++
// atom_example.hpp
class Atom_Example : public Atom {
 public:
  Atom_Example(float, std::string);
  void performAction(const PedestrianSet&,
                     const ObstacleSet&,
                     const Goals&,
                     const BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>) override;
 private:
  float _x;
  float _str;
};

//atom_example.cpp
  Atom_Example::Atom_Example(float x, std::string str) : _x(x), _str(str) {}
  void Atom_Example::performAction(const PedestrianSet&,
                     const ObstacleSet&,
                     const Goals&,
                     const BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>) {
  // ... code that writes changes to state
}

```

### A.3.2.3. Add To Atom Map

Add the `Atom` to `AtomMap` in `/VIPRA_Behaviors/src/actions/atom_map.cpp`

example:
- for an atom that takes a `float` and `VIPRA::f3d` in its constructor called `Example`
```C++
const std::unordered_map<std::string, std::any> AtomMap = {
	// ... other atoms
    {"Example", AtomFunc<float, std::string>([](float x, std::string str) -> std::unique_ptr<Atom> { return std::make_unique<Atom_Example>(x, str); })},
    // ... other atoms
}
```

### A.3.2.4. Add To BehaviorBuilder

Add the `Atom` to the `addAtomToAction` method in `/VIPRA_Behaviors/src/behavior/behavior_builder.cpp`

example:
- for our Example `Atom`:
```C++
if (atom->action_Example()) {
	spdlog::debug("Behavior \"{}\": Adding Action Atom: \"Example\"", currentBehavior.getName());
	// Getting parameters should be moved to a seperate function for clarity
	float x = std::stof(atom->action_Example()->NUMBER()->toString());
	std::string str = atom->action_Example()->ID()->toString();
	action.addAtom("Example", x, str);
	return;
}
```
- The function `action_Example()` comes from the name we gave the rule in the grammar

### A.3.2.5. Add Source To CMakeLists.txt

Add the `Atom` source file to `/VIPRA_Behaviors/src/CMakeLists.txt`

example:
- for our Example `Atom`:
`${SRC_DIR}/actions/atoms/atom_example.cpp`

### A.3.2.6. Add Tests

Add any tests in `/VIPRA_Behaviors/__tests__/atom_tests/`

### A.3.2.7. Add To Documentation

Add any documentation

---



# Conditions

A `Condition` is what decides if a `Conditional Action`  (§A.1)  or `Event`  (§E.)  occurs. 
`Conditions` are comprised of one or more `SubConditions` (§C.1) and the boolean operations between them (and/or).

# C.1 SubConditions

A `SubCondition` defines a condition of the state of the simulation in which it returns true.

A `SubCondition` is a functor that only has one constructor (can be defined to take any number of parameters) and overloads operator()

`SubConditions` derive from `/VIPRA_Behaviors/include/conditions/sub_condition.hpp`

## C.1.1 Combining SubConditions

! currently boolean logic is only applied in the order the sub conditions are added !
! there is no grouping subconditions !

When building `Conditions`, `SubConditions` are combined with either `and` or `or`



---



# E. Events

An `Event` is something that occurs during a simulation, for example an announcement or fire.

`Events` have a start `Condition` and end `Condition`  (§C.)
When either the start `Condition` or end `Condition` its respective `Event Handlers`  (§E.1) are called


# E.1 Event Handlers

`Event Hanlders` are the methods called when an `Event` either starts or ends

## E.1.1 Subscribing Handlers


---

