grammar selector;

import lexer_rules, values, common;

ped_Selector:
    (REQUIRED COLON)? selector (ID | PEDESTRIAN | PEDESTRIANS ) (ARE | IS) AN? id_list |
    (REQUIRED COLON)? selector_Everyone IS AN? id_list
    ;

selector:
    selector_Percent |
    selector_Exactly_N_Random |
    selector_Everyone
    ;

selector_Percent:
    value_number '%' (OF)?
    ;

selector_Exactly_N_Random:
    EXACTLY value_number (OF)?
    ;

selector_Everyone:
    EVERYONE
    ;

