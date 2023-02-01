grammar action;

import lexer_rules, condition;

action:
  conditional_action |
  non_conditional_action
  ;

conditional_action: 
  'Given' WS condition WS A ID ' will ' WS sub_action;

non_conditional_action:
  A ID ' will always ' WS sub_action;

sub_action:
  action_atom |
  action_atom ', ' sub_action |
  action_atom ' and ' sub_action
  ;

action_atom:
  action_Stop
  ;

action_Stop:
  'STOP';