grammar event;

import lexer_rules, condition;

event:
  event_Single |
  event_Lasting
;

event_Single:
  (AN|THE) EVNT (EVENT)? WILL OCCUR condition;

event_Lasting:
  (AN|THE) EVNT (EVENT)? WILL OCCUR condition AND END condition;

event_Individual:
  AN ID WILL EVNT condition
  ;
