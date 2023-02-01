grammar declarations;

import lexer_rules;

declaration:
  decl_Ped |
  decl_Ped_State |
  decl_Env_State
  ;

decl_Ped:
  'Consider ' A ID;

decl_Ped_State:
  'Possible Pedestrian States Are: ' ID+;

decl_Env_State:
  'Possible Environment States Are: ' ID+;