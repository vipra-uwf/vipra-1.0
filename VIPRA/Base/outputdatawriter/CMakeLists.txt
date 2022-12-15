
file(
  GLOB
  outputdatawriter_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${EXE_NAME}
  PRIVATE
  ${outputdatawriter_srcs}
)
