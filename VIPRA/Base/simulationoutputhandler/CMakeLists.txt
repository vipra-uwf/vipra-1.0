
file(
  GLOB
  simulationoutputhandler_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${simulationoutputhandler_srcs}
)
