grammar selector;

import lexer_rules;

ped_Selector:
    selector_Percent |
    selector_Exactly_N_Random |
    selector_Everyone;

selector_Percent : 'A Random' NUMBER '% of Pedestrians are' AN ID '.';

selector_Exactly_N_Random: 
'Exactly' NUMBER ('random pedestrians are' | 'random pedestrian is') AN ID '.'
;

selector_Everyone: 'Everyone is' AN ID '.';