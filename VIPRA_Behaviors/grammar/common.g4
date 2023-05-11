grammar common;

import lexer_rules;

id_list:
    (ID (COMMA? AND? AN? ID)*);