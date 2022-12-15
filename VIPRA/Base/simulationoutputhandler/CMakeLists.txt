
file(
  GLOB
  simulationoutputhandler_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${EXE_NAME}
  PRIVATE
  ${simulationoutputhandler_srcs}
)
