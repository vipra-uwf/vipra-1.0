grammar Behaviors;

/*
 * Parser Rules
 */

// A program is a series of statements
program: statement+;

// A statement is a consideration, count, and description
statement: consideration
    | stateSelector
    | stateDeclaration
    | initialStateDeclaration
    | environmentStateDeclaration
    | environmentInitialStateDeclaration
    | environmentTransition
    | stateTransitionElapsedTime
    | stateTransitionEnvironmentState
    | stateAction;

// Example: Consider a narcoleptic
consideration: 'Consider ' ('a '|'an ') ID '.';

stateSelector: idRatioSelector
    | randomIdRatioSelector
    | everyoneSelector
    ;

// Example: 2% of the population are a narcoleptic
idRatioSelector : NUMBER '% of the population are ' ('a '|'an ') ID '.';

// Example: A random 1 out of every 50 pedestrians is a narcoleptic
randomIdRatioStatement: 'A random ' NUMBER ' out of every ' NUMBER ' pedestrians is ' ('a '|'an ') ID;

randomIdRatioSelector : randomIdRatioStatement '.' #NoGroupRandomIdSelector
    | randomIdRatioStatement ', forming a ' ID '.' #GroupingRandomIdSelector
    ;

// Examples:
// A narcoleptic who is SLEEPING will be AWAKE after 120 seconds.
// A group-traveler who is SLOWING_DOWN will be IN_GROUP if they are less than 10 feet ahead of someone in their travel-party.
conditionElapsedTime: ' after ' NUMBER ' seconds.' ;
conditionEnvironmentState:  (' if'|' when') ' the environment is ' ID '.';

everyoneSelector: 'Everyone is ' ('a '|'an ') ID '.';

// Example: The environment can be ANNOUNCING.
environmentStateDeclaration: 'The environment can be ' ID '.';

// Example: The environment is initially PRE_ANNOUNCING.
environmentInitialStateDeclaration: 'The environment is initially ' ID '.';

// Example: The environment that is PRE_ANNOUNCING will be ANNOUNCING after 300 seconds.
environmentTransition: 'The environment that is ' ID ' will be ' ID conditionElapsedTime;

// Examples:
// A narcoleptic can be SLEEPING.
// A narcoleptic can be AWAKE.
stateDeclaration: ('A '|'An ') ID ' can be ' ID '.';

// Example: A narcoleptic is initially AWAKE.
initialStateDeclaration: ('A '|'An ') ID ' is initially ' ID '.';

pedestrianSelected: ('A '|'An ') ID ' who is ' ID;

stateTransitionElapsedTime: pedestrianSelected ' will be ' ID conditionElapsedTime;
stateTransitionEnvironmentState: pedestrianSelected ' will be ' ID conditionEnvironmentState;

// Examples:
// A group-traveler who is CATCHING_UP will walk 5% faster toward their group.
// A narcoleptic who is SLEEPING is STOPPED.
fasterOrSlower: 'faster' | 'slower';
towardOrAwayFrom: 'toward' | 'away from';
target: 'their group' | 'their goal';

stoppedBehavior: ' is STOPPED';
walkSpeedBehavior: ' will walk ' NUMBER '% ' fasterOrSlower;
walkSpeedWithTargetBehavior: ' will walk ' NUMBER '% ' fasterOrSlower ' ' towardOrAwayFrom ' ' target;
normalBehavior: ' will behave normally';

stateAction: pedestrianSelected stoppedBehavior '.'      #StateActionStopped
    | pedestrianSelected walkSpeedBehavior '.'           #StateActionWalkSpeed
    | pedestrianSelected walkSpeedWithTargetBehavior '.' #StateActionWalkSpeedWithTarget
    | pedestrianSelected normalBehavior '.'              #StateActionNormal
    ;

/*
 * Lexer Rules
 * These are only used for tokenizing. Use the parser rules above to combine these.
 */
ID: [a-zA-Z_\-]+ ;
NUMBER : [0-9]+ ;
COMMENT:            '/*' .*? '*/'    -> channel(HIDDEN);
LINE_COMMENT:       '//' ~[\r\n]*    -> channel(HIDDEN);
WHITESPACE : [ \t\r\n]+ -> channel(HIDDEN) ;

/**
Other transitions could include:
* A shy person who is WALKING will SLOW DOWN when they are 3 feet away from the nearest person.

// Additional notes for the future:
// Conditions:
// Put people in groups, like a travel party
// Environmental changes - obstacle avoidance perhaps?
// Events - environment state (like announcements over the speakers)
**/