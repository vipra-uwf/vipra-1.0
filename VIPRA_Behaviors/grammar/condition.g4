grammar condition;

import lexer_rules, directions, state, objects;

condition:
  sub_condition (ANDOR sub_condition)*
  ;

sub_condition:
  condition_State |
  condition_Time_Elapsed |
  condition_Existance |
  ;

condition_Existance:
  GIVEN 'There is' AN ID Direction |
  GIVEN 'There is' AN ID Direction condition_Others_State
  ;

condition_State:
  GIVEN object 'is ' STATE;

condition_Others_State:
  'That is ' STATE;

condition_Time_Elapsed:
  'after' NUMBER 'seconds'
  ;
  // GIVEN NUMBER 'seconds has elapsed' |