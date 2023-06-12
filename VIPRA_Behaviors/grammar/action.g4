grammar action;

import lexer_rules, values, condition, time;

action:
  conditional_action |
  un_conditional_action
  ;

conditional_action:
  AN ID WILL sub_action condition (duration?)
  ;

un_conditional_action:
  AN ID WILL ALWAYS sub_action;

sub_action:
  action_atom (THEN action_atom)*
  ;

action_atom:
  ACTION |
  action_Stop |
  action_Be |
  action_atom_Percent_Walk_Speed
  ;

action_Stop:
  '@stop'
  ;

action_atom_Percent_Walk_Speed:
  '@walk' value_numeric 'x' THEIR NORMAL SPEED
  ;

action_Be:
  '@be set to' STATE
  ;