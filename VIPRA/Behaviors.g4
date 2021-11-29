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
    | environmentStateDeclaration
    | stateTransition
    | stateAction;

// Example: Consider a narcoleptic
consideration: 'Consider ' ('a'|'an') ID '.';

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

everyoneSelector: 'Everyone is ' ('a '|'an ') ID '.';

// Example: The environment can be ANNOUNCING
environmentStateDeclaration: 'The environment can be ' ID '.';

// Examples:
// A narcoleptic can be SLEEPING.
// A narcoleptic can be AWAKE.
stateDeclaration: ('A '|'An ') ID ' can be ' ID '.';

pedestrianSelected: ('A '|'An ') ID ' who is ' ID;

// Examples:
// A narcoleptic who is SLEEPING will be AWAKE after 120 seconds.
// A group-traveler who is SLOWING_DOWN will be IN_GROUP if they are less than 10 feet ahead of someone in their travel-party.
stateCondition: ' after ' NUMBER ' seconds.'
//    | ' if they are ' NUMBER ' feet ' ID ' someone in their ' ID
    ;

stateTransition: pedestrianSelected ' will be ' ID stateCondition;

// Examples:
// A group-traveler who is CATCHING_UP will walk 5% faster toward their group.
// A narcoleptic who is SLEEPING is STOPPED.
fasterOrSlower: 'faster' | 'slower';
towardOrAwayFrom: 'toward' | 'away from';
target: 'their group' | 'their goal';

stoppedBehavior: ' is STOPPED';
walkSpeedBehavior: ' will walk ' NUMBER '% ' fasterOrSlower ' ' towardOrAwayFrom ' ' target;
normalBehavior: ' will behave normally';

stateAction: pedestrianSelected stoppedBehavior '.' #StateActionStopped
    | pedestrianSelected walkSpeedBehavior '.'      #StateActionWalkSpeed
    | pedestrianSelected normalBehavior '.'         #StateActionNormal
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