lexer grammar lexer_rules;

COMMENT : '/*' .*? '*/'    -> skip;
LINE_COMMENT: '//' ~[\r\n]*    -> skip;
WS : [ \t\r\n]+ -> channel(HIDDEN);

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

COMMA: ',';
COLON: ':';

// -- Keep These In This Area ------------

STATE: '#'[a-zA-Z_\-]+;
ACTION: '@'[a-zA-Z_\-]+;
EVNT: '!'[a-zA-Z_\-]+;
OBJECT: '+'[a-zA-Z_\-]+;

// ---------------------------------------

AN: A | A N;
AT: A T;
AND: A N D;
ARE: A R E;
AFTER: A F T E R;
ALWAYS: A L W A Y S;
AROUND: A R O U N D;

BEHIND: B E H I N D;

CONSIDER: C O N S I D E R;

DECIMAL: D E C I M A L;
DIRECTION: D I R E C T I O N;

END: E N D;
ENDS: E N D S;
ENVIRONMENT: E N V I R O N M E N T;
EVENT: E V E N T;
EXACTLY: E X A C T L Y;
EVERY: E V E R Y;
EVERYONE: E V E R Y O N E;

FOR: F O R;
FROM: F R O M;
FRONT: F R O N T;
FASTER: F A S T E R;

GIVEN: G I V E N;

HAS: H A S;

IN: I N;
INTEGER: I N T E G E R;
IS: I S;

LENGTH: L E N G T H;

LOCATION: L O C A T I O N;

METERS: M E T E R S;

NORMAL: N O R M A L;

OBSTACLE: O B S T A C L E;
OCCUR: O C C U R;
OCCURRED: O C C U R R E D;
OCCURRING: O C C U R R I N G;
OF: O F;
OR: O R;

PEDESTRIAN: P E D E S T R I A N;
PEDESTRIANS: P E D E S T R I A N S;
POSSIBLE: P O S S I B L E;

RADIUS: R A D I U S;
RANDOM: R A N D O M;
REQUIRED: R E Q U I R E D;

SECOND: S E C O N D;
SECONDS: S E C O N D S;
SLOWER: S L O W E R;
STATES: S T A T E S;
STARTS: S T A R T S;
SPEED: S P E E D;

TO: T O;
THE: T H E;
THAT: T H A T;
THEN: T H E N;
THEIR: T H E I R;
THERES: T H E R E S;
TYPES: T Y P E S;

VALUE: V A L U E;

WHEN: W H E N;
WHILE: W H I L E;
WIDTH: W I D T H;
WILL: W I L L;
WITH: W I T H;
WITHIN: W I T H I N;


// ---------- Keep The Following At The End Of The File ------------

ID: [a-zA-Z_\-]+;
NUMBER : [0-9]+;
FLOAT: [0-9]+'.'[0-9]+;
