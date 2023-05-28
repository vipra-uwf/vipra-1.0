grammar values;

import lexer_rules;

value_number:
  number_random |
  NUMBER |
  FLOAT
  ;

number_random:
  random_float |
  random_number
  ;

random_number:
  AN RANDOM NUMBER (TO | '-') NUMBER
  ;

random_float:
  AN RANDOM FLOAT (TO | '-') FLOAT
  ;