grammar time;

import lexer_rules, values;

duration:
  FOR value_number (SECONDS | SECOND)
  ;