grammar event;

import lexer_rules, condition, stimuli;

event:
  EVENT ':' event_attribute*
;

event_attribute:
  event_name |
  event_start |
  event_duration |
  event_produce |
  event_where
;

event_name:
  NAME ':' ID
;

event_start:
  START ':' value_numeric
;

event_duration:
  DURATION ':' value_numeric
;

event_produce:
  PRODUCE ':' produces
;

event_where:
  WHERE ':' (EVERYWHERE | value_coord)
;