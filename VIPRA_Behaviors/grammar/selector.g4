grammar selector;

import lexer_rules, common;

ped_Selector:
    (REQUIRED COLON)? selector (ID | PEDESTRIAN | PEDESTRIANS ) selector_Cond? (ARE | IS) AN? id_list |
    (REQUIRED COLON)? selector_Everyone selector_Cond? IS AN? id_list
    ;

selector_Cond:
    THAT ARE 
    ;

selector:
    selector_Percent |
    selector_Exactly_N_Random |
    selector_Everyone |
    selector_Area;

selector_Percent:
    NUMBER '%' OF
    ;

selector_Exactly_N_Random:
    EXACTLY NUMBER OF
    ;

selector_Everyone:
    EVERYONE
    ;

selector_Area:
    EVERYON IN LOC IS AN ID;
