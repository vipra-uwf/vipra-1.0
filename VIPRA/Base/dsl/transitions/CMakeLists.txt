file(
  GLOB
  tranisition_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${tranisition_srcs}
)
