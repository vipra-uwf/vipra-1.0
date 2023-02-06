grammar transitions;

import lexer_rules, condition, state;

transition_Environment:
  'The Environment will' state_Set condition '.';

transition_Pedestrian:
  AN ID 'will' state_Set condition '.';