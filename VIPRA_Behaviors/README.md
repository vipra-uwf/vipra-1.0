# VIPRA Behaviors

# Sections
### B. Behaviors
### L. Layout
### Sy. General Syntax Rules
### T. Types
### S. Selectors
### A. Actions
### C. Conditions
### E. Events
### V. Values
### St. State
### Ex. Creating An Example Behavior

---
<h1> B. Behaviors </h1>

`Behaviors` are a way to describe `Actions` that pedestrians take under certain `Conditions` without the use of a traditional programming language.

`Behaviors` are comprised of several major parts:
1. `Selectors` (§S.)
2. `Actions` (§A.)
3. `Events` (§E.)

---

<details>
  <summary>
    <h1>
      L. Behavior Layout
    </h1>
  </summary>

The general layout of a `Behavior` is as follows:
```
Consideration.       // section (§T.)

State declarations.  // section (§St.)

Selector statements. // section (§S.)

Event definitions.   // section (§E.)

Action statements.   // section (§A.)
```

</details>

---

<details>
  <summary>
    <h1>
      Sy. General Syntax Rules
    </h1>
  </summary>

This section has some simple `Syntax` rules that must be followed for a `Behavior` to be considered correct.

The other sections will have the specific `Syntax` rules for their respective parts, in a `Section - General Syntax Rules` section

1. All statements must end in a '.' <sub>A statement being an `Action`, `Selector`, `Event`, or `Consideration`</sub>
```
correct:
  An injured_person will always @stop.

incorrect:
  An injured_person will always @stop
```

2. Each `Behavior` (§B) must start with a `Consideration` (§T.1)
3. Each `Behavior` (§B) must only have 1 `Consideration` (§T.1)
4. Each `Behavior` (§B) must have at least 1 `Selector` (§S)
5. `Behaviors` are case in-sensitive so `Consider`, `consider`, and `ConSiDEr` are all valid.
6. 'A' and 'An' are interchangeable, use whichever sounds grammatically correct.
7. Comments can be added following '//' or between '/*' and '\*/'
```
// This is a comment and does not affect the behavior

/*
This is a multi-line comment
and does not affect the behavior
*/
```
8. Whitespace does not affect `Behaviors`, the following are valid and equivalent.
```
A typeA will always @stop.

// and

A
typeA will
always          @stop.
```
9. All commas are optional.
</details>

---

<details>
  <summary>
    <h1>
      T. Types
    </h1>
  </summary>

`Types` are how pedestrians are organized in `Behaviors` (§B)

Each pedestrian is assigned a user defined `Type`, and based on their `Type` they will follow different `Actions` (§A).

<details>
  <summary>
    <h2>
      T.1. Considerations
    </h2>
  </summary>

A `Consideration` is what says which types are being used in the `Behavior`. 

`Behaviors` can only have 1 `Consideration` with up to 64 types.

Single `Type` `Consideration`:
```
Consider an injured_person.
```

Multiple `Types` `Consideration`:
```
Consider an injured_person, and a helper.
```

<details>
  <summary>
    <h3>
      T.1.1. Consideration - General Syntax Rules
    </h3>
  </summary>

1. `Types` in `Considerations` can be connected in several ways, the following are all valid and equivalent:
```
Consider an injured_person, a helper.
Consider an injured_person and a helper.
Consider an injured_person, and a helper.
Consider an injured_person, and helper.
```
2. `Considerations` can be any length up to 64 `Types`
```
Consider a typeA, a typeB, a typeC, and typeD.
```
3. `Considerations` must be the first statement in a `Behavior`

</details>
</details>

---

<details>
  <summary>
    <h2>
      T.2. Composite Types
    </h2>
  </summary>

A Pedestrians `Type` can be composed of several other types.

A Pedestrian with a `Composite Type` will have the attributes of each individual `Type`.

How to assign `Composite Types` is explained in the `Selectors` (§S) section.

</details>

---

<details>
  <summary>
    <h2>
      T.3. Groups
    </h2>
  </summary>
Effectively, `Groups` and `Types` refer to the same thing.

The main difference between a `Type` and a `Group` is that there is a base `Group` for each `Behavior`, being 'Pedestrian' or 'Pedestrians'.

Each pedestrian with a `Type` is considered in that `Types` `Group`.

Pedestrians with `Composite Types` are in a `Group` for each `Type`.

</details>

---

<details>
  <summary>
    <h2>
      T.4. Types - General Syntax Rules
    </h2>
  </summary>

1. `Type` names can only contain Letters, Underscores, and Hyphens `(a-z), (A-Z), '_', '-'`

</details>
</details>

---

<details>
  <summary>
    <h1>
      S. Selectors
    <h1>
  </summary>

`Selectors` are how pedestrians are selected for a certain `Type` (§T).


<details>
<summary><h2>S.1. Selecting Pedestrians</h2></summary>

Selecting pedestrians is done through a `Selector` statement. The basic syntax is as follows:
```
*Selector* of *Group* are a *Type*.
or
*Selector* of *Group* are a *TypeA* and *TypeB*.
```

- \*Selector* - The exact `Selector` to use, available `Selectors` are in (§S.5.)
- \*Group* - The `Group` (§T.3) to select pedestrians from
- \*Type* - The `Type` (§T.) to assign to selected pedestrians

Selectors are applied with precedence equal to the order they appear in the `Behavior` file.

<details>
<summary><b>Example:</b></summary>

```
Consider a typeA, and a typeB.     // Consideration (§T.1.), saying what types the behavior uses

Exactly 10 pedestrians is a typeA. // Exactly N Selector statement
50% of pedestrians is a typeB.     // Percent Selector statement
```

</details>
<br/>

**Note:**
The `Everyone` `Selector` has a special syntax
```
Everyone is a typeA.
```

</details>

---

<details>
  <summary>
  <h2>
    S.2. Selecting From Groups
  </h2>
  </summary>

`Selectors` can select from specific `Groups` (§T.3)

This has the effect of selecting the pedestrians for a `Composite Type` (§T.2) but allows for more dynamic proportions.

<details> 
<summary><b>Example:</b></summary>

```
Consider a typeA, typeB and typeC.

50% of pedestrians are a typeA. // Selects from the 'Pedestrians Group'
15% of typeA are a typeB.       // Selects from typeA pedestrians
5% of typeA are a typeC.        // Selects from typeA pedestrians
```

With 100 pedestrians:
39 pedestrians are typeA.
8 pedestrians are typeA and typeB.
3 pedestrians are typeA and typeC.

</details>
</details>

---

<details>
  <summary>
    <h2>
      S.3. Selector Exclusivity
    </h2>
  </summary>

When a pedestrian is selected from a `Group`, it is marked as used and can not be selected by another `Selector`.

This has the affect of making `Selector` statements strictly interpreted.

```
15% of typeA are typeB.
```
Means:
15% of 'typeA' pedestrians are strictly 'typeA' and 'typeB', with no chance of being anything else.

</details>

---

<details>
  <summary>
    <h2>
      S.4. Required Selectors
    </h2>
  </summary>

`Selectors` can be marked as `Required` with 'Required:' before the `Selector` statement. 

This means, given the `Selector` is unable to be filled an error will be thrown, and the simulation will stop.

<details> 
<summary><b>Example:</b></summary>

```
Consider a typeA, and a typeB.

Everyone is a typeA.

Required: 50% of pedestrians are a typeB.
```
Output:
```
Behavior: Example, Required Selector Starved For Type: 2 From Group: 0"
```
</details>
</details>

---

<details>
  <summary>
    <h2>
      S.5. Available Selectors
    </h2>
  </summary>

1. Everyone Selector
2. Percent Selector
3. N Selector

---

<details>
  <summary>
    <h3>
      S.5.1. Everyone Selector
    </h3>
  </summary>

```
Everyone is a *Type*.
```

This selector chooses every pedestrian to have the selected `Type` (§T)

</details>

---

<details>
  <summary>
    <h3>
      S.5.2 Percent Selector
    </h3>
  </summary>


Selects a percentage of a `Group` for the provided `Type`

```
*X*%
```
\*X* - Number `Value` (§V) (1 - 100)


<details> 
<summary><b>Example:</b></summary>

```
15% of pedestrians are a injured_person.
```

</details>
</details>

---

<details>
  <summary>
    <h3>
      S.5.3 N Selector
    </h3>
  </summary>

Selects an exact number of pedestrians from a `Group`.

```
Exaclty *X*
```
\*X* - Number `Value` (§V)


<details> 
<summary><b>Example:</b></summary>

```
Exactly 10 pedestrians is a injured_person.
```

</details>
</details>
</details>

---

<details>
  <summary>
    <h2>
      S.6 Selectors - General Syntax Rules
    </h2>
  </summary>

1. The 'of' in 'of \*Group*' can be removed if it makes more grammatical sense.

</details>
</details>

---

<details>
  <summary>
    <h1>
      A. Action
    </h1>
  </summary>

`Actions` are what affect a Pedestrian's position, velocity, state, etc.

`Actions` are comprised of `Atoms` and, optionally, a `Condition`.

<details>
  <summary>
    <h2>
      A.1. Unconditional Actions
    </h2>
  </summary>

An `Unconditional Action` will ALWAYS take effect.

`Unconditional Actions` are written as follows:
```
A *Type* will always *Atoms*.
```
- Type being the pedestrian type that follows this `Action`
- Atoms being the steps taken in an action, more in (§A.3.)

<details>
  <summary>
    <b>
      Example:
    </b>
  </summary>

```
A typeA will always @stop.
```

</details>
</details>

---

<details>
  <summary>
    <h2>
      A.2. Conditional Actions
    </h2>
  </summary>

# A.2. Conditional Actions

A `Conditional Action` will only take effect if its `Condition` is satisfied.

`Conditional Actions` are written as follows:
```
A *Type* will *Atoms* *Condition*.
```

- \*Type* being the pedestrian type that follows this `Action`
- \*Atoms* being the steps taken in an action, more in (§A.4.)
- see (§C.) for an explanation of Conditions

<details>
  <summary>
    <b>
      Example:
    </b>
  </summary>

```
A typeA will 
  @stop                                  // Atom (§A.4.)
  given the !example event is occurring. // Condition (§C.)
```

</details>
</details>

---

<details>
  <summary>
    <h2>
      A.3. Action Durations
    </h2>
  </summary>

Normally `Actions` only apply to the time step their `Condition` is true in.

If a longer response is needed, a `Duration` can be added to an `Action`.


```
A *Type* will *Atoms* *Condition* for *value* seconds.
```
- \*Type* being the `Type` (§T.) the action applies to
- \*Atoms* being the `Atoms` (§A.4.) for the `Action`
- \*Condition* being the `Condition` (§C.) for the action to start
- \*value* being a numerical `Value` (§V.), for how long the action should continue

<details>
  <summary>
    <b>
      Example, Someone Tripping:
    </b>
  </summary>

```
a tripper will
  @stop                                   // Atom (§A.4.)
  after a random 1-10 seconds from !start // Condition (§C.)
  for 5 seconds.                          // Duration
```

</details>
</details>

---

<details>
  <summary>
    <h2>
      A.4. Atoms
    </h2>
  </summary>

`Atoms` are the part of an `Action` that actually affects a pedestrian. A group of `Atoms` comprise an `Action`.

`Atoms` can be one or multiple words long and are always preceded by an `@`

<details>
  <summary>
    <b>
    Examples:
    </b>
  </summary>

```
@stop
@walk 10% slower
```

</details>

## A.4.1 Atom List
An `Atom List` is the collection of `Atoms` that make up an `Action`.
`Atom Lists` are comprised of one or more `Atoms`.

`Atom Lists` are written as follows:
`*Atom* then *Atom*`

**Important Note:** `Atom` effects are applied in the order they are listed

<details>
  <summary>
    <b>
    Examples:
    </b>
  </summary>

```
@stop
@stop then @listen
@stop then @listen then @run in circles
```
- e.g The `Atom List` `@run in circles then @stop` might result in the pedestrian simply stopping *(dependent on the definition of @run in circles and @stop)*

</details>

</details>

---

<details>
  <summary>
    <h2>
      A.5. Available Atoms
    </h2>
  </summary>

<details>
  <summary>
    <h3>
      A.5.1. Stop
    </h3>
  </summary>

The `Stop` `Atom` keeps a pedestrian from moving.

```
@stop
```

</details>

---

<details>
  <summary>
    <h3>
      A.5.2. Walk Speed
    </h3>
  </summary>

The `Walk Speed Atom` scales the speed a pedestrian moves

```
@walk *value* x their normal speed.
```

- \*value* being any `Value` type (§V.)

</details>

---

<details>
  <summary>
    <h3>
      A.5.3. Be / Set State
    </h3>
  </summary>

The `Be Atom` sets a pedestrians `State` (§St.)

```
@be *state*
```

- \*state* being the `State` to set the pedestrian to (§St.)

</details>
</details>

---

<details>
  <summary>
    <h2>
      A.6. Actions - General Syntax Rules
    </h2>
  </summary>


</details>
</details>

---

<details>
  <summary>
    <h1>
      C. Conditions
    </h1>
  </summary>

A `Condition` is what decides if a `Conditional Action` or `Event` occurs. 

`Conditions` are comprised of one or more `Sub Conditions` and the boolean operations between them (and/or).

`Conditions` do not stand on their own, and only appear as part of an `Action` or `Event` statement.

<details>
  <summary>
    <b>
    Example:
    </b>
  </summary>

```
A typeA will @stop 
given the !example event has occurred
and
after 5 seconds from the !start.
```


</details>

---

<details>
  <summary>
    <h2>
      C.1 Sub Conditions
    </h2>
  </summary>

A `Sub Condition` defines a single condition of the state of the simulation in which it returns true.

Available `Sub Conditions` are in section (§C.2.)

</details>

<details>
  <summary>
    <h2>
      C.2 Available Sub Conditions
    </h2>
  </summary>

<details>
  <summary>
    <h3>
      C.2.1. Elapsed Time
    </h3>
  </summary>

This `Condition` will be true when a provided amount of time has passed from the start of an `Event` (§E.)

**Note:** This is true only for one time step when the time has elapsed, until the `Event` starts again.

```
after *duration* from the *event* event.
```

<details>
  <summary>
    <b>
      Example:
    </b>
  </summary>

```
A typeA will 
  @stop                            // Atom (§A.4)
  after 10 seconds from the !start // Elapsed Time Condition
  for 5 seconds.                   // Duration (§A.3)
```
**Note:** without the `Duration` the pedestrian would stop moving for only one time step.

</details>
</details>

---

<details>
  <summary>
    <h3>
      C.2.2. Event Occurred
    </h3>
  </summary>

This `Condition` is true for every time step after an `Event` has started, until the end of the simulation.

```
given the *event* event has occurred.
```

<details>
  <summary>
    <b>
    Example:
    </b>
  </summary>

```
A typeA will
  @walk 0.75x their normal speed // Atom (§A.4)
  given an !announcement event has occurred. // Event Occurred Condition
```

</details>
</details>

---

<details>
  <summary>
    <h3>
      C.2.3. Event Occurring
    </h3>
  </summary>

This `Condition` is true while an `Event` is occurring.

<details>
  <summary>
    <b>
    Example:
    </b>
  </summary>

```
A typeA will
  @stop // Atom (§A.4)
  while an !announcement event is occurring. // Event Occurred Condition
```

</details>
</details>
</details>
</details>

---

<details>
  <summary>
    <h1>
      E. Events
    </h1>
  </summary>

A `Event` is something that occurs during a simulation, for example an announcement or fire.

`Events` have a start `Condition` and, optionally, an end `Condition` (§C)

An `Event` can only be described once, if a `Behavior` file tries to redefine an `Event` of the same name a `Behavior Error` is thrown.

`Event` names are always preceded by a `!`
ex. 
```
!announcement
```

<details>
  <summary>
    <h2>
      E.1. Creating Events
    </h2>
  </summary>

`Events` a defined as follows:
```
The !example event will occur *condition*. // This event will never end

// or

The !example event will occur *condition* and end *condition*.
```

<details>
  <summary>
    <b>
    Example:
    </b>
  </summary>

```
The !example event will occur after 10 seconds from !start,
  and end
  after 10 seconds from !example.
```

</details>
</details>

---

<details>
  <summary>
    <h2>
      E.2. Special Events
    </h2>
  </summary>

Currently, there is only one special event that is predefined for each `Behavior`:

the `!start` event

The `!start` event fires at the start of a simulation run.

</details>

---

<details>
  <summary>
    <h2>
      E.3. Events - General Syntax Rules
    </h2>
  </summary>

1. 'The !example event will ...' can be written several ways, use whichever sounds most natural:
```
The !example will ...
// or
An !example will ...
// or
An !example event will ...
```
2. When referencing `Events`, the word 'event' can be dropped:
```
The !example event
// or
The !example
```

</details>
</details>

---

<details>
  <summary>
    <h1>
      V. Values
    </h1>
  </summary>

<details>
  <summary>
    <h2>
      V.1. Numerical Values
    </h2>
  </summary>

Anywhere there is a numerical value required the following can be used (with some exceptions):
1. `Exact Values`
2. `Range Values`
3. `Random Values`

<details>
  <summary>
    <h3>
      V.1.1. Float vs. Number Values
    </h3>
  </summary>

There are two kinds of `Numerical Values`:
1. `Float Values`
2. `Number Values`

The difference between the two is simple:
1. `Float Values` have a decimal value
2. `Number Values` are whole numbers

<details>
  <summary>
    <b>
      Example:
    </b>
  </summary>

```
50    // Number Value, has no decimal places
50.15 // Float Value, has a decimal value
```

</details>
</details>

---

<details>
  <summary>
    <h3>
      V.1.1. Exact Values
    </h3>
  </summary>

`Exact Values` are used when the value should be a specific value

`Exact Values` can either be a `Float Value` or `Number Value`.

`Exact Values` are written as simple numerical values.

<details>
  <summary>
    <b>
      Example:
    </b>
  </summary>

```
50% of pedestrians is a typeA.                      // Number Value

A typeA will always @walk 1.25x their normal speed. // Float Value
```

</details>
</details>

---

<details>
  <summary>
    <h3>
      V.1.2. Range Values
    </h3>
  </summary>

`Range Values` are singular random values within a given range.

When the `Behavior` is run, the value is the same for every individual.

<details>
  <summary>
    <h3>
      V.1.2.1 Float Value Ranges  vs. Number Value Ranges 
    </h3>
  </summary>

`Range Values` are either `Float Value Ranges` or `Number Value Ranges`

With the difference being that:
`Float Value Ranges` are any real value between the range and `Number Value Ranges` are any integer value between the range.

</details>
<br/>

`Range Values` are written as follows:
```
// Number Value Range -> 1, 2, or 3
1-3
or
1 to 3

// Float Value Range -> 1.0, 1.003, 1.11, 2.3, 2.5, 3.0, etc.
1.0-3.0
or
1.0 to 3.0
```

<details>
  <summary>
    <b>
      Example:
    </b>
  </summary>

```
10-20% of pedestrians is a typeA.
```

The exact percentage will be a random integer value between 10 and 20.

</details>
</details>

---

<details>
  <summary>
    <h3>
      V.1.2. Random Values
    </h3>
  </summary>

`Random Values` are very similar to `Range Values`, with a random value in a given range.

The big difference is that: `Range Values` only have one random value, `Random Values` have a random value that is different for each pedestrian.

<details>
  <summary>
    <h3>
      V.1.2.1 Float Random Values vs. Number Random Values
    </h3>
  </summary>

`Random Values` are either `Float Random Values` or `Number Random Values`

With the difference being that:
`Float Random Value` are any real value between the range and `Number Random Values` are any integer value between the range.

</details>

Random Values are written as follows:
```
// Number Random Value -> 1, 2, or 3 (different for each pedestrian)
A random 1-3
// or
A random 1 to 3

// Float Random Value -> 1.0, 1.003, 1.11, 2.3, 2.5, 3.0, etc. (different for each pedestrian)
A random 1.0-3.0
// or
A random 1.0 to 3.0

```

<details>
  <summary>
    <b>
      Example:
    </b>
  </summary>

```
A Random 10-20% of pedestrians is a typeA.
```

The exact percentage will be a random integer value between 10 and 20.

</details>

</details>
</details>
</details>

---

<details>
  <summary>
    <h1>
      St. State
    </h1>
  </summary>

Each pedestrian has a `State` associated with it.

`States` are user defined, and used for `Conditions`

`States` are always preceded by a '#'.

`States` are defined as follows:
```
Possible pedestrians states are #stateA, #stateB, and #stateC.
```

</details>

---

<details>
  <summary>
    <h1>
      Ex. Creating An Example Behavior
    </h1>
  </summary>

Here we will make a couple of example `Behaviors`.

<details>
  <summary>
    <h2>
      Ex.1. The Simplest Behavior
    </h2>
  </summary>

This example is a simple `Behavior` that causes every pedestrian to stand still for the duration of the simulation. 

```
Consider a person.          // Consideration (§T.) says what types of pedestrians there are

Everyone is a person.       // Selector (§S.) says who is of that type

A person will always @stop. // Action (§A.) says what people of that type do
```

</details>

---

<details>
  <summary>
    <h2>
      Ex.2. An Announcment Event
    </h2>
  </summary>

This `Behavior` shows `Events`, with an announcement. In this example, we will make a simple `Behavior` and add to it.

```
Consider a listener.                       // Consideration (§T.)

Everyone is a listener.                    // Selector (§S.)

An !announcement will occur                // Event (§E.)
  after 10 seconds from the !start         // Start Condition (§C.)
  and 
  end after 10 seconds from !announcement. // End Condition (§C.)

A listener will @stop                      // Action (§A.)
  given an !announcement is occurring.     // Condition (§C.)
```

In this example, an announcement will start after 10 seconds and last for 10 seconds.

While the announcement is occurring, every pedestrian will be stopped to listen.

<details>
  <summary>
    <h3>
      Ex.2.1. A bit more realistic
    </h3>
  </summary>

Everyone stopping to listen isn't very realistic, so we can change it slightly.

```
Consider a listener.                       // Consideration (§T.)

10% of pedestrians is a listener.          // Selector (§S.)

An !announcement will occur                // Event (§E.)
  after 10 seconds from the !start         // Start Condition (§C.)
  and 
  end after 10 seconds from !announcement. // End Condition (§C.)

A listener will @stop                     // Action (§A.)
  given an !announcement is occurring.     // Condition (§C.)
```

In this example, only 10% of pedestrians will actually stop to listen to the announcement. (probably still an over-estimation)

</details>

<details>
  <summary>
    <h3>
      Ex.2.2. Adding more
    </h3>
  </summary>

A black-and-white, either pedestrians stop to listen or don't, may not be as realistic as we would like.

```
Consider a listener, and partial_listener.             // Consideration (§T.)

10% of pedestrians is a listener.                      // Selector (§S.)
25% of pedestrians is a partial_listener.              // Selector (§S.)

An !announcement will occur                            // Event (§E.)
  after 10 seconds from the !start                     // Start Condition (§C.)
  and 
  end after 10 seconds from !announcement.             // End Condition (§C.)

A listener will @stop                                  // Action (§A.)
  given an !announcement is occurring.                 // Condition (§C.)

A partial_listener will @walk 0.75x their normal speed // Action (§A.)
  given an !announement is occurring.                  // Condition (§C.)
```

In this 10% of pedestrians stop to listen, another 25% slow down to listen, and the rest behave normally.

</details>
</details>
</details>