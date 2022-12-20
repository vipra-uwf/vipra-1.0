
file(
  GLOB
  conditions_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${conditions_srcs}
)
