
file(
  GLOB
  humanbehavior_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${EXE_NAME}
  PRIVATE
  ${humanbehavior_srcs}
)
