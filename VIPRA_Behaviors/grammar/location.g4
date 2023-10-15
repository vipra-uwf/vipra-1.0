grammar location;

import values, lexer_rules;

location:
  LOCATION ':' location_attribute*
;

location_attribute:
  loc_name |
  loc_dimensions
;

loc_name:
  NAME ':' ID
;

loc_dimensions:
  DIMENSIONS ':'
  value_coord ','
  value_coord ','
  value_numeric
;