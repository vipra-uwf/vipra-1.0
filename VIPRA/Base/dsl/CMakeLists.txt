
add_subdirectory(actions)
add_subdirectory(conditions)
add_subdirectory(selectors)
add_subdirectory(transitions)

add_subdirectory(generated)

target_sources(
  ${PROJECT_NAME}
  PUBLIC
  dsl_human_behavior.cpp
  human_behavior.cpp
)