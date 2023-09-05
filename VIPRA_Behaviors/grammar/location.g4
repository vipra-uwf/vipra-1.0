grammar location;

import values, lexer_rules;

location:
  LOCATION ':' location_attribute*
;

location_attribute:
  loc_name |
  loc_shape |
  loc_dimensions
;

loc_name:
  NAME ':' ID
;

loc_shape:
  SHAPE ':' RECTANGLE |
  SHAPE ':' CIRCLE
;

loc_dimensions:
  rect_dims |
  circle_dims
;

rect_dims:
  POINTS ':'
  value_coord
  value_coord
;

circle_dims:
  CENTER ':' value_coord
  RADIUS ':' value_numeric
;