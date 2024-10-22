grammar condition;

import lexer_rules, values, time, attributes;

condition:
  sub_condition connector*;

connector:
  or_Connector |
  and_Connector
  ;

or_Connector:
  OR sub_condition;

and_Connector:
  AND sub_condition;

sub_condition:
  condition_Time_Elapsed_From_Event |
  condition_Event_Occurred |
  condition_Event_Occurring |
  condition_Event_Starting |
  condition_Event_Ending |
  condition_Spatial |
  condition_Enter_Location |
  condition_Exit_Location
  ;

condition_Time_Elapsed_From_Event:
  value_numeric SECONDS AFTER EVNT
  ;

condition_Event_Occurred:
  EVNT HAS OCCURRED
  ;

condition_Event_Occurring:
  EVNT OCCURRING
  ;

condition_Event_Starting:
  EVNT STARTING
  ;

condition_Event_Ending:
  EVNT ENDING
  ;

condition_Spatial:
  TARGET WITHIN value_numeric
  ;

condition_Enter_Location:
  ENTER LOC_NAME
  ;

condition_Exit_Location:
  EXIT LOC_NAME
  ;

condition_Attribute:
  TARGET? attribute IS attr_value
  ;