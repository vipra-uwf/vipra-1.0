grammar definitions;

import lexer_rules, action;

definition_atom:
  THE 'action ' ID ' means: ' sub_action '.'
  ;

definition_condition:
  THE 'condition ' ID ' means: ' sub_condition '.'
  ;