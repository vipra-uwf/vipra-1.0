
file(
  GLOB
  actions_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${actions_srcs}
)
