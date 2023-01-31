lexer grammar lexer_rules;

A: ('a '|'an ' | 'A '|'An ');
AndOr: ('AND ' | 'OR ');
END: '.';
ID: [a-zA-Z_\-]+ ;
STATE: [a-zA-Z_\-]+ ;
NUMBER : [0-9]+ ;
PERCENT : NUMBER'%';
COMMENT : '/*' .*? '*/'    -> channel(HIDDEN);
LINE_COMMENT: '//' ~[\r\n]*    -> channel(HIDDEN);
WS : [ \t\r\n]+ -> skip ;