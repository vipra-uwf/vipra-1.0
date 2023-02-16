grammar action;

import lexer_rules, condition;

action:
  conditional_action |
  un_conditional_action
  ;

conditional_action:
  AN ID 'will' sub_action condition '.';

un_conditional_action:
  AN ID 'will always' sub_action '.';

sub_action:
  action_atom ('then' action_atom)*
  ;

action_atom:
  ACTION |
  state_Set |
  action_Stop |
  action_atom_Percent_Walk_Speed
  ;

action_Stop:
  '@stop'
  ;

action_atom_Percent_Walk_Speed:
  '@walk' NUMBER '%' FASTERorSLOWER;