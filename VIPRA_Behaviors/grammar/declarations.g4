grammar declarations;

import lexer_rules;

declaration:
  decl_Ped |
  decl_Ped_State |
  decl_Env_State
  ;

decl_Ped:
  CONSIDER AN (ID (COMMA? AND? AN? ID)*);

decl_Ped_State:
  POSSIBLE PEDESTRIAN STATES ARE (STATE (COMMA? AND? STATE)*);

decl_Env_State:
  POSSIBLE ENVIRONMENT STATES ARE (STATE (COMMA? AND? STATE)*);
