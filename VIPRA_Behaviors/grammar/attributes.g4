grammar attributes;

import lexer_rules, values;


attribute:
  POSITION |
  VELOCITY |
  GOAL |
  STATE |
  LOCATION |
  STATUS
  ;

attr_value:
  value_coord |
  STATE_VAL
  ;