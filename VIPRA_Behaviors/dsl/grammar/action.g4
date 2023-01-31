grammar action;

import lexer_rules, condition;

conditional_action: 
  'Given' WS condition WS A ID ' will ' WS action;

non_conditional_action:
  A ID ' will always ' WS action;

action:
  sub_action |
  sub_action ', ' action |
  sub_action ' and ' action
  ;

sub_action:
  action_Stop
  ;

action_Stop:
  'STOP';