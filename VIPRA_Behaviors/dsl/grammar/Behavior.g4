grammar Behavior;

import lexer_rules, selector, condition;

program: 
  consideration statement+;


consideration: 'Consider ' A ID;

statement:
  ped_Selector
  ;