grammar action;

import lexer_rules, attributes, values, condition, time, targets, stimuli;

action:
  ACTION '(' ID ')' ':' action_attribute*
;

// Note (rolland): this allows multiple of each for a given action but listing the permutations is a pain, errors are caught in the visit function
action_attribute:
  action_response |
  action_stimulus |
  action_duration |
  action_target |
  action_produce
;

action_stimulus:
  CONDITION ':' condition
;

action_response:
  RESPONSE ':' sub_action
;

action_duration:
  DURATION ':' duration
;

action_target:
  TARGET ':' target
;

action_produce:
  PRODUCE ':' produces
;

sub_action:
  action_atom (',' action_atom)*
;

action_atom:
  set_atom | 
  scale_atom
;

set_atom:
  SET TARGET? attribute TO attr_value
;

scale_atom:
  SCALE TARGET? attribute attr_value
;