
file(
  GLOB
  simulation_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${EXE_NAME}
  PRIVATE
  ${simulation_srcs}
)
