grammar declarations;

import lexer_rules, values;

declaration:
  decl_Ped_State |
  decl_Env_State |
  decl_Ped
;

decl_Ped_State:
  PEDESTRIAN STATES ':' STATE_VAL (COMMA? STATE_VAL)*;
  
decl_Env_State:
  ENVIRONMENT STATES ':' (STATE_VAL (COMMA? STATE_VAL)*);

decl_Ped:
  TYPES ':' ID (COMMA? ID)*;