
file(
  GLOB
  outputdatawriter_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${outputdatawriter_srcs}
)
