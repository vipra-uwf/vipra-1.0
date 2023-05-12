grammar declarations;

import lexer_rules;

declaration:
  decl_Ped |
  decl_Ped_State |
  decl_Env_State |
  decl_Loc_Area |
  decl_Loc_Point
  ;

decl_Ped:
  CONSIDER AN (ID (COMMA? AND? AN? ID)*);

decl_Ped_State:
  POSSIBLE PEDESTRIAN STATES ARE (STATE (COMMA? AND? STATE)*);

decl_Env_State:
  POSSIBLE ENVIRONMENT STATES ARE (STATE (COMMA? AND? STATE)*);
<<<<<<< Updated upstream
=======

decl_Loc_Area:
  CONSIDER AN ID AT (POINTX)X AND (POINTY)Y WITH A LENGTH OF L AND A WIDTH OF W;

decl_Loc_Point:
  CONSIDER AN ID AT (POINTX)X AND (POINTY)Y;
>>>>>>> Stashed changes
