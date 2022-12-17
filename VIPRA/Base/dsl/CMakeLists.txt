
file(
  GLOB
  dsl_srcs
  *.cpp
  */*.cpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${dsl_srcs}
)
