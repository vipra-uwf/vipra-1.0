grammar Behavior;

import lexer_rules, transitions, selector, condition, action, declarations;

program: statement+;

statement:
  declaration |
  ped_Selector |
  action |
  transition_Environment |
  transition_Pedestrian
  ;