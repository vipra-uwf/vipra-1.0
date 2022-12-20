
file(
  GLOB
  selectors_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${selectors_srcs}
)
