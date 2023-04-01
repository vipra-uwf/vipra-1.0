grammar attributes;

import lexer_rules;

ped_Attribute:
  speed |
  end_goal |
  state
  ;  

speed:
  '*speed';

end_goal:
  '*end_goal';

state:
  '*state';