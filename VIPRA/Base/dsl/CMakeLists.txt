
file(
  GLOB
  dsl_srcs
  *.cpp
  */*.cpp
)

target_sources(
  ${EXE_NAME}
  PRIVATE
  ${dsl_srcs}
)
