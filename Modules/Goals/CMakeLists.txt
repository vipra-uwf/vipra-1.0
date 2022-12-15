
file(
  GLOB
  goals_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${EXE_NAME}
  PRIVATE
  ${goals_srcs}
)
