grammar Behavior;

import lexer_rules, event, selector, condition, action, declarations;

program: 
  decl_Ped '.' 
  statement+;

statement:
  event '.' |
  declaration '.' |
  ped_Selector '.' |
  action '.'
  ;