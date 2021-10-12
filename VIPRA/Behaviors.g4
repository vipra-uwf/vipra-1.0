grammar Behaviors;

/*
 * Parser Rules
 */

// A program is a series of statements
program: statement+;

// A statement is a consideration, count, and description (for now)
statement: consideration count description ;

consideration: 'Consider a ' PERSON_TYPE '.' NEWLINE
    | 'Consider an ' PERSON_TYPE '.' NEWLINE ;
count : NUMBER '% of the population are a ' PERSON_TYPE '.' NEWLINE
    | NUMBER '% of the population are an ' PERSON_TYPE '.' NEWLINE;
/* This is just for testing for now. We will define this behavior more generically later on */
description: 'A ' PERSON_TYPE ' pauses movement randomly for 1 minute.';

/* A narcoleptic who is AWAKE will transition to ASLEEP randomly */
/* A narcoleptic who is SLEEPING will transition to AWAKE after 1 minute */
/* A narcoleptic who is SLEEPING is stopped */
/* A narcoleptic who is AWAKE moves normally */


state: 'AWAKE' #awake
    | 'SLEEPING' #sleeping;

/* TODO */
/* Define states and transitions _somehow_. */
/* Define what should happen in those states. */
/* Define a way to supply comments. */

/*
 * Lexer Rules
 */
PERSON_TYPE : [a-zA-Z]+ ;
NUMBER : [0-9]+ ;
NEWLINE : '\r'? '\n' ; // Return newlines to parser (is end-statement signal)
WHITESPACE : ' ' -> skip ;