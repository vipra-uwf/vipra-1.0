grammar declarations;

import lexer_rules;

declaration:
  decl_Ped |
  decl_Ped_State |
  decl_Env_State |
  decl_Parameters
  ;

decl_Ped:
  'Consider' AN ID '.';

decl_Ped_State:
  'Possible Pedestrian States Are:' (ID (COMMA ID)*) '.';

decl_Env_State:
  'Possible Environment States Are:' (ID (COMMA ID)*) '.';

decl_Parameters:
  PARAMETERS (PARAMETER (COMMA PARAMETER)*) '.';