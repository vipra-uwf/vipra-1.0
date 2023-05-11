
file(
  GLOB
  humanbehavior_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${humanbehavior_srcs}
)
