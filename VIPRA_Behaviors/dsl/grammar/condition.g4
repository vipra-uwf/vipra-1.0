grammar condition;

import lexer_rules, directions;

condition:
  WS sub_condition |
  WS sub_condition WS AndOr WS condition
  ;

sub_condition:
  condition_Existance
  ;

condition_Existance:
  ' There is ' A ID Direction |
  ' There is ' A ID Direction condition_State
  ;

condition_State:
  ' That is ' STATE;