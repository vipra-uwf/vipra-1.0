grammar selector;

import lexer_rules;

ped_Selector:
    (selector_Percent | selector_Exactly_N_Random | selector_Everyone) (ARE | IS) AN ID;

selector_Percent: 
    AN RANDOM NUMBER '%' OF PEDESTRIANS |
    NUMBER '%' OF PEDESTRIANS
    ;

selector_Exactly_N_Random:
    EXACTLY NUMBER RANDOM (PEDESTRIAN | PEDESTRIANS);

selector_Everyone:
    EVERYONE;