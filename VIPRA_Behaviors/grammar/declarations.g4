grammar declarations;

import lexer_rules, values;

declaration:
  decl_Loc |
  decl_Ped_State |
  decl_Env_State |
  decl_Ped
;

decl_Loc:
  decl_Loc_Area_Circle |
  decl_Loc_Point |
  decl_Loc_Area_Rect
;

decl_Ped_State:
  PEDESTRIAN STATES ':' STATE_VAL (COMMA? STATE_VAL)*;
  
decl_Env_State:
  ENVIRONMENT STATES ':' (STATE_VAL (COMMA? STATE_VAL)*);

decl_Loc_Area_Circle:
  CONSIDER AN LOCATION ID AT value_coord WITH AN RADIUS OF value_numeric;

decl_Loc_Area_Rect:
  CONSIDER AN LOCATION ID AT value_coord WITH AN LENGTH OF value_numeric AND AN WIDTH OF value_numeric;

decl_Loc_Point:
  CONSIDER AN LOCATION ID AT value_coord;

decl_Ped:
  TYPES ':' ID (COMMA? ID)*;