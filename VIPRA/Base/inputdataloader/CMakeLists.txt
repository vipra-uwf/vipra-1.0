
file(
  GLOB
  inputdataloader_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${EXE_NAME}
  PRIVATE
  ${inputdataloader_srcs}
)
