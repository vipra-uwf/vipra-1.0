grammar selector;

import lexer_rules;

ped_Selector:
    selector_Percent |
    selector_Exactly_N_Random |
    selector_Everyone;

selector_Percent : NUMBER ' out of ' NUMBER ' Pedestrians is ' A ID '.';

selector_Exactly_N_Random: 
'Exactly ' NUMBER ' random pedestrians are ' A ID '.' | 
'Exactly ' NUMBER ' random pedestrian is ' A ID '.'
;

selector_Everyone: 'Everyone is ' A ID '.';