grammar Behaviors;

/*
 * Parser Rules
 */
consideration: '[Cc]onsider a[n]? "' + PERSON_TYPE + '"[.]?' ;
count : NUMBER + '% of the population consider themselves a[n]? "' + PERSON_TYPE + '"';
statement: '[Aa][n]? "' + PERSON_TYPE + '" moves slower by a force of ' + NUMBER + ' newtons[.]';

/*
 * Lexer Rules
 */
PERSON_TYPE : [a-zA-Z ]+ ;
NUMBER : [0-9]+ ;
WHITESPACE : ' ' -> skip ;