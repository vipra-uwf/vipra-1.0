grammar declarations;

import lexer_rules;
import values;

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
  POSSIBLE PEDESTRIAN STATES ARE (STATE (COMMA? AND? STATE)*);

decl_Env_State:
  POSSIBLE ENVIRONMENT STATES ARE (STATE (COMMA? AND? STATE)*);

decl_Loc_Area_Circle:
  CONSIDER AN LOCATION ID AT point WITH AN RADIUS OF value_number;

decl_Loc_Area_Rect:
  CONSIDER AN LOCATION ID AT point WITH AN LENGTH OF value_number AND AN WIDTH OF value_number;

decl_Loc_Point:
  CONSIDER AN LOCATION ID AT point;

decl_Ped:
  CONSIDER AN (ID (COMMA? AND? AN? ID)*);

point: '('value_number',' value_number')';
