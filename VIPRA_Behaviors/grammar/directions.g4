grammar directions;

import lexer_rules;

direction:
  dir WITHIN NUMBER METERS;

dir:
  direction_of |
  infront |
  behind |
  around 
  ;

direction_of:
  IN DIRECTION OF ATTRIBUTE;

infront:
  IN FRONT;

behind:
  BEHIND;

around:
  AROUND;