grammar event;

import lexer_rules, condition;

event:
  event_Single |
  event_Lasting
;

event_Single:
  AN EVENT 'event will occur' condition '.';

event_Lasting:
  AN EVENT 'event will occur' condition 'and end' condition '.';