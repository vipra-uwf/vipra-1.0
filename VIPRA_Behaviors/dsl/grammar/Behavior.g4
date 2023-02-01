grammar Behavior;

import lexer_rules, selector, condition, action, declarations;

// TODO add state transitions

program: statement+;

statement:
  declaration |
  ped_Selector |
  action
  ;