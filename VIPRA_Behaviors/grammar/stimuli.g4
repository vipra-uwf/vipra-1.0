grammar stimuli;

import lexer_rules;

stimulus_type:
  AUDITORY |
  VISUAL
;

produces:
  ID '(' stimulus_type ')' (',' ID '(' stimulus_type ')')*
;