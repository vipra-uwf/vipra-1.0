
file(
  GLOB
  inputdataloader_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${inputdataloader_srcs}
)
