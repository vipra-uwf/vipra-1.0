

target_sources(
  ${LIB_NAME}
  PRIVATE
  condition.cpp
  subconditions/subcondition_elapsed_time.cpp
  subconditions/subcondition_event.cpp
  subconditions/subcondition_start.cpp
  subconditions/subcondition_event_occurring.cpp
)