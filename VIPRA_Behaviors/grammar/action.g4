grammar action;

import lexer_rules, condition;

action:
  conditional_action |
  un_conditional_action
  ;

conditional_action:
  AN ID WILL sub_action condition;

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
  '@walk' FLOAT 'x' THEIR NORMAL SPEED;

action_Push:
  '@push' ID
  ;

action_Be:
  '@be set to' STATE
  ;