grammar condition;

import lexer_rules, directions;

condition:
  WS sub_condition |
  WS sub_condition WS AndOr WS condition
  ;

sub_condition:
  condition_State |
  condition_Existance |
  condition_Env_State
  ;

condition_Existance:
  ' There is ' A ID Direction |
  ' There is ' A ID Direction condition_Others_State
  ;

condition_State:
  ' The ' ID ' is ' STATE;

condition_Others_State:
  ' That is ' STATE;

condition_Env_State:
  ' The Environment is ' STATE;