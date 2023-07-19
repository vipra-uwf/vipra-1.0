grammar targets;

import lexer_rules;

target:
  self |
  nearest_type
  ;

self:
  SELF
  ;

nearest_type:
  NEAREST ID
  ;