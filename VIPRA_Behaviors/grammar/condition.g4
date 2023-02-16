grammar condition;

import lexer_rules, directions, state, objects;

condition:
  sub_condition (ANDOR sub_condition)*
  ;

sub_condition:
  condition_State |
  condition_Time_Elapsed_From_Event |
  condition_Existance |
  condition_Event |
  condition_Event_Occurring
  ;

condition_Existance:
  GIVEN 'There is' AN ID Direction |
  GIVEN 'There is' AN ID Direction condition_Others_State
  ;

condition_State:
  GIVEN object 'is' STATE;

condition_Others_State:
  'That is' STATE;

condition_Met_Goal:
  'That has ' ('not ')? 'met any goal';

condition_Time_Elapsed_From_Event:
  'after' NUMBER 'seconds from' EVENT
  ;

condition_Event:
  GIVEN (AN)? EVENT 'event has occurred';

condition_Event_Occurring:
  WHILE (AN)? EVENT 'event is occurring';