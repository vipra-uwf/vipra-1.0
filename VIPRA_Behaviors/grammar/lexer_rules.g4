lexer grammar lexer_rules;

fragment A:[aA];
fragment B:[bB];
fragment C:[cC];
fragment D:[dD];
fragment E:[eE];
fragment F:[fF];
fragment G:[gG];
fragment H:[hH];
fragment I:[iI];
fragment J:[jJ];
fragment K:[kK];
fragment L:[lL];
fragment M:[mM];
fragment N:[nN];
fragment O:[oO];
fragment P:[pP];
fragment Q:[qQ];
fragment R:[rR];
fragment S:[sS];
fragment T:[tT];
fragment U:[uU];
fragment V:[vV];
fragment W:[wW];
fragment X:[xX];
fragment Y:[yY];
fragment Z:[zZ];

ID: [a-zA-Z_\-]+;

STATE: '#'[a-zA-Z_\-]+;
ACTION: '!'[a-zA-Z_\-]+;
ATTRIBUTE: '*'[a-zA-Z_\-]+;
PARAMETER: '$'[a-zA-Z_\-]+;


NUMBER : [0-9]+;
COMMENT : '/*' .*? '*/'    -> channel(HIDDEN);
LINE_COMMENT: '//' ~[\r\n]*    -> channel(HIDDEN);
WS : [ \t\r\n]+ -> skip ;


AN: (A | A N) WS;
AND: A N D WS;
OR: O R WS;
ANDOR: (AND | OR) WS;
COMMA: ',';
COLON: ':';

THE: T H E WS;
GIVEN: G I V E N WS;
SET: S E T WS;

PARAMETERS:
  P A R A M E T E R S COLON
  ;