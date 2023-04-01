grammar selector;

import lexer_rules;

ped_Selector:
    selector_Percent |
    selector_Exactly_N_Random |
    selector_Everyone;

selector_Percent: 
    AN RANDOM NUMBER '%' OF PEDESTRIANS ARE AN ID;

selector_Exactly_N_Random: 
    EXACLTY NUMBER (RANDOM PEDESTRIANS ARE | RANDOM PEDESTRIAN IS) AN ID;

selector_Everyone:
    EVERYONE IS AN ID;