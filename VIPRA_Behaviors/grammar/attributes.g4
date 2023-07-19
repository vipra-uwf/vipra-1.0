grammar attributes;

import lexer_rules, values;


attribute:
  POSITION  |
  VELOCITY  |
  GOAL      |
  STATE     |
  LOCATION  |
  STATUS    |
  MAX SPEED |
  ;

attr_value:
  value_numeric |
  value_coord   |
  STATE_VAL
  ;