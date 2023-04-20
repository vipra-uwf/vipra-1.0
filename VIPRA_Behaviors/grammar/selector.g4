grammar selector;

import lexer_rules, common;


ped_Selector:
    selector (ID | PEDESTRIAN | PEDESTRIANS ) (ARE | IS) AN id_list |
    selector_Everyone IS AN id_list
    ;

selector:
    selector_Percent |
    selector_Exactly_N_Random
    ;

selector_Percent:
    NUMBER '%' OF
    ;

selector_Exactly_N_Random:
    EXACTLY NUMBER OF
    ;

selector_Everyone:
    EVERYONE
    ;