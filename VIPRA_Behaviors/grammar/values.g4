grammar values;

import lexer_rules;

value_number:
  NUMBER |
  FLOAT |
  number_random
  ;

number_random:
  random_float |
  random_number
  ;

random_number:
  AN RANDOM NUMBER TO NUMBER
  ;

random_float:
  AN RANDOM FLOAT TO FLOAT
  ;