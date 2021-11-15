grammar Behaviors;

/*
 * Parser Rules
 */

// A program is a series of statements
program: statement+;

// A statement is a consideration, count, and description (for now)
statement: consideration | stateSelector | stateDeclaration | stateTransition | stateAction ;

consideration: 'Consider a ' ID '.' NEWLINE
    | 'Consider an ' ID '.' NEWLINE ;
stateSelector : NUMBER '% of the population are a ' ID '.' NEWLINE
    | NUMBER '% of the population are an ' ID '.' NEWLINE;

// A narcoleptic can be SLEEPING.
// A narcoleptic can be AWAKE.
stateDeclaration: 'A ' ID ' can be ' ID '.' NEWLINE;

// A narcoleptic who is SLEEPING will be AWAKE after 120 seconds.
// A narcoleptic who is AWAKE will be SLEEPING after 120 seconds.
stateTransition: 'A ' ID ' who is ' ID ' will be ' ID ' after ' NUMBER ' seconds.' NEWLINE;

// A narcoleptic who is SLEEPING is STOPPED.
stateAction: 'A ' ID ' who is ' ID ' is ' ID '.' NEWLINE;


// state: 'AWAKE' #awake
//     | 'SLEEPING' #sleeping;

// action: 'STOPPED' #stopped;

/*
 * Lexer Rules
 * These are only used for tokenizing. Use the parser rules above to combine these.
 */
ID: [a-zA-Z]+ ;
NUMBER : [0-9]+ ;
NEWLINE : '\r'? '\n' ; // Return newlines to parser (is end-statement signal)
WHITESPACE : ' ' -> skip ;

/**
A random 1 out of 10 people is a shy
A shy person who is WALKING will SLOW DOWN when they are 3 feet away from the nearest person.

// Conditions:
// Put people in groups
// Environmental changes - obstacle avoidance?
// Events - environment state (like announcements)
**/