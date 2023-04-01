grammar Behavior;

import lexer_rules, event, selector, condition, action, declarations;

program: statement+;

statement:
  event '.' |
  declaration '.' |
  ped_Selector '.' |
  action '.'
  ;